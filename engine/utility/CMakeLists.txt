project(engine-utility)

enable_testing()

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_UTILITY_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/File.cpp
src/Math.cpp

#HPP
include/engine/utility/Config.hpp
include/engine/utility/File.hpp
include/engine/utility/Math.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)

add_subdirectory(tests)
