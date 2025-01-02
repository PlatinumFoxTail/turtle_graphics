# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Turtle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Turtle_autogen.dir/ParseCache.txt"
  "Turtle_autogen"
  )
endif()
