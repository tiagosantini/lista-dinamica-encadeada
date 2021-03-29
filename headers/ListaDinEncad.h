// Arquivo de cabelhaço contendo os protótipos das funções e estruturas

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

// Protótipos das funções
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
void imprime_lista(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista *li, int mat);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);


// Funções de menu

void show_menu_principal();
void show_menu_cadastro(struct aluno al);
void show_mensagem_saida();
void show_mensagem_default();


