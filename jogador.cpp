#include "jogador.h"

                trabalho::jogador::jogador     () : jogador({}, "ninguém")
{}

                trabalho::jogador::jogador     (std::vector<trabalho::card> cards, std::string nome_v, bool bot_v, int dif_v)
{ mao=cards; nome=nome_v; bot=bot_v; dif=dif_v; }

void            trabalho::jogador::operator+=  (trabalho::card carta)
{
    add_card(carta);
}

trabalho::card  trabalho::jogador::pick_card   ()
{
    trabalho::card carta = mao.back();
    mao.pop_back();
    return carta;
}

void            trabalho::jogador::add_card    (trabalho::card carta)
{ mao.insert(mao.begin(), carta); }

void            trabalho::jogador::setNome     (std::string nome_v)
{nome=nome_v;}

void            trabalho::jogador::setBot      (bool bot_v)
{bot=bot_v;}

void            trabalho::jogador::setDificult (int val)
{dif=val;}

std::string     trabalho::jogador::getNome     ()
{return nome;}

bool            trabalho::jogador::getBot      ()
{return bot;}

int             trabalho::jogador::getDificult ()
{return dif;}

trabalho::card  trabalho::jogador::back        ()
{ return mao.back(); }

unsigned        trabalho::jogador::is_ended    ()
{ return unsigned( mao.size() ); }

void            trabalho::jogador::print_id     ()
{
    if (!mao.size())
    {
        std::cout << "Vazio!" << std::endl;
        return;
    }

    for (auto& carta:mao)
        std::cout << carta.getNumero() << carta.getClasse() << " ";
    std::cout << std::endl;
}