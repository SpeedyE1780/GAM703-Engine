project(engine-gui)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_GUI_DLL ENGINE_GUI_EXPORT)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_sources(${PROJECT_NAME} PRIVATE 
#CPP
src/Button.cpp
src/Checkbox.cpp
src/ColorPicker.cpp
src/GUIElement.cpp
src/Slider.cpp
src/Text.cpp
src/Window.cpp

#HPP
include/engine/gui/Button.hpp
include/engine/gui/Config.hpp
include/engine/gui/Checkbox.hpp
include/engine/gui/ColorPicker.hpp
include/engine/gui/GUIElement.hpp
include/engine/gui/Slider.hpp
include/engine/gui/Text.hpp
include/engine/gui/Window.hpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)

target_link_libraries(${PROJECT_NAME} PRIVATE glm)
