# Use this command to build the 3DS port of Allegro:
#
#   cmake -DWANT_TESTS=off -DWANT_TOOLS=off -DWANT_LOGG=off -DWANT_ALLEGROGL=off -DCMAKE_TOOLCHAIN_FILE=cmake/Toolchain-3ds.cmake .
#
# or for out of source:
#
#   cmake -DWANT_TESTS=off -DWANT_TOOLS=off -DWANT_LOGG=off -DWANT_ALLEGROGL=off -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain-3ds.cmake ..
#
# You will need at least CMake 2.6.0.

# The name of the target operating system.
set(CMAKE_SYSTEM_NAME Generic)

# setup helper variables
set(DKPRO "$ENV{DEVKITPRO}")
set(DKARM "$ENV{DEVKITARM}")

# check environment
if(DKPRO STREQUAL "" OR DKARM STREQUAL "")
    message(FATAL_ERROR "You need to setup DevkitARM properly by exporting the required "
        "environment variables DEVKITPRO and DEVKITARM!")
endif()

set(CMAKE_SYSTEM_INCLUDE_PATH "${DKPRO}/libctru/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${DKPRO}/libctru/lib")
set(CMAKE_SYSTEM_PROGRAM_PATH "${DKARM}/bin")

# Which compilers to use for C and C++.
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)

# Adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment.
set(CMAKE_FIND_ROOT_PATH ${DKPRO}/portlibs/arm)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(3DS 1)
