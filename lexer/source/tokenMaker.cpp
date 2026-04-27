#include <string>
#include <iostream>
#include "../include/tokenMaker.h"
#include "../include/excptsextra.h"

TokenMaker::TokenMaker()
{
    next = nullptr;
    prev = nullptr;
    value = "";
    type = "";
    Line = -1;
}

TokenMaker::TokenMaker(std::string value, std::string type, int Line)
{
    this->value = value;
    this->type = type;
    this->Line = Line;
    next = nullptr;
    prev = nullptr;
}

// Getters and setters for value, type, next, prev, and Line
std::string TokenMaker::getValue() const { return value; }
std::string TokenMaker::getType() const { return type; }
int TokenMaker::getLine() const { return Line; }
TokenMaker *TokenMaker::getNext() const { return next; }
TokenMaker *TokenMaker::getPrev() const { return prev; }

// insert a new token after the current token
void TokenMaker::insertAfter(TokenMaker *newToken)
{
}

void TokenMaker::traverseLines(TokenMaker &Head)
{
    if (Head.getPrev() != nullptr)
    {
        std::cout << "Provided Token Object is not a head pointer " << std::endl;
        std::cout << "Proceeding Form Line:" << Head.getLine();
    }
    for (int i = 0; Head.getNext() != nullptr; i++)
    {
        try
        {
            if (Head.getLine() == -1)
            {
                std::cout << "Token incorrectly made || does not belong to a line " << std::endl;
                throw CompileError("Token incorrectly made || line value = -1", Head.getType() + Head.getValue(), -1);
            }
            else if (Head.getNext() == nullptr && Head.getPrev() == nullptr)
            {
                std::cout << "Provided list is incomplete or disconected | no parent or clild tokens" << std::endl;
                std::cout << "Token type : " << Head.getType();
                std::cout << "Token Value : " << Head.getValue();
                std::cout << "Token in Line : " << Head.getLine();
                break;
            }
            else if (Head.getLine() != -1 && Head.getType() != "")
            {
                std::cout << "Token type : " << Head.getType();
                std::cout << "Token Value : " << Head.getValue();
                std::cout << "Token in Line : " << Head.getLine();
                (Head.getPrev()==nullptr)?(void)(std::cout << "Head Block . . . . . . " << std::endl):(void)1;
                (Head.getNext()==nullptr)?(void)(std::cout << "Traverse end . . . . . . " << std::endl):(void)1;
                break;
            }
        }
        catch (const CompileError &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

TokenMaker::~TokenMaker()
{
    // delete TokenMaker;
    std::cout << "\nTokenMaker destructor called!!" << std::endl;
}