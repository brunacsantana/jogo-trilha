#include <iostream>
#include "partida.hpp"
#include "tabuleiro.hpp"

namespace trabalho
{
    Partida ::Partida() {}

    //tabuleiro de exposicao
    std ::ostream &operator<<( std ::ostream &output, const Tabuleiro &T ) { 
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (T.tabuleiro[i][j] == 0)
                    std ::cout << "O  ";
                if (T.tabuleiro[i][j] == 1)
                    std ::cout << "B  ";
                if (T.tabuleiro[i][j] == 2)
                    std ::cout << "P  ";
                if (T.tabuleiro[i][j] == 10)
                    std ::cout << "   ";
            }

            std ::cout << std ::endl;
        }
        return output;            
    }

    void Partida ::comoJogar()
    {
        std ::cout << "\nBem-vindo ao jogo Trilha!\n\n\n";

        trabalho ::Tabuleiro trilha;
        std ::cout << trilha << std ::endl;

        std ::cout << "\n-----------DESCRIÇÃO-----------\n-> 2 Jogadores;\n-> 18 "
                      "peças, sendo 9 brancas(B) e 9 pretas(P);\n-> Tabuleiro com 24 "
                      "casas interligadas horizontalmente e verticalmente;\n-> "
                      "Objetivo do jogo é deixar o adversário com apenas 2 peças no "
                      "tabuleiro ou sem movimentos possíveis.\n\n";
    }

    void Partida ::jogoTrilha()
    {
        trabalho ::Tabuleiro trilha;

        comoJogar();

        int casas[25][2] = {{100, 100}, {0, 0}, {0, 3}, {0, 6}, {1, 1}, {1, 3}, {1, 5}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {3, 6}, {4, 2}, {4, 3}, {4, 4}, {5, 1}, {5, 3}, {5, 5}, {6, 0}, {6, 3}, {6, 6}};

        int pos;
        trilha.tabuleiroPartida();

        for (int i = 0; i < 18; i++)
        {
            int retorno;

            std ::cout << "\n\nJogador " << (i % 2) + 1 << ", insira uma peça!";
            std ::cout << std ::endl;
            std ::cout << "\nEscolha uma posição numerada: ";
            std ::cin >> pos;
            std ::cout << std ::endl;

            retorno = trilha.inserir(casas[pos], (i % 2) + 1);

            int x = casas[pos][0];
            int j = casas[pos][1];
            bool confere;

            confere = trilha.verfTrilha(x, j, (i % 2) + 1);
            if (confere == true)
            {
                trilha.tabuleiroPartida();
                retorno = trilha.removerPeca((i % 2) + 1);
            }

            if (retorno == 0)
            {
                trilha.tabuleiroPartida();
            }
            else
            {
                i--;
                std ::cout << "\n\nErro ao adicionar, escolha um posição válida!\n\n";
            }
        }

        std ::cout << "\n\nTodas as peças foram adicionadas!\n\n";

        int jogador = 0;
        int retorno = 0;

        while (retorno == 0)
        {
            retorno = trilha.mover((jogador % 2) + 1);
            jogador++;

            if (retorno == 2)
            {
                jogador--;
                retorno = 0;
            }
        }

        std ::cout << "\n\nFim de jogo!";
    }
}