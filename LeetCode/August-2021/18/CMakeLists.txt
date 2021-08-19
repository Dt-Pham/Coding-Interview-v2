cmake_minimum_required(VERSION 3.10)

project(Decode_Ways)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Decode_Ways Decode_Ways.cpp)

enable_testing()

# does the code run
add_test(NAME Test_Runs COMMAND Decode_Ways 12)

# does the usage message work?
add_test(NAME Test_Usage COMMAND Decode_Ways)
set_tests_properties(Test_Usage
                     PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*string"
                     )

function(do_test target arg result)
    add_test(NAME Test_${arg} COMMAND ${target} ${arg})
    set_tests_properties(Test_${arg}
                         PROPERTIES PASS_REGULAR_EXPRESSION ${result}
                         )
endfunction(do_test)

# sample tests from LeetCode
do_test(Decode_Ways "12" "2")
do_test(Decode_Ways "226" "3")
do_test(Decode_Ways "0" "0")
do_test(Decode_Ways "06" "0")

