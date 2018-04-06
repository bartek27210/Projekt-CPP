#include "pytanie.h"

Pytanie::Pytanie(const char * tresc, const char * a, const char * b, const char * c, const char * d, const char * poprawna, const char * kat, const char * ide)
{
    pyt_tresc=tresc;
    odp_a = a;
    odp_b = b;
    odp_c = c;
    odp_d = d;
    popr_tresc = poprawna;
    kategoria=kat;
    id=ide;
    Nastepne=nullptr;
}

QString Pytanie::get_pyt_tresc(){
    return QString::fromStdString(pyt_tresc);
}
QString Pytanie::get_popr_tresc(){
    return QString::fromStdString(popr_tresc);
}
QString Pytanie::get_odp_a(){
    return QString::fromStdString(odp_a);
}
QString Pytanie::get_odp_b(){
    return QString::fromStdString(odp_b);
}
QString Pytanie::get_odp_c(){
    return QString::fromStdString(odp_c);
}
QString Pytanie::get_odp_d(){
    return QString::fromStdString(odp_d);
}
QString Pytanie::get_kategoria(){
    return QString::fromStdString(kategoria);
}
QString Pytanie::get_id(){
    return QString::fromStdString(id);
}

void Pytanie::Wpisz(const char * tresc, const char * a, const char * b, const char * c, const char * d, const char * poprawna, const char * kat, const char * ide)
{
    pyt_tresc=tresc;
    odp_a=a;
    odp_b=b;
    odp_c=c;
    odp_d=d;
    popr_tresc=poprawna;
    kategoria=kat;
    id=ide;
}




