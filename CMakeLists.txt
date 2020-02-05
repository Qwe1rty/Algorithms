cmake_minimum_required(VERSION 3.8)
project(CLion)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE src_files
    "*.h"
    "*.cpp"
    "*.sql"
)

add_executable(algorithms ${src_files})


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