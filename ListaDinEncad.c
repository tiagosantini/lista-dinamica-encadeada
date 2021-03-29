// Arquivo ListaDinEncad.c

#include <stdio.h>
#include <stdlib.h>

#include "headers/ListaDinEncad.h"

//Definição do tipo lista
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

// Implementação da função que cria a lista
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
            *li = NULL;

    return li;
}

// Implementação da função que libera a lista
void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Implementação da função que retorna o tamanho da lista
int tamanho_lista(Lista* li) {
    if (li == NULL)
            return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

// Implementação da função lista_cheia
// Em uma lista Dinâmica não existe o conceito de lista cheia
int lista_cheia(Lista* li) {
    return 0;
}

// Implementação da função lista_vazia
int lista_vazia(Lista* li) {
    if (li == NULL)
            return 1;
    if (*li == NULL)
            return 1;
    return 0;
}

// Implementação da função insere_lista_inicio
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL)
            return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    
    if (no == NULL)
            return 0;
    
    no->dados =  al;
    no->prox = (*li);
    *li = no;
    return 1;
}

// Implementação da função insere_lista_final
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL)
            return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
            return 0;

    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL) { // lista vazia: insere inicio
            *li = no;
    } else {
        Elem *aux;
        aux = *li;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// Implementação da função insere_lista_ordenada
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL)
            return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
            return 0;
    
    no->dados = al;

    if ((*li) == NULL) { // lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
     } else {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { // insere inicio
            no->prox = (*li);
            *li = no;
         } else {
            no->prox = atual;
            ant->prox = no;
         }
        return 1;
     }
}

// Implementação da função imprime_lista
void imprime_lista(Lista *li) {
    if (li == NULL)
            return;
    Elem* no = *li;

    while (no != NULL) {
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n", no->dados.n1,
                        no->dados.n2,
                        no->dados.n3);
        printf("---------------------------------------\n");

        no = no->prox;
    }
}

// Implementação da função remove_lista_inicio;
int remove_lista_inicio(Lista* li) {
    if (li == NULL)
            return 0;
    if ((*li) == NULL) // lista vazia
            return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

// Implementação da função remove_lista_final
int remove_lista_final(Lista* li) {
    if (li == NULL)
            return 0;

    if ((*li) == NULL) // lista vazia
            return 0;

    Elem *ant, *no = *li;

    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }

    if (no == (*li)) // remover o primeiro?
            *li = no->prox;
    else
            ant->prox = no->prox;
    free(no);
    return 1;
}

// Implementação da função remove_lista
int remove_lista(Lista* li, int mat) {
    if (li == NULL)
            return 0;

    if ((*li) = NULL) // lista vazia
            return 0;
    
    Elem *ant, *no = *li;

    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL) // Não encontrado
            return 0;

    if (no == *li) // Remover o primeiro?
            *li = no->prox;
    else
            ant->prox = no->prox;
    free(no);
    return 1;
}

// Implementação da função consulta_lista_pos
int consulta_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0)
            return 0;

    Elem *no = *li;
    int i = 1;

    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }

    if (no == NULL)
            return 0;
    else {
        *al = no->dados;
        return 1;
    }  
}

// Implementação da função consulta_lista_mat
int consulta_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL)
            return 0;

    Elem *no = *li;
    
    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    
    }

    if (no == NULL)
            return 0;
    else {
        *al = no->dados;
        return 1;
    }
}


