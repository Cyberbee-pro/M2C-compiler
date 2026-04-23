#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <map>

enum TokenKeywords
{
    MAIN,
    FOR ,
    WHILE ,
    IF ,
    ELSE,
    PRINT,
    EXIT
};

static inline std::map<std::string, TokenKeywords> keywordsMap = {
    {"/", TokenKeywords::MAIN},
    {"%", TokenKeywords::FOR},
    {"%%", TokenKeywords::WHILE},
    {"~", TokenKeywords::IF},
    {"~~", TokenKeywords::ELSE},
    {"<", TokenKeywords::PRINT},
    {"^", TokenKeywords::EXIT}
};


enum TokenSeparator
{
    CURL_ST,
    COMA,
    SEMI_COLLON,
    SPACE
};

static inline std::map<std::string, TokenSeparator> separatorMap = {
    {"{", TokenSeparator::CURL_ST},
    {"}", TokenSeparator::CURL_ST},
    {",", TokenSeparator::COMA},
    {";", TokenSeparator::SEMI_COLLON},
    {" ", TokenSeparator::SPACE}
};


struct Token
{
    std::string value;
    TokenKeywords type;
};



class fileReader
{
private:
    std::ifstream inputFile;
    std::string fileName, readLine;
    int i;

public:
    fileReader()
    {
    }

    fileReader(std::string fileName)
    {
        this->fileName = fileName;
        openFile(1);
    }

    // std::ifstream inputFile("test.cym2c");
    void openFile()
    {
        std::cout << "\nEnter file name:" << std::endl;
        std::cin >> fileName;
        inputFile.open(fileName);
        if (!inputFile.is_open())
        {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
    }

    void openFile(int i)
    {
        inputFile.open(fileName);
        if (!inputFile.is_open())
        {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
    }

    // 3. Read the file line by line
    void readFile()
    {
        while (std::getline(inputFile, readLine))
        {
            // 4. Tokenize each line into tokens and separators
            std::string buffer = "";
            for (i = 0; i < readLine.length(); i++)
            {
                // Checks for separators ie space , semicolon,coma, curly braces and prints them and the buffer if it is not empty
                if (readLine[i] == ' ' || readLine[i] == ';'||readLine[i] == '{' || readLine[i] == '}'||readLine[i] == ',')
                {
                    std::cout << "\nSeperator : \"" << readLine[i] << "\"" << std::endl;
                    if (buffer != "")
                    {
                        std::cout << "Buffer : " << buffer <<std::endl<< std::endl;
                        buffer = "";
                    }
                }// open perenthesis is not a separator but it is used to check for function calls and loops and if statements
                else if (readLine[i] == '(')
                {   
                    std::cout << "Buffer : " << buffer <<std::endl;
                    std::cout << "\nOpen Parenthesis : \"" << readLine[i] << "\"" << std::endl;
                    buffer = "";
                }
                else if (readLine[i] == ')')
                {
                    std::cout << "\nClose Parenthesis : \"" << readLine[i] << "\"" << std::endl;
                    std::cout << "Buffer : " << buffer <<std::endl<< std::endl;
                    buffer = "";
                }
                // checks for number tokens
                else if (std::isdigit(readLine[i]))
                {
                    buffer += readLine[i];
                    std::cout << "Token_Numeric : " << readLine[i] << std::endl;
                }
                // checks for alphabetic tokens
                else if (std::isalpha(readLine[i]))
                {
                    buffer += readLine[i];
                    std::cout << "Token_Alphabetic : " << readLine[i] << std::endl;
                }
                // prints the token if it is not a separator and adds it to the buffer
                else
                {
                    buffer += readLine[i];
                    std::cout << "Token : " << readLine[i] << std::endl;
                }
                
            }
            // throws error if line ends without separator and buffer is not empty
            if (i == readLine.length() && buffer != "")
            {
                std::cout << "\n Buffer : " << buffer << std::endl;
                std::cout << "ERROR : Line end without separator!!" << std::endl;
                buffer = "";
                std::cout << "Line end" << std::endl;
            }
        }
    }


    




    ~fileReader()
    {
        std::cout << "\ndestructor called!!" << std::endl;
        inputFile.close();
    }
};

int main()
{
    // std::cout << "Hi Mom" << std::endl;
    fileReader file("test.cym2c");
    // file.openFile();
    file.readFile();
    return 0;
}
