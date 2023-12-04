project(components)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Camera.cpp

#HPP
include/components/Camera.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

