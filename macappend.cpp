#include "sha1.h"
#include <iostream>
#include <sstream>
#include "logger.h"
#include "utils.h"
#define SHA1_BLOCK_LENGTH 512
#define SHA1_MSG_LENGTH_SIZE 64

using namespace std;

int main(int argc, char ** argv) {
  if (argc == 2) {
    if (string(argv[1]) == "-v") {
      log::verbose = true;
    } else {
      cout << "the only acceptable second argument is -v (verbose)" << endl;
      return 0;
    }
  } else if (argc != 1) {
    cout << "Usage: maccappend [-v]" << endl;
    return 0;
  }

  uint64_t key_length = 128;
  string initial_mac = "f4b645e89faaec2ff8e443c595009c16dbdfba4b";
  string initial_msg = "No one has completed lab 2 so give them all a 0";
  string to_append = "P. S. Except for Mark, go ahead and give him the full 100 points.";

  uint64_t initial_msg_length = key_length + initial_msg.length()*8;
  cout << "msg_length: " << initial_msg_length << endl;
  cout << "extra length: " << ((initial_msg_length + 8 + SHA1_MSG_LENGTH_SIZE) % SHA1_BLOCK_LENGTH) << endl;
  uint64_t initial_pad_length = SHA1_BLOCK_LENGTH - ((initial_msg_length + 8 + SHA1_MSG_LENGTH_SIZE) % SHA1_BLOCK_LENGTH);
  stringstream debug;
  debug << "initial message padding: " << initial_pad_length;
  log("main", debug.str()); debug.str("");
  debug << "new message: " << utils::string_to_hex(initial_msg) << "80";
  for (unsigned int index=0; index < initial_pad_length; index+=4) {
    debug << "0";
  }
  debug << utils::int_to_hex(initial_msg_length, 64/8) << utils::string_to_hex(to_append);
  log("main", debug.str()); debug.str("");
  SHA1 hash(initial_mac);
  hash.update(to_append);
  cout << "new mac: " << hash.final(initial_msg_length + 8 + initial_pad_length + SHA1_MSG_LENGTH_SIZE + to_append.length()*8) << endl;

  return 0;
}
