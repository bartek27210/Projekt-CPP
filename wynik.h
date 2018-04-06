#ifndef WYNIK_H
#define WYNIK_H
#include <QMainWindow>
#include <QDebug>
class wynik
{
    QString wynik_gracza, nick, kategoria;
public:
    wynik * nastepny;
    wynik();
    void wpisz_wynik(QString wynik_gracza, QString kategoria, QString nick);
    int porownaj(const wynik & wzor) const;
    QString wypisz_wynik();
};

#endif // WYNIK_H
