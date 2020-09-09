#include "Infix.h"

float evaluate(char *infix)
{
    char *postfix = malloc(strlen(infix)*2*sizeof(char));
    int x=strlen(infix);
    infixTopostfix(infix,postfix,x);
    return evaluate_postfix(postfix);
}

int value(char x)
{
    if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    return 0;
}

void infixTopostfix(char* infix, char* postfix,int x)
{
    int i,j=0;
    stack s;
    intialize(&s);
    for(i=0,j=0; i<x ; i++)
    {
        if(infix[i]>='0')
        {
            postfix[j]='(';
            j++;
            for(; (!value(infix[i]))&&(infix[i]!=')')&&(infix[i]!='\0'); i++)
            {
                postfix[j]=infix[i];
                j++;
            }
            postfix[j]=')';
            j++;
            i--;
        }
        else if(infix[i]=='(')
        {
            push(&s,infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top(&s)!='(')
            {
                postfix[j]=pop(&s);
                j++;
            }
            pop(&s);
        }
        else if(infix[i]<'0')
        {
            while((value(infix[i])<=value(top(&s)))&&(!isempty(&s)))
            {
                postfix[j]=pop(&s);
                j++;
            }
            push(&s,infix[i]);
        }
    }
    while(!isempty(&s))
    {
        postfix[j]=pop(&s);
        j++;
    }
    postfix[j]=0;
}

float evaluate_postfix(char* postfix)
{
    int i,j;
    float p,r;
    char number[10];
    stack s;
    intialize(&s);
    for(i=0; postfix[i]!='\0'; i++)
    {
        switch (postfix[i])
        {
        case '+':
            r=pop(&s);
            p=pop(&s);
            push(&s,r+p);
            break;
        case '/':
            r=pop(&s);
            p=pop(&s);
            push(&s,p/r);
            break;
        case '*':
            r=pop(&s);
            p=pop(&s);
            push(&s,r*p);
            break;
        case '-':
            r=pop(&s);
            p=pop(&s);
            push(&s,p-r);
            break;
        default:
            i++;
            for(j=0; (postfix[i]!=')')&&(postfix[i]!='\0'); i++)
            {
                number[j]=postfix[i];
                j++;
            }
            number[j]='\0';
            push(&s,atof(number));
        }
    }
    return pop(&s);
}
