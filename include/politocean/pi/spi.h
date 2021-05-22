#ifndef SPI_H
#define SPI_H

#include "../serializable.h"
#include "exception.h"
#include "pigpio.h"
#include <cstdint>
#include <functional>
#include <vector>

namespace politocean::pi {
class SPI {
  const int kSPISpeed = 1000000;
  const int kSPIChannel = 0;
  const int kDFLTSPIHandle = -1;
  const char kSPIStarted = 0xff;

  int _handle;

public:
  SPI();
  ~SPI();

  bool open();
  void close();

  template <typename T, typename std::enable_if<std::is_base_of<
                            Serializable, T>::value>::type * = nullptr>
  bool write(const T &s) {
    std::vector<char> buffer = s.template serialize();

    for (char c : buffer) {
      if (spiWrite(_handle, c, sizeof(char)) <= 0) {
        throw exception::SPIException("Cannot write on SPI.\n");
      }
    }
  }

  template <typename T, typename std::enable_if<std::is_base_of<
                            Serializable, T>::value>::type * = nullptr>
  bool read(const T &s) {
    size_t size = s.template size();

    std::vector<char> buffer(size);

    for (int i = 0; i < size; i++) {
      if (spiRead(_handle, &buffer[i], sizeof(char)) <= 0) {
        throw exception::SPIException("Cannot read from SPI.\n");
      }
    }

    s.template deserialize(std::move(buffer));
  }

  template <typename T, typename std::enable_if<std::is_base_of<
                            Serializable, T>::value>::type * = nullptr>
  T read(const uint8_t nbytes);

  template <
      typename T, typename R,
      typename std::enable_if<std::is_base_of<Serializable, T>::value>::type * =
          nullptr,
      typename std::enable_if<std::is_base_of<Serializable, R>::value>::type * =
          nullptr>
  bool transfer(const T &, const R &);

  template <
      typename T, typename R,
      typename std::enable_if<std::is_base_of<Serializable, T>::value>::type * =
          nullptr,
      typename std::enable_if<std::is_base_of<Serializable, R>::value>::type * =
          nullptr>
  T transfer(const R &, const uint8_t nbytes);
};
} // namespace politocean::pi

#endif // SPI_H