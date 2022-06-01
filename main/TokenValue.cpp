#include <map>
#include <regex>

using namespace std;
class TokenValue {
public:
    map <string, regex> hash_map;
    map<string, regex>::iterator it_hash_map = hash_map.begin();
    TokenValue() {
        hash_map["IF"] = regex(("(IF)"));
        hash_map["PRINT"] = regex(("(PRINT)"));
        hash_map["WHILE"] = regex(("(WHILE)"));
        hash_map["VAR"] = regex(R"([a-z][a-z0-9]*)");
        hash_map["NUM"] = regex(R"(0|([1-9][0-9]*))");
        hash_map["OP"] = regex(R"(\*|\/|\-|\+)");
        hash_map["ASSING_OP"] = regex(R"(=)");
        hash_map["END"] = regex(("(;)"));
        hash_map["OPEN_BRACKET"] = regex(R"(\()");
        hash_map["CLOSE_BRACKET"] = regex(R"(\))");
        hash_map["OPEN_BRACE"] = regex(R"(\{)");
        hash_map["CLOSE_BRACE"] = regex(R"(\})");
        hash_map["MORE"] = regex(("(>)"));
        hash_map["LESS"] = regex(("(<)"));

    }
};
