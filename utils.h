#pragma once
#include <sstream>
using namespace std;

namespace utils {
  uint32_t hex_to_int(string);
  string int_to_hex(unsigned int num, unsigned int pad);
  string string_to_hex(string);
  string char_to_hex(char);
}
