function(add_soloud_sdk)
set(SOLOUD_TARGET soloud)


message(STATUS "Adding ${SOLOUD_TARGET} SDK....")

set(SOLOUD_SDK_DIR "${CMAKE_SOURCE_DIR}/_dependencies/SOLOUD")
set(SOLOUD_SRC_DIR "${SOLOUD_SDK_DIR}/src")
set(SOLOUD_INC_DIR "${SOLOUD_SDK_DIR}/include")

set (SOLOUD_HEADERS
	${SOLOUD_INC_DIR}/soloud.h
	${SOLOUD_INC_DIR}/soloud_audiosource.h
	${SOLOUD_INC_DIR}/soloud_ay.h
	${SOLOUD_INC_DIR}/soloud_bassboostfilter.h
	${SOLOUD_INC_DIR}/soloud_biquadresonantfilter.h
	${SOLOUD_INC_DIR}/soloud_bus.h
	${SOLOUD_INC_DIR}/soloud_dcremovalfilter.h
	${SOLOUD_INC_DIR}/soloud_echofilter.h
	${SOLOUD_INC_DIR}/soloud_error.h
	${SOLOUD_INC_DIR}/soloud_fader.h
	${SOLOUD_INC_DIR}/soloud_fft.h
	${SOLOUD_INC_DIR}/soloud_fftfilter.h
	${SOLOUD_INC_DIR}/soloud_file.h
	${SOLOUD_INC_DIR}/soloud_file_hack_off.h
	${SOLOUD_INC_DIR}/soloud_file_hack_on.h
	${SOLOUD_INC_DIR}/soloud_filter.h
	${SOLOUD_INC_DIR}/soloud_flangerfilter.h
	${SOLOUD_INC_DIR}/soloud_freeverbfilter.h
	${SOLOUD_INC_DIR}/soloud_internal.h
	${SOLOUD_INC_DIR}/soloud_lofifilter.h
	${SOLOUD_INC_DIR}/soloud_misc.h
	${SOLOUD_INC_DIR}/soloud_monotone.h
	${SOLOUD_INC_DIR}/soloud_noise.h
	${SOLOUD_INC_DIR}/soloud_openmpt.h
	${SOLOUD_INC_DIR}/soloud_queue.h
	${SOLOUD_INC_DIR}/soloud_robotizefilter.h
	${SOLOUD_INC_DIR}/soloud_sfxr.h
	${SOLOUD_INC_DIR}/soloud_speech.h
	${SOLOUD_INC_DIR}/soloud_tedsid.h
	${SOLOUD_INC_DIR}/soloud_thread.h
	${SOLOUD_INC_DIR}/soloud_vic.h
	${SOLOUD_INC_DIR}/soloud_vizsn.h
	${SOLOUD_INC_DIR}/soloud_wav.h
	${SOLOUD_INC_DIR}/soloud_waveshaperfilter.h
	${SOLOUD_INC_DIR}/soloud_wavstream.h
)

set(SOLOUD_SRC_CORE_DIR ${SOLOUD_SRC_DIR}/core)
set (SOLOUD_CORE_SOURCES
	${SOLOUD_SRC_CORE_DIR}/soloud.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_audiosource.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_bus.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_3d.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_basicops.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_faderops.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_filterops.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_getters.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_setters.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_voicegroup.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_core_voiceops.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_fader.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_fft.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_fft_lut.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_file.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_filter.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_misc.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_queue.cpp
	${SOLOUD_SRC_CORE_DIR}/soloud_thread.cpp
)

set(SOLOUD_SRC_AUDIOSOURCE_DIR ${SOLOUD_SRC_DIR}/audiosource)
set (AUDIOSOURCES_SOURCES
	# ay
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/chipplayer.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/chipplayer.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/readme.txt
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndbuffer.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndbuffer.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndchip.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndchip.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndrender.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/sndrender.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/ay/soloud_ay.cpp

	# monotone
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/monotone/soloud_monotone.cpp

	# noise
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/noise/soloud_noise.cpp

	# openmpt
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/openmpt/soloud_openmpt.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/openmpt/soloud_openmpt_dll.c

	# sfxr
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/sfxr/soloud_sfxr.cpp

	# speech
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/Elements.def
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/darray.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/darray.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/klatt.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/klatt.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/resonator.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/resonator.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/soloud_speech.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/tts.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/speech/tts.h

	# tedsid
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/tedsid/sid.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/tedsid/sid.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/tedsid/soloud_tedsid.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/tedsid/ted.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/tedsid/ted.h

	# vic
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/vic/soloud_vic.cpp

	# vizsn
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/vizsn/soloud_vizsn.cpp

	# wav
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/dr_flac.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/dr_impl.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/dr_mp3.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/dr_wav.h
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/soloud_wav.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/soloud_wavstream.cpp
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/stb_vorbis.c
	${SOLOUD_SRC_AUDIOSOURCE_DIR}/wav/stb_vorbis.h
)

set (SOLOUD_SRC_BACKENDS_DIR ${SOLOUD_SRC_DIR}/backend)          
add_definitions (-DWITH_ALSA)                
                                       
set (BACKENDS_SOURCES              
    ${BACKENDS_SOURCES} 
    ${BACKENDS_PATH}/alsa/soloud_alsa.cpp
)                       

find_library (ALSA_LIBRARY asound)
set (LINK_LIBRARIES
    ${LINK_LIBRARIES}
    ${ALSA_LIBRARY}
)

set (SOLOUD_SRC_FILTERS_DIR ${SOLOUD_SRC_DIR}/filter)
set (FILTERS_SOURCES
	${SOLOUD_SRC_FILTERS_DIR}/soloud_bassboostfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_biquadresonantfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_dcremovalfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_echofilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_fftfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_flangerfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_freeverbfilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_lofifilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_robotizefilter.cpp
	${SOLOUD_SRC_FILTERS_DIR}/soloud_waveshaperfilter.cpp
)

source_group ("Includes"		FILES ${SOLOUD_HEADERS})
source_group ("Core"			FILES ${SOLOUD_SRC_CORE_DIR})
source_group ("Audiosources"	FILES ${SOLOUD_SRC_AUDIOSOURCE_DIR})
source_group ("Backends"		FILES ${SOLOUD_SRC_BACKENDS_DIR})
source_group ("Filters"			FILES ${SOLOUD_SRC_FILTERS_DIR})

set (SOLOUD_SOURCES
	${SOLOUD_SRC_CORE_DIR}
	${SOLOUD_SRC_AUDIOSOURCE_DIR}
	${SOLOUD_SRC_BACKENDS_DIR}
	${SOLOUD_SRC_FILTERS_DIR}
)

add_library(${SOLOUD_TARGET} STATIC
	${SOLOUD_SOURCES}
)

set_target_properties(${SOLOUD_TARGET} PROPERTIES
	LINKER_LANGUAGE C
)

target_link_libraries (${SOLOUD_TARGET} ${LINK_LIBRARIES})

endfunction()