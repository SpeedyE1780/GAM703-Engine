project(components_test)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/main.cpp
src/TransformTests.cpp
src/ComponentsTests.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE components)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)

add_test(test_all ${PROJECT_NAME})
