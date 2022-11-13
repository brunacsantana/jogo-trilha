#include <iostream>
#include "tabuleiro.hpp"

namespace trabalho
{
    Tabuleiro ::Tabuleiro() {}

    /*
    void Tabuleiro ::tabuleiroExposicao()
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (tabuleiro[i][j] == 0)
                    std ::cout << "O  ";
                if (tabuleiro[i][j] == 1)
                    std ::cout << "B  ";
                if (tabuleiro[i][j] == 2)
                    std ::cout << "P  ";
                if (tabuleiro[i][j] == 10)
                    std ::cout << "   ";
            }
            std ::cout << std ::endl;
        }
    }*/

    void Tabuleiro ::tabuleiroPartida()
    {
        std ::cout << "Tabuleiro:\n\n";

        int pos = 1;

        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (tabuleiro[i][j] == 0)
                {
                    if (pos < 10)
                    {
                        std ::cout << " ";
                        std ::cout << pos;
                        std ::cout << "  ";
                    }
                    else
                    {
                        std ::cout << " ";
                        std ::cout << pos;
                        std ::cout << " ";
                    }
                    pos++;
                }
                if (tabuleiro[i][j] == 1)
                {
                    std ::cout << " B  ";
                    pos++;
                }
                if (tabuleiro[i][j] == 2)
                {
                    std ::cout << " P  ";
                    pos++;
                }

                if (tabuleiro[i][j] == 10)
                    std ::cout << "    ";
            }
            std ::cout << std ::endl;
            std ::cout << std ::endl;
        }
    }

    int Tabuleiro ::inserir(int i[], int numeroJogador)
    {
        if (tabuleiro[i[0]][i[1]] == 0)
        {
            tabuleiro[i[0]][i[1]] = numeroJogador;

            if (numeroJogador == 1)
            {
                maoJogador1--;
                tabuleiroJogador1++;
            }

            if (numeroJogador == 2)
            {
                maoJogador2--;
                tabuleiroJogador2++;
            }
        }
        else
        {
            return 1;
        }

        return 0;
    }

    int Tabuleiro ::mover(int numeroJogador)
    {
        int cont = 0;
        int pecaMover;
        int posMover;

        int casas[25][2] = {{100, 100}, {0, 0}, {0, 3}, {0, 6}, {1, 1}, {1, 3}, {1, 5}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {3, 6}, {4, 2}, {4, 3}, {4, 4}, {5, 1}, {5, 3}, {5, 5}, {6, 0}, {6, 3}, {6, 6}};

        tabuleiroPartida();

        std ::cout << "\nJogador " << numeroJogador << ", mova uma peça!\n";

        while (cont == 0)
        {
            std ::cout << "\nQual é a posição da peça que você deseja mover? ";
            std ::cin >> pecaMover;

            if (tabuleiro[casas[pecaMover][0]][casas[pecaMover][1]] != numeroJogador)
            {
                std ::cout << "\nMova uma peça sua!\n";
                return 2;
            }

            std ::cout << "\nPara qual posição você deseja mover? ";
            std ::cin >> posMover;
            std ::cout << std ::endl;

            if (tabuleiro[casas[pecaMover][0]][casas[pecaMover][1]] == numeroJogador)
            {
                if (tabuleiro[casas[posMover][0]][casas[posMover][1]] == 0)
                {
                    // posição recebe peça do jogador
                    tabuleiro[casas[posMover][0]][casas[posMover][1]] = numeroJogador;

                    // posição anterior recebe 0
                    tabuleiro[casas[pecaMover][0]][casas[pecaMover][1]] = 0;

                    // chama função para verificar trilha
                    int i = casas[posMover][0];
                    int j = casas[posMover][1];
                    bool trilha;

                    tabuleiroPartida();
                    std ::cout << std ::endl;
                    int fim = 0;

                    trilha = verfTrilha(i, j, numeroJogador);

                    if (trilha == true)
                    {
                        fim = removerPeca(numeroJogador);
                        tabuleiroPartida();
                    }
                    if (fim == 1)
                        return 1;

                    cont = 1;
                }
                else
                {
                    std ::cout << "\nEssa posição não esta livre.\n";
                    cont = 0;
                    return 2;
                }
            }
            else
            {
                std ::cout << "\nMova uma peça sua!\n";
                return 2;
            }
        }

        return 0;
    }

    bool Tabuleiro ::verfTrilha(int i, int j, int numeroJogador)
    {
        if (numeroJogador == 1)
        {
            int cont1 = 0;
            int cont2 = 0;

            // verificando linha
            for (int x = 0; x < 7; x++)
            {
                if (i != 3)
                {
                    if (tabuleiro[i][x] == 1)
                    {
                        cont1++;
                    }
                }
            }
            if (i == 3)
            {
                if (tabuleiro[i][0] == 1 && tabuleiro[i][1] == 1 && tabuleiro[i][2] == 1 && j < 3)
                {
                    cont1 = 3;
                }
                else if (tabuleiro[i][4] == 1 && tabuleiro[i][5] == 1 && tabuleiro[i][6] == 1 && j > 3)
                {
                    cont1 = 3;
                }
            }

            // verifica coluna
            for (int x = 0; x < 7; x++)
            {
                if (j != 3)
                {
                    if (tabuleiro[x][j] == 1)
                    {
                        cont2++;
                    }
                }
            }
            if (j == 3)
            {
                if (tabuleiro[0][j] == 1 && tabuleiro[1][j] == 1 && tabuleiro[2][j] == 1 && i < 3)
                {
                    cont2 = 3;
                }
                else if (tabuleiro[4][j] == 1 && tabuleiro[5][j] == 1 && tabuleiro[6][j] == 1 && i > 3)
                {
                    cont2 = 3;
                }
            }
            if (cont1 == 3 || cont2 == 3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (numeroJogador == 2)
        {
            int cont1 = 0;
            int cont2 = 0;

            // verificando linha
            for (int x = 0; x < 7; x++)
            {
                if (i != 3)
                {
                    if (tabuleiro[i][x] == 2)
                    {
                        cont1++;
                    }
                }
            }
            if (i == 3)
            {
                if (tabuleiro[i][0] == 2 && tabuleiro[i][1] == 2 && tabuleiro[i][2] == 2 && j < 3)
                {
                    cont1 = 3;
                }
                else if (tabuleiro[i][4] == 2 && tabuleiro[i][5] == 2 && tabuleiro[i][6] == 2 && j > 3)
                {
                    cont1 = 3;
                }
            }

            // verifica coluna
            for (int x = 0; x < 7; x++)
            {
                if (j != 3)
                {
                    if (tabuleiro[x][j] == 2)
                    {
                        cont2++;
                    }
                }
            }
            if (j == 3)
            {
                if (tabuleiro[0][j] == 2 && tabuleiro[1][j] == 2 && tabuleiro[2][j] == 2 && i < 3)
                {
                    cont2 = 3;
                }
                else if (tabuleiro[4][j] == 2 && tabuleiro[5][j] == 2 && tabuleiro[6][j] == 2 && i > 3)
                {
                    cont2 = 3;
                }
            }
            if (cont1 == 3 || cont2 == 3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }

    int Tabuleiro ::pecasTrilha(int numeroJogador)
    {
        int cont = 0;

        // peças do jogador 1
        if (numeroJogador == 2)
        {
            for (int x = 0; x < 7; x++)
            {
                for (int y = 0; y < 7; y++)
                {
                    if (tabuleiro[x][y] == 1)
                    {
                        if (verfTrilha(x, y, 1) == true)
                        {
                            cont++;
                        }
                    }
                }
            }
            if (cont == tabuleiroJogador1)
            {
                std ::cout << "Não existe movimento possível. Todas as peças do adversário estão em trilha.";
                return 1;
            }
        }

        // peças do jogador 2
        if (numeroJogador == 1)
        {
            for (int x = 0; x < 7; x++)
            {
                for (int y = 0; y < 7; y++)
                {
                    if (tabuleiro[x][y] == 2)
                    {
                        if (verfTrilha(x, y, 2) == true)
                        {
                            cont++;
                        }
                    }
                }
            }
            if (cont == tabuleiroJogador2)
            {
                std ::cout << "Não existe movimento possível. Todas as peças do adversário estão em trilha.";
                return 1;
            }
        }
        return 0;
    }

    int Tabuleiro ::removerPeca(int numeroJogador)
    {
        int semMovimentos;
        semMovimentos = pecasTrilha(numeroJogador);
        if (semMovimentos == 1 && maoJogador1 == 0 && maoJogador2 == 0)
            return 1;

        int cont = 0;
        int remPeca;

        int casas[25][2] = {{100, 100}, {0, 0}, {0, 3}, {0, 6}, {1, 1}, {1, 3}, {1, 5}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {3, 6}, {4, 2}, {4, 3}, {4, 4}, {5, 1}, {5, 3}, {5, 5}, {6, 0}, {6, 3}, {6, 6}};

        while (cont == 0)
        {
            std ::cout << "\nQual é a posição da peça que você quer remover do seu oponente? ";
            std ::cin >> remPeca;
            std ::cout << std ::endl;

            int i = casas[remPeca][0];
            int j = casas[remPeca][1];
            int adversario;

            if (numeroJogador == 1)
                adversario = 2;
            if (numeroJogador == 2)
                adversario = 1;

            if (tabuleiro[casas[remPeca][0]][casas[remPeca][1]] != adversario)
            {
                std ::cout << "\nRemova uma peça do adversário!\n";
                return 0;
            }

            if (verfTrilha(i, j, adversario) == false)
            {
                tabuleiro[i][j] = 0;
                cont = 1;
                if (numeroJogador == 1)
                {
                    tabuleiroJogador2--;
                }
                if (numeroJogador == 2)
                {
                    tabuleiroJogador1--;
                }

                tabuleiroPartida();
                bool retorno = fimJogo(tabuleiroJogador1, tabuleiroJogador2);
                if (retorno == true)
                    return 1;
            }
            else
            {
                std ::cout << "\nEssa peça está em trilha! Não é possivel remover.\n\n";
                cont = 0;
            }
        }
        return 0;
    }

    bool Tabuleiro ::fimJogo(int tabuleiroJ1, int tabuleiroJ2)
    {
        if(tabuleiroJ1 == 3 && tabuleiroJ2 == 3)
        {
            std ::cout << "\nMovimentos agora são permitidos para qualquer casa do tabuleiro!\n\n";
            return false;
        }
        if (tabuleiroJ1 < 3 && maoJogador1 == 0 && maoJogador2 == 0)
        {
            std ::cout << "\nParabéns jogador 2, você foi o vencedor!\n\n";
            return true;
        }
        if (tabuleiroJ2 < 3 && maoJogador1 == 0 && maoJogador2 == 0)
        {
            std ::cout << "\nParabéns jogador 1, você foi o vencedor!\n\n";
            return true;
        }
        return false;
    }
}