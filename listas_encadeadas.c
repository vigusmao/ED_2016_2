#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct _elemento {
    // dados
    int DRE;
    char nome[30];
    float CRA;

    // controle
    struct _elemento* proximo;
    struct _elemento* anterior;
} ELEMENTO;

typedef struct {
    ELEMENTO* primeiro;
    ELEMENTO* ultimo;
    int tamanho;
} LISTA_ENCADEADA;

LISTA_ENCADEADA* criar_lista() {
    LISTA_ENCADEADA* nova_lista = malloc(sizeof(LISTA_ENCADEADA));
    nova_lista->tamanho = 0;
    nova_lista->primeiro = NULL;
    nova_lista->ultimo = NULL;
    return nova_lista;
}

void append(LISTA_ENCADEADA* lista, int DRE, char nome[30], float CRA) {
    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    novo_elemento->DRE = DRE;
    strcpy(novo_elemento->nome, nome);
    novo_elemento->CRA = CRA;
    novo_elemento->proximo = NULL;
    novo_elemento->anterior = lista->ultimo;

    if (lista->tamanho == 0) {
        lista->primeiro = novo_elemento;
    } else {
        ELEMENTO* ultimo_da_lista = lista->ultimo;
        ultimo_da_lista->proximo = novo_elemento;
    }
    lista->ultimo = novo_elemento;
    lista->tamanho++;
}

void imprimir_elemento(ELEMENTO* elemento) {
    printf("(endereco %x) DRE: %d\tNome: %s\tCRA: %.1f\n",
           elemento, elemento->DRE, elemento->nome, elemento->CRA);
}

void imprimir_lista(LISTA_ENCADEADA* lista) {
    printf("\n\nLista com %d elementos:\n", lista->tamanho);
    ELEMENTO* no_corrente = lista->primeiro;
    while (no_corrente != NULL) {
        imprimir_elemento(no_corrente);
        no_corrente = no_corrente->proximo;
    }
}

ELEMENTO* buscar_por_DRE(LISTA_ENCADEADA* lista, int DRE) {
    ELEMENTO* no_corrente = lista->primeiro;
    while (no_corrente != NULL) {
        if (no_corrente->DRE == DRE) {
            return no_corrente;
        }
        no_corrente = no_corrente->proximo;
    }
    return NULL;
}

void remover(LISTA_ENCADEADA* lista, ELEMENTO* elemento) {
    if (elemento == NULL) {
        return;
    }

    ELEMENTO* anterior = elemento->anterior;
    ELEMENTO* proximo = elemento->proximo;

    if (anterior == NULL) {  // estamos removendo o primeiro!!!
        lista->primeiro = proximo;
    } else {
        anterior->proximo = proximo;
    }

    if (proximo == NULL) {  // estamos removendo o ultimo!!!
        lista->ultimo = anterior;
    } else {
        proximo->anterior = anterior;
    }

    lista->tamanho--;
    //free(elemento);
}

int main() {

    printf("Tamanho de um elemento = %d bytes\n", sizeof(ELEMENTO));
    LISTA_ENCADEADA* minha_lista = criar_lista();

    append(minha_lista, 1234, "Fulano", 8.1);
    append(minha_lista, 5555, "Beltrano", 5.5);
    append(minha_lista, 4321, "Cicrano", 4.8);

    imprimir_lista(minha_lista);

    ELEMENTO* aluno = buscar_por_DRE(minha_lista, 5555);
    if (aluno != NULL) {
        printf("Encontrei! O nome dele eh %s\n", aluno->nome);
    } else {
        printf("Nao encontrei\n");
    }

    remover(minha_lista, aluno);

    imprimir_lista(minha_lista);

    append(minha_lista, 999, "Novo Cara", 2.2);

    imprimir_lista(minha_lista);

}

