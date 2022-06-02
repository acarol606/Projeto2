#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "figuras.h"
#include "geo.h"
#include "parametros.h"
#include "svg.h"

int main (int argc, char* argv[]) {

    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    printf("iniciando o for\n");
    int i;
    for(i=0; i<argc; i++) {
        printf("i = %d ", i);
        printf("%s\n", argv[i]);
    }

    i=0;
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
    diretorioEntradaGeo = (char*)malloc(sizeof(char) * (strlen(dirEntrada) + strlen(arqGeo)+2));
    diretorios(dirEntrada, arqGeo, diretorioEntradaGeo);
    printf("\ndiretorioEntradaGeo: %s\n", diretorioEntradaGeo);

    // criando o arquivo geo a partir do diretorio de entrada
    FILE *geoFile;
    geoFile = fopen(diretorioEntradaGeo, "r");
    if(geoFile == NULL) {
        printf("Nao foi possivel abrir o arquivo geo.\n");
    }

    // criar árvore
    ArvB arvore = criaArvore();
    // chamar a função de interpretar o geo
    interpretandoGeo(geoFile, arvore);


    // diretorio de saida do svg inicial (apenas do .geo, antes do .qry)
    char* diretorioSvgInicial = NULL;
    diretorioSvgInicial = calloc(strlen(dirSaida) + strlen(arqGeo) + 20, sizeof(char));
    concatenarSvg(dirSaida, arqGeo, diretorioSvgInicial);
    printf("diretorioSvgInicial: %s\n", diretorioSvgInicial);

    // criando o arquivo svg inicial 
    FILE *svgInicial = fopen(diretorioSvgInicial, "w+");
    if(svgInicial == NULL) {
        printf("\nNao foi possivel abrir o svg inicial.");
    }
    fprintf(svgInicial, "<svg>");
    createSvg(svgInicial, arvore);  // insere as figuras que estão na lista no arquivo svg inicial
    fprintf(svgInicial, "\n</svg>");

    printf("fim da main\n");

    fclose(svgInicial);
    return 0;
}