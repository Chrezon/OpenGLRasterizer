cmake_minimum_required(VERSION 3.17)
project(OpenGLPlayground)

set(CMAKE_CXX_STANDARD 14)

# TODO: How to make this add all the .c and .cpp files? wildcards?
add_executable(OpenGLPlayground
        src/main.cpp
        libs/glad.c src/GLShader.h src/GLShader.cpp)

# MODIFY THIS FOR WHAT MAKES SENSE!
include_directories(libs/include)

if(APPLE)
    target_link_libraries(OpenGLPlayground PRIVATE
            "-framework Foundation"
            "-framework IOKit"
            "-framework CoreFoundation"
            "-framework AppKit"
            "-framework CoreGraphics"
            ${CMAKE_SOURCE_DIR}/libs/lib-x86_64/libglfw3.a
            OpenGL::GL
            )
endif()

find_package(OpenGL REQUIRED)



