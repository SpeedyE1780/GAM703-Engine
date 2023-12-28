project(engine-components)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_COMPONENTS_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Camera.cpp
src/DirectionalLight.cpp
src/PointLight.cpp
src/Renderer.cpp
src/SpotLight.cpp
src/Transform.cpp

#HPP
include/engine/components/Camera.hpp
include/engine/components/Config.hpp
include/engine/components/DirectionalLight.hpp
include/engine/components/PointLight.hpp
include/engine/components/Renderer.hpp
include/engine/components/SpotLight.hpp
include/engine/components/Transform.hpp
include/engine/components/Transform.fwd.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-core-interfaces)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-graphic)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

add_subdirectory(tests)