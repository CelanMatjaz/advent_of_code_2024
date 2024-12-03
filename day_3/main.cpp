#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

int read_and_parse_input();

int main() {
    std::cout << read_and_parse_input() << '\n';
}

int read_and_parse_input() {
    std::ifstream file("input.txt");

    if (!file.is_open() || file.bad()) {
        throw std::runtime_error("input file not opened");
    }

    int result = 0;
    int progress = 0;
    char progress_characters[] = "mul(\0,\0)";
    char ch = 0;
    int values[2]{};

    auto peek_for_number = [&file]() {
        char ch = file.peek();
        return ch >= '0' && ch <= '9';
    };

    auto check_for_character_and_update_progress = [&](char expected) {
        if (progress == 4 || progress == 6) {
            auto peek_for_number = [&file]() {
                char ch = file.peek();
                return ch >= '0' && ch <= '9';
            };

            if (peek_for_number()) {
                file >> values[progress / 5];
                progress++;
            } else {
                progress = 0;
            }

            return;
        }

        ch = file.get();
        if (ch == expected)
            progress++;
        else
            progress = 0;

        if (progress == 8) {
            result += values[0] * values[1];
            progress = 0;
        }
    };

    while (!file.eof()) {
        check_for_character_and_update_progress(progress_characters[progress]);
    }

    return result;
}
