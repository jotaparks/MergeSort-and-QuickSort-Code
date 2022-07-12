#include <stdio.h>

/**************************************************
*
* João Paulo da Silva Dantas
* Trabalho 1
* Professor(a): Diego Padilha Rubert
*
*/

/* Armazena informações de uma capivara */
typedef struct {

int numero; /* Número da capivara = posição na largada */
int ultrapass; /* Quantidade de ultrapassagens feitas */

} capivara;

void intercala(int p, int q, int r, capivara capivaras[]){

    int i, j, k=0;

    capivara w[r];

    i = p; j = q;

    while (i < q && j < r) {

        if (capivaras[i].ultrapass > capivaras[j].ultrapass) {
        w[k] = capivaras[i];
        i++;

        }
        else if((capivaras[i].ultrapass==capivaras[j].ultrapass)&&(capivaras[i].numero < capivaras[j].numero)){
            w[k] = capivaras[i];
            i++;
        }

        else {
        w[k] = capivaras[j];
        j++;

        }
        k++;
    }
    while (i < q) {
        w[k] = capivaras[i];
        i++; k++;
    }
    while (j < r) {
        w[k] = capivaras[j];
        j++; k++;
    }
    for (i = p; i < r; i++){
        capivaras[i] = w[i-p];
    }

}


void mergesort(int p, int r, capivara capivaras[]){

    int q ;

    if (p < r - 1) {

    q = (p + r) / 2;

    mergesort(p, q, capivaras);
    mergesort(q, r, capivaras);
    intercala(p, q, r, capivaras);

    }
}


int main(){

int n, u;
capivara index;

scanf("%d", &n);

capivara capivaras[n];

for(int i=0; i<n; i++){

    capivaras[i].numero=i+1;
    capivaras[i].ultrapass=0;
}

while(scanf("%d", &u) != EOF){

    for(int i=0; i<n; i++){
        if(u==capivaras[i].numero){
            capivaras[i].ultrapass=capivaras[i].ultrapass+1;
            index=capivaras[i];
            capivaras[i]=capivaras[i-1];
            capivaras[i-1]=index;
        }
    }
}

for(int i=0; i<n; i++){
    printf("%d ", capivaras[i].numero);
}

printf("\n");

mergesort(0,n,capivaras);

for(int i=0; i<n; i++){

    printf("%d ", capivaras[i].numero);

}
printf("\n");

return 0;

}
