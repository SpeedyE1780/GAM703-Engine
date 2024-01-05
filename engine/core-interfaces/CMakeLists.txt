project(engine-core-interfaces)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_CORE_INTERFACES_DLL ENGINE_CORE_INTERFACES_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/IEngine.cpp
src/Material.cpp
src/Scene.cpp
src/SceneRenderer.cpp
src/Shader.cpp
src/Texture.cpp
src/Time.cpp

#HPP
include/engine/core-interfaces/Config.hpp
include/engine/core-interfaces/IEngine.hpp
include/engine/core-interfaces/IEngine.fwd.hpp
include/engine/core-interfaces/IInput.hpp
include/engine/core-interfaces/IModel.hpp
include/engine/core-interfaces/IResourceManager.hpp
include/engine/core-interfaces/Material.hpp
include/engine/core-interfaces/Scene.hpp
include/engine/core-interfaces/Scene.fwd.hpp
include/engine/core-interfaces/SceneRenderer.hpp
include/engine/core-interfaces/Shader.hpp
include/engine/core-interfaces/Texture.hpp
include/engine/core-interfaces/Time.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-components)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
