cmake_minimum_required(VERSION 3.4...3.18)

project(bmipybind11)

set(PYTHON_TARGET_NAME phreeqcrm)

add_subdirectory(pybind11)

pybind11_add_module(bmipybind bmi-example.cpp)

enable_testing()

add_test(NAME run_pybind11_pytest
  COMMAND ${PYTHON_EXECUTABLE} -m pytest
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

set_tests_properties(run_pybind11_pytest
    PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}:$ENV{PYTHONPATH}")
