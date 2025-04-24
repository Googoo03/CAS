#include "Tokenizer.h"
#include "Lexer.h"
#include "VECTOR.h"
#include <string>
#include <functional>

#pragma once

#ifndef SYNTAX_ANALYSIS_H
#define SYNTAX_ANALYSIS_H

#define TERM_NUM 6
#define NONTERM_NUM 6

//So, enums need to be known at compile time. If we want this to be user-generated on the fly, then we can't use enums.
//However, we want the values to be referenced by name?


/*
enum Terminals{
    _end_stack,
    _variable,
    _ADDoperator,
    _MULoperator,
    _LParen,
    _RParen,
    TERM_NUM

};

enum NonTerminals{
    _START,
    _Expression,
    _Expression_,
    _Term,
    _Term_,
    Factor,
    NONTERM_NUM
};
*/

enum class Symbols{
    _START,
    _EPS,
    _Expression,
    _Expression_,
    _Term,
    _Term_,
    Factor,
    _end_stack,
    _variable,
    _ADDoperator,
    _MULoperator,
    _LParen,
    _RParen,
    SYMBOL_NUM
};


//we want the table to be a combination of terminals and non terminals.
//each one can be represented by an int. How do we have a sequence of them tho?


class Syntax_Analyzer{
    public:
        //Need a list of unique terminals
        VECTOR<Token> token_list;
        
        //Need a list of input terminals
        VECTOR<Token> input_tokens;
        //Need a transition table to reference
        VECTOR<Symbols> transitionTable[NONTERM_NUM][TERM_NUM]{
            {{}, {}, {}, {Symbols::_Expression, Symbols::_START}, {}, {Symbols::_Expression, Symbols::_START}}, //S
            {{}, {}, {}, {Symbols::_Term, Symbols::_Expression_}, {}, {Symbols::_Term, Symbols::_Expression_}}, //E
            {{Symbols::_EPS}, {Symbols::_Term, Symbols::_Expression_}, {}, {}, {Symbols::_EPS}, {}}, //E'
            {{}, {}, {}, {Symbols::Factor, Symbols::_Term_}, {}, {Symbols::Factor, Symbols::_Term_}}, //T
            {{Symbols::_EPS}, {Symbols::_EPS}, {Symbols::_MULoperator, Symbols::Factor, Symbols::_Term_}, {}, {Symbols::_EPS}, {}}, //T'
            {{}, {}, {}, {Symbols::_LParen, Symbols::_Expression, Symbols::_RParen}, {}, {Symbols::_variable}} //F
        
        };


        //Need a way to generate a null/first/follow table given a set of grammar rules. LATER

        Syntax_Analyzer(VECTOR<Token> _tkl):token_list(_tkl){

            //Creates a list of unique tokens for a given input token set.

            //Do we only need a subset of tokens (terminals?)
        }



        //Takes in a vector of input tokens and a transition table, and will build an AST tree. Both the transition table and the
        //AST tree are not included in the parameters as of yet. AST tree head will be a pointer.
        static bool Syntax_Analysis(VECTOR<Token> _ip){
            //What is the end structure? An ast can represent all of the expression as one tree.
            VECTOR<Symbols> symbol_stack;
            symbol_stack.Append(Symbols::_START);

            VECTOR<Symbols> transitionTable[NONTERM_NUM][TERM_NUM]{
                {{}, {}, {}, {Symbols::_Expression, Symbols::_START}, {}, {Symbols::_Expression, Symbols::_START}}, //S
                {{}, {}, {}, {Symbols::_Term, Symbols::_Expression_}, {}, {Symbols::_Term, Symbols::_Expression_}}, //E
                {{Symbols::_EPS}, {Symbols::_Term, Symbols::_Expression_}, {}, {}, {Symbols::_EPS}, {}}, //E'
                {{}, {}, {}, {Symbols::Factor, Symbols::_Term_}, {}, {Symbols::Factor, Symbols::_Term_}}, //T
                {{Symbols::_EPS}, {Symbols::_EPS}, {Symbols::_MULoperator, Symbols::Factor, Symbols::_Term_}, {}, {Symbols::_EPS}, {}}, //T'
                {{}, {}, {}, {Symbols::_LParen, Symbols::_Expression, Symbols::_RParen}, {}, {Symbols::_variable}} //F
            
            };



            
            while(!symbol_stack.Empty()){
                //pop top symbol
                Symbols top = symbol_stack.pop();

                //if terminal, match accordingly, build AST tree nodes
                if(isTerminal(top)){
                    //match
                    continue;
                }


                //push corresponding symbols based on input token front AND top symbol
                [&symbol_stack](VECTOR<Symbols> symb){
                    while (!symb.Empty())
                    {
                        symbol_stack.Append(symb.pop());
                    }
                }(transitionTable[0][0]);
            }

            //for testing purposes
            return false;
        }

        
    private:
        static bool isTerminal(Symbols symbol){ return false;}
};

#endif