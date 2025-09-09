#include <stdio.h>
int main()
{
    // Variaveis de sistema
    int menuList, pecasList, loopControl1 = 1, loopControl2 = 1;
    char pecasCadastradas[][10] = {"Bispo", "Torre", "Rainha"};
    int pecasLenght = sizeof(pecasCadastradas) / sizeof(pecasCadastradas[0]);

    // Menu de peças
    printf("Bem vindo ao MateCheck!\n");

    while (loopControl1 == 1)
    {
        // Movimentacao no menu
        printf("\n1 - Mostrar pecas cadastradas\n2 - Sair\n> ");
        scanf("%d", &menuList);
        switch (menuList)
        {
        case 1:

            do
            {
                // Mostra as pecas cadastradas
                printf("\nPecas Cadastradas: %d\n", pecasLenght);
                for (int i = 0; i < pecasLenght; i++)
                {
                    printf("%d - %s\n", i + 1, &pecasCadastradas[i]);
                }
                printf("4 - Voltar\n");
                // Faz o seletor de pecas
                printf(">");
                scanf("%d", &pecasList);
                // Exibe as pecas
                switch (pecasList)
                {
                case 1:
                    printf(pecasCadastradas[1 - 1], "\n");
                    printf("\nO Bispo se move nas diagonais\n");
                    printf("Bispo: 5 casas na diagonal direita\n");
                    for (int i = 1; i < 6; i++)
                    {
                        printf("Diagonal direita %d\n", i);
                    }
                    loopControl2 = 1;
                    break;
                case 2:
                    printf(pecasCadastradas[2 - 1], "\n");
                    printf("\nA torre se move nas horizontais e verticais\n");
                    printf("Torre: 5 casas na horizontal direita\n");
                    for (int i = 1; i < 6; i++)
                    {
                        printf("Horizontal direita %d\n", i);
                    }
                    loopControl2 = 1;
                    break;
                case 3:
                    printf(pecasCadastradas[3 - 1], "\n");
                    printf("\nA rainha se move nas horizontais, verticais e diagonais\n");
                    printf("Rainha: 5 casas na horizontal esquerda\n");
                    for (int i = 1; i < 9; i++)
                    {
                        printf("Horizontal direita %d\n", i);
                    }
                    loopControl2 = 1;
                    break;

                case 4:
                    loopControl2 = 0;
                    break;
                default:
                    printf("\nValor invalido\n");
                    loopControl2 = 0;
                    break;
                }
            } while (loopControl2 == 1);

            break;
            // Sai do programa
        case 2:
            printf("Programa encerrado...");
            loopControl1 = 0;
            break;
        default:
            break;
        }
    };

    return 0;
}