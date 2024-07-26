#ifndef FFT_H
#define FFT_H

#include "common.h"
#include <string>
#include <vector>

namespace fft {

struct FFTConfig {
    std::size_t kernel_size{5};
};

void ProcessFFT(
        const FFTConfig& config);


} // namespace fft

#endif // FFT_H