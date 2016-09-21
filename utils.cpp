#include "utils.h"

uint32_t utils::hex_to_int(string hex_string) {
  return strtol(hex_string.c_str(), NULL, 16);
}

string utils::int_to_hex(unsigned int num, unsigned int pad = 0) {
  stringstream converter;
  converter << hex << num;
  string to_return = converter.str();
  for (unsigned int index = to_return.length(); index < pad; index++) {
    to_return = "0" + to_return;
  }
  return to_return;
}

string utils::string_to_hex(string str) {
  stringstream converter;
  for (unsigned int index = 0; index < str.length(); index++) {
    converter << char_to_hex(str.c_str()[index]);
  }
  return converter.str();
}

string utils::char_to_hex(char character) {
  string to_return = int_to_hex(character);
  if (to_return.length() < 2) {
    return "0" + to_return;
  } else {
    return to_return;
  }
}
