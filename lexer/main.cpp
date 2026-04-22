#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

enum TokenKey
{
    MAIN,
    FOR,
    WHILE,
    IF,
    PRINT,
    SCAN
};

enum TokenSeparator
{
    CURL_ST,
    COMA,
    SEMI_COLLON,
    SPACE
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
                // Checks for separators ie space and semicolon
                if (readLine[i] == ' ' || readLine[i] == ';')
                {
                    std::cout << "\nSeperator : \"" << readLine[i] << "\"" << std::endl;
                    if (buffer != "")
                    {
                        std::cout << "Buffer : " << buffer <<std::endl<< std::endl;
                        buffer = "";
                    }
                }
                // checks for curly braces
                else if (readLine[i] == '{' || readLine[i] == '}')
                {
                    std::cout << "\nSeperator : \"" << readLine[i] << "\"" << std::endl;
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