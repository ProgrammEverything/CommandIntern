#include <iostream>
#include <Lexer.h>
#include <vector>
#include <CLI11.hpp>
#include <BinaryNode.h>
#include <Parser.h>
std::ostream& operator<<(std::ostream& os, const flags::Token& tkn){
    os<<"Token(data=\"" << tkn.data << "\", size=" << tkn.size << ", pos=(" << tkn.pos.current_line << "," << tkn.pos.current_char << "), type=" << tkn.type << ")";
    return os;
}

int main(){
    
    // while (true){
    //     std::string chr;
    //     std::cin>>chr;
    //     Lexer a(chr.c_str());
    //     while (true){
    //         flags::Token tkn = a.get_token();
    //         if (tkn.type == flags::EXPRESSION_NPOS){
    //             break;
    //         }
    //         if (tkn.data == ""){
    //             tkn.data = "?";
    //         }
    //         auto [j, b , c , d , e] = tkn;
    //         std::cout<<j << "\t" << b << "\t" << c << "\n\t" << d << "\t" << e << "\n";
    //     }
    // }
    Lexer x("2+5-1;3/3;");
    Parser l(x);
    auto block = l.parse_all();
    block->execute_all();
    return 0;
    
}