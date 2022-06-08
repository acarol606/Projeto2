#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "arvore.h"
#include "figuras.h"
#include "geo.h"
#include "parametros.h"
#include "svg.h"

void operacoes(char* dirEntrada, char* arqGeo, char* arqQry, char* dirSaida, int leuQry) {

    geoPart(dirEntrada, arqGeo, arqQry, dirSaida);
    //qryPart(dirEntrada, arqGeo, arqQry, dirSaida, leuQry);

}

void geoPart(char* dirEntrada, char* arqGeo, char* arqQry, char* dirSaida) {

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
    fclose(svgInicial);

}

qryPart(char* dirEntrada, char* arqGeo, char* arqQry, char* dirSaida) {
    /*
    if (leuQry != 0) {

        // tratamento do diretorio de entrada qry
        char* diretorioEntradaQry = NULL;
        diretorioEntradaQry = calloc(strlen(diretorioEnt) + strlen(nomeQry)+20, sizeof(char));
        
        diretorios(diretorioEnt, nomeQry, diretorioEntradaQry);
        printf("diretorioEntradaQry: %s\n", diretorioEntradaQry);
        // criando o arquivo qry a partir do diretorio de entrada
        FILE *qryFile;
        qryFile = fopen(diretorioEntradaQry, "r");
        if(qryFile == NULL) {
            printf("\nNao foi possivel abrir o arquivo qry.");
        }
        
        // criando o arquivo svg e txt final (depois de sofrer as consultas do qry)
        char* diretorioSvgFinal = NULL;
        diretorioSvgFinal = calloc(strlen(diretorioOut) + strlen(nomeGeo) + strlen(nomeQry), sizeof(char));
        char* diretorioTxtFinal = NULL;
        diretorioTxtFinal = calloc(strlen(diretorioOut) + strlen(nomeGeo) + strlen(nomeQry) + 20, sizeof(char));

        // tratamento dos diretorio de saída para o .svg e .txt
        diretorios(diretorioOut, nomeGeo, diretorioSvgFinal);
        diretorioSvgFinal = strtok(diretorioSvgFinal, ".");
        strcat(diretorioSvgFinal, "-");
        char* nomeArqQry = calloc(strlen(nomeQry), sizeof(char));
        nomeArqQry = getNomeQry(nomeQry);
        diretorioSvgFinal = strcat(diretorioSvgFinal, nomeArqQry);
        diretorioSvgFinal = strcat(diretorioSvgFinal, ".svg");

        diretorios(diretorioOut, nomeGeo, diretorioTxtFinal);
        diretorioTxtFinal = strtok(diretorioTxtFinal, ".");
        strcat(diretorioTxtFinal, "-");
        diretorioTxtFinal = strcat(diretorioTxtFinal, nomeArqQry);
        diretorioTxtFinal = strcat(diretorioTxtFinal, ".txt");

        printf("diretorioSvgFinal: %s\n", diretorioSvgFinal);
        printf("diretorioTxtFinal: %s\n", diretorioTxtFinal);

        // criando o arquivo .svg final , ou seja, após o qry
        FILE *svgFinal = fopen(diretorioSvgFinal, "w");
        if(svgFinal == NULL) {
            printf("\nNao foi possivel abrir o arquivo svg final.");
        }
        FILE *arqTxt = fopen(diretorioTxtFinal, "w");
        if(arqTxt == NULL) {
            printf("\nNao foi possivel criar o arquivo txt final.");
        }

        fprintf(svgFinal, "<svg>\n");   // inicializando o arquivo svg
        interpretandoQry(qryFile, lista, svgFinal, arqTxt); // le o .qry, chama as funções do qry e preenche os arquivos finais
        createSvg(svgFinal, lista); // cria o svg final a partir da lista que foi alterada conforme os queries
        fprintf(svgFinal, "\n</svg>");  // fechando o arquivo svg

        free(diretorioEntradaQry);
        free(diretorioSvgFinal);
        free(diretorioTxtFinal);
        fclose(qryFile);
        fclose(svgFinal);
        fclose(arqTxt);

    }

    */
}