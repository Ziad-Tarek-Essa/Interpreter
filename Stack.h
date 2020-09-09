#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct
{
    int top;
    float X[20];
} stack;

void intialize (stack *s);

float pop(stack *s);

void push (stack *s, float value);

float top (stack *s);

int isempty(stack*s);

int isfull(stack *s);


#endif // STACK_H_INCLUDED
