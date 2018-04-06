#ifndef RANKING_H
#define RANKING_H
#include <wynik.h>

class ranking
{
    wynik * pierwszy;
    int liczba_top;
public:
    ranking();
    void dodaj(const wynik &w);
    wynik get_wynik();
};

#endif // RANKING_H
