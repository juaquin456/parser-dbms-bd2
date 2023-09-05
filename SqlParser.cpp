#include <cassert>
#include <cctype>
#include <fstream>

#include "SqlParser.hpp"

const std::string METADATA_PATH = "./meta.data";

SqlParser::SqlParser(DBEngine& dbengine): engine(dbengine) {
  std::ifstream metadata(METADATA_PATH, std::ios::app | std::ios::binary);
  if (!metadata.is_open()) {
    std::cerr << "Can't open meta.data\n";
    exit(EXIT_FAILURE);
  }

  // Load all tablenames in memory
  metadata.seekg(0);
  while (metadata.peek() != EOF) {
    char name[64];
    metadata.read(name, 64);
    this->tablenames.insert(name);
  }

  metadata.close();
}

SqlParser::~SqlParser() {
  delete sc;
  sc = nullptr;
  delete parser;
  parser = nullptr;
}

void SqlParser::parse(const char *filename) {
  assert(filename != nullptr);
  std::ifstream in_file(filename);
  if (!in_file.good()) {
    exit(EXIT_FAILURE);
  }
  parse_helper(in_file);
}

void SqlParser::parse(std::istream &stream) {
  if (!stream.good() && stream.eof()) {
    return;
  }
  parse_helper(stream);
}

void SqlParser::parse_helper(std::istream &stream) {
  delete (sc);
  try {
    sc = new scanner(&stream);
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate scanner: (" << ba.what()
              << "), exiting!!\n";
    exit(EXIT_FAILURE);
  }
  delete (parser);
  try {
    parser = new yy::parser((*sc), (*this));
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate parser: (" << ba.what()
              << "), exiting!!\n";
    exit(EXIT_FAILURE);
  }

  const int accept(0);
  if (parser->parse() != accept) {
    std::cerr << "Parse failed!!\n";
  }
}

void SqlParser::insert() { printf("Insert found\n"); }

void SqlParser::del() { printf("Delete found\n"); }

void SqlParser::exec() {}

void SqlParser::createTable(std::string &tablename,
                            const std::vector<column_t *> &columns) {
  if (this->tablenames.find(tablename) != nullptr) {
    std::cerr << "Table already exist\n";
    exit(EXIT_FAILURE);
  }
  this->tablenames.insert(tablename);

  std::ofstream metadata(METADATA_PATH, std::ios::binary | std::ios::app);
  metadata.seekp(0, std::ios::end);
  metadata.write(tablename.c_str(), 64);
  metadata.close();

  std::ofstream tablefile(tablename + ".bin", std::ios::app);
  for (auto &column : columns) {
    tablefile.write((char *)&*column, sizeof(*column));
    delete column;
  }
  tablefile.close();
}

void SqlParser::select(std::vector<std::string> &response_body, std::string &tablename,
              std::vector<std::string> *column_names) {
                
              }
