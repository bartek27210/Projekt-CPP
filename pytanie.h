#ifndef PYTANIE_H
#define PYTANIE_H
#include <string>
#include <qstring>
#include <qvector.h>
#include <iostream>
#include <fstream>
using namespace std;

class Pytanie
{
private:
    string odp_a,odp_b,odp_c,odp_d,pyt_tresc,popr_tresc, kategoria, id;
public:
    Pytanie(const char * pyt_tresc = "", const char * odp_a = "", const char * odp_b = "", const char * odp_c = "", const char * odp_d = "", const char * popr_tresc = "", const char * kategoria = "", const char * id = "");
    QString get_pyt_tresc();
    QString get_popr_tresc();
    QString get_odp_a();
    QString get_odp_b();
    QString get_odp_c();
    QString get_odp_d();
    QString get_kategoria();
    QString get_id();
    void Wpisz(const char * tresc = "", const char * a = "", const char * b = "", const char * c = "", const char * d = "", const char * poprawna = "", const char * kategoria = "", const char * id = "");
    Pytanie * Nastepne;

};

#endif // PYTANIE_H
