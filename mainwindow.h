#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "pytanie.h"
#include "listapytan.h"
#include "wynik.h"
#include "ranking.h"
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_wyslij_clicked();

    void on_StronaGlowna_clicked();

    void on_Ranking_clicked();

    void on_Nastepne_clicked();

    void on_Kategorie_clicked();

    void on_Kategoria1_clicked();

    void on_Kategoria2_clicked();

    void on_Kategoria3_clicked();

    void on_Kategoria4_clicked();

    void on_pushButton_nick_clicked();

    void on_zmien_nick_clicked();

private:
    Ui::MainWindow *ui;
    QTime timer;
    int dobre;
    Pytanie *pyt = new Pytanie;
    Pytanie *pomoc = new Pytanie;
    ListaPytan * l1 = new ListaPytan;
    ListaPytan * lk = new ListaPytan;
    ranking * toplist = new ranking;
    QString nick="";
    QString kategoria="";
    //Pytanie pytanie;
    void czytaj_pytania();
};

#endif // MAINWINDOW_H
