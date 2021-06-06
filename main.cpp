#include <iostream>
#include <vector>
#include <string>

//#define DEBOUT

#include "Rotor.h"
#include "Enigma.h"
#include "time_counting.h"

void letters_to_numbers(std::string &text, std::vector<int> &numbers) {
    for (auto &letter: text) {
        numbers.emplace_back(static_cast<int>(letter) - static_cast<int>('A'));
    }
}

void numbers_to_letters(std::string &text, std::vector<int> &numbers) {
    for (auto &number: numbers) {
        text += (static_cast<char>(number + static_cast<int>('A') ));
    }
}

int main() {

    std::string text = "A";
    for (int i=0; i<100; i++) {
        text += "A";
    }

    auto start = get_current_time_fenced();

    Enigma enigma(1,2,3,2);


    std::string res = enigma.encript(text);

    auto end = get_current_time_fenced();

    std::cout << text << " -> " << res << std::endl;

    std::cout << "time: " << to_seconds(end - start) << std::endl;

    return 0;
}
