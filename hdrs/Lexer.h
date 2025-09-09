#include <string_view>
#include <flags.h>
class Lexer{
public:
    Lexer(Lexer& other);
    Lexer(std::string_view v);
    flags::Token get_token();
    void consume_whitespace();
    bool next_step();
    bool can_be_next();
private:
    flags::Token make_single_char(flags::T_Type tkn);
    bool is_space(const char* x);
    std::string_view m_v;
    int m_pos = 0;
    const char* m_current_char=nullptr;

    unsigned int m_cline=0;
    unsigned int m_cchar=0;
};