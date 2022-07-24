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

        jogadores.push_back(jogador({}, p, b, d));    
        n++;
    }
    
}

void            trabalho::jogo::mount_deck      ()
{
    trabalho::card  c1({"Opa Pilsen", 1, 1, 10, 5, 50, 70, 80});
    trabalho::card  c2({"Mr. Lúpulo", 2, 1, 10, 5, 50, 70, 80});
    trabalho::card  c3({"", 3, 1, 0, 0, 0, 0, 0});
    trabalho::card  c4({"", 4, 1, 0, 0, 0, 0, 0});
    trabalho::card  c5({"", 5, 1, 0, 0, 0, 0, 0});
    trabalho::card  c6({"", 6, 1, 0, 0, 0, 0, 0});
    trabalho::card  c7({"", 7, 1, 0, 0, 0, 0, 0});
    trabalho::card  c8({"", 1, 2, 0, 0, 0, 0, 0});
    trabalho::card  c9({"", 2, 2, 0, 0, 0, 0, 0});
    trabalho::card c10({"", 3, 2, 0, 0, 0, 0, 0});
    trabalho::card c11({"", 4, 2, 0, 0, 0, 0, 0});
    trabalho::card c12({"", 5, 2, 0, 0, 0, 0, 0});
    trabalho::card c13({"", 6, 2, 0, 0, 0, 0, 0});
    trabalho::card c14({"", 7, 2, 0, 0, 0, 0, 0});
    trabalho::card c15({"", 1, 3, 0, 0, 0, 0, 0});
    trabalho::card c16({"", 2, 3, 0, 0, 0, 0, 0});
    trabalho::card c17({"", 3, 3, 0, 0, 0, 0, 0});
    trabalho::card c18({"", 4, 3, 0, 0, 0, 0, 0});
    trabalho::card c19({"", 5, 3, 0, 0, 0, 0, 0});
    trabalho::card c20({"", 6, 3, 0, 0, 0, 0, 0});
    trabalho::card c21({"", 7, 3, 0, 0, 0, 0, 0});
    trabalho::card c22({"", 1, 4, 0, 0, 0, 0, 0});
    trabalho::card c23({"", 2, 4, 0, 0, 0, 0, 0});
    trabalho::card c24({"", 3, 4, 0, 0, 0, 0, 0});
    trabalho::card c25({"", 4, 4, 0, 0, 0, 0, 0});
    trabalho::card c26({"", 5, 4, 0, 0, 0, 0, 0});
    trabalho::card c27({"", 6, 4, 0, 0, 0, 0, 0});
    trabalho::card c28({"", 7, 4, 0, 0, 0, 0, 0});
    trabalho::card c29({"Guinness", 0, 0, 0, 0, 0, 0, 0});

    deck_st = trabalho::deck({c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15,
                              c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29});

}

void            trabalho::jogo::shuffle         ()
{ deck_st.shuffle();}

void            trabalho::jogo::card_dist       ()
{
    unsigned p=0;
    for (auto& card : deck_st.copy_cards())
    {
        jogadores[p].add_card(card);
        p = (p+1)%jogadores.size();
    }
    player = p%jogadores.size();
}

