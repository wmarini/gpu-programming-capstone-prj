#include "app.h"
#include <iostream>

namespace {

void Usage()
{
    std::cout << "Usage: fft\n";
}

void CheckCUDADevice()
{
    if (common::GetDeviceCount() == 0)
      throw app::AppException("No CUDA device found");
}

void CheckArguments(int argc)
{
    if (argc < 1) {
      Usage();
      throw app::AppException("No command line parameters");
    }
}

fft::FFTConfig ParseArguments(int argc, char* argv[])
{
    return fft::FFTConfig{5};
}

void Run(int argc, char* argv[]) 
{
  CheckArguments(argc);
  CheckCUDADevice();

  auto config = ParseArguments(argc, argv);

  fft::ProcessFFT(
      fft::FFTConfig{});
}

void PrintHeader()
{
    using namespace std::string_literals;
    std::cout 
        << "== FFT ==\n\n"
           "This is the Capstone project for the Coursera course \n"
           "CUDA Advanced Libraries\n"
           "https://www.coursera.org/learn/cuda-advanced-libraries/\n"
           "This course is part of GPU Programming Specialization - John Hopkins University\n"
           "https://www.coursera.org/specializations/gpu-programming\n\n";
}

void PrintCUDAVersion()
{
    auto version = common::CUDAVersion();
    std::cout << "CUDA version: " 
      << version.major << '.' << version.minor << "\n";
}

void PrintNPPVersion()
{
  auto version = common::NPPVersion();
    std::cout << "NPP version: " 
      << version.major << '.' << version.minor << "\n";
}

void PrintSeparator()
{
    std::cout << "----------------------------------------\n";
}

void PrintFinalWords()
{
    std::cout << "== FFT ==\n";
}

} // namespace

int main(int argc, char* argv[]) 
{
  try {
    PrintHeader();
    PrintSeparator();
    PrintCUDAVersion();
    PrintNPPVersion();
    PrintSeparator();
    Run(argc, argv);
    PrintSeparator();
    PrintFinalWords();
  } catch (...) {
    app::handle_exception();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}