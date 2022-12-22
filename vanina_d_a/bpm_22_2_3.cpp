#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector <char> input;
    char el;
    for (int i = 0; i < n; i++) {
        std::cin >> el;
        input.push_back(el);
    }
    std::vector <char> output;
    while(output.size()!=n) {
        if (input.size() % 2 != 0) {
            output.push_back(input[input.size() / 2]);
            input.erase(input.begin() + input.size() / 2);
        }
        else {
            output.push_back(input[input.size() / 2 - 1]);
            input.erase(input.begin() + input.size() / 2);
        }
        for (int i = 0; i < n; i++) {
            std::cout << output[i];
        }
    }
}
