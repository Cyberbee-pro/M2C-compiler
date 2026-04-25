#ifndef MORSE_H
#define MORSE_H

#include <map>
#include <string>


enum TokenChar
{
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
};

enum TokenNumeric
{ 
    ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE
};


inline std::map<std::string, TokenChar> charMap = {
    {".-", TokenChar::A},
    {"-...", TokenChar::B},
    {"-.-.", TokenChar::C},
    {"-..", TokenChar::D},
    {".", TokenChar::E},
    {"..-.", TokenChar::F},
    {"--.", TokenChar::G},
    {"....", TokenChar::H},
    {"..", TokenChar::I},
    {".---", TokenChar::J},
    {"-.-", TokenChar::K},
    {".-..", TokenChar::L},
    {"--", TokenChar::M},
    {"-.", TokenChar::N},
    {"---", TokenChar::O},
    {".--.", TokenChar::P},
    {"--.-", TokenChar::Q},
    {".-.", TokenChar::R},
    {"...", TokenChar::S},
    {"-", TokenChar::T},
    {"..-", TokenChar::U},
    {"...-", TokenChar::V},
    {".--", TokenChar::W},
    {"-..-", TokenChar::X},
    {"-.--", TokenChar::Y},
    {"--..", TokenChar::Z}};



inline std::map<std::string, TokenNumeric> numericMap = {
    {"-----", TokenNumeric::ZERO},
    {".----", TokenNumeric::ONE},
    {"..---", TokenNumeric::TWO},
    {"...--", TokenNumeric::THREE},
    {"....-", TokenNumeric::FOUR},
    {".....", TokenNumeric::FIVE},
    {"-....", TokenNumeric::SIX},
    {"--...", TokenNumeric::SEVEN},
    {"---..", TokenNumeric::EIGHT},
    {"----.", TokenNumeric::NINE}
};



    std::string morseType(std::string);

    bool isChar(std::string);
    bool isNum(std::string);
    bool isMorse(std::string);

    char morseToChar(std::string);

    int morseToInt(std::string);


#endif