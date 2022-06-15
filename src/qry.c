#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry.h"
#include "arvore.h"
#include "svg.h"

void leituraQry(FILE *qryFile, Tree arv, FILE *svg, FILE *arqTxt) {

    printf("entrou na leitursQry\n");
    char comando[500], id[10];
    float x, y, v, dx, dy, w, h;

    while (fscanf(qryFile, "%s", comando) != EOF) {

        if (!strcmp(comando, "na")) {

            fscanf(qryFile, "%f", &v);
            funcaoNA(arv, svg, arqTxt, v);
        } 
        else if (!strcmp(comando, "tp")) {

            fscanf(qryFile, "%f %f", &x, &y);
            funcaoTP(arv, svg, arqTxt, x, y);
        }
        else if (!strcmp(comando, "tr")) {

            fscanf(qryFile, "%f %f %f %f %s", &x, &y, &dx, &dy, id);
            funcaoTR(arv, svg, arqTxt, x, y, dx, dy, id);
        }
        else if (!strcmp(comando, "be")) {

            fscanf(qryFile, "%f %f %f %f", &x, &y, &w, &h);
            funcaoBE(arv, svg, arqTxt, x, y, w, h);
        }
    }
}

void funcaoNA(Tree arv, FILE* svg, FILE* arqTxt, float v) {

    printf("entrou NA\n");
}

void funcaoTP(Tree arv, FILE* svg, FILE* arqTxt, float x, float y) {

    printf("entrou TP\n");
}

void funcaoTR(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float dx, float dy, char id[]) {

    printf("entrou TR\n");
}

void funcaoBE(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float w, float h) {

    printf("entrou BE\n");
}