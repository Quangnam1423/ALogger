#pragma once

#define ALOGGER_VERSION "0.1.0"
#define ALOGGER_VERSION_MAJOR 0
#define ALOGGER_VERSION_MINOR 1
#define ALOGGER_VERSION_PATCH 0

// For now, module just supports Windows Patform.
#if defined(_WIN32) || defined(_WIN64)
    #define ALOGGER_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define ALOGGER_PLATFORM_LINUX
#elif defined(__APPLE__)
    #define ALOGGER_PLATFORM_MACOS
#elif defined(__unix__)
    #define ALOGGER_PLATFORM_UNIX
#elif defined(__ANDROID__)
    #define ALOGGER_PLATFORM_ANDROID
#else
    #error "Unsupported platform"
#endif


// Define ALOGGER_DEBUG if either NDEBUG or _DEBUG is defined
#if defined(NDEBUG) || defined(_DEBUG)
    #define ALOGGER_DEBUG
#endif

// Define ALOGGER_API for exporting symbols when building the library
#if defined(ALOGGER_STATIC)
    #define ALOGGER_API
#else 
    #if defined(_WIN32) || defined(_WIN64)
        #if defined(ALOGGER_BUILD)
            #define ALOGGER_API __declspec(dllexport)
        #else
            #define ALOGGER_API __declspec(dllimport)
        #endif

        #if defined(_MSC_VER)
            #pragma warning(disable : 4251)
            #pragma warning(disable : 4275)
        #endif
    #else
        #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
            #define ALOGGER_API __attribute__((visibility("default")))
        #else
            #define ALOGGER_API
        #endif
    #endif
#endif

