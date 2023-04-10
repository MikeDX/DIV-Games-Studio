# Raspberry Pi Toolchain
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm)

# specify the cross compiler
SET(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)
SET(CMAKE_FIND_ROOT_PATH /usr/arm-linux-gnueabihf)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target directories only
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
