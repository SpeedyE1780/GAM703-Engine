project(game-components)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE GAME_COMPONENTS_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/MovementController.cpp

#HPP
include/components/Config2.hpp
include/components/MovementController.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC core-interfaces)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

