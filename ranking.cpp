#include "ranking.h"

ranking::ranking()
{
    pierwszy=nullptr;
    liczba_top=0;
}

void ranking::dodaj(const wynik &w)
{
        wynik *nowy = new wynik(w);
        int ile;
        if (liczba_top == 0)
        {
            pierwszy = nowy;
            liczba_top++;
        }
        else
        {
            ile=0;
            wynik * temp = pierwszy;
            while (temp->porownaj(*nowy) && ile<8)
            {
                temp = temp->nastepny;
                ile++;
                if (!temp)
                {
                    break;
                }
            }
            if(ile>7)
                return;
            if (!temp)
            {
                temp = pierwszy;
                while (temp->nastepny!= nullptr)
                    temp = temp->nastepny;
                temp->nastepny = nowy;
                nowy->nastepny = nullptr;
                liczba_top++;
            }
            else if (temp->porownaj(*nowy) == -1)
            {
                delete nowy;
                return;
            }
            else
            {
                wynik * temp2 = pierwszy;
                if (temp == temp2)
                {
                    if (!pierwszy->nastepny)
                        temp2->nastepny = nullptr;
                    pierwszy = nowy;
                    nowy->nastepny = temp;
                    liczba_top++;
                    return;
                }
                while (temp2->nastepny != temp)
                    temp2 = temp2->nastepny;
                temp2->nastepny = nowy;
                nowy->nastepny = temp;
                liczba_top++;
            }
        }
}

wynik ranking::get_wynik()
{
    return *pierwszy;
}
