project(gui)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE GUI_EXPORT)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_sources(${PROJECT_NAME}
#CPP
PRIVATE src/Window.cpp
#HPP
include/gui/Config.hpp
include/gui/Window.hpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PUBLIC graphic)
target_link_libraries(${PROJECT_NAME} PUBLIC components)
