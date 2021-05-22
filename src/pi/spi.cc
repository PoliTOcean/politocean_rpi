#include "pigpio.h"

#include "exception.h"
#include "spi.h"

#include "spdlog/spdlog.h"

using namespace politocean::pi;
using namespace politocean::pi::exception;

SPI::SPI() : _handle(-1) {}

bool SPI::open() {
  if (gpioInitialise() < 0) {
    throw GPIOException("PiGPIO initialisation failed in PiMotor::run.\n");
  }

  _handle = spiOpen(kSPIChannel, kSPISpeed, 0);
  if (_handle < 0) {
    throw GPIOException("Cannot open SPI.\n");
  }

  char start = kSPIStarted;
  if (spiWrite(_handle, &start, sizeof(char)) < 0) {
    throw GPIOException("Cannot write on SPI.");
  }

  spdlog::debug("{} sent to start SPI communication.", start);

  return _handle >= 0;
}

void SPI::close() {
  if (_handle >= 0) {
    spiClose(_handle);
  }
}

SPI::~SPI() { close(); }