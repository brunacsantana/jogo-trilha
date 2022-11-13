#include <iostream>
#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

namespace trabalho
{
    class Tabuleiro
    {
        // posicao 0 = livre
        // posicao 10 = nao existe para o jogo

        int tabuleiro[7][7] = {
            {0, 10, 10, 0, 10, 10, 0},
            {10, 0, 10, 0, 10, 0, 10},
            {10, 10, 0, 0, 0, 10, 10},
            {0, 0, 0, 10, 0, 0, 0},
            {10, 10, 0, 0, 0, 10, 10},
            {10, 0, 10, 0, 10, 0, 10},
            {0, 10, 10, 0, 10, 10, 0},
        };

        int maoJogador1 = 9;
        int maoJogador2 = 9;
        int tabuleiroJogador1 = 0;
        int tabuleiroJogador2 = 0;

    public:
        Tabuleiro();

        friend std ::ostream &operator<<( std ::ostream &output, const Tabuleiro &T );

        //void tabuleiroExposicao();

        void tabuleiroPartida();

        int inserir(int i[], int numeroJogador);

        int mover(int numeroJogador);

        bool verfTrilha(int i, int j, int numeroJogador);

        int pecasTrilha(int numeroJogador);

        int removerPeca(int numeroJogador);

        bool fimJogo(int tabuleiroJ1, int tabuleiroJ2);
    };
}
#endif