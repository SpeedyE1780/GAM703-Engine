project(audio_test)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/AudioTests.cpp src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-audio)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest)

add_test(test_all ${PROJECT_NAME})
