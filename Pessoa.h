#pragma once

#include <string.h>
#include <stdio.h>

class Pessoa
{
protected:
    int idade;
    int dian;
    int mesn;
    int anon;
    char nome[30];
    int id;
public:
    Pessoa();
    Pessoa(int d, int m, int a , char s[]);
    ~Pessoa();
    void calculaIdade(int dn, int mn, int an);
    int getIdade();
    char* getNome();
    void setNome(char s[]);
    int getId();
    void setId(int n);
};
