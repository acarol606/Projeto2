
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry.h"
#include "arvore.h"
#include "svg.h"
#include "figuras.h"

void leituraQry(FILE *qryFile, Tree arv, FILE *svg, FILE *arqTxt) {

    //printf("entrou na leitursQry\n");
    char comando[500], id[10];
    float x, y, v, dx, dy, w, h,agress;
    
    while (fscanf(qryFile, "%s", comando) != EOF) {

        if (!strcmp(comando, "na")) {

            fscanf(qryFile, "%f ",&agress);
            printf("agress,%f\n",agress);

            //funcaoNA(arv, svg, arqTxt, v);
        } 
        else if (!strcmp(comando, "tp")) {

            fscanf(qryFile, "%f %f", &x, &y);
            funcaoTP(getRaiz(arv), svg, arqTxt, x, y);
        }
        else if (!strcmp(comando, "tr")) {

            fscanf(qryFile, "%f %f %f %f %s", &x, &y, &dx, &dy, id);
            funcaoTR(getRaiz(arv), svg, arqTxt, x, y, dx, dy, id);
        }
        else if (!strcmp(comando, "be")) {

            fscanf(qryFile, "%f %f %f %f", &x, &y, &w, &h);
            funcaoBE(arv, svg, arqTxt, x, y, w, h);
        }
    }
}

void funcaoTP(Node no, FILE* svg, FILE* arqTxt, float x, float y) {

    //printf("entrou TP\n");
    Item item;

    char tipo[2];
    int verificador;    // se verificador = 0 está dentro da coordenada , se = 1 não está dentro

    if (no == NULL) { // percorrer a arvore toda
        return;
    }

    item = getItem(no);

    strcpy(tipo, getTipo(item));

    if(strcmp(tipo, "r") == 0) { 
        verificador = rectInside(x, y, item);
    } else if(strcmp(tipo, "c") == 0) {
        verificador = circInside(x, y, item);
    } else if(strcmp(tipo, "l") == 0) {
        verificador = lineInside(x, y, item);
    } else if(strcmp(tipo, "t") == 0) {
        verificador = textInside(x, y, item);
    }

    if (verificador == 0) {     // figura dentro da coordenada
        fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"red\">*</text>", x, y);

        if (strcmp(tipo, "c") == 0)
            fprintf(arqTxt, "circulo, id = %s, x = %f, y = %f, raio = %f, cor preenchimento = %s, cor borda = %s\n", getID(item), getX(item), getY(item), getR(item), getCorp(item), getCorb(item));
        else if (strcmp(tipo, "r") == 0) 
            fprintf(arqTxt, "retangulo, id = %s, x = %f, y = %f, altura = %f, largura = %f, cor preenchimento = %s, cor borda = %s\n", getID(item), getX(item), getY(item), getH(item), getW(item), getCorp(item), getCorb(item));
        else if (strcmp(tipo, "t") == 0)
            fprintf(arqTxt, "texto, id = %s, x = %f, y = %f, ancora = %s, cor preenchimento = %s, cor borda = %s, texto = %s\n", getID(item), getX(item), getY(item), getAncora(item), getCorp(item), getCorb(item), getText(item));
        else if (strcmp(tipo, "l") == 0)
            fprintf(arqTxt, "linha, id = %s, x1 = %f, y1 = %f, x2 = %f, y2 = %f, cor = %s\n", getID(item), getX1(item), getY1(item), getX2(item), getY2(item), getCorp(item));
        
        limpaFigura(item);
    } else {                    // figura fora da coordenada
        fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"grey\">*</text>", getX(item), getY(item));
        fprintf(arqTxt, "AGUA\n");
    }

    // recursão
    funcaoTP(getEsquerda(no), svg, arqTxt, x, y);
    funcaoTP(getMeio(no), svg, arqTxt, x, y);
    funcaoTP(getDireita(no), svg, arqTxt, x, y);

}

void funcaoTR(Node no, FILE* svg, FILE* arqTxt, float x, float y, float dx, float dy, char id[]) {

    printf("entrou TR\n");
    Item item;
    float idFloat = atof(id);
    int verificador;

    // colocando um @ no ponto x,y
    fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"red\">@</text>", x, y);

    if (no == NULL) {
        return;
    } 

    item = getItem(no);

    if(strcmp(getTipo(item), "r") == 0) { 
        verificador = rectInside(x, y, item);
        if(verificador == 0) {

            fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" stroke=\"%s\"/>", getX(item)+dx, getY(item)+dy, getW(item), getH(item), getCorb(item), getCorp(item));
            fprintf(arqTxt, "\nATINGIDO: retangulo, id = %s\nx, y = %f, %f\naltura = %f\nlargura = %f\ncor preenchimento = %s\ncor borda = %s\n", getID(item), getX(item), getY(item), getH(item), getW(item), getCorp(item), getCorb(item));
            fprintf(arqTxt, "\nCLONE: retangulo, id = %f\nx, y = %f, %f\naltura = %f\nlargura = %f\ncor preenchimento = %s\ncor borda = %s\n\n-----------------------\n", idFloat, getX(item)+dx, getY(item)+dy, getH(item), getW(item), getCorb(item), getCorp(item));
            idFloat++;
        }
    } else if(strcmp(getTipo(item), "c") == 0) {
        verificador = circInside(x, y, item);
        if (verificador == 0) {

            fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>", getX(item)+dx, getY(item)+dy, getR(item), getCorb(item), getCorp(item));
            fprintf(arqTxt, "\nATINGIDO: circulo, id = %s\nx, y = %f, %f\nraio = %f\ncor preenchimento = %s\ncor borda = %s\n", getID(item), getX(item), getY(item), getR(item), getCorp(item), getCorb(item));
            fprintf(arqTxt, "\nCLONE: circulo, id = %f\nx,y = %f, %f\nraio = %f\ncor preenchimento = %s\ncor borda = %s\n\n-----------------------\n", idFloat, getX(item)+dx, getY(item)+dy, getR(item), getCorb(item), getCorp(item));
            idFloat++;
        }
    } else if(strcmp(getTipo(item), "l") == 0) {
        verificador = lineInside(x, y, item);
        if (verificador == 0) {

            fprintf(svg, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" fill=\"%s\" stroke=\"%s\"/>", getX1(item)+dx, getY1(item)+dy, getX2(item)+dx, getY2(item)+dy, getCorb(item), getCorp(item));
            fprintf(arqTxt, "\nATINGIDO: linha, id = %s\nx1, y1 = %f, %f\nx2, y2 = %f, %f\ncor preenchimento = %s\ncor borda = %s\n", getID(item), getX1(item), getY1(item), getX2(item), getY2(item), getCorp(item), getCorb(item));
            fprintf(arqTxt, "\nCLONE: linha, id = %f\nx1, y1 = %f, %f\nx2, y2 = %f, %f\ncor preenchimento = %s\ncor borda = %s\n\n-----------------------\n", idFloat, getX1(item)+dx, getY1(item)+dy, getX2(item)+dx, getY2(item)+dy, getCorb(item), getCorp(item));
            idFloat++;
        }
    } else if(strcmp(getTipo(item), "t") == 0) {
        verificador = textInside(x, y, item);
        if (verificador == 0) {

            fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\">%s</text>", getX(item)+dx, getY(item)+dy, getCorb(item), getCorp(item), getText(item));
            fprintf(arqTxt, "\nATINGIDO: texto, id = %s\nx, y = %f, %f\nancora = %s\ncor preenchimento = %s\ncor borda = %s\ntexto = %s\n", getID(item), getX(item), getY(item), getAncora(item), getCorp(item), getCorb(item), getText(item));
            fprintf(arqTxt, "\nCLONE: texto, id = %f\nx, y = %f, %f\nancora = %s\ncor preenchimento = %s\ncor borda = %s\ntexto = %s\n\n-----------------------\n", idFloat, getX(item)+dx, getY(item)+dy, getAncora(item), getCorb(item), getCorp(item), getText(item));
            idFloat++;
        }
    }

    // recursão
    funcaoTR(getEsquerda(no), svg, arqTxt, x, y, dx, dy, id);
    funcaoTR(getMeio(no), svg, arqTxt, x, y, dx, dy, id);
    funcaoTR(getDireita(no), svg, arqTxt, x, y, dx, dy, id);

}

void funcaoBE(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float w, float h) {


    printf("entrou BE\n");
}

int rectInside(float x, float y, Item rect) {

    if (x >= getX(rect) && x <=getX(rect) + getW(rect)) {
        if (y >= getY(rect) && y <= getY(rect)+getH(rect)) {
            return 0;   // retorna 0 se estiver dentro do retangulo
        } else {
            return 1;   // retorna 1 se estiver fora do retangulo
        }
    } else  
        return 1;
}

int circInside(float x, float y, Item circ) {

    if (getX(circ) - getR(circ) <= x && getX(circ) + getR(circ) >= x) {
        if (getY(circ) - getR(circ) <= y && getY(circ) + getR(circ) >= y) {
            return 0;   // retorna 0 se estiver dentro do circulo
        } else {
            return 1;   // retorna 1 se estiver fora do circulo
        }
    } else {
        return 1;
    }
}

int lineInside(float x, float y, Item line) {

    if (getX1(line) == x || getX2(line) == x || getY1(line) == y || getY2(line) == y) {
        return 0;
    } else    
        return 1;
    
}

int textInside(float x, float y, Item text) {

    if (getX(text) == x && getY(text) == y) 
        return 0;
    else 
        return 1;
}