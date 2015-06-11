# FindIrrlicht
# ------------
#
# Find Irrlicht library, this modules defines:
#
#  Irrlicht_LIBRARY, the name of the library to link against
#  Irrlicht_FOUND, if false, do not try to link to Irrlicht
#  Irrlicht_INCLUDE_DIR, where to find SDL.h

find_path(
	Irrlicht_INCLUDE_DIR
	NAMES irrlicht.h
	PATH_SUFFIXES include/irrlicht
)

find_library(
	Irrlicht_LIBRARY
	NAMES Irrlicht libIrrlicht
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	Irrlicht
	FOUND_VAR Irrlicht_FOUND
	REQUIRED_VARS Irrlicht_LIBRARY Irrlicht_INCLUDE_DIR
)

set(Irrlicht_LIBRARIES ${Irrlicht_LIBRARY})
set(Irrlicht_INCLUDE_DIRS ${Irrlicht_INCLUDE_DIR})

mark_as_advanced(Irrlicht_INCLUDE_DIR Irrlicht_LIBRARY)
