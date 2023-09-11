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
  SqlParser(DBEngine &dbengine);

  virtual ~SqlParser();

  void parse(const char *filename);

  std::vector<std::string> &parse(std::istream &iss);

  void checkTableName(const std::string &tablename);

  void createTable(std::string &tablename,
                   const std::vector<column_t *> &columns);

  void select(const std::string &tablename,
              const std::vector<std::string> &column_names,
              const std::list<std::list<condition_t>> &constraints);

private:
  DBEngine &engine;
  std::vector<std::string> response;
  void parse_helper(std::istream &stream);
  std::unordered_set<std::string> tablenames;
  yy::parser *parser = nullptr;
  scanner *sc = nullptr;
};

#endif // SQL_PARSER_HPP
