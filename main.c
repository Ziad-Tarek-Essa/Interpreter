#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include "Infix.h"

int main()
{
    Hash *h = (Hash *) malloc(500*sizeof(Hash));
    initializeH(h);
    char line[60],variable[30],Value[30];

    while(1)
    {
        printf("-> ");
        gets(line);
        int i=parse(h,line,variable,Value);
        if(i)
        {
            if(i == 1)
                printf("Invalid Character\n");
            else if(i == 2)
                printf("Left Hand side Should Only One Variable\n");
            else if(i == 3)
                printf("Missing = In The Expression\n");
            else if(i == 4)
                printf("Invalid Expressions\n");
            else if(i == 5)
            {
                printf("Bye");
                freeH(h);
                free(h);
                return 0;
            }
            continue;
        }
        addH(h,variable,evaluate(Value));
        printf("%s = %.2f\n",variable,getH(h,variable));
    }
}

int parse(Hash *h,char* line,char* variable,char* Value)
{
    RemoveSpaces(line);
    if(strcmp(line,"end") == 0)
        return 5;
    if(!isalpha(line[0]))
        return 1;
    int i,j = 0,k = 0,m = 0;
    for(i=0; line[i]!='=' && i<60; i++)
    {
        if(value(line[i])>0)
            return 2;
        variable[i]=line[i];
    }
    if(i==60)
        return 3;
    variable[i]='\0';
    i++;
    if(line[i]=='\0') return 4; //Space after '=' handled
    if(line[i]=='.'){m=0;Value[m++]='0'; for(k=i;line[k]!='\0';k++,m++)Value[m]=line[k];Value[m]='\0';} // the 0. problem at first
    else{
    for(; line[i]!='\0'; i++,j++)
    {
        if(line[i]=='.'){Value[j++]='0'; for(m=0,k=i;m<=2;k++,m++)Value[j++]=line[k];}// this for 0. problem in the middle
        else//
        Value[j] = line[i];
    }
    Value[j] = '\0';}

    char copy[strlen(Value)],var[10];
    strcpy(copy,Value);
    for(i=0,j=0,k=0; copy[i]!='\0'; i++)
    {
        if(isalpha(copy[i]))
        {
            for(m=0;(!value(copy[i]))&&(copy[i]!='\0')&&(copy[i]!=')'); i++,m++)
            {
                var[m]=copy[i];
            }
            var[m]='\0';
            i--;
            float val = getH(h,var);
            if(val == -9999)
                return 1;
            sprintf(var,"%.2f",val);
            for(m=0; m<strlen(var); m++,k++)
            {
                Value[k] = var[m];
            }
        }
        else
        {
            Value[k] = copy[i];
            k++;
        }
        if(value(copy[i])>0 && value(copy[i+1])>0)
            return 4;
        if(copy[i]=='(')
            j++;
        if(copy[i]==')')
            j--;
    }
    Value[k]='\0';
    if(j)
        return 4;
    return 0;
}
