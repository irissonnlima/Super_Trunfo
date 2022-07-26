#include "jogo.h"

double          trabalho::jogo::random          (bool uniform)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uni (0,100);
    std::normal_distribution<>      norm(50, 16.5);
    double val;
    if (uniform)
        val = uni(gen)/100.0;
    else
        val = norm(gen)/100.0;
    return val;    
}

                trabalho::jogo::jogo            ()
{Acabou = false; None = {"None Card", 99, 99, -1, -1,  -1, -1, -1};}

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
                d = int( 33.0 * random(false) );
            else if(d==1)
                d = int( 33.0 * random(false) + 33.0 );
            else if(d==2)
                d = int( 33.0 * random(false) + 66.0 );
            else
                d = 100;
        }
        else
            b=false;

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

    Deck_st = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15,
                              c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29};

}

void            trabalho::jogo::shuffle         ()
{ Deck_st.shuffle();}

void            trabalho::jogo::card_dist       ()
{
    unsigned p=0;
    for (auto& cd : Deck_st.copy_cards())
    {
        Jogadores[p].add_card(cd);
        p  = unsigned( (p+1)%Jogadores.size() );
    }
    Player = unsigned( p%Jogadores.size() );
}

unsigned        trabalho::jogo::avaliar         (int index)
{
    std::vector<trabalho::card> lista_carta;
    bool                        trunfo      = false;
    bool                        empate      = true;
    unsigned                    id          = 0;
    int                         numero      = 0;
    // =========================== Seleção as cartas que serão comparadas ===========================
    std::cout << "Jogador " << Jogadores[Player].getNome() << " está avaliando " << index << std::endl << std::endl;
    for (unsigned i=0; i<Jogadores.size(); i++)
    {
        auto vivo = Jogadores[i].is_ended();
        if (vivo)
        {
            std::cout<<Jogadores[i].getNome()<<" DECK("<<vivo<<")"<<std::endl;
            Jogadores[i].back().print();
            std::cout<<std::endl;

            lista_carta.push_back(Jogadores[i].pick_card());
            if(lista_carta.back().getClasse() == '@')
            {    
                trunfo  = true;
                id      = i;
            }
        }
        else
            lista_carta.push_back(None);
    }
    // =========================== Verificação e teste em caso de trunfo ===========================
    if(trunfo)
    {
        for(unsigned i=0; i<lista_carta.size(); i++)
            if(lista_carta[i].getClasse()=='A' && lista_carta[i].getNumero()>numero)
                id = i;
    }
    // =========================== Análise a jogada na inexistência de trunfo ===========================
    else
    {
        for (unsigned i=0; i<lista_carta.size(); i++)
        {
            if((lista_carta[i])[index] > (lista_carta[id])[index])
            {  
                empate  = false;
                id      = i;
            }
            else if (((lista_carta[id])[index] > (lista_carta[i])[index]))
                empate  = false;
        }
        if (empate)
        {
            std::cout << "EMPATE!!!!" << std::endl;
            std::cout << std::endl;
            for (auto& ct:lista_carta)
                Empate.push_back(ct);
            return Player;
        }
    }

    for (auto& ct:lista_carta)
    {
        if (ct.getClasse()!=char(64+99))
            Jogadores[id].add_card(ct);
    }
    for (auto& ct:Empate)
    {
        if (ct.getClasse()!=char(64+99))
            Jogadores[id].add_card(ct);
    }
    Empate = std::vector<trabalho::card>();
    std::cout << "Jogador " << Jogadores[id].getNome() << " GANHOU a rodada!!!!!" << std::endl;
    std::cout << std::endl;
    Player = id;
    return id;
}

void            trabalho::jogo::bot_play        ()
{
    int     roleta  = int( 100.0*random() );
    auto    fCard   = Jogadores[Player].back();
    int     id      = fCard.maxStats();
    if (roleta > Jogadores[Player].getDificult())
        id   = int( 5.0*random() );
    avaliar(id);
}

void            trabalho::jogo::gamer_play      ()
{
    int id=0;
    Jogadores[Player].back().print();
    std::cout << Jogadores[Player].getNome() << " qual status deseja comparar:" << std::endl;
    std::cin >> id;
    avaliar(id);
}

std::string     trabalho::jogo::verify_end      ()
{
    std::string vencedor;
    auto        size  = Jogadores.size();
    unsigned    morto = 0;

    for (auto& p:Jogadores)
        if(!p.is_ended())
            morto++;
        else
            vencedor = p.getNome();
    if (morto >= (size-1))
        Acabou = true;
    else
        Acabou = false;
    
    return vencedor;
}

void            trabalho::jogo::jogo_start      ()
{
    std::string vencedor;
    int         rodada = 0;

    while(!Acabou && rodada < 100000)
    {
        std::cout << std::endl;
        std::cout << "RODADA " << rodada << std::endl;
        if (Jogadores[Player].getBot())
            bot_play();
        else
            gamer_play();
        
        vencedor = verify_end();
        rodada++;
    }
    if (rodada>=100000)
        std::cout << "Cansamos tá doido!!" << std::endl;
    else
        std::cout << "VENCEDOR: " << vencedor << std::endl;
}