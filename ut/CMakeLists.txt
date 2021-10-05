set(APP_NAME GTEST)

project(${APP_NAME})

set(LIB_GOOGLE_TEST lib)
set(INC_GOOGLE_TEST include)

set(GOOGLE_TEST GoogleTest)
add_library(${GOOGLE_TEST} SHARED IMPORTED)
set_target_properties(${GOOGLE_TEST} PROPERTIES
    IMPORTED_LOCATION ${LIB_GOOGLE_TEST}
    INTERFACE_COMPILE_DEFINITIONS ${INC_GOOGLE_TEST}
)

add_subdirectory(linked_list_ut)