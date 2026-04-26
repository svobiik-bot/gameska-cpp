

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
    int respekt = 0;
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
/*funkce na vypis konika*/
void vypis_kun(kun k)
{
    cout << "  _^_ _^_                       " << k.jmeno << " (" << k.plemeno << ")" << endl;
    cout << " / ^ __   \\                     " << "HP: " << k.zivoty_ted_k << "/" << k.zivoty_k << " | Hlad kone: " << k.hunger_bar_k << endl;
    cout << "/_-_/   |_ \\__ __ __ __ __ _    " << "Pouto s konem: " << k.level_vernosti << " | Nebojacnost: " << k.nebojacnost << endl;
    cout << "        /   _-_--___---   \\ \\   " << "Rychlost kone: " << k.rychlost << " | Pece o kone: " << k.pece_o_kone << endl;
    cout << "        \\ ______________ /  |  " << endl;
    cout << "         |  |          |  | ***  " << endl;
    cout << "         |  |          |  |      " << endl;
    cout << "         |__|          |__|      " << endl;
}
/*Funkce na vypis postavy*/
void vypis_postava(postava p)
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
    if (p.typ == "Nacelnik Apacu")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "  |||||     " << p.jmeno << "(" << p.typ << ")\n";
        cout << " -------    " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << "  (o o)     " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << " | Respekt: " << p.respekt << endl;
        cout << " /|   |\\    " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "/ |___| \\   " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "  /   \\     " << "Pristup do rafinerie: " << p.pritstup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
    if (p.typ == "Ropny Magnat")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "    _____      " << p.jmeno << "(" << p.typ << ")\n";
        cout << "   |     |     " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << " --|_____|--   " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << endl;
        cout << "    (o o)      " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "    --|--      " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "   |  |  |     " << "Pristup do rafinerie: " << p.pritstup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "    /   \\     " << endl;
        cout << "   |     |     " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
    if (p.typ == "Bounty Hunter")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "      ____       " << p.jmeno << "(" << p.typ << ")\n";
        cout << "   __(____)__    " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << "     (e e)       " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << endl;
        cout << "    /| v |\\      " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "   / |___| \\     " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "    /     \\      " << "Pristup do rafinerie: " << p.pritstup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "   /_ __ __\\     " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
    if (p.typ == "Greenhorn")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "   ___     " << p.jmeno << "(" << p.typ << ")\n";
        cout << "  |___|    " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << "  (u u)    " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << endl;
        cout << "  --|--     " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "    |      " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "   / \\     " << "Pristup do rafinerie: " << p.pritstup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "  |   |    " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
}
void aktualizuj_obrazovku(postava hrac, kun muj_kun, string text_pribehu)
{
    cout << "\033[2J\033[1;1H";

    vypis_postava(hrac);
    vypis_kun(muj_kun);

    cout << "------------------------------------------" << endl;
    cout << text_pribehu << endl;
}
int main()
{
    postava opilec;
    opilec.zivoty = 25;
    opilec.zivoty_ted = 25;
    opilec.utok_bez_zbrane = 2;

    postava hrac;
    kun muj_kun;
    int volba = 0;

    cout << "-------Vitam te cizince na divokem zapade-------\n";
    cout << "Za jakou postavu by jsi si pral hrat\n";
    cout << "1-Nacelnik Apacu\n2-Ropny magnat\n3-Lovec Odmen\n4-Greenhorn\n";

    bool jistota = true;
    while (jistota)
    {
        cout << "\nKlidne si muzes prohlednout specifikace postav a pak si teprve vybrat\n";
        cin >> volba;
        switch (volba)
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
            hrac.respekt = 50;
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
            hrac.respekt = 20;
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
            hrac.respekt = 60;
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
            hrac.respekt = 0;
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
        vypis_postava(hrac);
        vypis_kun(muj_kun);
        int jista_volba = 0;
        cin >> jista_volba;
        if (jista_volba == 1)
        {
            jistota = false;
        }
    }

    aktualizuj_obrazovku(hrac, muj_kun, "Dojel jsi do mesta Valentine. Ztratil jsi svou zbran, ale jako by ti pralo stesti, mistni Smith´s Iron & Lead pro tebe jednu ma.\nTaky mas moznost pojmenovat sveho kone.");
    cin >> muj_kun.jmeno;
    aktualizuj_obrazovku(hrac, muj_kun, "Sveho kone jsi pojmenoval: ");
    cout << muj_kun.jmeno;

    aktualizuj_obrazovku(hrac, muj_kun, "Nasednes na " + muj_kun.jmeno + ".\nPo ceste do mistniho lokalu te nekdo shodi z kone\nJe to nejaky misti ozrala a vyzval te na souboj");
    cout << "\nUbral ti 1 Hp !TED JSI NA RADE TY!";
    hrac.zivoty_ted -= 1;
    /*boj*/
    while (hrac.zivoty_ted > 0 || opilec.zivoty_ted)
    {
        cout << "\nTvoje Hp: " << hrac.zivoty_ted << " | Opilcovo Hp: " << opilec.zivoty_ted << endl;
        if (opilec.zivoty_ted > 5)
        {
            cout << "Zde jsou tvoje možnosti: Pokusit se mu to vymluvit(1), Dat mu zpet jednu pesti(2) -- spotrebuje 1 dead eye utect(3)\n";
            cin >> volba;
            if (volba == 1)
            {
                if (hrac.respekt >= 50)
                {
                    cout << "Diky tvemu respektu se mu to podarilo vymluvit a gringo si radsi sel po svejch\n";
                    break;
                }
                else
                {
                    cout << "Bohuzel nemas dostatecny respekt a gringo ti jeste jednu k tomu napalil\n";
                    hrac.zivoty_ted--;
                }
            }
            if (volba == 2)
            {
                opilec.zivoty_ted -= hrac.utok_bez_zbrane;
                cout << "Zasadil jsi mi poradnou ranu a trochu se zapotacel\n Presto se ale zvednual a dal ti taky jednu\n";
                hrac.zivoty_ted -= opilec.utok_bez_zbrane;
            }
            if (volba == 3)
            {
                cout << "Rozhodl jsi se utect, opilce jsi tedy nechal tam kde je a vzal nohy do zajecich.\nTady u nas na zapade je ale dulezite, i jak te vnimaji ostatni. Timto jsi si ubral respekt. Priste na to pozor";
                hrac.respekt -= 6;
                break;
            }
        }
        else
        {
            cout << "\nChudak uz dostal tolik ran ze ani nestoji. Pustis ho(1) nebo ho umlatis k smrti(2).(prece jen si zacal a tady vitezi ten silnejsi)\n";
            cin >> volba;
            if (volba == 1)
            {
                cout << "Gringo od tebe dostal za ponaucenou. Tim ze jsi ho pustil, jsi dokazal ze si za necim stojis a ziskal jsi cest\n";
                hrac.honor += 5;
            }
            if (volba == 2)
            {
                hrac.honor -= 5;
                hrac.respekt += 5;
                cout << "Zabijeni lidi kdyz jsou bezmocni snizuje tovji cest.\n Tim ze to videli ostatni lidi, jsi vsak dostal vice respektu\n";
            }
            break;
        }
    }
    aktualizuj_obrazovku(hrac, muj_kun, "");

    if (hrac.zivoty_ted <= 0)
    {
        cout << "\n*******Bohuzel jsi neprezil WESTERN*******";
        cout << "*******YOU ARE DEAD MAN*******";
        return 0;
    }
}
