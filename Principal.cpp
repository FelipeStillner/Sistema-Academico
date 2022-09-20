#include "Principal.h"

using namespace std;

Principal::Principal()
{
    contAlunos = 0;
    contDepartamentos = 0;
    contDisciplinas = 0;
    contUniversidades = 0;
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
        std::cout << "0 - Sair\n1 - Criar\n2 - Print\n3 - Salvar\n4 - Cadastrar\n";
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
        else if (n == 4) // Cadastrar
        {
            menuCadastrar();
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
    pessoas.clear();
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
        al->setId(contAlunos);
        alunos.push_back(al);
        contAlunos++;
    }
    else if(n == 2)// Universidade
    {
        std::cout << "Nome:";
        scanf("%s", c);
        Universidade *u = new Universidade(c);
        u->setId(contUniversidades);
        universidades.push_back(u);
        contUniversidades++;
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
        d->setId(contDepartamentos);
        departamentos.push_back(d);
        contDepartamentos++;
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

        d->setDepartamento(*j);
        (*j)->setDisciplina(d);
        d->setId(contDisciplinas);
        disciplinas.push_back(d);
        contDisciplinas++;
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

void Principal::menuCadastrar()
{
    int n;
    std::cout << "0 - Sair\n1 - Aluno em Disciplina\n";
    std::cin >> n;

    if (n == 0) // sair
    {
        menuSair();
    }
    else if (n == 1) // Aluno em Disciplina
    {
        int k = 0;
        std::cout << "Aluno:" << std::endl;
        std::list<Aluno*>::iterator j;
        j = alunos.begin();
        while (j != alunos.end())
        {
            std::cout << k << " - " <<(*j)->getNome() << std::endl;
            j++;
            k++;
        }
        std::cin >> n;
        j = alunos.begin();
        for (k = 0; k < n; k++)
        {
            j++;
        }

        k = 0;

        std::cout << "Disciplina:" << std::endl;
        std::list<Disciplina*>::iterator i;
        i = disciplinas.begin();
        while (i != disciplinas.end())
        {
            std::cout << k << " - " <<(*i)->getNome() << std::endl;
            i++;
            k++;
        }
        std::cin >> n;
        i = disciplinas.begin();
        for (k = 0; k < n; k++)
        {
            i++;
        }

        (*j)->createDiscAlun(*i);

        std::list<DiscAlun*>::iterator l;
        l = (*j)->getDiscAlun().begin();
        while (l != (*j)->getDiscAlun().end())
        {
            if (((*l)->getAluno()->getId() == (*j)->getId()) && ((*l)->getDisciplina()->getId() == (*i)->getId()))
            {
                cout << "Nota1:" << endl;
                cin >> k;
                (*l)->setNota1(k);
                cout << "Nota2:" << endl;
                cin >> k;
                (*l)->setNota2(k);
            }
            l++;
        }
    }
    else
    {
        menuInvalido();
    }
}

void Principal::menuSalvar()
{
    SalvaAlunos();
    SalvaUniversidades();
    SalvaDepartamentos();
    SalvaDisciplinas();
    //SalvaDiscAlun();
}

void Principal::Recuperar()
{
    RecuperaUniversidades();
    RecuperaDepartamentos();
    RecuperaDisciplinas();
    RecuperaAlunos();
    //RecuperaDiscAlun();
}

void Principal::menuPrint()
{
    int n;
    std::cout << "0 - Sair\n1 - Alunos\n2 - Universidades \n3 - Departamentos\n4 - Disciplinas\n5 - Alunos em disciplinas\n";
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
    else if(n == 4)// Disciplina
    {
        std::list<Disciplina*>::iterator j;
        j = disciplinas.begin();
        while (j != disciplinas.end())
        {
            std::cout << (*j)->getNome() << std::endl;
            j++;
        }
    }
    else if(n == 5)// AlunDisc
    {
        int k, l;
        list<Disciplina*>::iterator j;
        list<DiscAlun*>::iterator i;
        j = disciplinas.begin();
        for (k = 0; k < contDisciplinas; k++)
        {
            i = (*j)->getDiscAlun().begin();
            for (l = 0; l < (*j)->getDiscAlun().size(); l++)
            {
                cout  << (*j)->getNome()  << " " /*<< (*i)->getAluno()->getNome()*/ << std::endl;
                i++;
            }
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
            contAlunos++;
        }
    }
    alunos.pop_back();
    contAlunos--;
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
            contUniversidades++;
        }
    }
    universidades.pop_back();
    contUniversidades--;
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
        Gravador << (*j)->getId ( ) << ' ' << (*j)->getNome ( ) << ' ' << (*j)->getUniv()->getId() << endl;
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
        int id, uId, k = 0;
        char nome[30];

        Recuperador >> id >> nome >> uId;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            departamento = new Departamento;
            departamento->setId ( id ); 
            departamento->setNome ( nome );

            std::list<Universidade*>::iterator j;
            j = universidades.begin();
            while (j != universidades.end())
            {
                if ((*j)->getId() == uId)
                {
                    departamento->setUniv(*j);
                    break;
                }
                j++;
            }

            departamentos.push_back(departamento);
            contDepartamentos++;
        }
    }
    departamentos.pop_back();
    contDepartamentos--;
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
        
        Gravador << (*j)->getId ( ) << ' ' << (*j)->getNome ( ) << ' ' << (*j)->getDepartamento()->getId() << endl;
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
        int id, dId;
        char nome[30];

        Recuperador >> id >> nome >> dId;

        if ( 0 != strcmp ( nome, "" ) ) 
        {
            disciplina = new Disciplina;
            disciplina->setId ( id ); 
            disciplina->setNome ( nome );

            std::list<Departamento*>::iterator j;
            j = departamentos.begin();
            while (j != departamentos.end())
            {
                if ((*j)->getId() == dId)
                {
                    disciplina->setDepartamento(*j);
                    (*j)->setDisciplina(disciplina);
                    break;
                }
                j++;
            }

            disciplinas.push_back(disciplina);
            contDisciplinas++;
        }
    }
    disciplinas.pop_back();
    contDisciplinas--;
    Recuperador.close();
}

void Principal::SalvaDiscAlun()
{
    int k;
    ofstream Gravador("discAluns.dat", ios::out);

    if(!Gravador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }
    std::list<Disciplina*>::iterator i;
    std::list<DiscAlun*>::iterator j;
    i = disciplinas.begin();
    for (k = 0; k < disciplinas.size(); k++)
    {
        j = (*i)->getDiscAlun().begin();
        for (int l = 0; l < (*i)->getDiscAlun().size(); l++)
        {
            Gravador << (*j)->getAluno()->getId() << ' ' << (*i)->getId() << ' ' << (*j)->getNota1() << ' ' << (*j)->getNota2() << endl;
            j++;
        }
        i++;
    }
    Gravador.close();
}

void Principal::RecuperaDiscAlun()
{
    ifstream Recuperador("discAluns.dat", ios::in);

    if(!Recuperador)
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (!Recuperador.eof())
    {
        int AlunId, DiscId, nota1, nota2;
        Aluno* a = NULL;
        Disciplina* d = NULL;

        Recuperador >> AlunId >> DiscId >> nota1 >> nota2;

        std::list<Disciplina*>::iterator j;
        j = disciplinas.begin();
        for (int k = 0; k < disciplinas.size(); k++)
        {
            if ((*j)->getId() == DiscId)
            {
                d = *j;
                break;
            }
            j++;
        }

        std::list<Aluno*>::iterator i;
        i = alunos.begin();
        for (int k = 0; k < alunos.size(); k++)
        {   
            if((*i)->getId() == AlunId)
            {
                a = *i;
                break;
            }
            i++;
        }

        if (a == NULL || d == NULL)
        {
            cout << "Erro";
        }
        else
        {
            (a)->createDiscAlun(d);
            int k, l;
            list<Disciplina*>::iterator j;
            j = disciplinas.begin();
            for (k = 0; k < contDisciplinas; k++)
            {
                list<DiscAlun*>::iterator i;
                i = (*j)->getDiscAlun().begin();
                for (l = 0; l < (*j)->getDiscAlun().size(); l++)
                {
                    a->getDiscAlun(0)->setNota1(nota1);
                    a->getDiscAlun(0)->setNota2(nota2);
                    i++;
                }
                j++;
            }
        }
    }
    Recuperador.close();
}
