#ifndef PROGRAM_LANGUAGE_TOKEN_H
#define PROGRAM_LANGUAGE_TOKEN_H
#include <string>
using namespace std;

class Token {
private:
    string value;
    string type;
public:
    Token(string, string);

    string get_type();

    void set_type(string);

    string get_token();
};
#endif
