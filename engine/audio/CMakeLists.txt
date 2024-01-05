project(engine-audio)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_AUDIO_DLL ENGINE_AUDIO_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/AudioEngine.cpp

#HPP
include/engine/audio/Config.hpp
include/engine/audio/AudioEngine.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC irrKlang)
