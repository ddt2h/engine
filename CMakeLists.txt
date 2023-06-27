cmake_minimum_required(VERSION 3.22)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif ()

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

add_compile_definitions(WIN32_LEAN_AND_MEAN)
add_compile_definitions(UNICODE)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

conan_cmake_run(CONANFILE conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BASIC_SETUP
        BUILD missing)

add_subdirectory(module)