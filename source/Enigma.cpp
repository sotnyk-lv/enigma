//
// Created by danyl on 6/3/2021.
//

#include "Enigma.h"

//#define DEBOUT

Enigma::Enigma (int r1, int r2, int r3, int ref=2) {
    rotor1 = rotor_wheel.rotors[r1-1];
    rotor2 = rotor_wheel.rotors[r2-1];
    rotor3 = rotor_wheel.rotors[r3-1];
    reflector = rotor_wheel.reflectors[ref-1];
    plugboard = rotor_wheel.default_plugboard;
}

int Enigma::letter_to_number(char letter) {
    return static_cast<int>(letter) - static_cast<int>('A');
}

char Enigma::number_to_letter(int number) {
    return static_cast<char>(number + static_cast<int>('A') );
}

void Enigma::letters_to_numbers(std::string &text, std::vector<int> &numbers) {
    for (auto &letter: text) {
        numbers.emplace_back(letter_to_number(letter));
    }
}

void Enigma::numbers_to_letters(std::string &text, std::vector<int> &numbers) {
    for (auto &number: numbers) {
        text += number_to_letter(number);
    }
}

bool Enigma::set_ring_offset(int r1, int r2, int r3) {
    if ((r1 < 0 || r1 > 25) ||
        (r2 < 0 || r2 > 25) ||
        (r3 < 0 || r3 > 25))
        return false;

    rotor1.offset = r1;
    rotor2.offset = r2;
    rotor3.offset = r3;
    return true;
}

bool Enigma::set_start_positions(int r1, int r2, int r3) {
    if ((r1 < 0 || r1 > 25) ||
        (r2 < 0 || r2 > 25) ||
        (r3 < 0 || r3 > 25))
        return false;

    rotor1.position = r1;
    rotor2.position = r2;
    rotor3.position = r3;
    return true;
}

bool Enigma::set_plugboard(std::vector<std::pair<char, char>> &settings) {
    for (auto &letter_pair: settings) {
        plugboard[letter_to_number(letter_pair.first)] = letter_to_number(letter_pair.second);
        plugboard[letter_to_number(letter_pair.second)] = letter_to_number(letter_pair.first);
    }

    return true;
}

std::string Enigma::encript(std::string &text) {
    std::string result;

    std::cout << text << std::endl;

    for (char &char_letter: text) {
        int letter = letter_to_number(char_letter);

        rotor1.position += 1;
        rotor1.position %= 26;

#ifdef DEBOUT
        std::cout << "old: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply plugboard: _____________________________
        letter = plugboard[letter];

#ifdef DEBOUT
        std::cout << "plugboard: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor1: _____________________________
        letter = (rotor1.forward[(letter + rotor1.position)%26] - rotor1.position + 26) % 26 ;
        if (rotor1.position % 26 == rotor1.notch) {
            rotor2.position += 1;
            rotor2.position %= 26;
        }

#ifdef DEBOUT
        std::cout << "rotor1: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor2: _____________________________
        letter = (rotor2.forward[(letter + rotor2.position)%26] - rotor2.position + 26) % 26;
        if (rotor2.position % 26 == rotor2.notch) {
            rotor3.position += 1;
            rotor3.position %= 26;
        }

#ifdef DEBOUT
        std::cout << "rotor2: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor3: _____________________________
        letter = (rotor3.forward[(letter + rotor3.position)%26] - rotor3.position + 26) % 26;

#ifdef DEBOUT
        std::cout << "rotor3: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply reflector: _____________________________
        letter = reflector[letter];

#ifdef DEBOUT
        std::cout << "reflector: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor3: _____________________________
        letter = (rotor3.backward[(letter + rotor3.position)%26] - rotor3.position + 26) % 26;

#ifdef DEBOUT
        std::cout << "rotor3: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor2: _____________________________
        letter = (rotor2.backward[(letter + rotor2.position)%26] - rotor2.position + 26) % 26;

#ifdef DEBOUT
        std::cout << "rotor2: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply rotor1: _____________________________
        letter = (rotor1.backward[(letter + rotor1.position)%26] - rotor1.position + 26) % 26;

#ifdef DEBOUT
        std::cout << "rotor1: " << letter << " " << (char)(letter + 'A') << std::endl;
#endif

        // _____________________________ apply plugboard: _____________________________
        letter = plugboard[letter];

#ifdef DEBOUT
        std::cout << "new: " << letter << " " << (char)(letter + 'A') << std::endl;
        std::cout << std::endl;
#endif

        result += number_to_letter(letter);
    }

    return result;
}
