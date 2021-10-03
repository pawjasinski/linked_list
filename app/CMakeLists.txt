set(LIB_NAME LINKED_LIST)

project(${LIB_NAME})

aux_source_directory(src SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC include)
message(STATUS "${SRC_FILES}")

option(BUILD_MAIN "Builds the test app executable" ON)
if(BUILD_MAIN)
set(APP_NAME TEST_APP)
project(${APP_NAME})
add_executable(${APP_NAME} ${SRC_FILES})
target_include_directories(${APP_NAME} PRIVATE include)
endif()