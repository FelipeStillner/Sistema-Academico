#include "Pessoa.h"

Pessoa::Pessoa()
{
    nome[0] = '\0';
    idade = -1;
}

Pessoa::Pessoa(int d, int m, int a, char s[])
{
    dian = d;
    mesn = m;
    anon = a;
    strcpy(nome, s);
    idade = -1;
}

Pessoa::~Pessoa()
{
}

void Pessoa::calculaIdade(int da, int ma, int aa)
{
    idade = aa - anon;
    if (ma < mesn)
    {
        idade--;
    }
    else if (ma == mesn)
    {
        if (da < dian)
        {
            idade--;
        }
    }
}

int Pessoa::getIdade()
{
    return idade;
}

char* Pessoa::getNome()
{
    return nome;
}

void Pessoa::setNome(char s[])
{
    strcpy(nome, s);
}

int Pessoa::getId()
{
    return id;
}

void Pessoa::setId(int n)
{
    id = n;
}
