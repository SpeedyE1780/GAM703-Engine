project(engine-core)

enable_testing()

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_CORE_DLL ENGINE_CORE_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Engine.cpp
src/Input.cpp
src/ResourceManager.cpp
src/Scene.cpp
src/SceneRenderer.cpp
src/Time.cpp

#HPP
include/engine/core/Config.hpp
include/engine/core/Engine.hpp
include/engine/core/Engine.fwd.hpp
include/engine/core/Input.hpp
include/engine/core/ResourceManager.hpp
include/engine/core/ResourceManager.fwd.hpp
include/engine/core/Scene.hpp
include/engine/core/Scene.fwd.hpp
include/engine/core/SceneRenderer.hpp
include/engine/core/Time.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-audio)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-components)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-graphic)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-gui)

add_subdirectory(tests)
