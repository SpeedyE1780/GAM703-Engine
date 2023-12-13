project(engine-core-interfaces)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_CORE_INTERFACES_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/ICamera.cpp
src/IComponent.cpp
src/IRenderer.cpp
src/ITransform.cpp

#HPP
include/engine/core-interfaces/Config.hpp
include/engine/core-interfaces/ICamera.hpp
include/engine/core-interfaces/IComponent.hpp
include/engine/core-interfaces/IEngine.hpp
include/engine/core-interfaces/IEngine.fwd.hpp
include/engine/core-interfaces/IInput.hpp
include/engine/core-interfaces/IModel.hpp
include/engine/core-interfaces/IRenderer.hpp
include/engine/core-interfaces/IScene.hpp
include/engine/core-interfaces/IScene.fwd.hpp
include/engine/core-interfaces/ISceneRenderer.hpp
include/engine/core-interfaces/IResourceManager.hpp
include/engine/core-interfaces/IShader.hpp
include/engine/core-interfaces/ITexture.hpp
include/engine/core-interfaces/ITime.hpp
include/engine/core-interfaces/ITransform.hpp
include/engine/core-interfaces/ITransform.fwd.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)
