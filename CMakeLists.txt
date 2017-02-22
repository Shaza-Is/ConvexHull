include (ACGCommon)
include_directories (
  ../../..
  ${CMAKE_CURRENT_SOURCE_DIR}
)
set (targetName ConvexHull)
# collect all header and source files
acg_append_files (headers "*.hh" .)
acg_append_files (sources "*.cpp" .)
acg_add_executable (${targetName} ${headers} ${sources})
target_link_libraries (${targetName}
  OpenMeshCore
  OpenMeshTools
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")