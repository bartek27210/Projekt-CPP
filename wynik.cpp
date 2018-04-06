#include "wynik.h"

wynik::wynik()
{
    this->wynik_gracza="";
    this->kategoria="";
    this->nick="";
    nastepny=nullptr;
}
void wynik::wpisz_wynik(QString wynik_gracza, QString kategoria, QString nick)
{
    this->wynik_gracza=wynik_gracza;
    this->kategoria=kategoria;
    this->nick=nick;
}

int wynik::porownaj(const wynik & wzor) const
{
    if(this->wynik_gracza.toDouble()==wzor.wynik_gracza.toDouble() && this->nick==wzor.nick && this->kategoria==wzor.kategoria)
        return -1;
    else
    {
            if (this->wynik_gracza.toDouble()>wzor.wynik_gracza.toDouble())
                return 1;
            else return 0;
     }
}

QString wynik::wypisz_wynik()
{
   return nick+"\n"+kategoria+"   "+wynik_gracza+"pkt";
}
