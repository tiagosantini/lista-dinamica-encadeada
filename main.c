#include <stdio.h>
#include <stdlib.h>

#include "headers/ListaDinEncad.h"

int main() {
    
    Lista* li = cria_lista();
    int opcao;
    int mat, pos;
    int i = 1;

    // Declarando a struct para armazenar e inserir eleementos do tipo aluno
    struct aluno dados_aluno;
    while (i == 1) {

        system("clear");
        show_menu_principal();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                    show_menu_cadastro(dados_aluno);
                    insere_lista_final(li, dados_aluno);
                    break;    
            case 2:
                    show_menu_cadastro(dados_aluno);
                    insere_lista_inicio(li, dados_aluno);
                    break;
            case 3:
                    show_menu_cadastro(dados_aluno);
                    insere_lista_ordenada(li, dados_aluno);
                    break;
            case 4:
                    remove_lista_final(li);
                    break;
            case 5:
                    remove_lista_inicio(li);
                    break;
            case 6:
                    printf("Digite a matrícula que seja remover: ");
                    scanf("%d", &mat);
                    getchar();
                    remove_lista(li, mat);
                    printf("Elemento removido com sucesso!\n");
                    break;
            case 7: // Não consegui implementar a tempo
                    printf("Digite a posição do elemento que deseja consultar: ");
                    scanf("%d", &pos);
                    getchar();
                    consulta_lista_pos(li, pos, &dados_aluno);
                    break;
            case 8: // Não consegui implementar a tempo
                    show_mensagem_default();
                    break;
            case 9:
                    imprime_lista(li);
                    break;
            case 10:
                    printf("Tamanho da lista: %d\n", tamanho_lista(li));
                    break;
            case 11:
                    show_mensagem_saida();
                    i--;
                    break;
            default:
                    show_mensagem_default();
                    i--;
                    break;
        }

    }
    libera_lista(li);
    return 0;
}
