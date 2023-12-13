project(utility_test)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/FileTests.cpp src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)

add_test(test_all ${PROJECT_NAME})

configure_file(${PROJECT_SOURCE_DIR}/ReadTest.txt ${CMAKE_BINARY_DIR}/ReadTest.txt)
