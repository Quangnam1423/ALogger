set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(TEST_SOURCES
    # headers

    #implementation
    main.cpp
)

add_executable(TestModule ${TEST_SOURCES})

target_link_libraries(TestModule PRIVATE ALogger::ALogger)