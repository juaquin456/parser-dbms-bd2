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

template <typename T>
concept engine_t = requires(T t) {
  {
    t.createTable(std::vector<std::string>(), std::string())
  } -> std::convertible_to<void>;
};

template <engine_t T> class SqlParser {
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

  void select(vect<str> &response_body, std::string &tablename,
              std::vector<std::string> *column_names) {
    response_body = engine.select(tablename, column_names);
  }

private:
  T engine;
  void parse_helper(std::istream &stream);
  std::unordered_set<std::string> tablenames;
  yy::parser *parser = nullptr;
  scanner *sc = nullptr;
};

#endif // SQL_PARSER_HPP
