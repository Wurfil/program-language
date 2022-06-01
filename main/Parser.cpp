#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class PairLecsem {
public:
    String tokenLeft;
    String tokenRight;

    PairLecsem(String token1,
               String token2) {
        this.tokenLeft = token1;
        this.tokenRight = token2;
    }
}

class Parser {
public:
    vector <PairLecsem> pairLecsems;

    Parser() {
        pairLecsems.push(PairLecsem("VAR", "ASSIGN"));
        pairLecsems.push(PairLecsem("ASSING_OP", "DIGIT"));
        pairLecsems.push(PairLecsem("ASSING_OP", "VAR"));
        pairLecsems.push(PairLecsem("ASSING_OP", "OPEN_BRACKET"));

        pairLecsems.push(PairLecsem("DIGIT", "OP"));

        pairLecsems.push(PairLecsem("OP", "DIGIT"));


        pairLecsems.push(PairLecsem("OP", "VAR"));

        pairLecsems.push(PairLecsem("VAR", "OP"));

        pairLecsems.push(PairLecsem("OP", "OPEN_BRACKET"));

        pairLecsems.push(PairLecsem("OPEN_BRACKET", "VAR"));
        pairLecsems.push(PairLecsem("OPEN_BRACKET", "DIGIT"));

        pairLecsems.push(PairLecsem("VAR", "CLOSE_BRACKET"));
        pairLecsems.push(PairLecsem("DIGIT", "CLOSE_BRACKET"));

        pairLecsems.push(PairLecsem("CLOSE_BRACKET", "OP"));


        pairLecsems.push(PairLecsem("CLOSE_BRACKET", "END"));
        pairLecsems.push(PairLecsem("DIGIT", "END"));
        pairLecsems.push(PairLecsem("VAR", "END"));

        pairLecsems.push(PairLecsem("END", "VAR"));
        pairLecsems.push(PairLecsem("END", "PRINT"));

        pairLecsems.push(PairLecsem("PRINT", "VAR"));
        pairLecsems.push(PairLecsem("PRINT", "DIGIT"));


        pairLecsems.push(PairLecsem("IF", "OPEN_BRACKET"));
        pairLecsems.push(PairLecsem("OPEN_BRACKET", "DIGIT"));
        pairLecsems.push(PairLecsem("OPEN_BRACKET", "VAR"));
        pairLecsems.push(PairLecsem("VAR", "LESS"));
        pairLecsems.push(PairLecsem("VAR", "MORE"));
        pairLecsems.push(PairLecsem("LESS", "VAR"));
        pairLecsems.push(PairLecsem("LESS", "DIGIT"));
        pairLecsems.push(PairLecsem("DIGIT", "LESS"));
        pairLecsems.push(PairLecsem("DIGIT", "MORE"));
        pairLecsems.push(PairLecsem("MORE", "DIGIT"));
        pairLecsems.push(PairLecsem("MORE", "VAR"));
        pairLecsems.push(PairLecsem("DIGIT", "CLOSE_BRACKET"));
        pairLecsems.push(PairLecsem("CLOSE_BRACKET", "OPEN_BRACE"));
        pairLecsems.push(PairLecsem("VAR", "CLOSE_BRACKET"));

        pairLecsems.push(PairLecsem("OPEN_BRACE", "KEY_WORD_VAR"));
        pairLecsems.push(PairLecsem("OPEN_BRACE", "VAR"));

        pairLecsems.push(PairLecsem("DIGIT", "CLOSE_BRACE"));
        pairLecsems.push(PairLecsem("VAR", "CLOSE_BRACE"));
        pairLecsems.push(PairLecsem("CLOSE_BRACE", "END"));
        pairLecsems.push(PairLecsem("END", "IF"));


        pairLecsems.push(PairLecsem("WHILE", "OPEN_BRACKET"));
        pairLecsems.push(PairLecsem("END", "WHILE"));

    }


public:
    bool parse(vector <Token> tokenList) {
        if (tokenList == null) {
            return true;
        }

        for (int i = 0; i <= tokenList.size() - 2; i++) {
            if (isRightPairLexem(tokenList[i], tokenList[i + 1]) == false) {
                return false;
            }
        }
        int openBrackets = 0;
        int closeBrackets = 0;

        for (Token token: tokenList) {
            switch (token.get_type()) {
                case "OPEN_BRACKET": {
                    openBrackets++;
                    break;
                }
                case "CLOSE_BRACKET": {
                    closeBrackets++;
                    break;
                }
                default:
                    break;
            }

            if (openBrackets == closeBrackets) {
                return true;
            } else {
                return false;
            }
        }
    }

private:
    bool isRightPairLecsem(Token tokenLeft, Token tokenRight) {
        for (PairLecsem p: pairLecsems) {
            if ((tokenRight.get_type() == p.tokenRight) && (tokenLeft.get_type() == p.tokenLeft)) {
                return true;
            }
        }
        return false;
    }
}

