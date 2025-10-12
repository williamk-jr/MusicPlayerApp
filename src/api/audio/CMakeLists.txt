add_library(libaudio STATIC
	"audio_stream.cpp"
	"audio_chunk.cpp"
	"stream/port_audio_stream.cpp" 
	"backends/port_audio_backend.cpp" 
	"resampler/sr_audio_resampler.cpp" 
	"reader/sndlib_audio_reader.cpp"
)

find_package(PortAudio)
find_package(LibSndFile)
find_package(LibSamplerate)

target_include_directories(libaudio
  PUBLIC ${CMAKE_SOURCE_DIR}/src/api/audio

  PRIVATE ${PORTAUDIO_INCLUDE_DIR}
  PRIVATE ${LIBSAMPLERATE_INCLUDE_DIR}
  PRIVATE ${LIBSNDFILE_INCLUDE_DIR}
)

target_link_directories(libaudio 
  PRIVATE ${PORTAUDIO_LIBRARIES}
  PRIVATE ${LIBSAMPLERATE_LIBRARIES}
  PRIVATE ${LIBSNDFILE_LIBRARIES}
)

target_link_libraries(libaudio 
  PRIVATE portaudio
  PRIVATE sndfile 
  PRIVATE samplerate
)