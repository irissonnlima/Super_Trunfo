#ifndef CARD_H
#define CARD_H

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

namespace trabalho
{
    class card
    {
        std::string nome;
        int         numero;
        int         classe;     // A, B, C, D, T
        int         aparencia;  // Malte
        int         balanco;    // Lúpulo
        int         sabor;      // Tostado
        int         aroma;      // Frutado
        int         tato;       // Amargor

        public:
                card        ();
                card        (std::string nome_v, int numero_v, int classe_v, int tato_v,
                             int aroma_v, int sabor_v, int balanco_v, int aparencia_v );
        
        int     getNumero   ();
        char    getClasse   ();
        int     getAparencia();
        int     getBalanco  ();
        int     getSabor    ();
        int     getAroma    ();
        int     getTato     ();

        void    setNome     (std::string val);
        void    setNumero   (int val);
        void    setClasse   (int val);
        void    setAparencia(int val);
        void    setBalanco  (int val);
        void    setSabor    (int val);
        void    setAroma    (int val);
        void    setTato     (int val);

        int     returnStats (int val);
        int     maxStats    ();
        void    print       ();

        int     operator[]  (int index);
    };
    
}

#endif