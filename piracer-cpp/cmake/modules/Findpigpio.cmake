################################################################################
### Find the pigpio shared libraries.
################################################################################

# Find the path to the pigpio includes.
find_path(pigpio_INCLUDE_DIR 
	NAMES pigpio.h pigpiod_if.h pigpiod_if2.h
	PATHS ${CMAKE_SYSROOT}/usr/include
)
	
# Find the pigpio libraries.
find_library(pigpio_LIBRARY 
	NAMES pigpio
	PATHS ${CMAKE_SYSROOT}/usr/lib
)
find_library(pigpiod_if_LIBRARY 
	NAMES pigpiod_if
	PATHS ${CMAKE_SYSROOT}/usr/lib
)
find_library(pigpiod_if2_LIBRARY 
	NAMES pigpiod_if2
	PATHS ${CMAKE_SYSROOT}/usr/lib
)
    
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