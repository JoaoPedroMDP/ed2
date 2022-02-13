#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * id;
    int count;
    int n;
} UF;

UF * initializeSet(int n);
int count_UF(UF * uf);
int pointsAreConnected(UF * uf, int p, int q);
int findGroup(UF * uf, int p);
void unitePoints(UF * uf, int p, int q);

//TODO: VOLTAR O NOME DA FUNÇÃO PARA 'init_UF'
UF * initializeSet(int n){
    int i;
    UF * uf;

    uf = malloc(sizeof(UF));

    uf->id = malloc(sizeof(int) * n);
    uf->n = n;
    uf->count = n;
    for (i = 0; i < uf->count; ++i) {
        uf->id[i] = i;
    }

    return(uf);
}

// Não faço ideia do porquê dessa função
int count_UF(UF * uf){
    return(uf->count);
}

//TODO: VOLTAR O NOME DA FUNÇÃO PARA 'connected_UF'
int pointsAreConnected(UF * uf, int p, int q){
    return(findGroup(uf, p) == findGroup(uf,q));
}

//TODO: VOLTAR O NOME DA FUNÇÃO PARA 'find_UF'
int findGroup(UF * uf, int p){
    return uf->id[p];
}

// Em todos os indexes onde tiver 'old', coloca 'new'
void replaceGroup(UF *uf, int old, int new)
{
    int i;
    for( i = 0; i < uf->n; i++){
        if(uf->id[i] == old){
            uf->id[i] = new;
        }
    }
}

//TODO: VOLTAR O NOME DA FUNÇÃO PARA 'union_UF'
void unitePoints(UF * uf, int p, int q){
    replaceGroup(uf, uf->id[q], uf->id[p]);
    uf->count--;
}

int main(){
    int n, p, q, counter=0;
    UF * uf;

    scanf("%d", &n);

    uf = initializeSet(n);

    scanf("%d %d", &p, &q);
    while(p > -1 && q > -1){
        printf("[%d]", counter);
        counter++;
        if(!pointsAreConnected(uf, p, q)){
            printf("%d %d\n", p, q);
            unitePoints(uf, p, q);
        }

        scanf("%d %d", &p, &q);
    }

    printf("\n");
    printf("\n");
    printf("Grupos: %d", uf->count);
}
