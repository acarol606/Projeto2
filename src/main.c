#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "figuras.h"
#include "geo.h"
#include "parametros.h"

int main (int argc, char* argv[]) {

    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    int i=0;
    while(i<argc) {

        if(strcmp("-e", argv[i]) == 0) { // diretorio de entrada (opcional)

            ++i; // a proxima string vai ser o caminho para o diretorio da base de entrada
            dirEntrada = (char*)malloc((strlen(argv[i])+5)*sizeof(char));
            strcpy(dirEntrada, argv[i]);

        } else if(strcmp("-f", argv[i]) == 0) { // arquivo geo (obrigatorio)

            ++i;
            arqGeo = (char*)malloc(sizeof(char) * (strlen(argv[i])+5));
            strcpy(arqGeo, argv[i]);

        } else if(strcmp("-q", argv[i]) == 0) { // arquivo qry (opcional)

            ++i;
            arqQry = (char*)malloc(sizeof(char) * (strlen(argv[i])+5));
            strcpy(arqQry, argv[i]);

        } else if(strcmp("-o", argv[i]) == 0) { // diretorio saida (obrigatorio)

            ++i;
            dirSaida = (char*)malloc((strlen(argv[i])+5)*sizeof(char));
            strcpy(dirSaida, argv[i]);

        } 
        i++;
    }

    // ---------------------------------------- GEO ------------------------------------------------------------

    // tratamento do diretorio de entrada geo
    char* diretorioEntradaGeo = NULL;
    diretorioEntradaGeo = (char*)malloc(sizeof(char) * (strlen(diretorioEnt) + strlen(nomeGeo)+2));
    diretorios(diretorioEnt, nomeGeo, diretorioEntradaGeo);
    printf("\ndiretorioEntradaGeo: %s\n", diretorioEntradaGeo);

    // criando o arquivo geo a partir do diretorio de entrada
    FILE *geoFile;
    geoFile = fopen(diretorioEntradaGeo, "r");
    if(geoFile == NULL) {
        printf("\nNao foi possivel abrir o arquivo geo.");
    }

    // criar árvore
    ArvB arvore = criaArvore();
    // chamar a função de interpretar o geo


    return 0;
}