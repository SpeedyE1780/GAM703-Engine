project(engine-audio)

add_library(${PROJECT_NAME} STATIC)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_AUDIO_DLL ENGINE_AUDIO_EXPORT)

target_sources(${PROJECT_NAME} PRIVATE
#CPP
src/AudioEngine.cpp
src/AudioMixer.cpp
src/AudioSource.cpp

#HPP
include/engine/audio/Config.hpp
include/engine/audio/AudioEngine.hpp
include/engine/audio/AudioEngine.fwd.hpp
include/engine/audio/AudioMixer.hpp
include/engine/audio/AudioMixer.fwd.hpp
include/engine/audio/AudioSource.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC irrKlang)

target_link_libraries(${PROJECT_NAME} PRIVATE engine-utility)

add_subdirectory(tests)
