#pragma once

#include <iostream>
#include <string>
#include "logger.h"
#include "utils.h"

class SHA1
{
public:
    SHA1();
    SHA1(std::string);
    void update(const std::string &s);
    void update(std::istream &is);
    std::string final();
    std::string final(uint64_t msg_length);
    static std::string from_file(const std::string &filename);

private:
    uint32_t digest[5];
    std::string buffer;
    uint64_t transforms;
};
