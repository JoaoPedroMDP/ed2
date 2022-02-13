#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * id;
    int * sizes;
    int count;
    int n;
} UF;

UF * init_UF(int n);
int count_UF(UF * uf);
int connected_UF(UF * uf, int p, int q);
int find_UF(UF * uf, int p);
void union_UF(UF * uf, int p, int q);

UF * init_UF(int n){
    int i;
    UF * uf;

    uf = malloc(sizeof(UF));

    uf->id = malloc(sizeof(int) * n);
    uf->sizes = malloc(sizeof(int) * n);
    uf->n = n;
    uf->count = n;
    for (i = 0; i < uf->count; ++i) {
        uf->id[i] = i;
        uf->sizes[i] = 1;
    }

    return(uf);
}

int count_UF(UF * uf){
    return(uf->count);
}

int connected_UF(UF * uf, int pDiplomat, int qDiplomat){
    return qDiplomat == pDiplomat;
}

int find_UF(UF * uf, int p){
    if(uf->id[p] == p){
        return p;
    }else{
        return find_UF(uf, uf->id[p]);
    }
}

//// Em todos os indexes onde tiver 'old', coloca 'new'
//void replaceGroup(UF *uf, int old, int new)
//{
//    int i;
//    for( i = 0; i < uf->n; i++){
//        if(uf->id[i] == old){
//            uf->id[i] = new;
//        }
//    }
//}

void attachGroups(UF *uf, int pRoot, int qRoot){
    if(uf->sizes[qRoot] < uf->sizes[pRoot]){
        uf->id[qRoot] = pRoot;
        uf->sizes[pRoot]++;
    }else{
        uf->id[pRoot] = qRoot;
        uf->sizes[qRoot]++;
    }
}

void union_UF(UF * uf, int pDiplomat, int qDiplomat){
    attachGroups(uf, pDiplomat, qDiplomat);
    uf->count--;
}

int main(){
    int n, p, q, pDiplomat, qDiplomat;
    UF * uf;

    scanf("%d", &n);

    uf = init_UF(n);

    scanf("%d %d", &p, &q);
    while(p > -1 && q > -1){
        pDiplomat = find_UF(uf, p);
        qDiplomat = find_UF(uf, q);
        if(!connected_UF(uf, pDiplomat, qDiplomat)){
            printf("%d %d\n", p, q);
            union_UF(uf, pDiplomat, qDiplomat);
        }

        scanf("%d %d", &p, &q);
    }
    printf("\n");
    printf("Grupos: %d", uf->count);
}
