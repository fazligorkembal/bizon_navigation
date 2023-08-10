# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_faraday_parking_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED faraday_parking_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(faraday_parking_FOUND FALSE)
  elseif(NOT faraday_parking_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(faraday_parking_FOUND FALSE)
  endif()
  return()
endif()
set(_faraday_parking_CONFIG_INCLUDED TRUE)

# output package information
if(NOT faraday_parking_FIND_QUIETLY)
  message(STATUS "Found faraday_parking: 0.0.0 (${faraday_parking_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'faraday_parking' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${faraday_parking_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(faraday_parking_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${faraday_parking_DIR}/${_extra}")
endforeach()
