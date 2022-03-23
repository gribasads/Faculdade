#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void PreencheMatriz(int Altura, int Largura, int* M, int Valor)
{
    int L, C; //Linha e Coluna
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            M[L * Altura + C] = Valor;
        }
    }
}
void PreencheMatrizB(int Altura, int Largura, int* M, int Valor)
{
    int L, C; //Linha e Coluna
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            M[C * Altura + L] = Valor;
        }
    }
}
void confereAlocacao( int* matriz ) {
    if ( matriz == NULL ) {
        printf("\nErro alocando memoria! \n");
        exit( EXIT_FAILURE );
    }
}
void multiplicaMatriz( int N, int* Ma, int* Mb, int* Mc ) {
    int L, C, K;
    for(L = 0; L < N; L++)
    {
        for(C = 0; C < N; C++)
        {
            for(K = 0; K < N; K++)
            {
                Mc[L * N + C] += Ma[L * N + K] * Mb[K * N + C];
            }
        }
    }
}
int main(){
    int N = 0;
    int i = 0;
    FILE *fp =fopen("teste.txt","a");
    for( i = 0 ; i < 24 ; i++){
        if(i % 1 == 0 ) {
            N += 1000;
        }
        int* Ma = (int*)malloc(sizeof(int) * N * N);
        confereAlocacao(Ma);
        int* Mb = (int*)malloc(sizeof(int) * N * N);
        confereAlocacao(Mb);
        int* Mc = (int*)malloc(sizeof(int) * N * N);
        confereAlocacao(Mc);
        printf("::: Matrix Multiplication \n");
        printf("::: N: %d\n", N);
        printf("::: Preenchendo as matrizes... ");
        PreencheMatrizB(N, N, Ma, 1);
        PreencheMatriz(N, N, Mb, 3);
        PreencheMatriz(N, N, Mc, 0);
        printf("Done! Now calculating...\n");
        // calculo do tempo
        clock_t tempo;
        tempo = clock();
        multiplicaMatriz( N, Ma, Mb, Mc );
        clock_t final = clock();
        double tempoProcessamento = ((double)(final-tempo)) / (double)(CLOCKS_PER_SEC);
        fprintf(fp,"%d;%lf \n", N, tempoProcessamento);
        printf("\nConcluido:\nTempo: %lf \n\n\n", tempoProcessamento);
    };
    // printf("\nAll done! Tempo de processamento: %lf segundos.\n", tempoProcessamento);
    return 0;
}
