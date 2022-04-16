# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("StuntKit_modules")

# Include sub-projects.
add_subdirectory ("skScreen")
add_subdirectory ("skDebug")
add_subdirectory ("skFreeze")

GET_FILENAME_COMPONENT(SGPPATH "[HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Team17SoftwareLTD\\StuntGP;Path]" ABSOLUTE CACHE)
MESSAGE("SGPPATH = ${SGPPATH}")

if(DEFINED SGPPATH)
	install(TARGETS skScreen skDebug skFreeze DESTINATION ${SGPPATH})
endif()