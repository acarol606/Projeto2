#ifndef arvore_h
#define arvore_h 

typedef void* ArvB;
typedef void* Node;
typedef void* Item;

ArvB criaArvore();
//void inserirEsquerda(Node N, int valor);
//void inserirDireita(Node N, int valor);
//void inserir(ArvB A, Item info);
Node inserir(ArvB T, Node N, Item info, double xFig, double yFig);
void imprimir(Node N);
int tamanho(Node N);

// na função buscar, coloquei pra retornar o conteúdo do nó que buscamos ao invés de retornar um inteiro
Item buscar(Node N, Item info); // a chave vai ser as coordenadas x, y, que são float
//int buscar(No *raiz, int chave);

Node remover(Node N, Item info);
Node getRaiz(ArvB T);
Item getItem(Node N);
Node getEsquerda(Node N);
Node getMeio(Node N);
Node getDireita(Node N);

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