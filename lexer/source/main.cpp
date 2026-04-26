#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <map>
#include <exception>
#include "../include/excptsextra.h"
#include "../include/morse.h"
#include "../include/tokens.h"

class TokenMaker
{

private:
    std::string value;          // e.g., "%%"
    std::string type;           // e.g., "WHILE" or "KEYWORD"
    TokenMaker *next = nullptr; // Pointer to the next token in the linked list
    TokenMaker *prev = nullptr; // Pointer to the previous token in the linked list

    int Line; // Line number where the token was found

public:
    TokenMaker()
    {
        next = nullptr;
        prev = nullptr;
        value = "";
        type = "";
        Line = -1;
    }

    TokenMaker(std::string value, std::string type, int Line)
    {
        this->value = value;
        this->type = type;
        this->Line = Line;
        next = nullptr;
        prev = nullptr;
    }

    // Getters and setters for value, type, next, prev, and Line
    std::string getValue() const { return value; }
    std::string getType() const { return type; }
    int getLine() const { return Line; }
    TokenMaker *getNext() const { return next; }
    TokenMaker *getPrev() const { return prev; }

    // insert a new token after the current token
    void insertAfter(TokenMaker *newToken)
    {

    }

    static void traverseLines(TokenMaker &Head)
    {
        if (Head.getPrev() != nullptr)
        {
            std::cout<<"Provided Token Object is not a head pointer "<<std::endl;
            std::cout<<"Proceeding Form Line:"<< Head.getLine();
        }else if(Head.getLine()==-1){
            std::cout<<"Token incorrectly made || does not belong to a line "<<std::endl;
            throw CompileError("Token incorrectly made || line value = -1",std::string(Head.getType(),Head.getValue()),-1);
        }else if(Head.getNext()==nullptr && Head.getPrev()==nullptr){
            std::cout<<"Provided list is incomplete or disconected "<<std::endl;
            std::cout<<"Token type : "<<Head.getType();
            std::cout<<"Token Value : "<<Head.getValue();
            std::cout<<"Token in Line : "<<Head.getLine();
            
        }else if(Head.getNext()==nullptr){
            std::cout<<"Traverse end . . . . . . "<<std::endl;
            std::cout<<"Process traverse exit . . . . . . "<<std::endl;

        }
    }

    ~TokenMaker()
    {
        // delete TokenMaker;
        std::cout << "\nTokenMaker destructor called!!" << std::endl;
    }
};

class fileReader
{
private:
    std::ifstream inputFile;
    std::string fileName, readLine;
    int i, error = 0, Line = 0;

public:
    fileReader()
    {
    }

    fileReader(std::string fileName)
    {
        this->fileName = fileName;
        inputFile.open(fileName);
        if (!inputFile.is_open())
        {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
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

    // 3. Read the file line by line
    void readFile()
    {

        Line = 0;

        while (std::getline(inputFile, readLine))
        {
            char current;
            // 4. Tokenize each line into tokens and separators
            std::string buffer = "";
            for (i = 0; i < static_cast<int>(readLine.length()); i++)
            {
                current = readLine[i];
                // checks for Comments
                if (current == '/' && readLine[i + 1] == '/')
                {
                    std::cout << "\nComment : \"" << readLine.substr(i) << "\"" << std::endl;
                    break;
                }
                // checks for separators and prints them and the buffer if it is not empty
                else if (M2C::separatorMap.find(std::string(1, current)) != M2C::separatorMap.end())
                {
                    std::cout << "\nSeperator : \" " << current << " \"" << std::endl;
                    if (buffer != "")
                    {
                        std::cout << "Buffer : " << buffer << "\n"
                                  << std::endl;
                        buffer = "";
                    }
                } // open perenthesis is not a separator but it is used to check for function calls and loops and if statements
                // checks for keywords and prints them
                else if (M2C::keywordsMap.find(std::string(1, current)) != M2C::keywordsMap.end())
                {
                    std::cout << "\nKeyword : \"" << current << "\"" << std::endl;
                }
                // close parenthesis is not a separator but it is used to check for function calls and loops and if statements
                // check for parenthesis
                else if (current == '(')
                {
                    std::cout << "Buffer : " << buffer << std::endl;
                    std::cout << "\nOpen Parenthesis : \"" << current << "\"" << std::endl;
                    buffer = "";
                }
                else if (current == ')')
                {
                    std::cout << "\nClose Parenthesis : \"" << current << "\"" << std::endl;
                    std::cout << "Buffer : " << buffer << "\n"
                              << std::endl;
                    buffer = "";
                }
                else if (current == '\"')
                {
                    i++;
                    std::cout << "\nFound Quote!" << std::endl;
                    std::cout << "morse Translation? " << morse_parse(readLine, i) << std::endl;
                }
                else
                {
                    buffer += current;
                    std::cout << "Token : " << current << std::endl;
                }
            }
            // throws error if line ends without separator and buffer is not empty
            try
            {
                if (i == static_cast<int>(readLine.length()) && buffer != "" && current != ';' && (current != '{' || current != '}'))
                {
                    std::cout << "\n Buffer : " << buffer << std::endl;
                    buffer = "";
                    std::cout << "Line end" << std::endl;
                    throw CompileError("***[Expected ; in the end of line]***", readLine, Line);
                }
            }
            catch (const CompileError &e)
            {
                std::cerr << e.what() << std::endl;
            }

            Line++;
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
    fileReader file("../../m2c_files/test.cym2c");
    // file.openFile();
    file.readFile();
    return 0;
}