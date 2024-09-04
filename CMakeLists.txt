cmake_minimum_required(VERSION 3.30)
add_definitions(-DUNICODE -D_UNICODE)

project(doublyCircularLinkedList) # executable name
set(CMAKE_C_STANDARD 23)

set(FullOutputPath "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${FullOutputPath}/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${FullOutputPath})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${FullOutputPath})

# Define the library
add_library(LinkedList_Lib ${CMAKE_SOURCE_DIR}/library/linkedList.c)

# Include directories for the library
target_include_directories(LinkedList_Lib PUBLIC ${CMAKE_SOURCE_DIR}/library)

# Define the executable
add_executable(${PROJECT_NAME} main.c)

# Link the library to the executable
target_link_libraries(${PROJECT_NAME} LinkedList_Lib)