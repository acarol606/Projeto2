#ifndef parametros_h
#define parametros_h

// realiza os tratamentos necessários e concatena o diretório e o nome do arquivo 
void diretorios(char* diretorio, char* nomeArq, char* arqCompleto);

void concatenarSvg(char* dirSvg, char* arqQry, int leuQry);
void concatenarTxt(char* dirTxt, char* dirSvg);
char* getNomeQry(char* arquivoQry);

#endif