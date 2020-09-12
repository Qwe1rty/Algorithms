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

