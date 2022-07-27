#ifndef DECK_H
#define DECK_H

#include "cards.h"

namespace trabalho
{
    class deck
    {
        std::vector<card>  card_list;

        public:
                deck        ();
                deck        (std::vector<card> cards);
                deck        (const deck& deck_copy);
        
        void    operator=   (std::vector<card> values);

        void    shuffle     ();
        void    print       ();
        void    print_id    ();
        void    add_card    (card new_card);
        
        card    pick_card   ();
        std::vector<card>   copy_cards  ();

    };
}

#endif