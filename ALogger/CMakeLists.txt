set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(LOGGER_SOURCES
    # headers
    ${INC_DIR}/ALogger.h

    #implementation
    ${SRC_DIR}/ALogger.cpp
)

add_library(ALogger ${ALOGGER_BUILD_TYPE} ${LOGGER_SOURCES})
add_library(ALogger::ALogger ALIAS ALogger)

target_include_directories(ALogger PUBLIC ${INC_DIR})

target_link_libraries(ALogger PUBLIC spdlog::spdlog)

## Define preprocessor macros for shared/static library builds.
if (ALOGGER_BUILD_SHARED)
    # For shared library, we define ALOGGER_EXPORTS when building the library,
    # and ALOGGER_COMSUME_DLL for consumers of the library.
    target_compile_definitions(ALogger PRIVATE ALOGGER_EXPORTS)
    # For consumers of the shared library, 
    # they should define ALOGGER_COMSUME_DLL to import the symbols.
    target_compile_definitions(ALogger INTERFACE ALOGGER_COMSUME_DLL)
else()
    target_compile_definitions(ALogger PUBLIC ALOGGER_STATIC)
endif()