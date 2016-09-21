#include "sha1.h"
#include <iostream>
#include "logger.h"

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

  unsigned int key_length = 128;
  string initial_mac = "f4b645e89faaec2ff8e443c595009c16dbdfba4b";
  string initial_msg = "No one has completed lab 2 so give them all a 0";
  string to_append = "P. S. Except for Mark, go ahead and give him the full 100 points.";


  SHA1 hash(initial_mac);
  hash.update(to_append);
  cout << "new mac: " << hash.final() << endl;

  return 0;
}
