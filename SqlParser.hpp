#ifndef SQL_PARSER_HPP
#define SQL_PARSER_HPP

#include <cstddef>
#include <istream>
#include <string>
#include <unordered_set>

#include "parser.tab.hh"
#include "scanner.hpp"

struct column_t;

class SqlParser {
public:
  SqlParser();

  virtual ~SqlParser();

  void parse(const char *filename);

  void parse(std::istream &iss);

  void insert();
  void del();
  void exec();
  void createTable(std::string &tablename,
                   const std::vector<column_t *> &columns);
  void select(std::string &tablename, std::vector<std::string> *column_names);

private:
  void parse_helper(std::istream &stream);
  std::unordered_set<std::string> tablenames;
  yy::parser *parser = nullptr;
  scanner *sc = nullptr;
};

#endif // SQL_PARSER_HPP
