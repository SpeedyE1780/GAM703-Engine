project(core-interfaces)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE CORE_INTERFACES_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/ICamera.cpp
src/IComponent.cpp
src/IRenderer.cpp
src/ITransform.cpp

#HPP
include/core-interfaces/Config.hpp
include/core-interfaces/ICamera.hpp
include/core-interfaces/IComponent.hpp
include/core-interfaces/IEngine.hpp
include/core-interfaces/IEngine.fwd.hpp
include/core-interfaces/IInput.hpp
include/core-interfaces/IModel.hpp
include/core-interfaces/IRenderer.hpp
include/core-interfaces/IScene.hpp
include/core-interfaces/IScene.fwd.hpp
include/core-interfaces/ISceneRenderer.hpp
include/core-interfaces/IResourceManager.hpp
include/core-interfaces/IShader.hpp
include/core-interfaces/ITexture.hpp
include/core-interfaces/ITime.hpp
include/core-interfaces/ITransform.hpp
include/core-interfaces/ITransform.fwd.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)
