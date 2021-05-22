#include "pi.h"
#include "spdlog/spdlog.h"

int main(int argc, const char *argv[]) {
  Pi controller;

  spdlog::info("Controller running.");
  spdlog::info("Press q to quit...");

  spdlog::info("Starting SPI...");
  controller.startSPI();

  while (std::tolower(std::cin.get()) != 'q')
    ;

  return 0;
}