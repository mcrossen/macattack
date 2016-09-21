#include "sha1.h"
#include <iostream>
#include <sstream>
#include "logger.h"
#include "utils.h"
#define SHA1_BLOCK_LENGTH 512
#define SHA1_MSG_LENGTH_SIZE 64

using namespace std;

// this is the main loop for the mac attack
int main(int argc, char ** argv) {
  // only one option is available from the command line, that is: -v which prints more debugging information
  if (argc == 2) {
    if (string(argv[1]) == "-v") {
      log::verbose = true;
    } else {
      cout << "the only acceptable second argument is -v (verbose)" << endl;
      return 0;
    }
  } else if (argc != 1) {
    cout << "Usage: macappend [-v]" << endl;
    return 0;
  }

  // these are the variables which every other calculation is based off of.
  // to append a different message, one must simply change the to_append variable
  uint64_t key_length = 128;
  string initial_mac = "f4b645e89faaec2ff8e443c595009c16dbdfba4b";
  string initial_msg = "No one has completed lab 2 so give them all a 0";
  string to_append = "P. S. Except for Mark, go ahead and give him the full 100 points.";

  // calculate the length of the message passed in above
  uint64_t initial_msg_length = initial_msg.length()*8;
  // calculate how much padding was on that message
  uint64_t initial_pad_length = SHA1_BLOCK_LENGTH - ((key_length + initial_msg_length + SHA1_MSG_LENGTH_SIZE) % SHA1_BLOCK_LENGTH);
  // print the original pad length if in debug mode
  stringstream debug;
  debug << "initial message padding: " << initial_pad_length;
  log("main", debug.str()); debug.str("");
  // start printing the spoofed message
  cout << "new message: " << utils::string_to_hex(initial_msg);
  stringstream padding;
  padding << "1";
  for (unsigned int index=1; index < initial_pad_length; index++) {
    padding << "0";
  }
  cout << utils::bin_to_hex(padding.str()) << utils::int_to_hex(initial_msg_length+key_length, 64/4) << utils::string_to_hex(to_append) << endl;
  // initialize the digester with the previous MAC
  SHA1 hash(initial_mac);
  // update the digester with the message to be appended
  hash.update(to_append);
  // output the new MAC after adding the final padding
  cout << "new MAC: " << hash.final(key_length + initial_msg_length + initial_pad_length + SHA1_MSG_LENGTH_SIZE + to_append.length()*8) << endl;

  return 0;
}
