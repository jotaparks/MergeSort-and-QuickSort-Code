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

void troca(capivara *a, capivara *b)
{
  capivara aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

int separa(int p, int r, capivara capivaras[]){

    int i, j;
    capivara x;

    x = capivaras[p];

    i = p - 1;
    j = r + 1;

    while (i < j) {

        do {
            j--;
        } while ((capivaras[j].ultrapass < x.ultrapass) || ((capivaras[j].ultrapass == x.ultrapass)&&(capivaras[j].numero > x.numero)));

        do {
            i++;
        } while ((capivaras[i].ultrapass > x.ultrapass) || ((capivaras[i].ultrapass == x.ultrapass)&&(capivaras[i].numero < x.numero)));

        if (i < j){
         troca(&capivaras[j], &capivaras[i]);
        }
    }
    return j;
}

void quicksort(int p, int r, capivara capivaras[]){

    int q;

    if (p < r) {

    q = separa(p, r, capivaras);
    quicksort(p, q, capivaras);
    quicksort(q+1, r, capivaras);

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
            capivaras[i].ultrapass= capivaras[i].ultrapass+1;
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

quicksort(0,n-1,capivaras);

for(int i=0; i<n; i++){

    printf("%d ", capivaras[i].numero);

}
printf("\n");

}
