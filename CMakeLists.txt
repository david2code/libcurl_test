cmake_minimum_required(VERSION 3.10)
project(curl_test)


find_package(PkgConfig REQUIRED)
pkg_search_module(SPDLOG REQUEIRED spdlog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -std=c++17 ${CMAKE_CXX_FLAGS}")
#target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC ${SPDLOG_CFLAGS})


aux_source_directory(src SRCS)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries (
    ${PROJECT_NAME}
    ${SPDLOG_LDFLAGS}
    curl
)