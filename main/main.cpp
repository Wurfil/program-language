#include <iostream>
#include "Lecser.h"
#include <fstream>
#include "Parser.cpp"

int main(int argc, char *argv[]) {

    std::fstream file;
    file.open("text.txt");

    if (file.is_open()) {
        std::string line;
        while (!file.eof()) {
            std::getline(file, line);
            Lexer::run(line);
        }

        std::list<Token>::iterator it_tokens = Lexer::get_list_token().begin();

        for (;it_tokens != Lexer::get_list_token().end(); ++it_tokens) {
            std::cout << *it_tokens << '\n';
        }

//        Parser Parser(Lexer::get_list_token());
//
//        try {
//            if (!Parser.check()) {
//                std::cout << "ошибка в парсере\n";
//            }
//        } catch (std::string exception_string) {
//            std::cout << "error " << exception_string << '\n';
//        }
//    } else {
//        std::cout << "файл c кодом не найден\n";
//    }n


    return 0;