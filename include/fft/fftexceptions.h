#ifndef FFT_EXCEPTION_H
#define FFT_EXCEPTION_H

#include <exception>
#include <string>

namespace fft {

class FFTException : public std::exception {
public:
    FFTException(const std::string message) 
    : message_(message) {}
    virtual ~FFTException() = default;

    virtual const char* what() const noexcept override { 
        return message_.c_str(); 
    }

private:
    std::string message_;
};

} // namespace mosaic

#endif // FFT_EXCEPTION_H
