#include <algorithm>
#include <cassert>
#include <cctype>
#include <fstream>
#include <functional>
#include <ranges>

#include "SqlParser.hpp"

// #include "../../include/DBEngine/DBEngine.hpp"

// const std::string METADATA_PATH = "./meta.data";

// SqlParser::SqlParser(DBEngine &dbengine) : engine(dbengine) {
//   std::ifstream metadata(METADATA_PATH, std::ios::app | std::ios::binary);
//   if (!metadata.is_open()) {
//     std::cerr << "Can't open meta.data\n";
//     exit(EXIT_FAILURE);
//   }
//
//   // Load all tablenames in memory
//   metadata.seekg(0);
//   while (metadata.peek() != EOF) {
//     char name[64];
//     metadata.read(name, 64);
//     this->tablenames.insert(name);
//   }
//
//   metadata.close();
// }
//
// SqlParser::~SqlParser() {
//   delete sc;
//   sc = nullptr;
//   delete parser;
//   parser = nullptr;
// }

void SqlParser::parse(const char *filename) {
  assert(filename != nullptr);
  std::ifstream in_file(filename);
  if (!in_file.good()) {
    exit(EXIT_FAILURE);
  }
  parse_helper(in_file);
}

auto SqlParser::parse(std::istream &stream) -> std::vector<std::string> & {
  if (!stream.good() && stream.eof()) {
    return this->m_response;
  }
  parse_helper(stream);
  return this->m_response;
}

void SqlParser::parse_helper(std::istream &stream) {
  delete (m_sc);
  try {
    m_sc = new scanner(&stream);
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate scanner: (" << ba.what()
              << "), exiting!!\n";
    exit(EXIT_FAILURE);
  }
  delete (m_parser);
  try {
    m_parser = new yy::parser((*m_sc), (*this));
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate parser: (" << ba.what()
              << "), exiting!!\n";
    exit(EXIT_FAILURE);
  }

  const int ACCEPT(0);
  if (m_parser->parse() != ACCEPT) {
    std::cerr << "Parse failed!!\n";
  }
}

void SqlParser::check_table_name(const std::string &tablename) {
  if (!this->m_engine.is_table(tablename)) {
    throw std::runtime_error("Table not exists");
  }
}

void SqlParser::create_table(const std::string &tablename,
                             const std::vector<column_t *> &columns) {

  std::vector<Type> col_types;
  std::vector<std::string> col_names;

  std::string primary_key;

  col_types.reserve(columns.size());
  col_names.reserve(columns.size());

  for (const auto &col : columns) {
    if (col->is_pk) {
      primary_key = col->name;
    }

    col_types.push_back(col->type);
    col_names.push_back(col->name);
  }

  if (!m_engine.create_table(tablename, primary_key, col_types, col_names)) {
    throw std::runtime_error("Table already exists");
  }
}

void SqlParser::select(const std::string &tablename,
                       const std::vector<std::string> &column_names,
                       const std::list<std::list<condition_t>> &constraints) {
  auto table_attributes = this->m_engine.get_table_attributes(tablename);

  // check if col exists
  if (std::ranges::any_of(column_names, [&](const auto &col) {
        return std::ranges::find(table_attributes, col) ==
               table_attributes.end();
      })) {
    throw std::runtime_error("Column doesn't exist");
  }

  // Iterating OR constraints
  for (const auto &or_constraint : constraints) {

    condition_t constraint_key;

    std::function<bool(const Record &rec)> lamb = [](const Record & /*rec*/) {
      return true;
    };

    // Iterating the AND contraints
    for (const auto &column_constraint : or_constraint) {
      // Checkear si el constraint actual tiene un indice asociado
      // si lo tiene, asignar al constraint_key
      // si no, construir un predicado con los operadores;

      auto indexes = this->m_engine.get_indexes_names(tablename);

      // If the column doesnt has an index
      if (std::ranges::find(indexes, column_constraint.column_name) ==
          indexes.end()) {

        auto record_comp = m_engine.get_comparator(
            tablename, column_constraint.c, column_constraint.column_name,
            column_constraint.value);

        lamb = [&lamb, &record_comp](const Record &rec) {
          return lamb(rec) && record_comp(rec);
        };
      } else {
        // If the column has an index and the constraint_key is empty
        if (constraint_key.column_name.empty()) {
          constraint_key = column_constraint;
        }
      }
    }

    if (constraint_key.c == Comp::EQUAL) {

      auto or_response = m_engine.search(
          tablename, {constraint_key.column_name, constraint_key.value}, lamb,
          column_names);
    } else {

      Attribute begin_key = KEY_LIMITS::MIN;
      Attribute end_key = KEY_LIMITS::MAX;

      switch (constraint_key.c) {
      case Comp::L:
      case Comp::LE:
        end_key = {constraint_key.column_name, constraint_key.value};
        break;
      case Comp::G:
      case Comp::GE:
        begin_key = {constraint_key.column_name, constraint_key.value};
        break;
      case Comp::EQUAL:
        break;
      }

      auto or_response = m_engine.range_search(tablename, begin_key, end_key,
                                               lamb, column_names);

      m_response = merge_vectors(m_response, or_response);
    }
  }
}

auto SqlParser::merge_vectors(const std::vector<std::string> &vec1,
                              const std::vector<std::string> &vec2)
    -> std::vector<std::string> {

  std::vector<std::string> result;
  result.reserve(vec1.size() + vec2.size());

  result.insert(result.end(), vec1.begin(), vec1.end());

  std::unordered_set<std::string> unique_elements(vec1.begin(), vec1.end());

  for (const auto &element : vec2) {
    if (unique_elements.find(element) == unique_elements.end()) {
      result.push_back(element);
      unique_elements.insert(element);
    }
  }

  return result;
}
