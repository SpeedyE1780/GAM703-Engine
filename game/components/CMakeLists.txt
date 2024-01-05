project(game-components)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE GAME_COMPONENTS_DLL GAME_COMPONENTS_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/MovementController.cpp
src/Wonder.cpp

#HPP
include/game/components/Config.hpp
include/game/components/MovementController.hpp
include/game/components/Wonder.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC engine-core)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

