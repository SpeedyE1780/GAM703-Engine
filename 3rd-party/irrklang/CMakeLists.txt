project(irrKlang)

find_library(irrKlang-prebuilt irrKlang ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} INTERFACE ${irrKlang-prebuilt})

add_custom_target(copy-irrKlang-dll ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/dll
    ${COPY_DIRECTORY_PATH}/
    )

add_dependencies(${PROJECT_NAME} copy-irrKlang-dll)
