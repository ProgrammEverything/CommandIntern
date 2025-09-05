#include <iostream>
#include <Lexer.h>
#include <vector>
int main(){
    Lexer a("b=\"222\" + 2 + 2 - 1 - 1 - 1 + x - 2");
    std::vector<flags::Token> tkn{};
    while (true){
        flags::Token tkn = a.get_token();
        if (tkn.type == flags::EXPRESSION_NPOS ){
            break;
        }
        if (tkn.data == ""){
            tkn.data = "?";
        }
        std::cout<<tkn.data<<"\t"<<tkn.type<<"\t"<<tkn.size<<std::endl;
    }
}