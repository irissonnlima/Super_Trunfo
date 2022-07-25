#include "jodador.h"

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


void            trabalho::jogador::print_id     ()
{
    if (!mao.size())
    {
        std::cout << "Vazio!" << std::endl;
        return;
    }

    for (auto& carta:mao)
        std::cout << carta.getNumero() << (char)(64+carta.getClasse()) << " ";
    std::cout << std::endl;
}

// =============================== Jogo ===============================
double          trabalho::jogo::random          (bool uniform)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uni (0,100);
    std::normal_distribution<>      norm(50, 14);
    double val;
    if (uniform)
        val = uni(gen)/100.0;
    else
        val = norm(gen)/100.0;
    return val;    
}

                trabalho::jogo::jogo            ()
{}

void            trabalho::jogo::mount_jogadores ()
{
    int                 n=0, nfim;
    std::string         is_b;
    std::string         p;
    bool                b;
    int                 d;

    std::cout << "Quantos jogadores participarão: " << std::endl;
    std::cin >> nfim;

    while (n<nfim)
    {
        p = is_b = "";
        d = 0;
        std::cout << "Digite o nome do jogador: " << std::endl;
        std::cin >> p;
        
        std::cout << "Será um bot:(S/N) " << std::endl;
        std::cin >> is_b;
        if (is_b == "S" || is_b == "s")
        {
            b = true;
            std::cout << "Qual a dificuldade do bot:(0 = fácil, 1 = médio, 2 = difícil, 3 = impossível) " << std::endl;
            std::cin >> d;
            if (d==0)
                d = 33 * random();
            else if(d==1)
                d = 33 * random() + 33;
            else if(d==2)
                d = 33 * random() + 66;
            else
                d = 100;
        }

        Jogadores.push_back(jogador({}, p, b, d));    
        n++;
    }
    
}

void            trabalho::jogo::mount_deck      ()
{                                                //Tato, aroma, sabor, balanço, aparencia 
    trabalho::card  c1({"Opa Pilsen"        , 1, 1,  10,     5,    50,      10,        40});
    trabalho::card  c2({"Mr. Lúpulo"        , 2, 1,  15,    15,    60,      25,        45});
    trabalho::card  c3({"Magnifica São Luís", 3, 1,  10,    60,    65,      50,        45});
    trabalho::card  c4({"Lagunitas ipa"     , 4, 1,  80,    85,    70,      80,        90});
    trabalho::card  c5({"Stella Artois"     , 5, 1,  50,    30,    70,      85,        50});
    trabalho::card  c6({"Wäls"              , 6, 1,  60,    90,    80,      90,        80});
    trabalho::card  c7({"Spaten munich"     , 7, 1,  40,    35,    60,      80,        50});
    trabalho::card  c8({"Serramalte"        , 1, 2,  45,    20,    40,      50,        50});
    trabalho::card  c9({"Patagonia"         , 2, 2,  40,    10,    20,      25,        30});
    trabalho::card c10({"Original"          , 3, 2,  10,    10,    35,      40,        20});
    trabalho::card c11({"Goose Island"      , 4, 2,  80,    40,    60,      75,        85});
    trabalho::card c12({"Colorado"          , 5, 2,  20,    25,    35,      30,        50});
    trabalho::card c13({"Corona"            , 6, 2,  10,    35,    40,      55,        55});
    trabalho::card c14({"Brahma"            , 7, 2,   5,    10,    10,      10,        35});
    trabalho::card c15({"Budweiser"         , 1, 3,   5,    15,    10,      25,        45});
    trabalho::card c16({"Bohemia"           , 2, 3,  10,    15,    15,      30,        40});
    trabalho::card c17({"Beck's"            , 3, 3,  30,    40,    25,      40,        30});
    trabalho::card c18({"Antarctica"        , 4, 3,   5,     0,    10,      25,        20});
    trabalho::card c19({"Sol"               , 5, 3,  30,    75,     0,      85,        70});
    trabalho::card c20({"Império"           , 6, 3,  15,    50,    55,      25,        55});
    trabalho::card c21({"Petra"             , 7, 3,  25,    35,    40,      15,        80});
    trabalho::card c22({"Heineken"          , 1, 4,  55,    65,     0,      40,        20});
    trabalho::card c23({"Cacildis"          , 2, 4,  65,     0,    50,      22,        30});
    trabalho::card c24({"Madame Satã"       , 3, 4,  95,    70,     5,      40,        45});
    trabalho::card c25({"Amistel"           , 4, 4,  60,    55,    35,      60,        50});
    trabalho::card c26({"Itaipava"          , 5, 4,   0,     0,     0,       0,         0});
    trabalho::card c27({"Skol"              , 6, 4,   5,    40,     5,      10,        80});
    trabalho::card c28({"Kaiser"            , 7, 4,  10,    25,    55,      55,        10});
    trabalho::card c29({"Guinness"          , 0, 0, 100,    40,    70,      25,      8000});

    Deck_st = trabalho::deck({c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15,
                              c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29});

}

void            trabalho::jogo::shuffle         ()
{ Deck_st.shuffle();}

void            trabalho::jogo::card_dist       ()
{
    unsigned p=0;
    for (auto& card : Deck_st.copy_cards())
    {
        Jogadores[p].add_card(card);
        p = (p+1)%Jogadores.size();
    }
    Player = p%Jogadores.size();
}

int             trabalho::jogo::avaliar         (int index)
{
    std::vector<trabalho::card> lista_carta;
    for (auto& jog:Jogadores)
        lista_carta.push_back(jog.pick_card());
    
    int  id     = 0;
    bool empate = true;
    
    for (int i=0; i<lista_carta.size(); i++)
    {    std::cout << (lista_carta[i])[index] <<" "<< (lista_carta[id])[index]<< std::endl;
        if((lista_carta[i])[index] > (lista_carta[id])[index])
        {  
            empate  = false;
            id      = i;
        }
    }
    if (empate)
    {
        for (auto& ct:lista_carta)
            Empate.push_back(ct);
        return Player;
    }

    for (auto& ct:lista_carta)
        Jogadores[id].add_card(ct);
    for (auto& ct:Empate)
        Jogadores[id].add_card(ct);
    Empate = std::vector<trabalho::card>();
    return id;
}

void            trabalho::jogo::bot_play        ()
{
    // 0 x 1
    //min y max
    //(y-min)/(max-min) = x therefore y = (max-min)*x + min
    int     roleta  = 100*random();
    auto    fCard   = Jogadores[Player].back();
    int     id      = fCard.maxStats();
    if (roleta > Jogadores[Player].getDificult())
        id   = 5*random();
    auto idi = Player;
    auto idf = avaliar(id);
    while(idi==idf)
    {
        id  = Jogadores[Player].back().maxStats();
        idf = avaliar(id);
    }

}