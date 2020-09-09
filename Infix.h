#ifndef INFIX_H_INCLUDED
#define INFIX_H_INCLUDED
#include "Stack.h"
#include <string.h>
#include <stdlib.h>

int value(char x);

void infixTopostfix(char* infix, char* postfix,int x);

float evaluate(char *infix);

float evaluate_postfix(char* postfix);

#endif // INFIX_H_INCLUDED
