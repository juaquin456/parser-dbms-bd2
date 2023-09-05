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

struct column_t;

class DBEngine;

class SqlParser {
public:
  SqlParser(DBEngine& dbengine);

  virtual ~SqlParser();

  void parse(const char *filename);

  void parse(std::istream &iss);

  void insert();
  void del();
  void exec();

  void createTable(std::string &tablename,
                   const std::vector<column_t *> &columns);

  void select(std::vector<std::string> &response_body, std::string &tablename,
              std::vector<std::string> *column_names);
private:
  DBEngine& engine;
  void parse_helper(std::istream &stream);
  std::unordered_set<std::string> tablenames;
  yy::parser *parser = nullptr;
  scanner *sc = nullptr;
};

#endif // SQL_PARSER_HPP
