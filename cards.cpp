#include "cards.h"

// ==================================== Construção dos objetos de carta ====================================
        trabalho::card::card    ()
{
    nome="";
    numero=-1;
    classe=-1;
    aparencia=-1; 
    balanco=-1;
    sabor=-1;
    aroma=-1;
    tato=-1;
}

        trabalho::card::card    (std::string nome_v, int numero_v, int classe_v, int aparencia_v, int balanco_v, int sabor_v, int aroma_v, int tato_v)
{
    if (nome_v.length() > 21)
    {
        for (int i=0; i<(nome_v.length()-21); i++)
            nome_v.pop_back();
        nome.pop_back();
    }
    
    nome=nome_v; 
    numero=numero_v; 
    classe=classe_v; 
    aparencia=aparencia_v; 
    balanco=balanco_v; 
    sabor=sabor_v; 
    aroma=aroma_v; 
    tato=tato_v;
}

int     trabalho::card::getNumero   ()
{return numero;}

int     trabalho::card::getClasse   ()
{return classe;}

int     trabalho::card::getAparencia()
{return aparencia;}

int     trabalho::card::getBalanco  ()
{return balanco;}

int     trabalho::card::getSabor    ()
{return sabor;}

int     trabalho::card::getAroma    ()
{return aroma;}

int     trabalho::card::getTato     ()
{return tato;}

void    trabalho::card::setNumero   (int val)
{numero=val;}

void    trabalho::card::setClasse   (int val)
{classe=val;}

void    trabalho::card::setAparencia(int val)
{aparencia=val;}

void    trabalho::card::setBalanco  (int val)
{balanco=val;}

void    trabalho::card::setSabor    (int val)
{sabor=val;}

void    trabalho::card::setAroma    (int val)
{aroma=val;}

void    trabalho::card::setTato     (int val)
{tato=val;}

void    trabalho::card::setNome     (std::string val)
{nome=val;}

void    trabalho::card::print   ()
{
    int tam = 34;
    std::string p1  = "|Nome: "       + nome + " ",
                p2 = "|Tato: "       + std::to_string(tato)      + " ",
                p3 = "|Aroma: "      + std::to_string(aroma)     + " ",
                p4 = "|Sabor: "      + std::to_string(sabor)     + " ",
                p5 = "|Balanço: "    + std::to_string(balanco)   + " ",
                p6 = "|Aparência: "  + std::to_string(aparencia) + " ";
    
    std::cout << "(" << numero << (char) (64+classe) << ")" << std::setfill('=') << std::setw(tam-4) << "+" << std::endl;
    std::cout << p1  << std::setfill(' ') << std::setw(tam-p1.length())     << "+" << std::endl;
    std::cout << "+" << std::setfill('-') << std::setw(tam-1)               << "+" << std::endl;

    std::cout << p2  << std::setfill(' ') << std::setw(tam-p2.length())     << "+" << std::endl;
    std::cout << p3  << std::setfill(' ') << std::setw(tam-p3.length())     << "+" << std::endl;
    std::cout << p4  << std::setfill(' ') << std::setw(tam-p4.length())     << "+" << std::endl;
    std::cout << p5  << std::setfill(' ') << std::setw(tam+1-p5.length())   << "+" << std::endl;
    std::cout << p6  << std::setfill(' ') << std::setw(tam+1-p6.length())   << "+" << std::endl;
    std::cout << "+" << std::setfill('=') << std::setw(tam-1)               << "+" << std::endl;
}

// ==================================== Construção dos objetos de deck ====================================
                trabalho::deck::deck        ()
{card_list = std::vector<trabalho::card>();}

                trabalho::deck::deck        (std::vector<card> cards)
{card_list=cards;}

                trabalho::deck::deck        (const deck& deck_copy)
{
    card_list = deck_copy.card_list;                        
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
        std::cout << carta.getNumero() << (char) (64+carta.getClasse()) << " ";
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