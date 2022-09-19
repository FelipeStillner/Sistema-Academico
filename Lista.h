#pragma once

#include "Elemento.h"
#include <iostream>

using namespace std;

template<class TIPO>
class Lista
{
private:
  Elemento<TIPO>* pPrimeiro;
  Elemento<TIPO>* pAtual;
public:
  Lista(/* args */);
  ~Lista();
  void inicializa ( );
  bool incluaElemento ( Elemento<TIPO>* pElemento ); 
  bool incluaInfo ( TIPO* pInfo, char* nome = "" );
  void listeInfos ( );
};


template<class TIPO>
Lista<TIPO>::Lista(/* args */)
{
}

template<class TIPO>
Lista<TIPO>::~Lista()
{
}

template<class TIPO>
void Lista<TIPO>::inicializa()
{
  pPrimeiro = NULL;
  pAtual = NULL;
}

template<class TIPO>
bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
  if (NULL != pElemento) 
  {
    if (NULL == pPrimeiro) 
    {
      pPrimeiro = pElemento;
      pAtual = pPrimeiro; 
    }
    else 
    {
      pElemento->setAnterior ( pAtual ); 
      //pElemento->setProximo ( NULL ); 
      pAtual->setProximo ( pElemento ); 
      pAtual = pAtual->getProximo ( );
    }
    return true; 
  }
  else 
  {
    cout << " Erro, elemento nulo na lista. " << endl; 
    return false;
  }
}

template<class TIPO>
bool Lista<TIPO>::incluaInfo ( TIPO * pInfo, char* nome ) 
{
  if (NULL != pInfo) 
  {
    Elemento<TIPO>* pElemento = NULL; 
    pElemento = new Elemento<TIPO>(); 
    pElemento->setNome ( nome ); 
    pElemento->setInfo ( pInfo ); 
    incluaElemento ( pElemento );
    return true; 
  }
  else 
  {
    printf ( "Erro, elemento (informação) nulo(a) na lista. \n" );
    return false;
  }
}
template<class TIPO>
void Lista<TIPO>::listeInfos ( ) 
{
  Elemento<TIPO>* pAux; pAux = pPrimeiro;
  if (NULL != pPrimeiro ) 
  {
    while ( NULL != pAux ) 
    {
      printf ( " Elemento na lista %s \n", pAux->getNome() );
      pAux = pAux->getProximo();
   }
  } 
}