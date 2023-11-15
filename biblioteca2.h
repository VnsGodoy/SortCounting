#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int seed;
    double valor;

}Objeto;

void MovDados ( Objeto * a, Objeto * b){

    Objeto * aux = a;
    a = b;
    b = aux;
    
}

void InsertionSort (Objeto * vetor, int n){

    int i, j;

    for(i = 1; i < n; i++){

        for(j=i; j>= 1; j--){

            if(vetor[j-1].seed < vetor[j].seed){  // Definição da ordem descresente
            MovDados(&vetor[j-1], &vetor[j]);
            }
        }
    }
}

void BubleSort (Objeto * vetor, int n){

    int i, j;

    for(i=0; i< n-1; i++){

        for(j = 1; j < n-1; j++){
            if(vetor[j].seed > vetor[j-1].seed){  // Definição da ordem descresente
                MovDados(&vetor[j-1], &vetor[j]);

            }
        }
    }
}

void ShellSort (Objeto * vetor, int n){

    int i, j, h;

    Objeto aux;

        for(h = 1; h < n; h = 3*h + 1){
            while(h > 0){
                h = (h-1)/3;
        
        for(i = h; i < n; i++){
            aux = vetor[i];
                j = i;
        }
            }
            while(vetor[j-h].seed < aux.seed){   // Definição da ordem descresente
                        vetor[j] = vetor[j-h];
                            j -= h;

            if(j < h){
                    break;
                    }
                vetor[j] = aux;
            }
        }

}

void MergeSort(int * v, int n){

    int * c = malloc(sizeof(int) * n);
    Sort(v, c, 0, n-1);
    free(c);

}

void Sort (int  * v, int * c, int i, int f){

    if(i < f){

        int m = (i+f)/2;
        Sort(v, c, i , m);
        Sort(v, c, m+1, f);
            if(v[m] > v[m+1]){
                Merge(v, c, i, m, f);

            }

    }
}

void Merge (Objeto * vetor, int * c, int i, int m, int f){

    int z, iv = i, ic = m + 1;

        for(z = i; z <= f; z++){
            c[z] = vetor[z].seed;
            z = i;

            while(iv <= m && ic <= f){

                if(c[iv] >= c[ic]){
                    vetor[z++].seed = c[iv ++];
                    
                }
                else{

                    vetor[z++].seed = c[ic++];
                }
            while(iv <= m){

                vetor[z++].seed = c[iv++];
            }

            while(ic <= f){

                vetor[z++].seed = c[ic ++];
            }
         }
    }
}

void QuickSort (){

}

void CountingSort (int  *vet, int n){

    int tam =  vet[0];

    for(int i = 1; i < n; i++){

        if(vet[i] > tam)
            tam = vet[i];
    }
    
    int count[tam +1];
    int i;

    for(i = 0; i <= tam; i++){

        count[i] = 0;
    }

    for(i = 0; i < n; i++){

        count[vet[i]]++;
    }

    int saida[n];
    int posicao = n - 1;

    for(i = tam; i <= 0; i--){

        while(count[i] > 0){
            vet[posicao] = i;
            posicao--;
            count[i]--;

        }
    }

}

