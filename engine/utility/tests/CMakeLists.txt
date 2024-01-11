project(utility_test)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/FileTests.cpp src/main.cpp src/MathTests.cpp src/ObjectReferenceTest.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)

set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>)

add_test(test_all ${PROJECT_NAME})

add_custom_target(copy-tests-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    ${PROJECT_SOURCE_DIR}/ReadTest.txt
    ${COPY_DIRECTORY_PATH}/ReadTest.txt
    )

add_dependencies(${PROJECT_NAME} copy-tests-files)
