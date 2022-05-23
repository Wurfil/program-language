#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "TokenValue.cpp"
using namespace std;

int main() {
    TokenValue lexems;
    cout << "Enter string\n";
    string enter_str, work_str = "";
    getline(cin, enter_str);

    for (int i = 0; i < enter_str.length(); i++) {
        if (enter_str[i] == ' ') {
            enter_str.erase(i, 1);
            i--;
        }
    }

    vector <Token> token_list;
    string temp;
    temp.clear();
    for (int i = 0; i < enter_str.length(); i++) {
        temp += enter_str[i];
        for (lexems.it_hash_map = lexems.hash_map.begin(); lexems.it_hash_map != lexems.hash_map.end(); lexems.it_hash_map++) {
            smatch match;
            while (regex_match(temp, match, lexems.it_hash_map->second)) {
                i++;
                temp += enter_str[i];
            }
            if (regex_search(temp, match, lexems.it_hash_map->second)) {
                token_list.push_back(Token(lexems.it_hash_map->first, match[0]));
                temp.clear();
                i--;
            }
        }
    }
    for (int i = 0; i < token_list.size(); i++) {
        cout << token_list[i].get_token() << endl;
    }

    return 0;
}