#include <iostream>
#include <Tokenizer.h>

int main(int argc, char* argv[]){
    Tokenizer::Tokenize(argv[1],';');
    return 0;
}