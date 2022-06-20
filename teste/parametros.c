#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parametros.h"

void diretorios(char* diretorio, char* arquivoGeo, char* arqCompleto) { //tratamentos no endereço

    if (diretorio[strlen(diretorio)-1] == '/' || arquivoGeo[0] == '/') {

        if(diretorio[strlen(diretorio)-1] == '/' && arquivoGeo[0] == '/') {

            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, arquivoGeo);
        } else {

            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, arquivoGeo);
        }
    } else {

        strcat(arqCompleto, diretorio);
        strcat(arqCompleto, "/");
        strcat(arqCompleto, arquivoGeo);
    }
}

void concatenarSvg(char* dirSvg, char* arqQry, int leuQry) {

    //saidas/esquadra-alet-25-001.qry
    if (leuQry == 1) {
        strtok(dirSvg, ".");
        strcat(dirSvg, ".svg");
    } else {
        char* nomeQry = getNomeQry(arqQry);
        strtok(dirSvg, ".");
        strcat(dirSvg, "-");
        strcat(dirSvg, nomeQry);
        strcat(dirSvg, ".svg");
    }

}

void concatenarTxt(char* dirTxt, char* dirSvg) {

    strcat(dirTxt, dirSvg);
    strtok(dirTxt, ".");
    strcat(dirTxt, ".txt");

}

char* getNomeQry(char* arquivoQry) {

    char* nomeQry = strrchr(arquivoQry, '/'); 
    nomeQry++;
    nomeQry = strtok(nomeQry, ".");
    return nomeQry;

}
