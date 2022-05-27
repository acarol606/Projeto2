#ifndef parametros_h
#define parametros_h

// realiza os tratamentos necessários e concatena o diretório e o nome do arquivo 
void diretorios(char* diretorio, char* nomeArq, char* arqCompleto);

// realiza os tratamentos necessários e concatena o diretório e o nome do arquivo - caso do svg inicial
void concatenarSvg(char* diretorio, char* nomeArq, char* arqCompleto);

// realiza os tratamentos necessários e concatena o diretório e o nome do arquivo - caso do svg final
void concatenarSvgFinal(char* diretorio, char* arquivoGeo, char* arquivoQry, char* arqCompleto, char* tipoArquivo);

// realiza os tratamentos necessários e concatena o diretório e o nome do arquivo para o qry
void diretorioQry(char* diretorio, char* nomeArq, char* nomeQry, char* arqCompleto);

// remove um caractere (utilizado nas outras funções no momento de concatenar)
void removeChar(char *str, char garbage);

#endif