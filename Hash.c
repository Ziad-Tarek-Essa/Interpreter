#include "Hash.h"
#include <string.h>

unsigned int sdbm(char *str) //(a public-domain reimplementation of ndbm)
{
    unsigned int hash = 0;
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        hash = (str[i] + (hash << 6) + (hash << 16) - hash)%500;
    }
    return hash;
}

void addH(Hash *h,char *variable,float value)
{
    int index = sdbm(variable);
    while(index%500)
    {
        if(h[index].is_full == 1 && strcmp(variable,h[index].variable) == 0)
        {
            h[index].value = value;
        }
        if(h[index].is_full == 0)
        {
            h[index].variable = (char *) malloc(strlen(variable)*sizeof(char));
            strcpy(h[index].variable,variable);
            h[index].value = value;
            h[index].is_full = 1;
            return;
        }
        index++;
    }
}

float getH(Hash *h,char *variable)
{
    int index = sdbm(variable),oldindex=-1;
    while(oldindex != index)
    {
        if(h[index].is_full!=0) // element found
        {
            if(strcmp(h[index].variable,variable)==0)
                return h[index].value;
        }
        if(oldindex == -1)
            oldindex = index;
        index= ( index + 1 ) % 500;
    }
    return -9999; //not found
}

void initializeH(Hash *h)
{
    int i = 0;
    for(; i<500; i++)
    {
        h[i].is_full = 0;
        h[i].variable = NULL;
    }
}

void RemoveSpaces(char* source) ///Removes white spaces
{
    char* i = source;
    char* j = source;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

void freeH(Hash *h)
{
    int i = 0;
    for(; i<500; i++)
    {
        if(h[i].variable!=NULL)
            free(h[i].variable);
    }
}
