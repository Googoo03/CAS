#include <iostream>
#include <Tokenizer.h>

int main(int argc, char* argv[]){

    VECTOR<std::string*> result = Tokenizer::Tokenize(argv[1],' ');
    std::cout << result << std::endl;
    return 0;
}