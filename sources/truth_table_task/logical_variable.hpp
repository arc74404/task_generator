#ifndef LOGICAL_VARIABLE_HPP
#define LOGICAL_VARIABLE_HPP

#include <algorithm>

class LogicalVariable
{
private:
    char m_symbol;

    bool m_is_using;

public:
    int count;
    
    LogicalVariable();

    char getSymbol() const noexcept;

    void setSymbol(char symb);

    void swapSymbol(LogicalVariable& other);
};

#endif // LOGICAL_VARIABLE_HPP