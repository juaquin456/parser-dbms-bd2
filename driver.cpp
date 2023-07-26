#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

driver::~driver(){
    delete sc;
    sc = nullptr;
    delete parser;
    parser = nullptr;
}

void driver::parse(const char* filename){
    assert(filename != nullptr);
    std::ifstream in_file(filename);
    if (!in_file.good()){
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
}

void driver::parse(std::istream &stream){
    if(!stream.good() && stream.eof()){
        return;
    }
    std::cout<<"ok"<<std::endl;
    parse_helper(stream);
}

void driver::parse_helper(std::istream &stream){
    delete(sc);
    try{
        sc = new scanner(&stream);
    }
    catch(std::bad_alloc &ba){
        std::cerr << "Failed to allocate scanner: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }
    delete(parser);
    try{
        parser = new yy::parser((*sc), (*this));
    }
    catch(std::bad_alloc &ba){
        std::cerr << "Failed to allocate parser: (" << ba.what() << "), exiting!!\n";
        exit( EXIT_FAILURE );
    }

    const int accept(0);
    if(parser->parse() != accept){
        std::cerr << "Parse failed!!\n";
    }
}

void driver::insert(){
    printf("Insert found\n");
}

void driver::del(){
    printf("Delete found\n");
}

void driver::exec(){
    /* execute engine db */

    this->table_name = "";
}

void driver::setTableName(const std::string& table) {
    this->table_name = table;
    std::cout << "Current table name: " << this->table_name << std::endl;
}