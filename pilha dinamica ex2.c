#include <stdio.h>
#include <stdlib.h>

typedef struct pilhao{

    int valor;

    struct pilhao *anterior;

}pilhao;

typedef struct toppilha
{
    pilhao *topo;
}toppilha;

typedef struct Tfila{
    int dado;
    struct Tfila *prox;
}Tfila;


typedef struct fila{
    Tfila *inicio;
    Tfila *fim;
}fila;

void criarPilha(toppilha *p){

    p->topo = NULL;

}

int pilhaVazia(toppilha *p){

    if(p->topo == NULL)
        return 1;
    else
        return 0;

}

void empilharElemento(toppilha *p, int valor){

    pilhao *novo = malloc(sizeof(pilhao));

    novo->valor = valor;
    novo->anterior = p->topo;

    p->topo = novo;

    novo=NULL;

    free(novo);

}


void mostrarPilha(toppilha *p){

    if(pilhaVazia(p) == 0){
        pilhao *aux;
        aux = p->topo;


        while (aux != NULL)
        {
            printf("\n %d", aux->valor);

            aux = aux->anterior;
        }
        printf("\n\n");

    }
    else{
        //printf("\n===Pilha vazia===\n");
    }
}

int  desempilha(toppilha *p){

    int x;

    pilhao *aux;
    aux=p->topo;
    x = aux->valor;
    p->topo = aux->anterior;
    aux->anterior=NULL;

    free(aux);


    return x;

}

//=========================================================

void createfila(fila *f){
    f->inicio =NULL;
    f->fim    =NULL;
}

int fila_vazia(fila *f){

    if(f->inicio==NULL){
        return 1; //fila vazia
    }else{
        return 0; //fila não está vazia
    }
}

void insere_fila(fila *f,int valor){

    Tfila *novo= malloc(sizeof(Tfila));
    novo->dado = valor;
    novo->prox = NULL;


  if(fila_vazia(f)==1){//primeira vez na fila
    f->inicio = novo;
    f->fim    = novo;


  }else{
    f->fim->prox = novo;
    f->fim = novo; //ajusta o ponteiro do fim

  }

    novo=NULL;
    free(novo);
}

int remove_fila(fila *f){
  int valor;

  Tfila *aux=malloc(sizeof(Tfila));

  aux=f->inicio; //aux aponta para o inicio da fila

  valor = aux->dado; //guardando o valor na variável

  f->inicio = aux->prox; //ajustando o ponteiro do inicio

  aux->prox = NULL;

  if(f->inicio==NULL){ //verifico se existe um só elemento
    f->fim=NULL;
    free(aux);
  }else{
   free(aux);
  }

  return valor;

}

void mostrar_fila(fila *f){

 Tfila *aux=malloc(sizeof(Tfila));

 aux = f->inicio;

     while(aux!= NULL){
        printf(" | %d",aux->dado);
        aux=aux->prox;

     }
   free(aux);

}
int menu(){
    int opc;

    printf("\n\n1 - Pilha 1");
    printf("\n2 - Pilha 2");
    printf("\n3 - Mostrar pilhas");
    printf("\n4 - Mostrar fila");
    printf("\n0 - Sair");
    printf("\n-> ");

    fflush(stdin);
    scanf("%d", &opc);

    return opc;
}

int menuPilha(){

    int opc_pilha = 0;

    printf("1- Empilhar\n");
    printf("2- Desempilhar\n");
    printf("3- Mostrar Pilha\n");
    printf("4- Voltar\n");
    printf("-> ");
    fflush(stdin);
    scanf("%d", &opc_pilha);

    return opc_pilha;

}

int main()
{
    fila *f= malloc(sizeof(fila));
    createfila(f);

    toppilha *pi1 = malloc(sizeof(pilhao));
    toppilha *pi2 = malloc(sizeof(pilhao));

    criarPilha(pi1);
    criarPilha(pi2);

    int valor = 0;
    int opc = 0;
    int opc_pilha = 0;
    int x;

    do{
        opc = menu();

        switch (opc)
        {
        case 1:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi1, valor);
                break;

            case 2:
                x = desempilha(pi1);
                insere_fila(f, x);
                break;

            case 3:
                mostrarPilha(pi1);
                break;

            default:
                break;
            }

            break;

        case 2:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi2, valor);

                break;

            case 2:
                x = desempilha(pi2);
                insere_fila(f, x);
                break;

            case 3:
                mostrarPilha(pi2);
                break;

            default:
                break;
            }

            break;

        case 3:

            printf("\npilha 1 : ");
            mostrarPilha(pi1);

            printf("\n\npilha 2: ");
            mostrarPilha(pi2);

            break;

        case 4:
            mostrar_fila(f);
            break;

        default:
            break;

        }

    }while(opc != 0);





    return 0;
}
