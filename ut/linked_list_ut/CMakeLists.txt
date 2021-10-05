set(APP_NAME LINKED_LIST_UT)

project(${APP_NAME})

aux_source_directory(src SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})
target_link_libraries(${APP_NAME} ${GOOGLE_TEST})
target_include_directories(${APP_NAME} PRIVATE include)
target_compile_options(${APP_NAME} PRIVATE "${CMAKE_CXX_FLAGS}" "-Wall" "-Wno-comment" "-Weffc++" )

