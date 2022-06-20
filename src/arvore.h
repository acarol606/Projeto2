#ifndef arvore_h
#define arvore_h 

typedef void* Tree;
typedef void* Node;
typedef void* Item;

Tree criaArvore();
//void inserirEsquerda(Node N, int valor);
//void inserirDireita(Node N, int valor);
//void inserir(Tree A, Item info);
Node inserir(Tree T, Node N, Item info, double xFig, double yFig);
void imprimir(Node N);
int tamanho(Node N);

// na função buscar, coloquei pra retornar o conteúdo do nó que buscamos ao invés de retornar um inteiro
Item buscar(Node N, Item info); // a chave vai ser as coordenadas x, y, que são float
//int buscar(No *raiz, int chave);

Node removeNo(Node N, Item info);
Node getRaiz(Tree T);
Item getItem(Node N);
Node getEsquerda(Node N);
Node getMeio(Node N);
Node getDireita(Node N);

#endif