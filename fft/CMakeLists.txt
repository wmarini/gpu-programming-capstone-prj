# CUDA
include_directories("${CMAKE_SOURCE_DIR}/include/fft")
include_directories("${CMAKE_SOURCE_DIR}/include/Common")
message(STATUS "Platform in use: ${CMAKE_SOURCE_DIR}")
add_library(fft STATIC
    "fft.cu"
    "common.cu"
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 11)
    target_compile_features(fft PUBLIC cxx_std_17)
else()
    target_compile_features(fft PUBLIC cxx_std_14)
endif()

target_link_libraries(fft
    PRIVATE
        cuda
        npps
        nppisu_static
        nppif_static
        nppc_static
        culibos
        pthread
        freeimage
)
set_property(TARGET ${target_name} 
        PROPERTY CUDA_SEPARABLE_COMPILATION ON)