#include<stdlib.h>
#include<stdio.h>
#include<float.h>
#include<time.h>

float** memo;

float optBST(int min_idx, int max_idx, float* freq) {
    if (memo[min_idx][max_idx] != -1) {  // ja conheco a resposta!
        return memo[min_idx][max_idx];
    }
    float result;
    if (min_idx > max_idx) {
        result = 0;
    } else if (min_idx == max_idx) {
        result = freq[min_idx];
    } else {
        float soma_freq = 0;
        int i;
        for (i = min_idx; i <= max_idx; i++) {
            soma_freq += freq[i];
        }
        float menor_custo = FLT_MAX;
        int r;
        for (r = min_idx; r <= max_idx; r++) {
            float custo_TrL = optBST(min_idx, r-1, freq);
            float custo_TrR = optBST(r+1, max_idx, freq);
            float custo_Tr = custo_TrL + custo_TrR + soma_freq;
            if (custo_Tr < menor_custo) {
                menor_custo = custo_Tr;
            }
        }

        result = menor_custo;
    }
    //memo[min_idx][max_idx] = result;
    return result;
}

int sorteie(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    srand(time(NULL));
    int n_chaves;
    float soma_freq = 0;
    printf("\nDigite o numero de chaves: ");
    scanf("%d", &n_chaves);
    float* frequencias = malloc((n_chaves + 1) * sizeof(float));
//    printf("\nDigite as frequencias de cada chave: ");
    int i;
    for (i = 1; i <= n_chaves; i++) {
//        scanf("%f", &frequencias[i]);
        frequencias[i] = sorteie(1, 1000);
        soma_freq += frequencias[i];
    }

    memo = malloc((n_chaves+2) * sizeof(float*));
    for (i = 0; i <= n_chaves + 1; i++) {
        memo[i] = malloc((n_chaves + 1) * sizeof(float));
        int j;
        for (j = 0; j <= n_chaves + 1; j++) {
            memo[i][j] = -1;
        }
    }

    float custo_otimo = optBST(1, n_chaves, frequencias);

    printf("\nCusto otimo (numerador) = %f", custo_otimo);
    printf("\nNumero medio de comparacoes = %f\n\n",
           custo_otimo / soma_freq);

    free(frequencias);
}



