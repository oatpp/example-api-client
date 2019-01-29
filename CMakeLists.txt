cmake_minimum_required(VERSION 3.1)

set(project_name example-api-client) ## rename your project here

project(${project_name}-loader)

include(ExternalProject)

#############################################################################
## load all dependencies

ExternalProject_Add(oatpp
        GIT_REPOSITORY "https://github.com/oatpp/oatpp.git"
        GIT_TAG origin/master
        CMAKE_ARGS -DOATPP_BUILD_TESTS=OFF
)

ExternalProject_Add(oatpp-curl
        GIT_REPOSITORY "https://github.com/oatpp/oatpp-curl.git"
        GIT_TAG origin/master
        DEPENDS oatpp
)

ExternalProject_Add(main
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/main
        INSTALL_COMMAND cmake -E echo "SKIP INSTALL"
        DEPENDS oatpp oatpp-curl
)

#############################################################################
## make run command

ExternalProject_Get_Property(main BINARY_DIR)

add_custom_target(run
        COMMAND ${BINARY_DIR}/${project_name}-exe
        DEPENDS main
        WORKING_DIRECTORY ${BINARY_DIR}
)

#############################################################################
## make test command

enable_testing()
add_test(all-tests ${BINARY_DIR}/${project_name}-test)