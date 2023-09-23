#ifndef SQL_PARSER_HPP
#define SQL_PARSER_HPP

#include <concepts>
#include <cstddef>
#include <istream>
#include <string>
#include <unordered_set>
#include <vector>

#include "parser.tab.hh"
#include "scanner.hpp"

class SqlParser {
public:
  SqlParser() = default;

  ~SqlParser();

  void parse(const char *filename);

  auto parse(std::istream &stream) -> std::vector<std::string> &;

  void check_table_name(const std::string &tablename);

  void create_table(const std::string &tablename,
                    const std::vector<column_t> &columns);

  void select(const std::string &tablename,
              const std::vector<std::string> &column_names,
              const std::list<std::list<condition_t>> &constraints);
  auto get_engine() -> DB_ENGINE::DBEngine & { return m_engine; }

  void insert_from_file(const std::string &tablename,
                        const std::string &filename);

  void insert(const std::string &tablename, const std::vector<std::string>& values);

private:
  DB_ENGINE::DBEngine m_engine;
  std::vector<std::string> m_response;

  void parse_helper(std::istream &stream);
  std::unordered_set<std::string> m_tablenames;
  yy::parser *m_parser = nullptr;
  scanner *m_sc = nullptr;

  static auto merge_vectors(const std::vector<std::string> &vec1,
                            const std::vector<std::string> &vec2)
      -> std::vector<std::string>;
};

#endif // SQL_PARSER_HPP
