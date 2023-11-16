#include "truth_table_task/logical_variable.hpp"

LogicalVariable::LogicalVariable()
{
    m_symbol   = 'a';
    m_is_using = false;
    count      = 0;
}

char
LogicalVariable::getSymbol() const noexcept
{
    return m_symbol;
}

void
LogicalVariable::setSymbol(char symb)
{
    m_symbol = symb;
}

void
LogicalVariable::swapSymbol(LogicalVariable& other)
{
    std::swap(this->m_symbol, other.m_symbol);
}