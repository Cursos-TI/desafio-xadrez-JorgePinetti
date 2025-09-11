
#include <stdio.h>
// Movimentacao do bispo
void moverBispo(int movimentosPeca)
{
    int movimentosPecaConv = movimentosPeca + 6 - (movimentosPeca * 2);
    printf("%d - Diagonal direita\n", movimentosPecaConv);
};
// Movimentacao da Torre
void moverTorre(int movimentosPeca)
{
    if (movimentosPeca > 0)
    {
        printf("%d - Horizontal direita \n", movimentosPeca);
        moverTorre(movimentosPeca - 1);
    }
}
// Movimentacao da Rainha
void moverRainha(int movimentosPeca)
{
    if (movimentosPeca > 0)
    {
        printf("%d - Horizontal direita \n", movimentosPeca);
        moverRainha(movimentosPeca - 1);
    }
}
// Movimentacao do cavalo
void moverCavalo()
{
    int cavaloControl = 1;
    do
    {
        for (int i = 1, j = 3; i <= j; i++)
        {
            int movimentosPecaConv = i + 4 - (i * 2);
            if (i == j)
            {
                printf("%d - Horizontal direita\n", movimentosPecaConv);
                cavaloControl = 0;
                break;
            }
            else
            {
                printf("%d - Vertical pra baixo\n", movimentosPecaConv);
                cavaloControl = 1;
                continue;
            }
        }
    } while (cavaloControl == 1);
}

// Codigo principal
int main()
{
    // Variaveis de sistema
    int menuList, pecasList, loopControl1 = 1, loopControl2 = 1;
    char pecasCadastradas[][10] = {"Bispo", "Torre", "Rainha", "Cavalo"};
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
                printf("5 - Voltar\n");
                // Faz o seletor de pecas
                printf(">");
                scanf("%d", &pecasList);
                // Exibe as pecas
                switch (pecasList)
                {
                    // Movimentacao do bispo
                case 1:
                    printf(pecasCadastradas[1 - 1], "\n");
                    printf("\nO Bispo se move nas diagonais\n");
                    printf("Distancia ate o destino: \n");
                    int bispoControl = 1;
                    do
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            moverBispo(i);
                        }
                        bispoControl = 0;
                    } while (bispoControl == 1);
                    loopControl2 = 1;
                    break;
                // Movimentacao da torre
                case 2:
                    printf(pecasCadastradas[2 - 1], "\n");
                    printf("\nA torre se move nas horizontais e verticais\n");
                    printf("Distancia ate o destino: \n");
                    moverTorre(5);
                    loopControl2 = 1;
                    break;
                // Movimentacao da rainha
                case 3:
                    printf(pecasCadastradas[3 - 1], "\n");
                    printf("\nA rainha se move nas horizontais, verticais e diagonais\n");
                    printf("Distancia ate o destino: \n");
                    moverRainha(8);
                    loopControl2 = 1;
                    break;
                // Movimentacao do cavalo
                case 4:
                    printf(pecasCadastradas[4 - 1], "\n");
                    printf("\nO cavalo se move em posicao de L\n");
                    printf("Distancia ate o destino: \n");
                    moverCavalo();
                    loopControl2 = 1;
                    break;
                // Volta ao menu
                case 5:
                    loopControl2 = 0;
                    break;
                // Controle de valor invalido
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
