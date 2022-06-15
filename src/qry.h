#ifndef qry_h
#define qry_h 
#include "arvore.h"

// função que lê o arquivo .qry e chama as funções passadas nele
void leituraQry(FILE *qryFile, Tree arv, FILE *svg, FILE *arqTxt);

// atribui o nível de agressividade v às regiões de ataque
void funcaoNA(Tree arv, FILE* svg, FILE* arqTxt, float v);

// remove todas as figuras contidas na coordenada x, y
void funcaoTP(Tree arv, FILE* svg, FILE* arqTxt, float x, float y);

// 
void funcaoTR(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float dx, float dy, char id[]);

// 
void funcaoBE(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float w, float h);

#endif