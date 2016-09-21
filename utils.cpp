#include "utils.h"

uint32_t utils::hex_to_int(string hex_string) {
  return strtol(hex_string.c_str(), NULL, 16);
}

string utils::int_to_hex(unsigned int num) {
  stringstream converter;
  converter << hex << num;
  return converter.str();
}
