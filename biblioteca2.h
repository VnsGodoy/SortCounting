#ifndef biblioteca2_h_included
#define biblioteca2_h_included
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{

    int seed;
    double valor;

}Objeto;

void MovDados ( Objeto * a, Objeto * b){

    Objeto * temp = a;
    a = b;
    b = temp;
    
}

//Função que faz o InserionSort
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

//Função que faz o BubleSort
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

//Função que faz o ShellSort
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

//Função que faz o Merge do MergeSort
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

//Função que faz o Sort do MergeSort
void Sort (Objeto *vetor, int * c, int i, int f){

    if(i < f){

        int m = (i + f) / 2;
        Sort(vetor, c, i , m);
        Sort(vetor, c, m + 1, f);
            if(vetor[m].seed > vetor[m+1].seed){
                Merge(vetor, c, i, m, f);

            }

    }
}

//Função principal que faz do MergeSort
void MergeSort(Objeto *vetor, int n){

    int * c = malloc(sizeof(int) * n);
    Sort(vetor, c, 0, n-1);
    free(c);

}

//Função que faz o Pivo Superior do QuickSort
int partSuperior(Objeto *vetor, int LI, int LS) {

    int aux, pivo, esq = LI, dir = LS;
    pivo = vetor[LI].seed;   // Escolha do pivô como o valor da chave do limite inferior

    while (1) {  

        while (esq <= LS && vetor[esq].seed >= pivo) {
            esq++;
        }
        while (dir >= LI && vetor[dir].seed < pivo) {
            dir--;
        }
        if (esq < dir) {
        
            aux = vetor[esq].seed;
            vetor[esq].seed = vetor[dir].seed;
            vetor[dir].seed = aux;

        } else {

            break;
        }
    }

            aux = vetor[LI].seed;

            vetor[LI].seed = vetor[dir].seed; // Troca do pivô com a posição final

            vetor[dir].seed = aux;

    return dir;
}

//Função que faz o Pivo Inferior do QuickSort
int partInferior(Objeto *vetor, int LI, int LS) {

    int aux, pivo, esq = LI, dir = LS;

    pivo = vetor[LI].seed;  // Escolha do pivô como o valor da chave do limite inferior

    while (esq < dir) {

        while ((vetor[esq].seed >= pivo) && (esq < LS)) { esq++; } // Condição invertida para elementos menores

        while ((vetor[dir].seed < pivo) && (dir > LI)) { dir--; }  // Condição invertida para elementos 
        
        if (esq < dir) {

            aux = vetor[esq].seed;
            vetor[esq].seed = vetor[dir].seed;  // Troca dos elementos de posição
            vetor[dir].seed = aux;
        }
    }
            aux = vetor[LI].seed;
            vetor[LI].seed = vetor[dir].seed;  // Troca do pivô com a posição final
            vetor[dir].seed = aux;
    
            return dir;
}

//Função que faz o Pivo Central do QuickSort
int partCentral(Objeto *vetor, int LI, int LS) {

    int aux, pivo, esq = LI, dir = LS;
    int centro = LI + (LS - LI) / 2;  // Encontra o índice do meio do subvetor

    pivo = vetor[centro].seed;  // Escolha do pivô como o valor da chave do meio

    while (esq < dir) {

        while ((vetor[esq].seed >= pivo) && (esq < LS)) { esq++; } // Condição invertida para elementos menores

        while ((vetor[dir].seed < pivo) && (dir > LI)) { dir--; }  // Condição invertida para elementos maiores

        if (esq < dir) {

            aux = vetor[esq].seed;
            vetor[esq].seed = vetor[dir].seed;  // Troca dos elementos de posição
            vetor[dir].seed = aux;
        }
    }
            aux = vetor[centro].seed;
            vetor[centro].seed = vetor[dir].seed;  // Troca do pivô com a posição final
            vetor[dir].seed = aux;
            
            return dir;
}

//Função que faz o QuickSort
void QuickSort (Objeto *vetor, int LI, int LS, int (*EscPivo)(Objeto *, int, int)){

    if(LI < LS){

        int p;

        p = EscPivo(vetor, LI, LS);
        QuickSort(vetor, LI, p-1, EscPivo);
        QuickSort(vetor, p+1, LS, EscPivo);

    }

}

//Função que faz o CountingSort
void CountingSort (Objeto  *vetor, int n){

    int tam =  vetor[0].seed;

    for(int i = 1; i < n; i++){

        if(vetor[i].seed > tam)
            tam = vetor[i].seed;
    }
    
    int count[tam +1];
    int i;

    for(i = 0; i <= tam; i++){

        count[i] = 0;
    }

    for(i = 0; i < n; i++){

        count[vetor[i].seed]++;
    }

    int saida[n];
    int posicao = n - 1;

    for(i = tam; i <= 0; i--){

        while(count[i] > 0){
            vetor[posicao].seed = i;
            posicao--;
            count[i]--;

        }
    }

}

// Função para gerar valores aleatórios para as estruturas
void GeradorDeSeed(Objeto estrutura[], int n) {

    int i;
    for (i = 0; i < n; i++) {

        estrutura[i].seed = rand() % 100000; // Gera valores aleatórios para a chave (0-99999)
        estrutura[i].valor = 100.0 + ((double)rand() / RAND_MAX) * 99899.99;
    }
}

// Função para gerar a chave em ordem crescente e valores aleatórios para as estruturas
void GeradorDeSeedCrescente(Objeto estrutura[], int n) {

    int i;
    for (i = 0; i < n; i++) {

        estrutura[i].seed = i; // Gera a chave em ordem crescente
        estrutura[i].valor = 100.0 + ((double)rand() / RAND_MAX) * 99899.99; // Gera valores aleatórios para o número real (entre 100 e 99999.99)
    }
}

//Função para Imprimir Vetor
void imprimirVetor(Objeto arr[], int n) {

    printf("\n");

    for (int i = 0; i < n; i++) {

        printf("%d\t", arr[i].seed);
    }
    printf("\n");
}

//Função utilizada para calcular o tempo de execução de cada função
void calcularTempo(Objeto arr[], int n, int escolha) {

    clock_t inicio, fim;

    switch (escolha) {
        case 1:
            inicio = clock();
            InsertionSort(arr, n);
            break;

        case 2:
            inicio = clock();
            BubleSort(arr, n);
            break;

        case 3:
            inicio = clock();
            CountingSort(arr, n);
            break;

        case 4:
            inicio = clock();
            ShellSort(arr, n);
            break;

        case 5:
            inicio = clock();
            MergeSort(arr, n);
            break;
    }

            fim = clock();

    printf("\t\t-> Tempo de execucao: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);
}

#endif // biblioteca2_h_included
