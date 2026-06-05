add_library(${LIB_SIMPLE_LOGGER} STATIC SimpleLogItem.cpp SimpleLogger.cpp )
target_link_libraries(${LIB_SIMPLE_LOGGER} PUBLIC FileSystemUtils_File)
