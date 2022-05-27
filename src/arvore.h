#ifndef arvore_h
#define arvore_h 

typedef void* ArvB;
typedef void* No;
typedef void* Item;

ArvB criaArvore();
void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(ArvB *arv, Item info);
void imprimir(No *raiz);
int tamanho(No *raiz);

// na função buscar, coloquei pra retornar o conteúdo do nó que buscamos ao invés de retornar um inteiro
Item buscar(No *raiz, float chave); // a chave vai ser as coordenadas x, y, que são float
//int buscar(No *raiz, int chave);

No *remover(No *raiz, int chave);

// provavelmente na função de buscar vai ter que alterar bastante coisa quando for transofmrar em ternária:
/*
Item buscar(No *raiz, float chave1, float chave2) {
    if(raiz == NULL) {
        //return 0;
        return NULL;
    } else {
        if(raiz->conteudo->x == chave1 && raiz->conteudo->y == chave2)
            return raiz->conteudo;  // vai retornar a struct da figura inteira
        else {
            if(chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}
*/

#endif