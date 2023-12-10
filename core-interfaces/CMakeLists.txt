project(core-interfaces)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} PRIVATE
#HPP
include/core-interfaces/IEngine.hpp
include/core-interfaces/IInput.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include/)
