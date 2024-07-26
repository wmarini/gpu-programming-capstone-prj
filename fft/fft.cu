#include "fft.h"
#include "fftexceptions.h"
#include "UtilNPP/Exceptions.h"
#include "UtilNPP/ImageIO.h"
#include "UtilNPP/ImagesCPU.h"
#include "UtilNPP/ImagesNPP.h"
#include <npp.h>
#include "helper_cuda.h"
#include "helper_string.h"
#include <cuda_runtime.h>
#include <filesystem>
#include <iostream>

namespace fft {

void ProcessFFT(const FFTConfig& config)
{
    try {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    } catch (const npp::Exception& e) {
        throw fft::FFTException(e.toString());
    }
}

}