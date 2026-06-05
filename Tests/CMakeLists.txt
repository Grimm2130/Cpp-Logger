set(EXE_TESTS "LoggerTests")
add_executable(${EXE_TESTS} TestRunner.cpp)
target_link_libraries(${EXE_TESTS} PUBLIC ${LIB_SIMPLE_LOGGER} )