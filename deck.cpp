#include "deck.h"

                trabalho::deck::deck        ()
{card_list = std::vector<trabalho::card>();}

                trabalho::deck::deck        (std::vector<card> cards)
{card_list=cards;}

                trabalho::deck::deck        (const deck& deck_copy)
{
    card_list = deck_copy.card_list;                        
}

void            trabalho::deck::operator=   (std::vector<card> values)
{
    for (auto& cd : values)
        card_list.push_back(cd);

}

void            trabalho::deck::print       ()
{
    for(auto& carta:card_list)
    {
        carta.print();
        std::cout << std::endl;
    }
}

void            trabalho::deck::print_id    ()
{
    for(auto& carta:card_list)
        std::cout << carta.getNumero() << carta.getClasse() << " ";
    std::cout << std::endl;
}

void            trabalho::deck::add_card    (card new_card)
{card_list.push_back(new_card);}

void            trabalho::deck::shuffle     ()
{std::random_shuffle(card_list.begin(), card_list.end());}

trabalho::card  trabalho::deck::pick_card   ()
{
    auto pop_card   = card_list.back();
    card_list.pop_back();
    return pop_card;
}

std::vector<trabalho::card>   trabalho::deck::copy_cards  ()
{
    return card_list;
}

