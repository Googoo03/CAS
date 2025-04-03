#include <VECTOR.h>

class Tokenizer{

    //takes in string input, returns token array
    public:
        static VECTOR<std::string> Tokenize(const std::string& str, char delimiter){
            VECTOR<std::string> token_vec(1);
            int length = str.size();
            int s = 0;

            for(int e = 0; e < length; ++e){
                //if hit a delimiter, add the token to the list, and increment start
                if(str[e] == delimiter){
                    token_vec.Append(str.substr(s,e-s));
                    e++;
                    s = e;
                    
                }
            }
            return token_vec;
        }

};