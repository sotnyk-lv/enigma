//
// Created by danyl on 6/3/2021.
//

#ifndef ENIGMA_ENIGMA_H
#define ENIGMA_ENIGMA_H

#include <vector>
#include <string>
#include <array>
#include <cstring>
#include <iostream>

#include "Rotor.h"

class Enigma {

public:
    Enigma(int rotor1, int rotor2, int rotor3, int reflector);
    bool set_ring_offset(int rotor1, int rotor2, int rotor3);
    bool set_start_positions(int rotor1, int rotor2, int rotor3);
    bool set_plugboard(std::vector<std::pair<char, char>> &settings);

    static inline int letter_to_number(char letter);
    static inline char number_to_letter(int number);
    static void letters_to_numbers(std::string &text, std::vector<int> &numbers);
    static void numbers_to_letters(std::string &text, std::vector<int> &numbers);

    std::string encript(std::string &text);

private:

    Rotor rotor1, rotor2, rotor3;

    std::array<int, 26> reflector;

    std::array<int, 26> plugboard;

    Rotors rotor_wheel;

};


#endif //ENIGMA_ENIGMA_H
