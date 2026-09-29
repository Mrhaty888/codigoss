#include <stdio.h>

void main() {
    int x;
    printf("\nInsira a ordem da matriz: (de 1 a 5) ");
    scanf("%d", &x);

    if (x < 1 || x > 5) {
        printf("\nA ordem da matriz deve ser de 1 a 5.\n");
    } else {
        int mat[x][x];
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                printf("\nInsira o valor da %dº linha e %dº coluna: ", i + 1, j + 1);
                scanf("%d", &mat[i][j]);
            }
        }

        int maiores[x];
        int somaLinha[x];
        int menorI = 0;
        int menorJ = 0;


        for (int i = 0; i < x; i++) {
            maiores[i] = mat[i][0];
            somaLinha[i] = 0;
            for (int j = 0; j < x; j++) {
                somaLinha[i] += mat[i][j];

                if (maiores[i] < mat[i][j]) {
                    maiores[i] = mat[i][j];
                }

                if (mat[menorI][menorJ] > mat[i][j]) {
                    menorI = i;
                    menorJ = j;
                }
            }
        }

        printf("\n");

        for (int i = 0; i < x; i++) {
            printf("A soma da %dº linha foi de: %d\n", i + 1, somaLinha[i]);
            printf("O maior numero da %dº linha foi de: %d\n\n", i + 1, maiores[i]);
        }
        printf("O menor numero da matriz se encontra na posicao i = %d, j = %d, sendo o numero: %d\n", menorI, menorJ, mat[menorI][menorJ]);


    }
}
