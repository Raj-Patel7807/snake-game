#pragma once

#include <string>

class HighScore {
public:
    static int load(const std::string &filePath);

    static void save(const std::string &filePath, int score);
};
