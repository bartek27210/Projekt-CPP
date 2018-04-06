#include "listapytan.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <qDebug>

ListaPytan::ListaPytan()
{
    Pierwsze=nullptr;
}

void ListaPytan::Dodaj(const Pytanie &p)
{
    Pytanie *nowe = new Pytanie(p);
    nowe->Nastepne=nullptr;
    if (Pierwsze == nullptr)
        {
            Pierwsze = nowe;
        }
        else
         {
            Pytanie * temp = Pierwsze;
            while (temp->Nastepne)
               {
                    temp = temp->Nastepne;
                }
            temp->Nastepne = nowe;
            nowe->Nastepne = nullptr;
         }
 }

Pytanie ListaPytan::get_pytanie()
{
    return *Pierwsze;
}

ListaPytan ListaPytan::losuj(int kategoria) const
{
    srand( time( NULL ) );
    int wylosowana,i=0;
    int wylosowane[6];
    ListaPytan * lk = new ListaPytan;
    Pytanie * temp = Pierwsze;
    switch (kategoria)
   {
        case 1:
        {
            i=0;
            while(i<6)
            {
                temp = Pierwsze;
                wylosowana=rand()%120;
                while(( wylosowane[ 0 ] == wylosowana ) ||( wylosowane[ 1 ] == wylosowana ) ||( wylosowane[ 2 ] == wylosowana ) ||( wylosowane[ 3 ] == wylosowana ) ||( wylosowane[ 4 ] == wylosowana ) ||( wylosowane[ 5 ] == wylosowana ) )
                wylosowana=rand()%120;
                wylosowane[i]=wylosowana;
                for(int j=0;j<wylosowana;j++)
                    temp = temp->Nastepne;
                if(temp->get_kategoria()=="1")
                {
                    lk->Dodaj(*temp);
                    i++;
                }
            }
         break;
        }
        case 2:
        {
        i=0;
        while(i<6)
        {
            temp = Pierwsze;
            wylosowana=rand()%120;
            while(( wylosowane[ 0 ] == wylosowana ) ||( wylosowane[ 1 ] == wylosowana ) ||( wylosowane[ 2 ] == wylosowana ) ||( wylosowane[ 3 ] == wylosowana ) ||( wylosowane[ 4 ] == wylosowana ) ||( wylosowane[ 5 ] == wylosowana ) )
            wylosowana=rand()%120;
            wylosowane[i]=wylosowana;
            for(int j=0;j<wylosowana;j++)
                temp = temp->Nastepne;
            if(temp->get_kategoria()=="2")
            {
                lk->Dodaj(*temp);
                i++;
            }
        }
            break;
        }
        case 3:
        {
        i=0;
        while(i<6)
        {
            temp = Pierwsze;
            wylosowana=rand()%120;
            while(( wylosowane[ 0 ] == wylosowana ) ||( wylosowane[ 1 ] == wylosowana ) ||( wylosowane[ 2 ] == wylosowana ) ||( wylosowane[ 3 ] == wylosowana ) ||( wylosowane[ 4 ] == wylosowana ) ||( wylosowane[ 5 ] == wylosowana ) )
            wylosowana=rand()%120;
            wylosowane[i]=wylosowana;
            for(int j=0;j<wylosowana;j++)
                temp = temp->Nastepne;
            if(temp->get_kategoria()=="4")
            {
                lk->Dodaj(*temp);
                i++;
            }
        }
            break;
        }
        case 4:
        {
        i=0;
        while(i<6)
        {
            temp = Pierwsze;
            wylosowana=rand()%120;
            while(( wylosowane[ 0 ] == wylosowana ) ||( wylosowane[ 1 ] == wylosowana ) ||( wylosowane[ 2 ] == wylosowana ) ||( wylosowane[ 3 ] == wylosowana ) ||( wylosowane[ 4 ] == wylosowana ) ||( wylosowane[ 5 ] == wylosowana ) )
            wylosowana=rand()%120;
            wylosowane[i]=wylosowana;
            for(int j=0;j<wylosowana;j++)
                temp = temp->Nastepne;
            if(temp->get_kategoria()=="3")
            {
                lk->Dodaj(*temp);
                i++;
            }
        }
            break;
        }
   }
  return *lk;
}

int ListaPytan::zlicz()
{
    Pytanie * temp = Pierwsze;
    int i=0;
    qDebug() << i;
    while (temp != nullptr)
    {
        i++;
        qDebug() << i;
        temp = temp->Nastepne;
    }
    return i;
}
