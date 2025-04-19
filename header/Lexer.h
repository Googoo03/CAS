#include "VECTOR.h"
#include <string>
#include <regex>

//INCLUDE ALL TOKEN TYPES THAT WE NEED. LIKELY MATHEMATICAL UNITS LIKE VECTOR AND MATRIX
enum TokenType{
    _keyword,
    _variable,
    _ADDoperator,
    _MULoperator,
    _LParen,
    _RParen,
    _LBracket,
    _RBracket

};


struct Token{
    std::string val;
    TokenType type;

    public:
        Token():val(std::string{}),type(TokenType{}){}
        Token(std::string _v,TokenType _t):val(_v),type(_t){}

        friend std::ostream& operator<<(std::ostream& os, Token& obj){
            os << "Token: " << obj.val << " : " << obj.type << std::endl;
            return os;
        }
};


class Lexer{
    public:
        static VECTOR<Token*> Lexelize(VECTOR<std::string*> blocks){
            VECTOR<Token*> token_list;
            
            while(!blocks.Empty()){
                //Logic for identifying each token goes here

                //There's likely a better way? Doesn't this still copy the entire substring?
                std::string block = *blocks.pop();
                if(block == "("){ token_list.Append(new Token(block,TokenType::_LParen)); continue; }

                if(block == ")"){ token_list.Append(new Token(block,TokenType::_RParen)); continue; }

                if(block == "{"){ token_list.Append(new Token(block,TokenType::_LBracket)); continue; }

                if(block == "}"){ token_list.Append(new Token(block,TokenType::_RBracket)); continue; }

                if(block == "+" || block == "-"){ token_list.Append(new Token(block,TokenType::_ADDoperator)); continue; }

                if(block == "*" || block == "/"){ token_list.Append(new Token(block,TokenType::_MULoperator)); continue; }

                if(block == "let"){ token_list.Append(new Token(block,TokenType::_keyword)); continue; }

                if(std::regex_match(block,std::regex("^[A-Za-z]+$"))){ token_list.Append(new Token(block,TokenType::_variable)); continue; }
                //Append to token_list
            }

            return token_list;
        }
    private:

};