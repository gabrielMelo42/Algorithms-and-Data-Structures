#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s{
    char* nome;
    int elimi;
    struct s* prox;
    struct s* ant;
} Soldado;

typedef struct lista{
    Soldado* inicio;
}LISTA;

/*int tamanhoDoNome(char* nome){
    char* letra;
    int i = 0;
    int tamanho = 0;
    whle(letra){
        letra = nome[i];
        if(letra==NULL) return tamanho;
        else tamanho++;
        i++
    }
}*/

Soldado* criarSoldado(char* nome){ //Inicializar
    Soldado* soldado = (Soldado*) malloc(sizeof(Soldado));
    soldado->nome = nome;
    soldado->elimi = 0;
    return soldado;
}


void inserirOrdenado(LISTA* l, Soldado* novo){
    Soldado* p = l->inicio;
    printf("%s", l->inicio->nome);
    if(p!=NULL){
        printf("debugando");
        while(p){
            if (strcmp(p->prox->nome, novo->nome) > 0 && p->prox != l->inicio){ 
                //Se o novo for maior que p, insere em uma posição anterior.
                //p->prox = p->prox->prox;
                p->prox->ant = novo;
                novo->prox = p->prox;
                p->prox = novo;
                novo->ant = p;
                novo = NULL; //Sinaliza que o elemento novo foi inserido na lista
                break;            
            }
            p = p->prox;
        }
        if (novo){ //Insere no fim da lista
            novo->prox = l->inicio;
            novo->ant = p;
            p->prox = novo;
            l->inicio->ant = novo;
        }
        
    }
    else{ //esse soldado sera o primeiro elemento da lista 
        printf("idsjomsdiokmcd");
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        printf("foi porra");
    }
}

void criarLista(LISTA* l, int numeroDeSoldados){
    l = (LISTA*) malloc(sizeof(LISTA));
    for (int i = 0; i < numeroDeSoldados; i++){
        char nome[1024];
        scanf("%s", &nome);
        Soldado* soldado = criarSoldado(nome);
        inserirOrdenado(l, soldado);
    }
}

void imprimeListaDeSoldados(LISTA* l){
    Soldado* p = l->inicio;
    while (p){
        printf("%s\n", p->nome);
        p = p->prox;
        if (p->prox == l->inicio) break;
    }
}

int main(){
    printf("Ola :)\n");
    printf("As regras de insercao sao as seguintes:\n");
    printf("1. Os nomes serao inseridos no console -terminal-, e nao por meio de arquivo\n");
    printf("2. Primeiramente, sera inserido o numero de soldados que estarao presentes, e dar-se-a enter\n");
    printf("3. Apos escolher o numero de soldados, coloca-se os nomes dos soldados, desta forma:\n");
    printf("4. Para cada soldado, so sera aceito o primeiro nome\n");
    printf("5. Ao escrever o nome de um soldado, da-se enter, e o proximo soldado sera inserido na proxima linha\n");
    printf("Essas sao as regras :)\n");
    printf("\n");
    printf("Insira o numero de soldados, por favor :)\n");
    int numeroDeSoldados;
    scanf("%i", &numeroDeSoldados);
    printf("\n");
    printf("Insira o nome dos soldados, por favor :)\n");
    LISTA* l;
    criarLista(l, numeroDeSoldados);
    /*for (int i = 0; i < nsoldados; i++){
        char nome[1024];
        scanf("%s", nome);
        Soldado* soldado = criarSoldado(nome);
        
        inserirOrdenado(l, soldado);
        printf("foi");
    }*/
    imprimeListaDeSoldados(l);
    return 0;
}


/*lembrete:
    a lista eh circular, portanto nao da pra ver se chegou no NULL p/ saber se a lista acabou*/





