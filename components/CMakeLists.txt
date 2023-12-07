project(components)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE COMPONENTS_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Camera.cpp

#HPP
include/components/Camera.hpp
include/components/Config.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)

