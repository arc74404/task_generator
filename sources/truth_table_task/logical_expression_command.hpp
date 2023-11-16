#include "truth_table_task/logical_expression.hpp"

enum class LogicalExpression::Command
{
    ADD_EXPRESSION = 0,
    ADD_LETTER     = 1,
    ADD_OPERATOR   = 2,
    CR_4_VAR       = 3,
    CR_3_VAR       = 4,
    OPEN_BRACKETS  = 5,
    CLOSE_BRACKETS  = 6
};