#include <VECTOR.h>

class Tokenizer{

    //takes in string input, returns token array
    public:

        //I want a tokenizer that takes in a file as well

        //Tokenizer that takes in a string. Multi line programs not possible?
        static VECTOR<std::string*> Tokenize(const std::string& str, char delimiter){
            VECTOR<std::string*> token_vec(5);
            int length = str.size();
            int s = 0;

            for(int e = 0; e < length; ++e){
                //if hit a delimiter, add the token to the list, and increment start
                if(str[e] == delimiter){
                    std::string* new_string = new std::string(str.substr(s,e-s));
                    token_vec.Append(new_string);
                    e++;
                    s = e;
                    
                }
            }
            return token_vec;
        }

};