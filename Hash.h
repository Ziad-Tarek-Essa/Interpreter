#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <string.h>

typedef struct{
    char *variable;
    float value;
    int is_full; // for place availability
}Hash;

unsigned int sdbm(char *str);

void addH(Hash *h,char *variable,float value);

float getH(Hash *h,char *variable);

void initializeH(Hash *h);

void RemoveSpaces(char* source);

void freeH(Hash *h);

#endif // HASH_H_INCLUDED
