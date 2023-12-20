project(imgui)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/imgui.cpp
src/imgui_demo.cpp
src/imgui_draw.cpp
src/imgui_tables.cpp
src/imgui_widgets.cpp
src/backends/imgui_impl_glfw.cpp
src/backends/imgui_impl_opengl3.cpp

#HPP
include/imgui/imconfig.h
include/imgui/imgui.h
include/imgui/imgui_internal.h
include/imgui/imstb_rectpack.h
include/imgui/imstb_textedit.h
include/imgui/imstb_truetype.h
include/imgui/backends/imgui_impl_glfw.h
include/imgui/backends/imgui_impl_opengl3.h
include/imgui/backends/imgui_impl_opengl3_loader.h
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
