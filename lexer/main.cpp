#include<iostream>
#include<bits/stdc++.h>
#include<string>


enum TokenKey{
    MAIN,
    FOR,
    WHILE,
    IF,
    PRINT,
    SCAN
};

enum TokenSeparator{
    CURL_ST,
    COMA,
    SEMI_COLLON,
};

int main (){
    std::cout<<"Hi Mom"<<std::endl;
    std::ifstream inputFile("test.cym2c");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    std::string readLine;
    // 3. Read the file line by line
    while (std::getline(inputFile, readLine)) {
        std::cout << readLine << std::endl;
    }

    return 0;
}