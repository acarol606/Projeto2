
// estrutura nó
typedef struct no {
    Item conteudo;
    struct no *esquerda, *direita;
} No;

// estrutura árvore com um ponteiro para um nó
typedef struct {
    No *raiz;
    int tam;
} ArvB;


// procedimento para inserir um elemento na subárvore esquerda
void inserirEsquerda(No *no, int valor) {
    if(no->esquerda == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    } else {
        if(valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if(valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

// procedimento para inserir um elemento na subárvore direita
void inserirDireita(No *no, int valor) {
    if(no->direita == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    } else {
        if(valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if(valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

/*
    Procedimento para inserir um elemento na árvore
    faz uso dos dois procedimentos anteriores,
    inserindo à esquerda ou à direita
*/
void inserir(ArvB *arv, Item info) {
    if(arv->raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = info;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    } else {
        if(info < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, info);
        if(info > arv->raiz->conteudo)
            inserirDireita(arv->raiz, info);
    }
}

/*  nova versão para a inserção, mais resumida
    perceba que agora é só uma função
*/
No* inserirNovaVersao(No *raiz, int valor) {
    if(raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    } else {
        if(valor < raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if(valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

// função que retorna o tamanho de uma árvore
int tamanho(No *raiz) {
    if(raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

// função para buscar um elemento na árvore
int buscar(No *raiz, float chave) {
    if(raiz == NULL) {
        return 0;
        //return NULL;
    } else {
        if(raiz->conteudo == chave)
            return 1;
            //return raiz->conteudo;
        else {
            if(chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}

/*  faz a impressão da árvore em ordem crescente
    esquerda - raiz - direita
*/
void imprimir(No *raiz) {
    if(raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

// função para a remoção de um nó
No* remover(No *raiz, int chave) {

    // 3 casos de remoção:
    // 1º : quando o nó que desejo remover é folha (não possui filhos);
    // 2º : quando o nó que desejo remover tem 1 filho (esquerda ou direita);
    // 3º : quando o nó que desejo remover tem os 2 filhos (caso mais difícil).
    
    if(raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    } else {
        if(raiz->conteudo == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }
            else{
                // remover nós que possuem apenas 1 filho
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
            }
        } else {
            if(chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}