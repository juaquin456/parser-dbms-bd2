#include <cctype>
#include <fstream>
#include <cassert>
#include <cstring>

#include "driver.hpp"

const std::string METADATA_PATH = "./meta.data";

driver::driver() {
    std::ifstream metadata(METADATA_PATH, std::ios::app | std::ios::binary);
    if (!metadata.is_open()) {
        std::cerr << "Can't open meta.data\n";
        exit(EXIT_FAILURE);
    }

    // Load all tablenames in memory
    metadata.seekg(0);
    while(metadata.peek() != EOF) {
        char name[64];
        metadata.read(name, 64);
        this->tablenames.insert(name);
    }

    metadata.close();
}

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

}

void driver::createTable(std::string& tablename, const std::vector<column_t*>& columns) {
    if (this->tablenames.find(tablename) != nullptr) {
        std::cerr << "Table already exist\n";
        exit(EXIT_FAILURE);
    }
    this->tablenames.insert(tablename);
    
    std::ofstream metadata(METADATA_PATH, std::ios::binary | std::ios::app);
    metadata.seekp(0, std::ios::end);
    metadata.write(tablename.c_str(), 64);
    metadata.close();

    std::ofstream tablefile(tablename+".bin", std::ios::app | std::ios::app);
    for(auto& column: columns) {
        tablefile.write((char*)& *column, sizeof(*column));
        delete column;
    }
    tablefile.close();
}

void driver::select(const std::string& tablename, std::vector<std::string>* column_names, condition_t* constraint) {
    if (this->tablenames.find(tablename) == nullptr) {
        std::cerr << "Table doesn't exist\n";
        exit(EXIT_FAILURE);
    }

    if (constraint == nullptr) return;
    switch (constraint->value.type.value) {
        case Type::Bool:
            break;
        case Type::Numeric:
            int value;
            memcpy(&value, constraint->value.data, constraint->value.type.size);
            std::cout << "the value to compare is "<< value << std::endl;
            break;
        case Type::Floating:
            double value1;
            memcpy(&value1, constraint->value.data, constraint->value.type.size);
            std::cout << "the value to compare is "<< value1 << std::endl;
            break;
        case Type::Char:
            std::string buffer(constraint->value.data);
            std::cout << "the value to compare is "<< buffer << std::endl;
            break;
    }

    switch (constraint->c)
    {
    case EQUAL:
        break;
    
    default:
        break;
    }
}