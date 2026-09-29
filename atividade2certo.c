#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hamburguerias{
    char nomeEstabelecimento[40];
    float precoHamburguer, precoCerveja;
} hamburguerias;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar(int n, hamburguerias hamburguer[15], int totalH, int atualH){

    int novoTotal = totalH + atualH;

    for (int i = totalH; i < novoTotal; i++) {
        printf("Digite o nome do estabelecimento: \n");
        gets(hamburguer[i].nomeEstabelecimento);
        printf("Digite o preco do hamburguer: \n");
        scanf("%f", &hamburguer[i].precoHamburguer);
        printf("Digite o preco da cerveja: \n");
        scanf("%f", &hamburguer[i].precoCerveja);
        limparBuffer();

    }
}

void menorCombo(hamburguerias hamburguer[15], int totalH) {
    float valorCombo, menorValor = hamburguer[0].precoCerveja + hamburguer[0].precoHamburguer;

    for (int i = 1; i < totalH; i++) {
        valorCombo = hamburguer[i].precoCerveja + hamburguer[i].precoHamburguer;

        if (menorValor > valorCombo) {
            menorValor = valorCombo;
        }
    }

    char estabelecimento[15][40];
    int iEsta = 0;

    for (int i = 0; i < totalH; i++) {
        valorCombo = hamburguer[i].precoCerveja + hamburguer[i].precoHamburguer;
        if (valorCombo == menorValor) {
            strcpy(estabelecimento[iEsta], hamburguer[i].nomeEstabelecimento);
            iEsta++;
        }
    }

    printf("O menor preco foi de R$%.2f , as hamburgueria(s) com o menor valor sao: \n", menorValor);

    for (int i = 0; i < iEsta; i++) {
        printf("- %s\n", estabelecimento[i]);
    }
}

void medioCerveja(hamburguerias hamburguer[15], int totalH) {
    float total = 0, media;

    for (int i = 0; i < totalH; i++) {
        total += hamburguer[i].precoCerveja;
    }

    media = total / totalH;

    printf("A media de preco das cervejas foi de R$%.2f\n", media);

}

void main(){
    hamburguerias hamburgueria[15];
    int i, menor, opcao, totalHamburguerias = 0, atualHamburgueria;


    do{
        printf("-------Menu--------");
        printf("\n[1] - Cadastrar uma hamburgueria");
        printf("\n[2] - Menor preco do combo");
        printf("\n[3] - Preco medio da cerveja na cidade");
        printf("\n[0] - Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite quantas hambuerguerias deseja cadastrar: \n");
                scanf(" %d", &atualHamburgueria);
                limparBuffer();

                if (totalHamburguerias + atualHamburgueria > 15) {
                    printf("O maximo de hamburguerias eh 15.\n");
                    getchar();
                } else if (atualHamburgueria <= 0) {
                    printf("O numero de hamburguerias deve ser mais que 0.");
                    getchar();
                } else {
                    cadastrar(atualHamburgueria, hamburgueria, totalHamburguerias, atualHamburgueria);
                    totalHamburguerias += atualHamburgueria;
                }

                break;

            case 2:
                if (totalHamburguerias > 0) {
                    menorCombo(hamburgueria, totalHamburguerias);
                } else {
                    printf("Ainda nao tem hamburguerias cadastradas.\n");
                }

                break;

            case 3:
                if (totalHamburguerias > 0) {
                    medioCerveja(hamburgueria,totalHamburguerias);
                } else {
                    printf("Ainda nao tem hamburguerias cadastradas.\n");
                }

            default:
                break;
        }
        system("pause");
        system("cls");

    } while (opcao != 0);

    printf("Saindo . . .");

}
