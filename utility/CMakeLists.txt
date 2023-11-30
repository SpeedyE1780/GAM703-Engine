project(utility)

enable_testing()

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/File.cpp include/utility/File.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)
