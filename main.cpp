#include "cards.h"
#include "jodador.h"

using namespace trabalho;

int main(int, char**) 
{    
    // ======================================= PREPARAÇÃO DO JOGO =======================================
    jogo novo_jogo;
    novo_jogo.mount_jogadores();
    novo_jogo.mount_deck();
    novo_jogo.shuffle();
    novo_jogo.card_dist();
    novo_jogo.bot_play();
    // ======================================= COMEÇO DO JOGO =======================================

}
