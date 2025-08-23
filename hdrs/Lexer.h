#include <string_view>
#include <flags.h>
class Lexer{
public:
    Lexer(std::string_view v);
    flags::Token get_token();
    void consume_whitespace();
    bool next_step();
private:
    bool is_space(const char* x);
    std::string_view m_v;
    int pos = 0;
    const char* current_char;
};