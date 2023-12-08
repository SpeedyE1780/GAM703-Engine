project(glad)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PUBLIC GLAD_GLAPI_EXPORT PRIVATE GLAD_GLAPI_EXPORT_BUILD)

target_sources(${PROJECT_NAME} PRIVATE src/glad.c include/glad/glad.h include/KHR/khrplatform.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
