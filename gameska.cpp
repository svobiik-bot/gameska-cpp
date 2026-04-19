

#include <iomanip>
#include <iostream>
using namespace std;

struct postava
{
    string jmeno = " ";
    string typ = " ";
    /*Zakladni zivotni hodnoty*/
    int zivoty = 0;
    int zivoty_ted = 0;
    int dead_eye = 0;
    int dead_eye_ted = 0;
    int hunger_bar = 0;
    int hunger_bar_ted = 0;

    int zlato = 0;
    int level = 0;
    int zkusenosti = 0;
    /*Vysoky honor bude 100 a nizky -100*/
    int honor = 0;
    /*vlastnosti boj */
    int plizeni = 0;
    int utok_bez_zbrane = 0;
    int znalec_prirody = 0;
    /* zbrane */
    bool luk = false; /*dostupne jen pri pratelstvi s indiany a treninkem*/
    /*dosazen jen 100+- honor*/
    bool dvojity_r_high_honor = false; /*sance na uzdraveni pri likvidovani nepratel*/
    bool brokovnice_low_honor = false; /*vetsi sance na padnuti zlata*/
    /*Vnimani postavy lidmi a lokace*/
    bool pritstup_rafinerie = false;
    bool pristup_velke_mesto = false;
    bool pratelstvi_s_indiany = false; /*honor nesmi byt mensi nez -50*/
};
struct kun
{
    string jmeno;
    string barva;
    string plemeno;

    int zivoty_k = 0;
    int zivoty_ted_k = 0;
    int level_vernosti = 0;
    int nebojacnost = 0;
    int rychlost = 0;
    int hunger_bar_k = 0;
    int pece_o_kone = 0;
};

/*Funkce na vypis postavy*/
void vypis_vse(string pribeh, postava p)
{

    string barva_honoru = "\033[0m";
    if (p.honor < -50)
    {
        barva_honoru = "\033[31m";
    };
    if (p.honor > 50)
    {
        barva_honoru = "\033[37m";
    };
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "" << p.jmeno << "(" << p.typ << ")\n";
    cout << "" << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
    cout << "" << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << endl;
    cout << "" << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
    cout << "" << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
    cout << "" << "Pristup do rafinerie: " << p.pritstup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "--- Událost tohoto dne ---" << endl;
    cout << pribeh << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

int main()
{
    postava hrac;
    kun muj_kun;
    int volba_postavy = 0;

    cout << "-------Vitam te cizince na divokem zapade-------\n";
    cout << "Za jakou postavu by jsi si pral hrat\n";
    cout << "1-Nacelnik Apacu\n2-Ropny magnat\n3-Lovec Odmen\n4-Greenhorn\n";

    bool jistota = true;
    while (jistota)
    {
        cout << "\nKlidne si muzes prohlednout specifikace postav a pak si teprve vybrat\n";
        cin >> volba_postavy;
        switch (volba_postavy)
        {
        /*Voba nacelnik apacu*/
        case 1:
            hrac.jmeno = "Rychli Sip";
            hrac.typ = "Nacelnik Apacu";
            hrac.hunger_bar = 100;
            hrac.hunger_bar_ted = 100;
            hrac.zivoty = 140;
            hrac.zivoty_ted = 140;
            hrac.dead_eye = 120;
            hrac.dead_eye_ted = 120;

            hrac.zlato = 500;
            hrac.level = 0;
            hrac.zkusenosti = 0;
            hrac.honor = 50;
            hrac.plizeni = 75;
            hrac.utok_bez_zbrane = 15;
            hrac.znalec_prirody = 100;
            /* zbrane */
            hrac.luk = true;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            /*Vnimani postavy lidmi*/
            hrac.pritstup_rafinerie = false;
            hrac.pristup_velke_mesto = false;
            hrac.pratelstvi_s_indiany = true;

            /*Apacuv kun*/
            muj_kun.plemeno = "Mustang";
            muj_kun.barva = "Hneda";
            muj_kun.hunger_bar_k = 100;
            muj_kun.level_vernosti = 3;
            muj_kun.pece_o_kone = 100;
            muj_kun.nebojacnost = 60;
            muj_kun.rychlost = 65;
            muj_kun.zivoty_k = 100;
            muj_kun.zivoty_ted_k = 100;
            break;
        /*Volba Ropny magnat*/
        case 2:
            hrac.jmeno = "Leopold Cornwall";
            hrac.typ = "Ropny Magnat";
            hrac.hunger_bar = 100;
            hrac.hunger_bar_ted = 100;
            hrac.zivoty = 70;
            hrac.zivoty_ted = 70;
            hrac.dead_eye = 50;
            hrac.dead_eye_ted = 50;

            hrac.zlato = 1300;
            hrac.level = 0;
            hrac.zkusenosti = 0;
            hrac.honor = -50;
            hrac.plizeni = 0;
            hrac.utok_bez_zbrane = 5;
            hrac.znalec_prirody = 0;
            /* zbrane */
            hrac.luk = false;
            /*dosazeni bud pri 100 +-*/
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            /*Vnimani postavy lidmi a lokace*/
            hrac.pritstup_rafinerie = true;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;

            /*kun*/
            muj_kun.plemeno = "Arabsky Plnokrevnik";
            muj_kun.barva = "Bila";
            muj_kun.hunger_bar_k = 100;
            muj_kun.level_vernosti = 0;
            muj_kun.pece_o_kone = 70;
            muj_kun.nebojacnost = 30;
            muj_kun.rychlost = 70;
            muj_kun.zivoty_k = 100;
            muj_kun.zivoty_ted_k = 100;
            break;
        /*Volba Bounty hounter*/
        case 3:
            hrac.jmeno = "Mortimer Schultz";
            hrac.typ = "Bounty Hunter";
            hrac.hunger_bar = 100;
            hrac.hunger_bar_ted = 80;
            hrac.zivoty = 110;
            hrac.zivoty_ted = 110;
            hrac.dead_eye = 140;
            hrac.dead_eye_ted = 140;

            hrac.zlato = 350;
            hrac.level = 0;
            hrac.zkusenosti = 0;
            hrac.honor = 0;
            hrac.plizeni = 30;
            hrac.utok_bez_zbrane = 12;
            hrac.znalec_prirody = 40;
            /* zbrane */
            hrac.luk = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            /*Vnimani postavy lidmi*/
            hrac.pritstup_rafinerie = false;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;

            /*kun*/
            muj_kun.plemeno = "Ardensky tazny";
            muj_kun.barva = "Hneda";
            muj_kun.hunger_bar_k = 100;
            muj_kun.level_vernosti = 2;
            muj_kun.pece_o_kone = 80;
            muj_kun.nebojacnost = 80;
            muj_kun.rychlost = 50;
            muj_kun.zivoty_k = 100;
            muj_kun.zivoty_ted_k = 100;
            break;
        /*Volba Greenhorn*/
        case 4:
            hrac.jmeno = "Rip Van Winkle";
            hrac.typ = "Greenhorn";
            hrac.hunger_bar = 100;
            hrac.hunger_bar_ted = 100;
            hrac.zivoty = 100;
            hrac.zivoty_ted = 100;
            hrac.dead_eye = 80;
            hrac.dead_eye_ted = 80;

            hrac.zlato = 120;
            hrac.level = 0;
            hrac.zkusenosti = 0;
            hrac.honor = 50;
            hrac.plizeni = 10;
            hrac.utok_bez_zbrane = 8;
            hrac.znalec_prirody = 20;
            /* zbrane */
            hrac.luk = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            /*Vnimani postavy lidmi*/
            hrac.pritstup_rafinerie = false;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;
            /*kun nema*/
            muj_kun.plemeno = "Morgan";
            muj_kun.barva = "Hneda";
            muj_kun.hunger_bar_k = 100;
            muj_kun.level_vernosti = 0;
            muj_kun.pece_o_kone = 50;
            muj_kun.nebojacnost = 50;
            muj_kun.rychlost = 35;
            muj_kun.zivoty_k = 100;
            muj_kun.zivoty_ted_k = 100;

            break;
        }
        string pribeh = " ";
        cout << "Jsi si jisty s vyberem postavy? Jestli chces znovu napis 0\n";
        vypis_vse(pribeh, hrac);
        int jista_volba = 0;
        cin >> jista_volba;
        if (jista_volba == 1)
        {
            jistota = false;
        }
    }
    string pribeh = "Dorazil jsi do mesta Valentine. Tvuj kun na tebe ceka na nadrazi\n";
    vypis_vse(pribeh, hrac);
}
