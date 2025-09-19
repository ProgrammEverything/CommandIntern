#include <Lexer.h>
#include <StmtNode.h>
#include <BinaryNode.h>
#include <vector>
#include <BlockNode.h>
class Parser {
public:
    Parser(Lexer& lexer);
    std::shared_ptr<StmtNode> parse_statement();
    std::shared_ptr<BlockNode> parse_block();
    std::shared_ptr<BlockNode> parse_all();
    std::vector<flags::Token> get_token_until(flags::T_Type t);
private:
    Lexer& m_lexer;
};