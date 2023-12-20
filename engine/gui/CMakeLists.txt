project(engine-gui)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_GUI_EXPORT)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_sources(${PROJECT_NAME} PRIVATE 
#CPP
src/Window.cpp
src/Text.cpp

#HPP
include/engine/gui/Config.hpp
include/engine/gui/IGUIElement.hpp
include/engine/gui/Text.hpp
include/engine/gui/Window.hpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
