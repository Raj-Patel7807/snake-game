#include "HighScore.h"
#include <fstream>

int HighScore::load(const std::string &filePath) {
    std::ifstream in(filePath.c_str());
    if (!in.is_open()) return 0;

    int x = 0;
    in >> x;

    if (!in.good()) return 0;
    if (x < 0) x = 0;
    return x;
}

void HighScore::save(const std::string &filePath, int score) {
    if (score < 0) score = 0;
    std::ofstream out(filePath.c_str(), std::ios::trunc);

    if (!out.is_open()) return;
    out << score;
}

