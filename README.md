# MAC Attack
This was project was made as part of a class in computer security (CS 465) at BYU.

## Introduction
MACs are used to verify messages. In essence, they are stamping the message as ‘legitimate’. This means that no one has tampered with the message other than the sender. To ‘stamp’ a message, the SHA1 digest of the message prepended with a shared key is computed. To verify the message (when received), the same process is repeated and the MACs are compared. To change the message without the receiver knowing, the attacker must simply append new content to the end of the message and compute the new mac given the old MAC. This is possible because the SHA1 hashing algorithm used to compute the MAC takes as input the previous digest combined with the next chunk and outputs the new digest. In this case, the previous digest is simply the MAC, and the next chunk is the message that we’re adding on. The output is the new MAC that can be attached to the maliciously-modified message. In this manner, the attacker doesn’t need to know the shared key to be able to change the message.

## Usage
Because this project was made as a proof of concept, the only command line option is '-v'. This displays debugging info to the console.
```bash
./macappend [-v]
```

To change the inputed message, MAC, key length, or new message, simply change the constants near the beginning of macappend.cpp
```c++
uint64_t key_length = 128;
string initial_mac = "f4b645e89faaec2ff8e443c595009c16dbdfba4b";
string initial_msg = "No one has completed lab 2 so give them all a 0";
string to_append = "P. S. Except for Mark, go ahead and give him the full 100 points.";
```

To run the attack, compile the code with the given makefile, and then execute the outputted binary.
```bash
make
./macappend
```

The new message and MAC (in hex) will be displayed to the console.

## Results

The project was tested for one use case in particular:
```
original message: "No one has completed lab 2 so give them all a 0"
original MAC: f4b645e89faaec2ff8e443c595009c16dbdfba4b
message to append: "P. S. Except for Mark, go ahead and give him the full 100 points."
```

From the data above, the following new message and MAC were generated (in hex):

```
new message: 4e6f206f6e652068617320636f6d706c65746564206c6162203220736f2067697665207468656d20616c6c2061203080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001f8502e20532e2045786365707420666f72204d61726b2c20676f20616865616420616e6420676976652068696d207468652066756c6c2031303020706f696e74732e
new MAC: 60a179d4a46e0ce8ed7a0f4d4776f1e41a1b6943
```
