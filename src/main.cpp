#include <iostream>
#include <Lexer.h>
#include <vector>
#include <CLI11.hpp>
int main(){
    
    while (true){
        std::string chr;
        std::cin>>chr;
        Lexer a(chr.c_str());
        while (true){
            flags::Token tkn = a.get_token();
            if (tkn.type == flags::EXPRESSION_NPOS){
                break;
            }
            if (tkn.data == ""){
                tkn.data = "?";
            }
            auto [j, b , c , d , e] = tkn;
            std::cout<<j << "\t" << b << "\t" << c << "\n\t" << d << "\t" << e << "\n";
        }
    }
}