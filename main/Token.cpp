#include "Token.h"

Token::Token(string type, string value){
        this->type = type;
        this->value = value;
    }
string Token::get_type(){
        return type;
    }
void Token::set_type(string type){
        this->type = type;
    }
string Token::get_token(){
        return type + " : " + value;
    }

