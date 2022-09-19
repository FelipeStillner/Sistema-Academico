#pragma once

#include <stdio.h>
#include <string.h>
#include <ostream>
#include <fstream>

class MinhaString {
public:
  // MinhaString () { }
  MinhaString (const char* s = ""); 
  ~MinhaString ( );
  const char* getString();
  // Sobre carga de operadores
  void operator = (const char* s); 
  void operator = (MinhaString& s); 
  bool operator == (MinhaString& s);
private:
  void setString ( const char* s );
private:
  int tamanho; 
  char* pStr;
};

std::ostream &operator<< (std::ostream &saida, MinhaString& s);
