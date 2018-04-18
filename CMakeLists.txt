cmake_minimum_required(VERSION 3.8.2)
project(reimplalgo
  VERSION 0.1.0
  LANGUAGES CXX
)
set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type for only meaningful to single-configuration generators")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS RelWithDebInfo Release Debug MinSizeRel)

option(ENABLE_TEST "Add build target for gtest" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(DOXYGEN_EXCUDE_PATTERNS */detail/*)
  doxygen_add_docs(doxygen
    "${PROJECT_NAME}"
    COMMENT "Generate ${PROJECT_NAME} API reference.")
endif()

if(ENABLE_TEST)
  include_directories(.)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
  enable_testing()
  add_subdirectory(test)
endif()

install(DIRECTORY "${PROJECT_NAME}" DESTINATION include)
