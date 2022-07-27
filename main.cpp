#include "jogo.h"

using namespace trabalho;

int main()
{   
    // ======================================= PREPARAÇÃO DO JOGO =======================================
    jogo novo_jogo;
    novo_jogo.mount_jogadores();
    novo_jogo.mount_deck();
    novo_jogo.shuffle();
    // ======================================= COMEÇO DO JOGO =======================================
    novo_jogo.card_dist();
    novo_jogo.jogo_start();
}
