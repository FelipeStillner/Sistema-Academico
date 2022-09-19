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
