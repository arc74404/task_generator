#include "letter.hpp"

Letter::Letter() : m_symbol(' '), m_code(""), m_chance(0), visible(false)
{
}

void
Letter::setSymbol(char ch)
{
    m_symbol = ch;
}

void
Letter::setCode(std::string code)
{
    m_code = code;
}

char
Letter::getSymbol() const
{
    return m_symbol;
}

std::string
Letter::getCode() const
{
    return m_code;
}

void
Letter::setChance(float chance)
{
    m_chance = chance;
}

float
Letter::getChance() const
{
    return m_chance;
}

Letter&
Letter::operator=(const Letter& other)
{
    this->m_chance = other.m_chance;

    this->m_code = other.m_code;

    this->m_symbol = other.m_symbol;

    return *this;
}

bool
Letter::IsVisible() const
{
    return visible;
}

void
Letter::setVisibility(bool v)
{
    visible = v;
}