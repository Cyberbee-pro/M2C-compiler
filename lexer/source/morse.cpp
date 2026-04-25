#include "../include/morse.h"
#include <string.h>
#include <map>


#include "../include/morse.h"

bool isChar(std::string buffer) {
    return charMap.find(buffer) != charMap.end();
}

bool isNum(std::string buffer) {
    return numericMap.find(buffer) != numericMap.end();
}

bool isMorse(std::string buffer) {
    return isChar(buffer) || isNum(buffer);
}

// Fixed morseToChar to return from our updated map
char morseToChar(std::string buffer) {
    if (isChar(buffer)) return charMap[buffer];
    if (isNum(buffer)) return numericMap[buffer];
    return '?'; 
}

// Updated morseToStr to return the actual letter, not its ASCII number
std::string morseToStr(std::string buffer) {
    if (isChar(buffer)) {
        // This creates a string containing the actual letter (e.g., "A")
        return std::string(1, charMap[buffer]); 
    } 
    else if (isNum(buffer)) {
        return std::string(1, numericMap[buffer]);
    }
    return "Not A Morse char/num";
}

std::string morseType(std::string buffer) {
    if (isChar(buffer)) return "Morse : Character";
    if (isNum(buffer)) return "Morse : Numeric";
    return "Unknown";
}