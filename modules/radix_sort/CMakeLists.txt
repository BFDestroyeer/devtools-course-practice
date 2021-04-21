# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Include directory with public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add all submodules
# add_subdirectory(src)
add_subdirectory(test)
# add_subdirectory(application)

#############################################
##### Project
#############################################

set(target ${LIBRARY})

file(GLOB hdrs "include/*.h")
set_source_files_properties(${hdrs} PROPERTIES
        LABELS "${MODULE};Library")

add_library(${target} STATIC ${hdrs})
set_target_properties(${target} PROPERTIES
        OUTPUT_NAME ${MODULE}
        LABELS "${MODULE};Library")

if (UNIX)
    target_link_libraries(${target} ${CMAKE_THREAD_LIBS_INIT})
endif (UNIX)
target_link_libraries(${target} ${LIBRARY_DEPS})

set(LIBRARY_DEPS "${LIBRARY_DEPS};${target}" PARENT_SCOPE)


#############################################
##### Testing
#############################################

# include("CTestTests.txt")
