cmake_minimum_required(VERSION 3.8)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

set(EXCLUDE_DIR "cmake-build-debug")
file(GLOB_RECURSE SOURCE_FILES
    "*.h"
    "*.cpp"
    "*.tpp"
    "*.sql"
)

foreach (TMP_PATH ${SOURCE_FILES})
    string (FIND ${TMP_PATH} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM SOURCE_FILES ${TMP_PATH})
    endif ()
endforeach(TMP_PATH)

add_executable(algorithms ${SOURCE_FILES})


#cmake_minimum_required(VERSION 3.8)
#project(CLion)
#
#set(CMAKE_CXX_STANDARD 14)
#set(sourceDir "${PROJECT_SOURCE_DIR}")
#
#file(GLOB_RECURSE sourceFiles "${sourceDir}/*.c" "${sourceDir}/*.h" "${sourceDir}/*.sql")
#
#FOREACH (sourceFile ${sourceFiles})
#    MESSAGE(STATUS "Process file: ${sourceFile}")
#
#    get_filename_component(dir1 ${sourceFile} PATH)
#    get_filename_component(dir1 ${dir1} NAME)
#
#    get_filename_component(dir2 "${sourceFile}/../../" ABSOLUTE)
#    get_filename_component(dir2 ${dir2} NAME)
#
#    MESSAGE(STATUS "New target: ${dir2}_${dir1}")
#    add_executable("${dir2}_${dir1}" ${sourceFile})
#endforeach (sourceFile)