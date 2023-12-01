cmake_minimum_required(VERSION 3.26)

project(GAM703-Engine)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

add_subdirectory(3rd-party/glfw)
add_subdirectory(3rd-party/glad)
add_subdirectory(3rd-party/glm)
add_subdirectory(3rd-party/gtest)

add_subdirectory(gui)
add_subdirectory(graphic)
add_subdirectory(utility)

target_link_libraries(${PROJECT_NAME} PRIVATE gui)

add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources/
    ${CMAKE_BINARY_DIR}/resources/
    )

add_dependencies(${PROJECT_NAME} copy-files)
