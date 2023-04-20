cmake_minimum_required(VERSION 3.4...3.18)

project(bmiswig)

find_package(SWIG REQUIRED)

find_package(Python 3.8 REQUIRED COMPONENTS Interpreter Development Development.Module NumPy)

include(${SWIG_USE_FILE})

set_source_files_properties(bmi_swig.i PROPERTIES SWIG_FLAGS "-Wall")
set_source_files_properties(bmi_swig.i PROPERTIES CPLUSPLUS ON)

swig_add_library(
  bmiswig
  LANGUAGE python
  TYPE MODULE
  SOURCES bmi_swig.i BMIswig.cpp BMIswig.h
)

target_compile_features(bmiswig PUBLIC cxx_std_11)

target_include_directories(bmiswig PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(bmiswig
  PRIVATE
    Python::Python
    Python::NumPy
)

enable_testing()

add_test(NAME run_swig_pytest
  COMMAND ${PYTHON_EXECUTABLE} -m pytest
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

set_tests_properties(run_swig_pytest
    PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}:$ENV{PYTHONPATH}")
