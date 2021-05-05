cmake_minimum_required(VERSION 3.14)

################################
# Unit Tests
################################
add_executable(emailsim_test tests.cpp tests-main.cpp catch.hpp)

set_target_properties(emailsim_test PROPERTIES
	CXX_STANDARD 20
)

add_test(NAME emailsim_test
		COMMAND emailsim_test)