// https://adventofcode.com/2024/day/1

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <print>
#include <vector>

std::array<std::vector<uint32_t>, 2> read_input();

uint32_t absolute(int input) {
    if (input < 0) return -input;
    return input;
}

int main() {
    auto input = read_input();
    uint32_t count = input[0].size();

    std::sort(input[0].begin(), input[0].end());
    std::sort(input[1].begin(), input[1].end());

    uint32_t total_distance = 0;
    for (int i = 0; i < count; ++i) {
        total_distance += absolute(input[0][i] - input[1][i]);
    }

    std::cout << total_distance << '\n';
}

std::array<std::vector<uint32_t>, 2> read_input() {
    std::array<std::vector<uint32_t>, 2> vectors;
    std::ifstream file("input.txt");

    if (!file.is_open() || file.bad()) {
        throw std::runtime_error("input file not opened");
    }

    uint32_t count = 1000;
    vectors[0].resize(count);
    vectors[1].resize(count);

    for (int i = 0; i < count; i++) {
        file >> vectors[0][i] >> vectors[1][i];
    }

    return vectors;
}
