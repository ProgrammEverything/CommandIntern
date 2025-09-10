#include <Lexer.h>
#include <StmtNode.h>
class Parser {
public:
    Parser(Lexer& lexer);
    StmtNode parse_statement();
private:
    Lexer& m_lexer;
};