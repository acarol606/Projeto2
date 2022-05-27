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

void concatenarSvg(char* diretorio, char* arquivoGeo, char* arqCompleto) {

    char *nomeSvg;
    nomeSvg = strtok(arquivoGeo, ".");

    if (diretorio[strlen(diretorio)-1] == '/' || arquivoGeo[0] == '/') {

        if(diretorio[strlen(diretorio)-1] == '/' && arquivoGeo[0] == '/') {

            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, nomeSvg);
            strcat(arqCompleto, ".svg");
        } else {

            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeSvg);
            strcat(arqCompleto, ".svg");
        }
    } else {

        strcat(arqCompleto, diretorio);
        strcat(arqCompleto, "/");
        strcat(arqCompleto, nomeSvg);
        strcat(arqCompleto, ".svg");
    }
}

void diretorioQry(char* diretorio, char* arquivoGeo, char* arquivoQry, char* arqCompleto) {

    char *nomeGeo;
    nomeGeo = strtok(arquivoGeo, ".");

    if(diretorio[strlen(diretorio)-1] == '/' && arquivoQry[0] == '/') {
        if(arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, arquivoQry);
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, arquivoQry);
        }         
    } else if(diretorio[strlen(diretorio)-1] == '/' && arquivoQry[0] != '/') {
        if (arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, "/");
            strcat(arqCompleto, arquivoQry);
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, arquivoQry);
        }

    } else if(diretorio[strlen(diretorio)-1] != '/' && arquivoQry[0] == '/') {

        if (arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, arquivoGeo);
            strcat(arqCompleto, arquivoQry);
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, arquivoQry);
        }

    } else if(diretorio[strlen(diretorio)-1] != '/' && arquivoQry[0] != '/') {
        if (arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, arquivoGeo);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, arquivoQry);
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, arquivoQry);
        }
    }
}

void concatenarSvgFinal(char* diretorio, char* arquivoGeo, char* arquivoQry, char* arqCompleto, char* tipoArquivo) {

    char *nomeGeo;
    nomeGeo = strtok(arquivoGeo, ".");

    char *nomeQry;
    nomeQry = strtok(arquivoQry, ".");

    if(diretorio[strlen(diretorio)-1] == '/' && arquivoQry[0] == '/') {
        if(arquivoGeo[0] == '/') {
            removeChar(nomeQry, '/');
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        } else {
            removeChar(nomeQry, '/');
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        }         
    } else if(diretorio[strlen(diretorio)-1] == '/' && arquivoQry[0] != '/') {
        if (arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, ".");
            strcat(arqCompleto, nomeGeo);   // nomeGeo é a apsta em que o arquivo qry está
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        }

    } else if(diretorio[strlen(diretorio)-1] != '/' && arquivoQry[0] == '/') {

        if (arquivoGeo[0] == '/') {
            removeChar(nomeQry, '/');
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        } else {
            removeChar(nomeQry, '/');
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            strcat(arqCompleto, ".svg");
        }

    } else if(diretorio[strlen(diretorio)-1] != '/' && arquivoQry[0] != '/') {
        if (arquivoGeo[0] == '/') {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            if(tipoArquivo[0] == 's') {
                strcat(arqCompleto, ".svg");
            } else if (tipoArquivo[0] == 't') {
                strcat(arqCompleto, ".txt"); }
        } else {
            strcat(arqCompleto, diretorio);
            strcat(arqCompleto, "/");
            strcat(arqCompleto, nomeGeo);
            strcat(arqCompleto, "-");
            strcat(arqCompleto, nomeQry);
            if(tipoArquivo[0] == 's') {
                strcat(arqCompleto, ".svg");
            } else {
                strcat(arqCompleto, ".txt"); }
        }
    }
}

void removeChar(char *str, char garbage) {

    char *source, *destiny;
    for (source = destiny = str; *source != '\0'; source++) {
        *destiny = *source;
        if (*destiny != garbage) destiny++;
    }
    *destiny = '\0';
}
