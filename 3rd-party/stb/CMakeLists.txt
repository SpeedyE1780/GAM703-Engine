project(stb)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE include/stb/stb_image.h src/stb_image.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
