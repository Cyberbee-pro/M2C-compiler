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

class flileReader{
    private:
    // FILE *inputFlie;
    std::string fileName;
    public:


    // std::ifstream inputFile("test.cym2c");
    void openFile(){
        std::cout<<"\nEnter file name:"<<std::endl;
        std::cin>>fileName;
        std::ifstream inputFile(fileName); //open file
        if (!inputFile.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
    }


        void readFile(){
            while (std::getline(inputFile, readLine)) {
                std::cout << readLine << std::endl;
            }   
        }


};


int main (){
    std::cout<<"Hi Mom"<<std::endl;

    std::string readLine;
    // 3. Read the file line by line
    

    return 0;
}