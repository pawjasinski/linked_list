set(LIB_NAME LINKED_LIST)

project(${LIB_NAME})

aux_source_directory(src SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC include)
message(STATUS "${SRC_FILES}")

target_compile_options(${LIB_NAME} PRIVATE "${CMAKE_CXX_FLAGS}" "-Wall" "-Wno-comment" "-Weffc++" )