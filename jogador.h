#ifndef JOGADOR_H
#define JOGADOR_H

#include "cards.h"
#include <random>

namespace trabalho
{
    class jogador
    {
        std::vector<trabalho::card> mao;
        std::string                 nome;
        bool                        bot;
        int                         dif;

        public:
                        jogador     ();
                        jogador     (std::vector<trabalho::card> cards, std::string nome_v, bool bot_v=true, int dif_v=5);

        void            operator+=  (trabalho::card carta);

        trabalho::card  pick_card   ();
        void            add_card    (trabalho::card carta);

        void            setNome     (std::string nome_v);
        void            setBot      (bool bot_v);
        void            setDificult (int val);

        std::string     getNome     ();
        bool            getBot      ();
        int             getDificult ();
        unsigned        is_ended    ();

        trabalho::card  back        ();
        void            print_id    ();
    };
}

#endif
// elefante camelo cavaaalo garça vaquita
// ordinário mequetrefe arretado oculto  miudo