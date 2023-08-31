#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <cstddef>
#include <istream>
#include <string>
#include <unordered_set>

#include "parser.tab.hh"
#include "scanner.hpp"

struct column_t;

class driver {
public:
  driver();

  virtual ~driver();

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

#endif
