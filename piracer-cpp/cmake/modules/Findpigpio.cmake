################################################################################

### Find the pigpio shared libraries.

################################################################################



# Find the path to the pigpio includes.

#/home/seame/Head-Unit-Team1/yocto/build/tmp/work/cortexa72-poky-linux/pigpio/1.0-r0/image/usr/include

find_path(pigpio_INCLUDE_DIR 

	NAMES pigpio.h pigpiod_if.h pigpiod_if2.h

	HINTS ${CMAKE_SYSROOT}/usr/include)

	

# Find the pigpio libraries.

find_library(pigpio_LIBRARY 

	NAMES libpigpio.so

	HINTS ${CMAKE_SYSROOT}/usr/lib)

find_library(pigpiod_if_LIBRARY 

	NAMES libpigpiod_if.so

	HINTS ${CMAKE_SYSROOT}/usr/lib)

find_library(pigpiod_if2_LIBRARY 

	NAMES libpigpiod_if2.so

	HINTS ${CMAKE_SYSROOT}/usr/lib)

    

# Set the pigpio variables to plural form to make them accessible for 

# the paramount cmake modules.

set(pigpio_INCLUDE_DIRS ${pigpio_INCLUDE_DIR})

set(pigpio_INCLUDES     ${pigpio_INCLUDE_DIR})



# Handle REQUIRED, QUIET, and version arguments 

# and set the <packagename>_FOUND variable.

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(pigpio 

    DEFAULT_MSG 

    pigpio_INCLUDE_DIR pigpio_LIBRARY pigpiod_if_LIBRARY pigpiod_if2_LIBRARY)