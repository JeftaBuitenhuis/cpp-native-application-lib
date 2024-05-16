cmake_minimum_required(VERSION 3.13)

project(TBA-v0.0.1)


set(CMAKE_CXX_STANDARD 17)

#these will automatically add all of the cpp files to the project!
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/app/src/*.cpp")
file(GLOB_RECURSE MIDDLEWARE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/middleware/src/*.cpp")
IF(WIN32)
    file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")
    list(FILTER PLATFORM_SOURCES EXCLUDE REGEX "linuxMain.cpp$|macMain.cpp$")
ELSEIF(UNIX)
    file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")
    list(FILTER PLATFORM_SOURCES EXCLUDE REGEX "winMain.cpp$|macMain.cpp$")
ELSEIF(APPLE)
    file(GLOB_RECURSE PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*.cpp")
    list(FILTER PLATFORM_SOURCES EXCLUDE REGEX "winMain.cpp$| linuxMain.cpp$")
ENDIF(WIN32)

add_executable(window ${APP_SOURCES} ${MIDDLEWARE_SOURCES} ${PLATFORM_SOURCES})
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/game/include") #add header file
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/middleware/include") #add header file
target_include_directories(window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/platform/include") #add header file
remove_definitions(-DUNICODE) #remove unicode