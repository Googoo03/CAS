#include <iostream>
#include <Tokenizer.h>
#include <Lexer.h>

int main(int argc, char* argv[]){

    //Word step
    VECTOR<std::string*> result = Tokenizer::Tokenize(argv[1],' ');
    std::cout << result << std::endl;

    //Lexer
    VECTOR<Token*> tokens = Lexer::Lexelize(result);
    std::cout << tokens << std::endl;
    
    return 0;
}