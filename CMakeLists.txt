set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")

project(simple_wc_example CXX)

cmake_minimum_required(VERSION 3.1)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

bison_target(parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cc)
flex_target(lexer lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cc)
add_flex_bison_dependency(lexer parser)

add_executable(my_wc main.cpp driver.cpp ${FLEX_lexer_OUTPUTS}
                     ${BISON_parser_OUTPUTS})
target_include_directories(
  my_wc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${FLEX_INCLUDE_DIRS}
                ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET my_wc PROPERTY CXX_STANDARD 14)
enable_testing()
add_test(
  NAME basic
  COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
