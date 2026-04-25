#include "../include/morse.h"
#include <string.h>
#include <map>


bool isChar(std::string buffer){
    return charMap.find(buffer) != charMap.end() ;
}

bool isNum(std::string buffer){
    return numericMap.find(buffer) != numericMap.end() ;
}

bool isMorse(std::string buffer){
    return (charMap.find(buffer) != charMap.end()||numericMap.find(buffer)!= numericMap.end());
}

std::string morseType(std::string buffer){
    if(isChar(buffer)){
        return std::string("Morse : Charecter");
    }else if(isNum(buffer)){
        return std::string("Morse : Charecter");
    }
}


char morseToChar(std::string buffer){
    char output = charMap[buffer];
    return output;
}

int morseToInt(std::string buffer){
    int output = charMap[buffer];
    return output;
}


