cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_subdirectory(gtest)

set(Clang_WARN_OPTIONS
  -Weverything
  -Wno-c++98-compat
  -Wno-c++98-compat-pedantic
  -Wno-global-constructors
  -Wno-missing-variable-declarations
  -Wno-padded
)
set(GNU_WARN_OPTIONS
  -Wall
  -Wextra
  -Wpedantic
  -Wchkp
  -Wdouble-promotion
  -Wnull-dereference
  -Wimplicit-fallthrough
  -Wmissing-include-dirs
  -Wswitch-enum
  -Wsync-nand
  -Wunused-parameter
  -Wuninitialized
  -Wstrict-overflow
  -Wsuggest-attribute=noreturn
  -Wsuggest-final-types
  -Wsuggest-final-methods
  -Walloc-zero
  -Walloca
  -Wduplicated-branches
  -Wduplicated-cond
  -Wtrampolines
  -Wfloat-equal
  -Wshadow
  -Wunsafe-loop-optimizations
  -Wcast-qual
  -Wconditionally-supported
  -Wconversion
  -Wzero-as-null-pointer-constant
  -Wdate-time
  -Wuseless-cast
  -Wsized-deallocation
  -Wlogical-op
  -Wmissing-declarations
  -Wnormalized
  -Wopenmp-simd
  -Wpacked
  -Wredundant-decls
  -Wrestrict
  -Winvalid-pch
  -Wvla
  -Wdisabled-optimization
  -Wstack-protector
  -Whsa
)

add_compile_options(
  "$<$<CXX_COMPILER_ID:Clang>:${Clang_WARN_OPTIONS}>"
  "$<$<CXX_COMPILER_ID:GNU>:${GNU_WARN_OPTIONS}>"
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# Add some test
add_executable(test_combination combination.cpp)
target_link_libraries(test_combination gmock_main)
add_test(NAME test_combination COMMAND test_combination)

add_executable(test_horner horner.cpp)
target_link_libraries(test_horner gmock_main)
add_test(NAME test_horner COMMAND test_horner)

add_executable(test_factorial factorial.cpp)
target_link_libraries(test_factorial gmock_main)
add_test(NAME test_factorial COMMAND test_factorial)

add_executable(test_pow pow.cpp)
target_link_libraries(test_pow gmock_main)
add_test(NAME test_pow COMMAND test_pow)

add_executable(test_fibonacci fibonacci.cpp)
target_link_libraries(test_fibonacci gmock_main)
add_test(NAME test_fibonacci COMMAND test_fibonacci)

add_executable(test_rank_map rank_map.cpp)
target_link_libraries(test_rank_map gmock_main)
add_test(NAME test_rank_map COMMAND test_rank_map)
