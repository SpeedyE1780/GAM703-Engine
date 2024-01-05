project(engine-graphic)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_GRAPHIC_DLL ENGINE_GRAPHIC_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Mesh.cpp
src/Model.cpp
src/ModelLoader.cpp
src/Texture.cpp

#HPP
include/engine/graphic/Config.hpp
include/engine/graphic/Mesh.hpp
include/engine/graphic/Model.hpp
include/engine/graphic/ModelLoader.hpp
include/engine/graphic/Texture.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-core-interfaces)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE assimp)
target_link_libraries(${PROJECT_NAME} PRIVATE stb)
