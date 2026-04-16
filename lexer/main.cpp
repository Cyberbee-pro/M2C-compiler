#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>


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
    SPACE
};

class fileReader{
    private:
    std::ifstream inputFile;
    std::string fileName, readLine;
    int i;

    public:

    fileReader(){
        
    }

    fileReader(std::string fileName){
        this->fileName = fileName;
        openFile(1);
    }

    // std::ifstream inputFile("test.cym2c");
    void openFile(){
        std::cout<<"\nEnter file name:"<<std::endl;
        std::cin>>fileName;
        inputFile.open(fileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
    }

    void openFile(int i){
        inputFile.open(fileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            exit(1);
        }
    }

    // 3. Read the file line by line
    void readFile(){
        while (std::getline(inputFile, readLine)) {
            // std::cout << readLine << std::endl;
            std::string buffer = "";
            for(i = 0 ; i < readLine.length() ; i++){
                
                if(readLine[i] == ' ' ||readLine[i] == ';'){
                    std::cout<<"\n Seperator : \""<< readLine[i]<<"\""<<std::endl;
                    if(buffer!=""){
                        std::cout<<"\n Buffer : "<<buffer<<std::endl;
                        buffer="";
                    }
                }else{
                        buffer+=readLine[i];
                        std::cout<<"\n Token : "<< readLine[i]<<std::endl;
                    }
            }
            if(i==readLine.length()){
                    std::cout<<"\n Buffer : "<<buffer<<std::endl;
                    buffer=""; 
                }
        
        }
    }

    ~fileReader(){
        std::cout<<"\ndestructor called!!"<<std::endl;
        inputFile.close();
    }

};


int main (){
    std::cout<<"Hi Mom"<<std::endl;
    fileReader file("test.cym2c");
    // file.openFile();
    file.readFile();
    return 0;
}