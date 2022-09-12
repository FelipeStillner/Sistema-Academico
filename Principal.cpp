#include "Principal.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Principal::Principal()
{
    Executar();
}

Principal::~Principal()
{
}

void Principal::Executar()
{   
    Recuperar();

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
        std::cout << "0 - Sair\n1 - Criar\n2 - Print\n3 - Salvar\n";
        std::cin >> n;

        if (n == 0) // sair
        {
            menuSair();
        }
        else if (n == 1)// Criar
        {
            menuCriar();
        }
        else if (n == 2) // Print
        {
            menuPrint();
        }
        else if (n == 3) // Salvar
        {
            menuSalvar();
        }
        else
        {
            menuInvalido();
        }
    }
    delete[] c;
}

void Principal::deleteLists()
{
    alunos.clear();
    universidades.clear();
    departamentos.clear();
    disciplinas.clear();
    professores.clear();
}

void Principal::menuCriar()
{
    int n;
    char*c = new char[30];
    std::cout << "0 - Sair\n1 - Aluno\n2 - Universidade\n3 - Departamento\n4 - Disciplina\n";
    std::cin >> n;
    if (n == 0) // sair
    {
        menuSair();
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
        alunos.push_back(al);
    }
    else if(n == 2)// Universidade
    {
        std::cout << "Nome:";
        scanf("%s", c);
        Universidade *u = new Universidade(c);
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
        disciplinas.push_back(d);
    }
    else
    {
        menuInvalido();
    }
    delete[] c;
}

void Principal::menuSair()
{
    std::cout << "Saindo";
}

void Principal::menuSalvar()
{
    SalvaAlunos();
    SalvaUniversidades();
    SalvaDepartamentos();
    SalvaDisciplinas();
}

void Principal::Recuperar()
{
    RecuperaAlunos();
    RecuperaUniversidades();
    RecuperaDepartamentos();
    RecuperaDisciplinas();
}

void Principal::menuPrint()
{
    int n;
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
        menuInvalido();
    }
}

void Principal::menuInvalido()
{
    std::cout << "Opcao invalida";
}

void Principal::SalvaAlunos()
{
    ofstream Gravador("alunos.dat", ios::out);

    if(!Gravador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    std::list<Aluno*>::iterator j;
    j = alunos.begin();
    for (int k = 0; k < alunos.size(); k++)
    {
        
        Gravador << (*j)->getId ( ) << ' ' << (*j)->getRA ( ) << ' ' << (*j)->getNome ( ) << endl;
        j++;
    }
    Gravador.close();
}

void Principal::RecuperaAlunos()
{
    ifstream Recuperador("alunos.dat", ios::in);

    if(!Recuperador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (!Recuperador.eof())
    {
        Aluno *aluno;
        int id;
        int RA;
        char nome[30];

        Recuperador >> id >> RA >> nome;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            aluno = new Aluno;
            aluno->setId ( id ); 
            aluno->setRA ( RA ); 
            aluno->setNome ( nome );
            alunos.push_back(aluno);
        }
    }
    Recuperador.close();
}

void Principal::SalvaUniversidades()
{
    ofstream Gravador("universidades.dat", ios::out);

    if(!Gravador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    std::list<Universidade*>::iterator j;
    j = universidades.begin();
    for (int k = 0; k < universidades.size(); k++)
    {
        
        Gravador << (*j)->getId ( ) << ' ' << ' ' << (*j)->getNome ( ) << endl;
        j++;
    }
    Gravador.close();
}

void Principal::RecuperaUniversidades()
{
    ifstream Recuperador("universidades.dat", ios::in);

    if(!Recuperador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (!Recuperador.eof())
    {
        Universidade *universidade;
        int id;
        char nome[30];

        Recuperador >> id >> nome;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            universidade = new Universidade;
            universidade->setId ( id ); 
            universidade->setNome ( nome );
            universidades.push_back(universidade);
        }
    }
    Recuperador.close();
}

void Principal::SalvaDepartamentos()
{
    ofstream Gravador("departamentos.dat", ios::out);

    if(!Gravador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    std::list<Departamento*>::iterator j;
    j = departamentos.begin();
    for (int k = 0; k < departamentos.size(); k++)
    {
        
        Gravador << (*j)->getId ( ) << ' ' << ' ' << (*j)->getNome ( ) << endl;
        j++;
    }
    Gravador.close();
}

void Principal::RecuperaDepartamentos()
{
    ifstream Recuperador("departamentos.dat", ios::in);

    if(!Recuperador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (!Recuperador.eof())
    {
        Departamento *departamento;
        int id;
        char nome[30];

        Recuperador >> id >> nome;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            departamento = new Departamento;
            departamento->setId ( id ); 
            departamento->setNome ( nome );
            departamentos.push_back(departamento);
        }
    }
    Recuperador.close();
}

void Principal::SalvaDisciplinas()
{
    ofstream Gravador("disciplinas.dat", ios::out);

    if(!Gravador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    std::list<Disciplina*>::iterator j;
    j = disciplinas.begin();
    for (int k = 0; k < disciplinas.size(); k++)
    {
        
        Gravador << (*j)->getId ( ) << ' ' << ' ' << (*j)->getNome ( ) << endl;
        j++;
    }
    Gravador.close();
}

void Principal::RecuperaDisciplinas()
{
    ifstream Recuperador("disciplinas.dat", ios::in);

    if(!Recuperador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (!Recuperador.eof())
    {
        Disciplina *disciplina;
        int id;
        char nome[30];

        Recuperador >> id >> nome;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            disciplina = new Disciplina;
            disciplina->setId ( id ); 
            disciplina->setNome ( nome );
            disciplinas.push_back(disciplina);
        }
    }
    Recuperador.close();
}

