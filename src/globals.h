#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>
#include <cmath>

typedef enum OPERATOR {
    ADD = 1,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    SIN,
    COS,
    TAN,
    SQRT,
    LOG,
    LN,
    FACTORIAL,
    INVERSE,
    COMPARE,
    QUIT
} OPERATOR;

inline const double pi = 3.14159265358979323846;
inline const double e = 2.71828182845904523536;
inline double operand_1 = 0;
inline double operand_2 = 0;
inline double result = 0;
inline OPERATOR op = ADD;

#endif // GLOBALS_H