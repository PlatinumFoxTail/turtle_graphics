# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TurtleTests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TurtleTests_autogen.dir/ParseCache.txt"
  "CMakeFiles/Turtle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Turtle_autogen.dir/ParseCache.txt"
  "TurtleTests_autogen"
  "Turtle_autogen"
  )
endif()
