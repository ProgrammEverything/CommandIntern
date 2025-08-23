#include <iostream>
#include <Lexer.h>
#include <vector>
int main(){
    Lexer a("13121+-");
    std::vector<flags::Token> tkn{};
    while (true){
        flags::Token x = a.get_token();
        if (x.type == flags::EXPRESSION_NPOS){
            std::cout<<"TYPE: "<<x.type<<" Value:"<<x.val<<std::endl;
            break;
        } else {
            std::cout<<"TYPE: "<<x.type<<" Value:"<<x.val<<std::endl;
            tkn.push_back(x);
        }
    }
    
}