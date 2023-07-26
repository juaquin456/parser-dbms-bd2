#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>

#include "scanner.hpp"
#include "parser.tab.hh"

class driver{
public:
    driver() = default;

    virtual ~driver();

    void parse(const char* filename);

    void parse(std::istream &iss);

    void insert();
    void del();
    void exec();
    void setTableName(const std::string& table);
private:
    void parse_helper(std::istream &stream);
    std::string table_name;
    yy::parser *parser = nullptr;
    scanner *sc = nullptr;
};

#endif