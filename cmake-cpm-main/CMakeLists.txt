cmake_minimum_required(VERSION 3.16)

set(EXEC_NAME testCpm)
set(PROJ_NAME test_cpm)

project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CPM_DOWNLOAD_VERSION 0.32.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
set(CPM_SOURCE_CACHE "${CMAKE_SOURCE_DIR}/3rdParty" CACHE PATH "Directory to download CPM dependencies" FORCE)

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.8.5)

# Alternative use case
CPMAddPackage("gh:catchorg/Catch2@2.13.4")

include_directories(${CMAKE_SOURCE_DIR}/tests)
include_directories(${CMAKE_SOURCE_DIR}/src/leilao)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)

# Checks if tests will to be built
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    message("")
    message(STATUS "The project will build the tests.")
    add_subdirectory(tests)
    message("")
    add_executable(${EXEC_NAME} ${TEST_FILES} ${SRC_FILES})
    add_definitions(-DBUILD_TESTS)
else()
    add_executable(${EXEC_NAME} ${SRC_FILES})
endif(BUILD_TESTS)

if(spdlog_ADDED)
    target_link_libraries(${EXEC_NAME} spdlog)
endif()

if(Catch2_ADDED)
    target_link_libraries(${EXEC_NAME} Catch2)
endif(Catch2_ADDED)

# Assign Main as the startup project of the Solution
set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXEC_NAME})