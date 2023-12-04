project(core)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Engine.cpp

#HPP
include/core/Engine.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PUBLIC gui)

