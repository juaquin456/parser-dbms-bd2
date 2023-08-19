#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>
#include <unordered_set>

#include "scanner.hpp"
#include "parser.tab.hh"

class driver{
public:
    driver();

    virtual ~driver();

    void parse(const char* filename);

    void parse(std::istream &iss);

    void insert();
    void del();
    void exec();
    void createTable(std::string& tablename, const std::vector<std::tuple<std::string, std::pair<int, int>, bool>*>& columns);
private:
    void parse_helper(std::istream &stream);
    std::unordered_set<std::string> tablenames;
    yy::parser *parser = nullptr;
    scanner *sc = nullptr;
};

#endif