#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H

#include <stdbool.h>

struct musicas;
typedef struct musicas * LLNode;

struct player;
typedef struct player * LList;

LList player_new();

void tocar(LList list);

void pausar(LList list);

void parar(LList list);

void avancar(LList list);

void retroceder(LList list);

void mostrar(LList list);

bool adicionar(LList list, char music[], int pos);

void remover(LList list, int pos);

int estado_atual(LList list);

LLNode musica_atual(LList list);

void encerrar(LList list);

int chamarMenu();

void setStatus(LList list, int value);

#endif //PLAYER_PLAYER_H

