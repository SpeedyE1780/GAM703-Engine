cmake_minimum_required(VERSION 3.26)

project(GAM703-Engine)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

find_package(Git)

execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(3rd-party/assimp)
add_subdirectory(3rd-party/glfw)
add_subdirectory(3rd-party/glad)
add_subdirectory(3rd-party/glm)
add_subdirectory(3rd-party/gtest)
add_subdirectory(3rd-party/stb)

add_subdirectory(core)
add_subdirectory(core-interfaces)
add_subdirectory(components)
add_subdirectory(graphic)
add_subdirectory(gui)
add_subdirectory(utility)

target_link_libraries(${PROJECT_NAME} PRIVATE core)

add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources/
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/
    )

add_dependencies(${PROJECT_NAME} copy-files)
