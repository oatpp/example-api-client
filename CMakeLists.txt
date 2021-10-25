cmake_minimum_required(VERSION 3.1)

set(project_name example-api-client) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        src/AsyncExample.hpp
        src/DemoApiClient.hpp
        src/DemoApiModels.hpp
        src/SimpleExample.hpp
        src/AsyncExample.cpp)

## link libs

find_package(oatpp      1.3.0 REQUIRED)
find_package(oatpp-curl 1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-curl
)

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/App.cpp
)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
)
target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

enable_testing()
add_test(project-tests ${project_name}-test)
