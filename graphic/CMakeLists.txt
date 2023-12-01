project(graphic)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Shader.cpp 
src/Mesh.cpp

#HPP
include/graphic/Shader.hpp
include/graphic/Shader.fwd.hpp
include/graphic/Mesh.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE utility)
