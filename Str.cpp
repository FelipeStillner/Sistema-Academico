#include "Str.h"
#include <iostream>
#include <ostream>

MinhaString::MinhaString(const char* s)
{
  tamanho = strlen( s );
  setString( s );
}

MinhaString::~MinhaString ( )
{
  delete [] pStr;
  pStr = NULL;
}

const char* MinhaString::getString()
{
  return pStr;
}

void MinhaString::operator = (const char* s)
{
  if ( s != pStr ) 
  {
    delete[] pStr; 
    tamanho = strlen (s); 
    setString(s);
  }
}

void MinhaString::operator = (MinhaString& s)
{
  operator = (s.getString());
}

bool MinhaString::operator == (MinhaString& s)
{
  if (s.tamanho != tamanho)
  {
    return 0;
  }
  int i;
  for ( i = 0; i < tamanho; i++)
  {
    if (s.pStr[i] != pStr[i])
    {
      return 0;
    }
  }
  return 1;
}

void MinhaString::setString ( const char* s )
{
  pStr = new char [ tamanho + 1 ];
  strcpy ( pStr, s );
}

std::ostream &operator<< ( std::ostream &saida, MinhaString& s ) 
{
  saida << s.getString();
  return saida; // possibilita encadeamento
}

int main()
{
  MinhaString S1 ( "Minha primeira string soh minha." ); MinhaString S2A, S2B;
  S2A = "Operador de atribuicao sobrecarregado é muito útil."; S2B = S2A;
  std::cout << S1 << std::endl; 
  std::cout << S2A << std::endl; 
  std::cout << S2B << std::endl; 
  std::cout << std::endl;
  // Operador ternário
  // Se (Expressão) Então (ComandosA) Senão (ComandosB) // (Expressão) ? (ComandosA) : (ComandosB)
  ( S2A == S2B ) ? ( std::cout << "S2A eh igual a S2B!" ) : ( std::cout << "S2A NAO eh igual a S2B!" ); 
  std::cout << std::endl << std::endl;
  (S1 ==S2B)?(std::cout<<"S1ehigualaS2B!"):(std::cout<<"S1NAOehigualaS2B!");
  std::cout << std::endl << std::endl;
  return 0;

  return 0;
}
