#include "appexception.h"
#include "fft/fftexceptions.h"
#include <stdexcept>
#include <iostream>

namespace app {

void handle_exception() noexcept {
    try {
        throw;
    } catch (const fft::FFTException& e) {
        std::cerr << "FFT Exception: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    } catch (...) {
        std::cerr << "Bad luck :( Unknow Exception!\n";
        std::exit(EXIT_FAILURE);
    }
}

} // namespace app
