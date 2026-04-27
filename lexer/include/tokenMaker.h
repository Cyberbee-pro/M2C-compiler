#ifndef TOKENMAKER_H 
#define TOKENMAKER_H
#include <string>



class TokenMaker
{

private:
    std::string value;          // e.g., "%%"
    std::string type;           // e.g., "WHILE" or "KEYWORD"
    TokenMaker *next = nullptr; // Pointer to the next token in the linked list
    TokenMaker *prev = nullptr; // Pointer to the previous token in the linked list

    int Line; // Line number where the token was found

public:
    TokenMaker();

    TokenMaker(std::string value, std::string type, int Line);

    // Getters and setters for value, type, next, prev, and Line
    std::string getValue() const;
    std::string getType() const;
    int getLine() const;
    TokenMaker *getNext() const;
    TokenMaker *getPrev() const;

    // insert a new token after the current token
    void insertAfter(TokenMaker *newToken);

    static void traverseLines(TokenMaker &Head);

    ~TokenMaker();
};


#endif