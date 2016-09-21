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
    }
  } else if (argc != 1) {
    cout << "Usage: maccappend [-v]" << endl;
  }
}
