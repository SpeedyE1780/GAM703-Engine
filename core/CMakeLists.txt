project(core)

enable_testing()

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE CORE_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Engine.cpp
src/Input.cpp
src/SceneRenderer.cpp
src/Time.cpp

#HPP
include/core/Config.hpp
include/core/Engine.hpp
include/core/Input.hpp
include/core/SceneRenderer.hpp
include/core/Time.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE graphic)
target_link_libraries(${PROJECT_NAME} PUBLIC gui)
target_link_libraries(${PROJECT_NAME} PUBLIC components)

add_subdirectory(tests)
