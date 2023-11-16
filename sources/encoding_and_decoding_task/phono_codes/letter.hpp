#ifndef LETTER
#define LETTER

#include <string>

class Letter
{
private:
    char m_symbol;

    float m_chance;

    std::string m_code;

    bool visible;

public:
    Letter();

    void setSymbol(char ch);

    void setCode(std::string code);

    void setChance(float chance);

    float getChance() const;

    char getSymbol() const;

    std::string getCode() const;

    Letter& operator=(const Letter& other);

    bool IsVisible() const;

    void setVisibility(bool v);
};

#endif // LETTER