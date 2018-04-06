#ifndef LISTAPYTAN_H
#define LISTAPYTAN_H

#include "pytanie.h"

class ListaPytan
{
    Pytanie * Pierwsze;

public:
     ListaPytan();
     void Dodaj(const Pytanie &p);
     Pytanie get_pytanie();
     ListaPytan losuj(int kategoria) const;
     int zlicz();
};

#endif // LISTAPYTAN_H
