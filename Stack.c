#include "Stack.h"

void intialize (stack *s)
{
    s->top=0;
}

float pop(stack *s)
{
    return s->X[--s->top];
}

void push (stack *s, float value)
{
    s->X[s->top++]=value;
}

float top (stack *s)
{
    int x=s->top-1;
    return s->X[x];
}

int isempty(stack*s)
{
    return s->top==0? 1:0;

}

int isfull(stack *s)
{
    return s->top==20? 1:0;
}
