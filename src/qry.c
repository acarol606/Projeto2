#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qry.h"
#include "arvore.h"
#include "svg.h"
#include "figuras.h"

void leituraQry(FILE *qryFile, Tree arv, FILE *svg, FILE *arqTxt) {

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

    //fprintf(arqTxt, "\n[*] sel %f %f %f %f\n", x, y, w, h);

    Node no = getRaiz(arv);
    Item item = getItem(no);

    char tipo[2];
    int verificador;    // se verificador = 0 está dentro da coordenada , se = 1 não está dentro

    while (no != NULL) { // percorrer a lista toda

        item = getItem(no);
        strcpy(tipo, getTipo(item));
        printf("\ntipo = %s\n", getTipo(item));

        if(strcmp(tipo, "r") == 0) { 
            verificador = rectInside(x, y, item);
        } else if(strcmp(tipo, "c") == 0) {
            verificador = circInside(x, y, item);
        } else if(strcmp(tipo, "l") == 0) {
            verificador = lineInside(x, y, item);
        } else if(strcmp(tipo, "t") == 0) {
            verificador = textInside(x, y, item);
        }

        no = getEsquerda(no);
        //no = getMeio(no);
        //no = getDireita(no);
        printf("só não percorreu a arvore toda (não sei como fazer :S)\n");

        if (verificador == 0) {     // figura dentro da coordenada
            fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"red\">*</text>", x, y);
            printf("removi a figura de um jeito porco (ao inves de chamar a função de remover nó da arvore)\n");
            limpaFigura(item);
            if (strcmp(tipo, "c") == 0)
                fprintf(arqTxt, "tipo = %s, id = %s, x = %f, y = %f, raio = %f, cor preenchimento = %s, cor borda = %s\n", getTipo(item), getID(item), getX(item), getY(item), getR(item), getCorp(item), getCorb(item));
            else if (strcmp(tipo, "r") == 0) 
                fprintf(arqTxt, "tipo = %s, id = %s, x = %f, y = %f, altura = %f, largura = %f, cor preenchimento = %s, cor borda = %s\n", getTipo(item), getID(item), getX(item), getY(item), getH(item), getW(item), getCorp(item), getCorb(item));
            else if (strcmp(tipo, "t") == 0)
                fprintf(arqTxt, "tipo = %s, id = %s, x = %f, y = %f, ancora = %s, cor preenchimento = %s, cor borda = %s, texto = %s\n", getTipo(item), getID(item), getX(item), getY(item), getAncora(item), getCorp(item), getCorb(item), getText(item));
            else if (strcmp(tipo, "l") == 0)
                fprintf(arqTxt, "tipo = %s, id = %s, x1 = %f, y1 = %f, x2 = %f, y2 = %f, cor = %s\n", getTipo(item), getID(item), getX1(item), getY1(item), getX2(item), getY2(item), getCorp(item));
        } else {                    // figura fora da coordenada
            fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"grey\">*</text>", getX(item), getY(item));
            fprintf(arqTxt, "AGUA\n");
        }

    }

}

void funcaoTR(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float dx, float dy, char id[]) {

    printf("entrou TR\n");
}

void funcaoBE(Tree arv, FILE* svg, FILE* arqTxt, float x, float y, float w, float h) {

    printf("entrou BE\n");
}

int rectInside(double x, double y, Item rect) {

    if (getX(rect) <= x && getX(rect) + getW(rect) >= x) {
        if (getY(rect) <= y && getY(rect)+getH(rect) >= y) {
            return 0;   // retorna 0 se estiver dentro do retangulo
        } else {
            return 1;   // retorna 1 se estiver fora do retangulo
        }
    } else  
        return 1;
}

int circInside(double x, double y, Item circ) {

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

int lineInside(double x, double y, Item line) {

    if (getX1(line) == x || getX2(line) == x || getY1(line) == y || getY2(line) == y) {
        return 0;
    } else    
        return 1;
    
}

int textInside(double x, double y, Item text) {
    /*
    if (getX(text)<= x && getX(text)+15 <= x) {
        if (getY(text)-15 <= y && getY(text)+15 >= y)
            return 0;
        else 
            return 1;
    } else 
        return 1;
    */
    if (getX(text) == x && getY(text) == y) 
        return 0;
    else 
        return 1;
}