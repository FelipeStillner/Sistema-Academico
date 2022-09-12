#include "Principal.h"
#include <iostream>
#include <string>

Principal::Principal()
{

    Executar();
}

Principal::~Principal()
{
}

void Principal::Executar()
{   
    

    //Testes
    Aluno Felipe(8, 6, 2004, "FELIPE");
    Universidade UTFPR("UTFPR");
    Felipe.createUniAlun(&UTFPR);
    std::cout << Felipe.getUniAlun()->getUniversidade()->getNome();
    //--------

    Menu();  

    deleteLists();
}

void Principal::Menu()
{
    int id = 0;
    int n = 1;
    char*c = new char[30];
    while (n != 0)
    {
        std::cout << "0 - Sair\n1 - Criar\n2 - print\n";
        std::cin >> n;

        if (n == 0) // sair
        {
            std::cout << "Saindo";
        }
        else if (n == 1)// Criar
        {
            std::cout << "0 - Sair\n1 - Aluno\n2 - Universidade\n3 - Departamento\n4 - Disciplina\n";
            std::cin >> n;
            if (n == 0) // sair
            {
                std::cout << "Saindo";
            }
            else if(n == 1)// Aluno
            {
                int d, m, a;
                std::cout << "Nome:";
                scanf("%s", c);
                std::cout << "Dia Nascimento:";
                std::cin >> d;
                std::cout << "Mes Nascimento:";
                std::cin >> m;
                std::cout << "Ano Nascimento:";
                std::cin >> a;
                Aluno *al = new Aluno(d, m, a, c);
                std::cout << "RA:";
                std::cin >> n;
                al->setRA(n);
                al->setId(id);
                id++;
                alunos.push_back(al);
            }
            else if(n == 2)// Universidade
            {
                std::cout << "Nome:";
                scanf("%s", c);
                Universidade *u = new Universidade(c);
                u->setId(id);
                id++;
                universidades.push_back(u);
            }
            else if(n == 3)// Departamento
            {
                int k1 = 0;
                std::cout << "Nome:";
                scanf("%s", c);
                Departamento *d = new Departamento(c);
                std::cout << "Universidade do departamento:" << std::endl;
                std::list<Universidade*>::iterator j;
                j = universidades.begin();
                while (j != universidades.end())
                {
                    std::cout << k1 << " - " <<(*j)->getNome() << std::endl;
                    j++;
                    k1++;
                }
                std::cin >> k1;
                j = universidades.begin();
                for (int k = 0; k < n; k++)
                {
                    j++;
                }

                d->setUniv(*j);
                d->setId(id);
                id++;
                departamentos.push_back(d);
            }
            else if(n == 4)// Disciplina
            {
                int k1 = 0;
                std::cout << "Nome:";
                scanf("%s", c);
                Disciplina *d = new Disciplina(c);
                std::cout << "Departamento da Disciplina:" << std::endl;
                std::list<Departamento*>::iterator j;
                j = departamentos.begin();
                while (j != departamentos.end())
                {
                    std::cout << k1 << " - " <<(*j)->getNome() << std::endl;
                    j++;
                    k1++;
                }
                std::cin >> k1;
                j = departamentos.begin();
                for (int k = 0; k < n; k++)
                {
                    j++;
                }

                d->createDepDisc(*j);
                d->setId(id);
                id++;
                disciplinas.push_back(d);
            }
            else
            {
                std::cout << "Opcao invalida";
            }
        }
        else if (n == 2) // print
        {
            std::cout << "0 - Sair\n1 - Alunos\n2 - Universidades \n3 - Departamentos\n";
            std::cin >> n;
            if (n == 0) // sair
            {
                std::cout << "Saindo";
            }
            else if(n == 1)// Aluno
            {
                std::list<Aluno*>::iterator j;
                j = alunos.begin();
                while (j != alunos.end())
                {
                    std::cout << (*j)->getNome() << std::endl;
                    j++;
                }
            }
            else if(n == 2)// Universidade
            {
                std::list<Universidade*>::iterator j;
                j = universidades.begin();
                while (j != universidades.end())
                {
                    std::cout << (*j)->getNome() << std::endl;
                    j++;
                }
            }
            else if(n == 3)// Departamento
            {
                std::list<Departamento*>::iterator j;
                j = departamentos.begin();
                while (j != departamentos.end())
                {
                    std::cout << (*j)->getNome() << std::endl;
                    j++;
                }
            }
            else
            {
                std::cout << "Opcao invalida";
            }
        }
        else
        {
            std::cout << "Opcao invalida";
        }
    }
}

void Principal::deleteLists()
{
    alunos.clear();
    universidades.clear();
    departamentos.clear();
    disciplinas.clear();
    professores.clear();
}
