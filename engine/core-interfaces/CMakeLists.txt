project(engine-core-interfaces)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_CORE_INTERFACES_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Behavior.cpp
src/Camera.cpp
src/Component.cpp
src/IEngine.cpp
src/IRenderer.cpp
src/Light.cpp
src/Material.cpp
src/Scene.cpp
src/SceneRenderer.cpp
src/Shader.cpp
src/Texture.cpp
src/Time.cpp
src/Transform.cpp

#HPP
include/engine/core-interfaces/Behavior.hpp
include/engine/core-interfaces/Camera.hpp
include/engine/core-interfaces/Component.hpp
include/engine/core-interfaces/Config.hpp
include/engine/core-interfaces/IEngine.hpp
include/engine/core-interfaces/IEngine.fwd.hpp
include/engine/core-interfaces/IInput.hpp
include/engine/core-interfaces/IModel.hpp
include/engine/core-interfaces/IRenderer.hpp
include/engine/core-interfaces/IResourceManager.hpp
include/engine/core-interfaces/Light.hpp
include/engine/core-interfaces/Material.hpp
include/engine/core-interfaces/Scene.hpp
include/engine/core-interfaces/Scene.fwd.hpp
include/engine/core-interfaces/SceneRenderer.hpp
include/engine/core-interfaces/Shader.hpp
include/engine/core-interfaces/Texture.hpp
include/engine/core-interfaces/Time.hpp
include/engine/core-interfaces/Transform.hpp
include/engine/core-interfaces/Transform.fwd.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
