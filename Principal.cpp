#include "Principal.h"
#include <iostream>

Principal::Principal()
{

    Executar();
}

Principal::~Principal()
{
}

void Principal::Executar()
{
    Universidade UTFPR("UTFPR");
    UTFPR.setId(1);

    Departamento Dainf("Dainf");
    Dainf.setId(2);
    Dainf.setUniv(&UTFPR);
    UTFPR.setDepartamento(&Dainf);

    Disciplina TecProg("Tecnicas de Programacao");
    TecProg.setDepartamento(&Dainf);
    TecProg.setId(3);
    Dainf.setDisciplina(&TecProg);
    Disciplina ED1("Estruturas de dados 1");
    ED1.setDepartamento(&Dainf);
    ED1.setId(4);
    Dainf.setDisciplina(&ED1);

    Professor Simao;
    Simao.setDep(&Dainf);
    Simao.setUniv(&UTFPR);
    Simao.setId(5);
    
    Aluno Felipe(8, 6, 2004, "Felipe Stillner Eufranio");
    Felipe.calculaIdade(29, 8, 2022);
    Felipe.setDep(&Dainf);
    Felipe.setUniv(&UTFPR);
    Felipe.setRA(2449021);
    Felipe.setId(6);
    Felipe.createCursar(&TecProg);
    Felipe.createCursar(&ED1);

    std::cout <<  Felipe.getCursar(1)->getDisciplina()->getNome();

    Felipe.~Aluno();
    Simao.~Professor();
    TecProg.~Disciplina();
    Dainf.~Departamento();
    UTFPR.~Universidade();
}

void Principal::Menu()
{
    char n = -1;
    std::cout << "1 - Criar\n2 - Sair\n";
    n = getchar(); 
    switch (n)
    {
    case 1:
        std::cout << "1 - Aluno\n2 - \n";
        n = getchar(); 
        switch (n)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
        break;

    case 2:
        /* code */
        break;
    
    default:
        std::cout << "Opcao invalida";
        break;
    }
}