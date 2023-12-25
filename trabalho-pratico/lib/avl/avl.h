#ifndef STRUCTS_H
#define STRUCTS_H
#include "../structs.h"
#endif

Nodo *rotacao_direita(Nodo *p, int *rotacoes);
Nodo *rotacao_esquerda(Nodo *p, int *rotacoes);
Nodo *rotacao_dupla_direita(Nodo *p, int *rotacoes);
Nodo *rotacao_dupla_esquerda(Nodo *p, int *rotacoes);
Nodo *Caso1(Nodo *a, int *ok, int *rotacoes);
Nodo *Caso2(Nodo *a, int *ok, int *rotacoes);
Nodo *InsereAvl(Nodo *a, Dados dados, int *ok, int *rotacoes);