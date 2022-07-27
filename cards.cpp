#include "cards.h"

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
        for (unsigned i=0; i<(nome_v.length()-21); i++)
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

char    trabalho::card::getClasse   ()
{return char( 64+classe );}

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

int     trabalho::card::returnStats (int val)
{
    switch (val)
    {
    case 0:
        return tato;
        break;
    
    case 1:
        return aroma;
        break;

    case 2:
        return sabor;
        break;
    
    case 3:
        return balanco;
        break;
    
    case 4:
        return aparencia;
        break;

    default:
        return -1;
        break;
    }
}

int     trabalho::card::maxStats    ()
{
    int maxval=returnStats(0), id=0;
    for (int i=0; i<5; i++)
        if(returnStats(i) > maxval)
        {
            maxval  = returnStats(i);
            id      = i;
        }
    return id;
}

void    trabalho::card::print   ()
{
    unsigned tam = 34;
    std::string p1  = "|Nome: "       + nome + " ",
                p2 = "|(0)Tato: "       + std::to_string(tato)      + " ",
                p3 = "|(1)Aroma: "      + std::to_string(aroma)     + " ",
                p4 = "|(2)Sabor: "      + std::to_string(sabor)     + " ",
                p5 = "|(3)Balanço: "    + std::to_string(balanco)   + " ",
                p6 = "|(4)Aparência: "  + std::to_string(aparencia) + " ";
    
    std::cout << "(" << numero << getClasse() << ")" << std::setfill('-') << std::setw( int(tam-4) ) << "+" << std::endl;
    std::cout << p1  << std::setfill(' ') << std::setw( int(tam-p1.length())   )   << "|" << std::endl;
    std::cout << "+" << std::setfill('-') << std::setw( int(tam-1)             )   << "+" << std::endl;
 
    std::cout << p2  << std::setfill(' ') << std::setw( int(tam  -p2.length()) )   << "|" << std::endl;
    std::cout << p3  << std::setfill(' ') << std::setw( int(tam  -p3.length()) )   << "|" << std::endl;
    std::cout << p4  << std::setfill(' ') << std::setw( int(tam  -p4.length()) )   << "|" << std::endl;
    std::cout << p5  << std::setfill(' ') << std::setw( int(tam+1-p5.length()) )   << "|" << std::endl;
    std::cout << p6  << std::setfill(' ') << std::setw( int(tam+1-p6.length()) )   << "|" << std::endl;
    std::cout << "+" << std::setfill('-') << std::setw( int(tam-1)             )   << "+" << std::endl;
}

int     trabalho::card::operator[]  (int index)
{return returnStats(index);}
