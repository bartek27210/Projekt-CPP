#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setFixedSize(450,450);
    ui->Pytanie->setStyleSheet("QLabel { color : white; }");
    QPixmap pixmap("pictures/baner.png");
    ui->background->setPixmap(pixmap);
    QPixmap pixmap1("pictures/tlo.png");
    ui->wholebackground->setPixmap(pixmap1);
    QPixmap pixmap2("pictures/Tablica.png");
    ui->Tlo_pytania->setPixmap(pixmap2);
    QPixmap pixmap3("pictures/ranking.png");
    ui->background_ranking->setPixmap(pixmap3);
    ui->Nastepne->setDisabled(1);
    ui->radioButton_1->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_2->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_3->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_4->setStyleSheet("QRadioButton { color : white; }");

    czytaj_pytania();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_wyslij_clicked()
{

    if(ui->buttonGroup->checkedButton()==NULL)
    {

    }
    else
    {
        if(!ui->buttonGroup->checkedButton()->text().compare(pomoc->get_popr_tresc()))
        {
            QPixmap pixmap4("pictures/dobrze.png");
            ui->Dobrze->setPixmap(pixmap4);
            ui->buttonGroup->checkedButton()->setStyleSheet("QRadioButton { color : #00C000; }");
            dobre++;
        }
        else
        {
            ui->buttonGroup->checkedButton()->setStyleSheet("QRadioButton { color : #fc2020; }");
            if(!ui->radioButton_1->text().compare(pomoc->get_popr_tresc()))
                ui->radioButton_1->setStyleSheet("QRadioButton { color : #00C000; }");
            else if(!ui->radioButton_2->text().compare(pomoc->get_popr_tresc()))
                ui->radioButton_2->setStyleSheet("QRadioButton { color : #00C000; }");
            else if(!ui->radioButton_3->text().compare(pomoc->get_popr_tresc()))
                ui->radioButton_3->setStyleSheet("QRadioButton { color : #00C000; }");
            else
                ui->radioButton_4->setStyleSheet("QRadioButton { color : #00C000; }");
            QPixmap pixmap5("pictures/zle.png");
            ui->Zle->setPixmap(pixmap5);
        }
        ui->wyslij->setDisabled(1);
        ui->Nastepne->setEnabled(1);
    }
}

void MainWindow::on_StronaGlowna_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_Ranking_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_Nastepne_clicked()
{
    if(ui->buttonGroup->checkedButton()==NULL)
    {

    }
    else
    {
        ui->wyslij->setEnabled(1);
        ui->Dobrze->clear();
        ui->Zle->clear();
        ui->radioButton_1->setStyleSheet("QRadioButton { color : white; }");
        ui->radioButton_2->setStyleSheet("QRadioButton { color : white; }");
        ui->radioButton_3->setStyleSheet("QRadioButton { color : white; }");
        ui->radioButton_4->setStyleSheet("QRadioButton { color : white; }");
        ui->buttonGroup->setExclusive(false);
        ui->radioButton_1->setChecked(false);
        ui->radioButton_2->setChecked(false);
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(false);
        ui->buttonGroup->setExclusive(true);
        pomoc = pomoc->Nastepne;
        if(pomoc==nullptr)
        {
            ui->Nastepne->setDisabled(1);
            ui->stackedWidget->setCurrentIndex(4);
            QPixmap pixmap6("pictures/wynik.png");
            ui->wynik->setPixmap(pixmap6);
            int czas = timer.elapsed()/1000;
            int pkt = dobre*100/(czas/10+1);
            QString podpis="Wynik: "+QString::number(pkt)+"pkt\n Poprawne odpowiedzi:\n "+QString::number(dobre)+" / 6";
            ui->wynikgracza->setText(podpis);
            wynik * w1 = new wynik;
            w1->wpisz_wynik(QString::number(pkt),kategoria, nick);
            toplist->dodaj(*w1);
            wynik * test = new wynik;
            *test = toplist->get_wynik();
            ui->rang1->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang2->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang3->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang4->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang5->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang6->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang7->setText(test->wypisz_wynik());
            if(!(test=test->nastepny))
                return;
            ui->rang8->setText(test->wypisz_wynik());
        }
        else
        {
            ui->Pytanie->setStyleSheet("QLabel { color : white; }");
            ui->Pytanie->setText(pomoc->get_pyt_tresc());
            ui->radioButton_1->setText(pomoc->get_odp_a());
            ui->radioButton_2->setText(pomoc->get_odp_b());
            ui->radioButton_3->setText(pomoc->get_odp_c());
            ui->radioButton_4->setText(pomoc->get_odp_d());
            ui->Nastepne->setDisabled(1);
        }
    }
}

void MainWindow::on_Kategorie_clicked()
{
    ui->radioButton_1->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_2->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_3->setStyleSheet("QRadioButton { color : white; }");
    ui->radioButton_4->setStyleSheet("QRadioButton { color : white; }");
    ui->Dobrze->clear();
    ui->Zle->clear();
    ui->buttonGroup->setExclusive(false);
    ui->radioButton_1->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_4->setChecked(false);
    ui->buttonGroup->setExclusive(true);
    ui->wyslij->setEnabled(1);
    ui->stackedWidget->setCurrentIndex(1);
    QPixmap pixmap6("pictures/pilkanozna.png");
    ui->kat1->setPixmap(pixmap6);
    QPixmap pixmap7("pictures/informatyka.png");
    ui->kat2->setPixmap(pixmap7);
    QPixmap pixmap8("pictures/skokinarciarskie.png");
    ui->kat3->setPixmap(pixmap8);
    QPixmap pixmap9("pictures/geografia.png");
    ui->kat4->setPixmap(pixmap9);
    if(nick=="")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }


}

void MainWindow::czytaj_pytania()
{
    QSettings pytania("pytania.ini", QSettings::IniFormat);
    QStringList list = pytania.childGroups();
    for(auto i:list)
    {
        pytania.beginGroup(i);
        QString id = pytania.value("id").toString();
        QString kategoria = pytania.value("kat").toString();
        QString tresc = pytania.value("Tresc").toStringList().join(",");
        QString a = pytania.value("odp_a").toStringList().join(",");
        QString b = pytania.value("odp_b").toStringList().join(",");
        QString c = pytania.value("odp_c").toStringList().join(",");
        QString d = pytania.value("odp_d").toStringList().join(",");
        QString poprawna = pytania.value("poprawna").toStringList().join(",");
        pyt->Wpisz(tresc.toStdString().c_str(),a.toStdString().c_str(),b.toStdString().c_str(),c.toStdString().c_str(),d.toStdString().c_str(),poprawna.toStdString().c_str(),kategoria.toStdString().c_str(),id.toStdString().c_str());
        l1->Dodaj(*pyt);
        pytania.endGroup();
    }
}
void MainWindow::on_Kategoria1_clicked()
{
    kategoria="Piłka nożna";
    dobre=0;
    timer.start();
    ui->stackedWidget->setCurrentIndex(2);
    delete lk;
    lk = new ListaPytan;
    delete pomoc;
    pomoc = new Pytanie;
    *lk=l1->losuj(1);
    *pomoc = lk->get_pytanie();
    ui->Pytanie->setText(lk->get_pytanie().get_pyt_tresc());
    ui->radioButton_1->setText(lk->get_pytanie().get_odp_a());
    ui->radioButton_2->setText(lk->get_pytanie().get_odp_b());
    ui->radioButton_3->setText(lk->get_pytanie().get_odp_c());
    ui->radioButton_4->setText(lk->get_pytanie().get_odp_d());
 }

void MainWindow::on_Kategoria2_clicked()
{
    kategoria="Informatyka";
    dobre=0;
    timer.start();
    ui->stackedWidget->setCurrentIndex(2);
    delete lk;
    lk = new ListaPytan;
    delete pomoc;
    pomoc = new Pytanie;
    *lk=l1->losuj(2);
    *pomoc = lk->get_pytanie();
    ui->Pytanie->setText(lk->get_pytanie().get_pyt_tresc());
    ui->radioButton_1->setText(lk->get_pytanie().get_odp_a());
    ui->radioButton_2->setText(lk->get_pytanie().get_odp_b());
    ui->radioButton_3->setText(lk->get_pytanie().get_odp_c());
    ui->radioButton_4->setText(lk->get_pytanie().get_odp_d());
}

void MainWindow::on_Kategoria3_clicked()
{
    kategoria="Skoki narciarskie";
    dobre=0;
    timer.start();
    ui->stackedWidget->setCurrentIndex(2);
    delete lk;
    lk = new ListaPytan;
    delete pomoc;
    pomoc = new Pytanie;
    *lk=l1->losuj(3);
    *pomoc = lk->get_pytanie();
    ui->Pytanie->setText(lk->get_pytanie().get_pyt_tresc());
    ui->radioButton_1->setText(lk->get_pytanie().get_odp_a());
    ui->radioButton_2->setText(lk->get_pytanie().get_odp_b());
    ui->radioButton_3->setText(lk->get_pytanie().get_odp_c());
    ui->radioButton_4->setText(lk->get_pytanie().get_odp_d());
}

void MainWindow::on_Kategoria4_clicked()
{
    kategoria="Geografia";
    dobre=0;
    timer.start();
    ui->stackedWidget->setCurrentIndex(2);
    delete lk;
    lk = new ListaPytan;
    delete pomoc;
    pomoc = new Pytanie;
    *lk=l1->losuj(4);
    *pomoc = lk->get_pytanie();
    ui->Pytanie->setText(lk->get_pytanie().get_pyt_tresc());
    ui->radioButton_1->setText(lk->get_pytanie().get_odp_a());
    ui->radioButton_2->setText(lk->get_pytanie().get_odp_b());
    ui->radioButton_3->setText(lk->get_pytanie().get_odp_c());
    ui->radioButton_4->setText(lk->get_pytanie().get_odp_d());
}

void MainWindow::on_pushButton_nick_clicked()
{
    nick=ui->lineEdit_nick->text();
    if(nick!="")
    {
        ui->label_nick->setText(nick);
        ui->label_nick2->setText(nick);
        ui->lineEdit_nick->setText("");
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_zmien_nick_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
