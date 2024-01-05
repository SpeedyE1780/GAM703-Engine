project(engine-core)

enable_testing()

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_CORE_DLL ENGINE_CORE_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Engine.cpp
src/Input.cpp
src/ResourceManager.cpp

#HPP
include/engine/core/Config.hpp
include/engine/core/Engine.hpp
include/engine/core/Engine.fwd.hpp
include/engine/core/Input.hpp
include/engine/core/ResourceManager.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-core-interfaces)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-graphic)
target_link_libraries(${PROJECT_NAME} PUBLIC engine-gui)


add_subdirectory(tests)
