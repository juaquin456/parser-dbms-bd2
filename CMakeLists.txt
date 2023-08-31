cmake_minimum_required(VERSION 3.26)

project(
  SqlParser
  VERSION 1.0
  DESCRIPTION "A simple sql parser made in c++"
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Dynamically Generating headers? (not sure if this is the best way to do it)
# Doesnt seems like its fetching anything
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
bison_target(parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cc)
flex_target(lexer lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cc)
add_flex_bison_dependency(lexer parser)

add_library(sql_parser SqlParser.cpp)

target_compile_features(sql_parser PRIVATE cxx_std_20)

# Additional files to be compiled
target_sources(sql_parser PRIVATE ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})

target_include_directories(
  sql_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${FLEX_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_BINARY_DIR})

target_compile_options(
  sql_parser
  PRIVATE
    # Prefered warnings
    $<$<CXX_COMPILER_ID:MSVC>:/W4
    /WX>
    $<$<CXX_COMPILER_ID:Clang>:-Weverything>
    $<$<CXX_COMPILER_ID:GCC>:-Wall
    -Wextra
    -Wpedantic
    -Wformat=2
    -Wno-unused-parameter
    -Wshadow
    -Wwrite-strings
    -Wcast-qual
    -Wcast-align
    -Wconversion
    -Werror>
    # Disable some warnings
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-deprecated-register> # WHY?
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-c++98-compat>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-c++98-compat-pedantic>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-c++20-compat>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-zero-as-null-pointer-constant> # Solves a
                                                                         # bug,
                                                                         # forgot
                                                                         # which one
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wno-error=padded>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-fsanitize=address,undefined>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-fsanitize-address-use-after-scope>
    $<$<CONFIG:RELEASE>:-Ofast>
    $<$<CONFIG:DEBUG>:-O0>
    $<$<CONFIG:DEBUG>:-ggdb3>
    "-fsanitize=address,undefined")

target_link_options(
  sql_parser PRIVATE
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-fsanitize=address,undefined>)

# Wht kind of tests are these?
enable_testing()
add_test(
  NAME basic
  COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
