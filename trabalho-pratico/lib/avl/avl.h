#ifndef STRUCTS_H
#define STRUCTS_H
#include "../structs.h"
#endif

Nodo *rotacao_direita(Nodo *p);
Nodo *rotacao_esquerda(Nodo *p);
Nodo *rotacao_dupla_direita(Nodo *p);
Nodo *rotacao_dupla_esquerda(Nodo *p);
Nodo *Caso1(Nodo *a, int *ok);
Nodo *Caso2(Nodo *a, int *ok);
Nodo *InsereAvl(Nodo *a, Dados dados, int *ok);