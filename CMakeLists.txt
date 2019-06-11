# CMakeList.txt : CMake project for TheRayTracingChallenge, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

# Add source to this project's executable.
add_executable (TheRayTracerChallenge "TheRayTracerChallenge.cpp" "TheRayTracerChallenge.h" "tuples.cpp" "colors.cpp")

# TODO: Add tests and install targets if needed.
