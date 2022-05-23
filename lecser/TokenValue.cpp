#include <map>
#include <regex>
using namespace std;
class TokenValue {
public:
    map <string, regex> hash_map;
    map<string, regex>::iterator it_hash_map = hash_map.begin();
    TokenValue() {
        hash_map["VAR"] = regex(R"([a-z][a-z0-9]*)");
        hash_map["NUM"] = regex(R"(0|([1-9][0-9]*))");
        hash_map["OP"] = regex(R"(\*|\/|\-|\+)");
        hash_map["ASSING_OP"] = regex(R"(=)");
    }
};
