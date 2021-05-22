# CMakeList.txt : CMake project for BarcodeReader, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("BarcodeReader")

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/BarcodeReader.h
        ${INC_DIR}/BarcodeDecoder.h
        ${INC_DIR}/Vector.h
        ${INC_DIR}/fileParser.h
        ${INC_DIR}/Defines.h
        
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Vector.c
        ${SRC_DIR}/BarcodeReader.c
        ${SRC_DIR}/BarcodeDecoder.c
        ${SRC_DIR}/fileParser.c
    )

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)
