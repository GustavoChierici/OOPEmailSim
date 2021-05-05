cmake_minimum_required(VERSION 3.16)
project(OOPEmailSim VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -v")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

option(OOPEmailSimTests "Build tests" ON)

# function(add_module target dir)
#     file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
#     foreach(name ${ARGN})
#         add_custom_target(${name}.pcm
#         COMMAND
#             ${CMAKE_CXX_COMPILER}
#             -std=c++2a
#             -stdlib=libc++
#             -fmodules
#             -c
#             ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/${name}.cpp
#             -Xclang -emit-module-interface
#             -o ${PREBUILT_MODULE_PATH}/${name}.pcm
#         )
#         add_dependencies(${target} ${name}.pcm)
#     endforeach()
# endfunction()

# add_compile_options(-fmodules)
# add_compile_options(-stdlib=libc++)
# add_compile_options(-fbuiltin-module-map)
# add_compile_options(-fimplicit-module-maps)
# add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})


file(GLOB OOP_EMAIL_SIM_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/User.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Inbox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Email.cpp
)

file(GLOB OOP_EMAIL_SIM_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

set(OOP_EMAIL_SIM_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


if(OOPEmailSimTests)
    add_subdirectory(tests)
    target_sources(emailsim_test PUBLIC ${OOP_EMAIL_SIM_SOURCES})
    target_include_directories(emailsim_test PUBLIC ${OOP_EMAIL_SIM_INCLUDE_DIRS})
endif()

add_executable(OOPEmailSim 
    ${OOP_EMAIL_SIM_HEADERS}
    ${OOP_EMAIL_SIM_SOURCES}
    src/main.cpp
)

# add_module(OOPEmailSim ./src User test)

set_target_properties(OOPEmailSim
    PROPERTIES CXX_STANDARD 20
)

target_include_directories(OOPEmailSim PUBLIC ${OOP_EMAIL_SIM_INCLUDE_DIRS})
