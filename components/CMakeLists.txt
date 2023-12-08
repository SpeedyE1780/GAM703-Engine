project(components)

add_library(${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE COMPONENTS_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/Camera.cpp
src/IComponent.cpp
src/Transform.cpp

#HPP
include/components/Camera.hpp
include/components/Config.hpp
include/components/IComponent.hpp
include/components/Transform.hpp
include/components/Transform.fwd.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC glm)

add_subdirectory(tests)
