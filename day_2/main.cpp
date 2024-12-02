#include <fstream>
#include <iostream>

int read_input_and_verify();

int main() {
    std::cout << read_input_and_verify() << '\n';
}

int absolute(int input) {
    if (input < 0) return -input;
    return input;
}

int read_input_and_verify() {
    std::ifstream file("input.txt");

    if (!file.is_open() || file.bad()) {
        throw std::runtime_error("input file not opened");
    }

    int safe_count = 0;
    int current_count = 0;
    int arr[1024]{};
    char temp[1024];
    while (!file.eof()) {
        char next_char = file.peek();
        if (next_char == '\n') {
            if (current_count == 1) {
                safe_count++;
                current_count = 0;
                file.getline(&temp[0], 1024, '\n');
            }

            bool is_safe = true;
            bool is_decreasing = false;

            for (int i = 1; i < current_count; i++) {
                int prev = arr[i - 1];
                int current = arr[i];

                int diff = current - prev;

                if (i == 1) {
                    is_decreasing = diff < 0;
                }

                if (int abs = absolute(diff); diff == 0 || abs > 3 || abs < 1) {
                    is_safe = false;
                    break;
                }

                if ((is_decreasing && diff > 0) || (!is_decreasing && diff < 0)) {
                    is_safe = false;
                    break;
                }
            }

            if (is_safe) {
                safe_count++;
            }

            current_count = 0;
            file.getline(&temp[0], 1024, '\n');
        } else if ((next_char >= '0' && next_char <= '9') || next_char == ' ') {
            file >> arr[current_count++];
        }
    }

    return safe_count;
}
