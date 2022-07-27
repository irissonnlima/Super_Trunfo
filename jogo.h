#ifndef JOGO_H
#define JOGO_H

#include "jogador.h"
#include "deck.h"

namespace trabalho
{
    class jogo
    {
        trabalho::card                  None;
        std::vector<trabalho::jogador>  Jogadores;
        std::vector<trabalho::card>     Empate;
        deck                            Deck_st;
        unsigned                        Player;
        bool                            Acabou;
        
        double          random          (bool uniform=true);
        unsigned        avaliar         (int index);
        
        public:
                        jogo            ();

        void            mount_jogadores ();
        void            mount_deck      ();
        void            shuffle         ();
        void            card_dist       ();

        void            bot_play        ();  
        void            gamer_play      ();
        std::string     verify_end      ();

        void            jogo_start      ();
    };
}

#endif