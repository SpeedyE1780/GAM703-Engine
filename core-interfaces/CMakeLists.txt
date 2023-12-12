project(core-interfaces)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} PRIVATE
#HPP
include/core-interfaces/IEngine.hpp
include/core-interfaces/IInput.hpp
include/core-interfaces/IModel.hpp
include/core-interfaces/IRenderer.hpp
include/core-interfaces/IScene.hpp
include/core-interfaces/ISceneRenderer.hpp
include/core-interfaces/IResourceManager.hpp
include/core-interfaces/IShader.hpp
include/core-interfaces/ITexture.hpp
include/core-interfaces/ITime.hpp
include/core-interfaces/ITransform.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} INTERFACE glm)
