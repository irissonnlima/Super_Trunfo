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
{}
