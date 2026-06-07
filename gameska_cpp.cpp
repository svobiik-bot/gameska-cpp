#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct nepritel
{
    string jmeno_n;
    int hp_n;
    int hp_max_n;
    int utok_n;
    bool ma_zbran;
    string zbran_n;
    string hlasky[3];
    int pocet_hlasek;
    int zlato_n;
    int xp_n;
    bool je_boss;
};

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
    bool winchesterovka = false;
    bool brokovnice = false;
    bool luk = false; /*dostupne jen pri pratelstvi s indiany a treninkem*/
    /*dosazen jen 100+- honor*/
    bool dvojity_r_high_honor = false; /*sance na uzdraveni pri likvidovani nepratel*/
    bool brokovnice_low_honor = false; /*vetsi sance na padnuti zlata*/
    /*Vnimani postavy lidmi a lokace*/
    bool pristup_rafinerie = false;
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

//  VYPIS KONE
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

//  VYPIS POSTAVY
void vypis_postava(postava p)
{
    string barva_honoru = "\033[0m";
    if (p.honor < -50)
    {
        barva_honoru = "\033[31m";
    }
    if (p.honor > 50)
    {
        barva_honoru = "\033[37m";
    }

    if (p.typ == "Nacelnik Apacu")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "  |||||     " << p.jmeno << "(" << p.typ << ")\n";
        cout << " -------    " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << "  (o o)     " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << " | Respekt: " << p.respekt << endl;
        cout << " /|   |\\    " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "/ |___| \\   " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "  /   \\     " << "Pristup do rafinerie: " << p.pristup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
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
        cout << "   |  |  |     " << "Pristup do rafinerie: " << p.pristup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
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
        cout << "    /     \\      " << "Pristup do rafinerie: " << p.pristup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "   /_ __ __\\     " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
    if (p.typ == "Greenhorn")
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "   ___     " << p.jmeno << "(" << p.typ << ")\n";
        cout << "  |___|    " << "HP: " << p.zivoty_ted << "/" << p.zivoty << "| Dead eye: " << p.dead_eye_ted << "/" << p.dead_eye << " | Hlad: " << p.hunger_bar_ted << "/" << p.hunger_bar << endl;
        cout << "  (u u)    " << "Zlato: " << p.zlato << "$ | Level:" << p.level << " | Zkusenosti: " << p.zkusenosti << " | Honor: " << barva_honoru << p.honor << "\033[0m" << endl;
        cout << "  --|--    " << "Plizeni: " << p.plizeni << " | Utok bez zbrane: " << p.utok_bez_zbrane << " | Znalost prirody: " << p.znalec_prirody << endl;
        cout << "    |      " << "Luk: " << p.luk << " | Dvojity high honor revolver: " << p.dvojity_r_high_honor << " | Brokovnice low honor: " << p.brokovnice_low_honor << endl;
        cout << "   / \\     " << "Pristup do rafinerie: " << p.pristup_rafinerie << " | Pristup do velkeho mesta: " << p.pristup_velke_mesto << " | Pratelstvi s Indiany: " << p.pratelstvi_s_indiany << endl;
        cout << "  |   |    " << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
}

//  AKTUALIZUJ OBRAZOVKU
void aktualizuj_obrazovku(postava hrac, kun muj_kun, string text_pribehu)
{
    cout << "\033[2J\033[1;1H";
    vypis_postava(hrac);
    vypis_kun(muj_kun);
    cout << "------------------------------------------" << endl;
    cout << text_pribehu << endl;
}

//  POMOCNE FUNKCE

void cekej()
{
    cout << "\n[Stiskni ENTER pro pokracovani...]";
    cin.ignore();
    cin.get();
}

//  LEVEL UP
void zkontroluj_level(postava &hrac)
{
    while (hrac.zkusenosti >= 100)
    {
        hrac.zkusenosti -= 100;
        hrac.level++;
        cout << "\n*** NOVY LEVEL POSTAVY! Jsi nyni level " << hrac.level << " ***\n";
        cout << "Ziskavas:\n";
        cout << "  Max zivoty       " << hrac.zivoty << " => " << hrac.zivoty + 20 << "\n";
        cout << "  Max Dead Eye     " << hrac.dead_eye << " => " << hrac.dead_eye + 15 << "\n";
        cout << "  Utok bez zbrane  " << hrac.utok_bez_zbrane << " => " << hrac.utok_bez_zbrane + 2 << "\n";
        cout << "  Respekt          " << hrac.respekt << " => " << hrac.respekt + 5 << "\n";
        hrac.zivoty += 20;
        hrac.zivoty_ted = min(hrac.zivoty_ted + 10, hrac.zivoty);
        hrac.dead_eye += 15;
        hrac.dead_eye_ted = min(hrac.dead_eye_ted + 10, hrac.dead_eye);
        hrac.utok_bez_zbrane += 2;
        hrac.respekt += 5;
    }
}

//  SOUBOJ (1 nepritel
bool souboj(postava &hrac, kun &muj_kun, nepritel &n, bool boss_tah_prvni = false)
{

    while (hrac.zivoty_ted > 0 && n.hp_n > 0)
    {
        aktualizuj_obrazovku(hrac, muj_kun, "BOJUJES: " + n.jmeno_n);
        if (n.je_boss)
        {
            if (n.hp_n > 0)
            {
                cout << n.jmeno_n << ": \"" << n.hlasky[rand() % n.pocet_hlasek] << "\"\n";
                cout << n.jmeno_n << " utoci pomoci " << n.zbran_n << " za " << n.utok_n << " hp!\n";
                hrac.zivoty_ted -= n.utok_n;
                if (hrac.zivoty_ted < 0)
                    hrac.zivoty_ted = 0;
            }
        }
        cout << "\n------------------------------------------\n";
        cout << "Nepritel: " << n.jmeno_n << " | HP: " << n.hp_n << "/" << n.hp_max_n << " | Zbran: " << n.zbran_n << endl;
        cout << "Tvoje HP: " << hrac.zivoty_ted << " | Dead Eye: " << hrac.dead_eye_ted << endl;
        cout << "------------------------------------------\n";

        cout << "Co udelas:\n";
        cout << "(1) Utok pesti    [" << hrac.utok_bez_zbrane << " hp, 0 dead eye]\n";
        cout << "(2) Strelba revolverem  [20 hp, 10 dead eye]\n";
        if (hrac.brokovnice)
            cout << "(3) Strelit z brokovnice  [50 hp, 45 dead eye]\n";
        if (hrac.winchesterovka)
            cout << "(4) Strelit z winchestrovky  [35 hp, 25 dead eye]\n";
        if (hrac.dvojity_r_high_honor)
            cout << "(5) Strelit z dvojiteho high honor revolveru  [65 hp, 30 dead eye]\n";
        if (hrac.brokovnice_low_honor)
            cout << "(6) Strelit z low honor brokovnice  [80 hp, 60 dead eye]\n";
        if (hrac.luk)
            cout << "(7) Vystrelit sipku z luku  [30 hp, 15 dead eye]\n";
        if (!n.je_boss)
            cout << "(0) Utect\n";

        int volba;
        cin >> volba;

        // Uteci
        if (volba == 0 && !n.je_boss)
        {
            if (muj_kun.rychlost >= 70)
            {
                cout << "Tvuj kun je dostatecne rychly — utikas!\n";
                cekej();
                return true;
            }
            else
            {
                cout << "Tvuj kun je moc pomaly, neutekl jsi!\n";
                // nepritel utoči
                cout << n.jmeno_n << " utoči pomoci " << n.zbran_n << " za " << n.utok_n << " hp!\n";
                hrac.zivoty_ted -= n.utok_n;
                cekej();
                continue;
            }
        }

        // Dead Eye kontrola
        if (hrac.dead_eye_ted <= 0 && volba >= 2 && volba <= 7)
        {
            cout << "Nemas dostatek Dead Eye! Bijes se pesti.\n";
            volba = 1;
        }

        // Tah hrace
        if (volba == 1)
        {
            n.hp_n -= hrac.utok_bez_zbrane;
            cout << "Dal jsi mu ranu za " << hrac.utok_bez_zbrane << " hp\n";
        }
        else if (volba == 2)
        {
            hrac.dead_eye_ted -= 10;
            n.hp_n -= 20;
            cout << "Strelil jsi ho revolverem za 20 hp\n";
        }
        else if (volba == 3 && hrac.brokovnice)
        {
            hrac.dead_eye_ted -= 45;
            n.hp_n -= 50;
            cout << "Dal jsi mu poradnou slupku brokovnici za 50 hp!\n";
        }
        else if (volba == 4 && hrac.winchesterovka)
        {
            hrac.dead_eye_ted -= 25;
            n.hp_n -= 35;
            cout << "Strelil jsi ho winchestrovkou za 35 hp\n";
        }
        else if (volba == 5 && hrac.dvojity_r_high_honor)
        {
            hrac.dead_eye_ted -= 30;
            n.hp_n -= 65;
            cout << "Strelil jsi z dvojiteho high honor revolveru za 65 hp!\n";
        }
        else if (volba == 6 && hrac.brokovnice_low_honor)
        {
            hrac.dead_eye_ted -= 60;
            n.hp_n -= 80;
            cout << "Strelil jsi z low honor brokovnice za 80 hp!\n";
        }
        else if (volba == 7 && hrac.luk)
        {
            hrac.dead_eye_ted -= 15;
            n.hp_n -= 30;
            cout << "Vystrelil jsi sip za 30 hp!\n";
        }
        else
        {
            cout << "Neplatna volba — bijes se pesti za " << hrac.utok_bez_zbrane << " hp.\n";
            n.hp_n -= hrac.utok_bez_zbrane;
        }

        if (hrac.dead_eye_ted < 0)
        {
            hrac.dead_eye_ted = 0;
        }
        if (n.hp_n < 0)
        {
            n.hp_n = 0;
        }
        // Tah nepritele
        if (n.hp_n > 0)
        {
            cout << n.jmeno_n << ": \"" << n.hlasky[rand() % n.pocet_hlasek] << "\"\n";
            cout << n.jmeno_n << " utoci pomoci " << n.zbran_n << " za " << n.utok_n << " hp!\n";
            hrac.zivoty_ted -= n.utok_n;
            if (hrac.zivoty_ted < 0)
                hrac.zivoty_ted = 0;
        }

        cekej();
    }

    // Vysledek
    if (hrac.zivoty_ted <= 0)
    {
        cout << "\n!!! PROHRALS !!! " << n.jmeno_n << " te porazil. Hra konci.\n***********NEPREZIL JSI WESTERN GRINGO************\n";
        return false;
    }

    // Vitezstvi — odmena
    cout << "\n--- VITEZSTVI! " << n.jmeno_n << " byl porazen! ---\n";

    int zisk_xp = n.xp_n;
    int zisk_zlato = 0;

    if (n.zlato_n == -1)
    {
        // 50% sance na zlato
        if (rand() % 2 == 0)
            zisk_zlato = 10 + rand() % 20;
    }
    else
    {
        zisk_zlato = n.zlato_n; // miniboss/boss vzdy
    }

    if (hrac.dvojity_r_high_honor || hrac.brokovnice_low_honor)
    {
        zisk_xp += 5;
        zisk_zlato += 10;
        cout << "Diky tvym legendarnim zbranim jsi ziskal bonusovou korist!\n";
    }

    hrac.zkusenosti += zisk_xp;
    hrac.zlato += zisk_zlato;
    int obnova_de = 10;
    hrac.dead_eye_ted = min(hrac.dead_eye_ted + obnova_de, hrac.dead_eye);

    cout << "Ziskal jsi: " << zisk_xp << " XP";
    if (zisk_zlato > 0)
        cout << ", " << zisk_zlato << "$";
    else
        cout << " (zadne zlato)";
    cout << " a " << obnova_de << " Dead Eye.\n";

    zkontroluj_level(hrac);
    cekej();
    return true;
}

//  SOUBOJ VICE NEPRATEL
bool souboj_vice(postava &hrac, kun &muj_kun, nepritel nepratele[], int pocet)
{
    while (hrac.zivoty_ted > 0)
    {
        //  jestli jsou jeste zivi
        bool nekdo_zije = false;
        for (int i = 0; i < pocet; i++)
            if (nepratele[i].hp_n > 0)
                nekdo_zije = true;
        if (!nekdo_zije)
            break;

        aktualizuj_obrazovku(hrac, muj_kun, "SOUBOJ S VICE NEPRATELI!");

        cout << "\nNepratele:\n";
        for (int i = 0; i < pocet; i++)
        {
            if (nepratele[i].hp_n > 0)
                cout << "  [" << i + 1 << "] " << nepratele[i].jmeno_n << " HP: " << nepratele[i].hp_n << "/" << nepratele[i].hp_max_n << "\n";
            else
                cout << "  [" << i + 1 << "] " << nepratele[i].jmeno_n << " [MRTVY]\n";
        }
        cout << "Tvoje HP: " << hrac.zivoty_ted << " | Dead Eye: " << hrac.dead_eye_ted << "\n";

        // Vyber cil
        int cil = 0;
        if (pocet > 1)
        {
            cout << "Na koho utocis? (1-" << pocet << "): ";
            cin >> cil;
            cil--;
            // Validace
            if (cil < 0 || cil >= pocet || nepratele[cil].hp_n <= 0)
            {
                for (int i = 0; i < pocet; i++)
                    if (nepratele[i].hp_n > 0)
                    {
                        cil = i;
                        break;
                    }
            }
        }

        cout << "\nUtocis na: " << nepratele[cil].jmeno_n << "\n";
        cout << "Co udelas:\n";
        cout << "(1) Utok pesti    [" << hrac.utok_bez_zbrane << " hp]\n";
        cout << "(2) Revolver  [20 hp, 10 dead eye]\n";
        if (hrac.brokovnice)
            cout << "(3) Brokovnice  [50 hp, 45 dead eye]\n";
        if (hrac.winchesterovka)
            cout << "(4) Winchester  [35 hp, 25 dead eye]\n";
        if (hrac.dvojity_r_high_honor)
            cout << "(5) Dvojity revolver  [65 hp, 30 dead eye]\n";
        if (hrac.brokovnice_low_honor)
            cout << "(6) LH brokovnice  [80 hp, 60 dead eye]\n";
        if (hrac.luk)
            cout << "(7) Luk  [30 hp, 15 dead eye]\n";
        cout << "(0) Utect\n";

        int volba;
        cin >> volba;

        if (volba == 0)
        {
            if (muj_kun.rychlost >= 70)
            {
                cout << "Utikas pryc!\n";
                cekej();
                return true;
            }
            else
            {
                cout << "Kun je prilis pomaly!\n";
            }
        }
        else
        {
            if (hrac.dead_eye_ted <= 0 && volba >= 2 && volba <= 7)
            {
                cout << "Malo Dead Eye! Bijes pesti.\n";
                volba = 1;
            }
            int dmg = 0;
            switch (volba)
            {
            case 1:
                dmg = hrac.utok_bez_zbrane;
                cout << "Rana za " << dmg << " hp!\n";
                break;
            case 2:
                hrac.dead_eye_ted -= 10;
                dmg = 20;
                cout << "Revolver za 20 hp!\n";
                break;
            case 3:
                if (hrac.brokovnice)
                {
                    hrac.dead_eye_ted -= 45;
                    dmg = 50;
                    cout << "Brokovnice za 50 hp!\n";
                }
                else
                {
                    dmg = hrac.utok_bez_zbrane;
                    cout << "Nemas! Pest.\n";
                }
                break;
            case 4:
                if (hrac.winchesterovka)
                {
                    hrac.dead_eye_ted -= 25;
                    dmg = 35;
                    cout << "Winchester za 35 hp!\n";
                }
                else
                {
                    dmg = hrac.utok_bez_zbrane;
                    cout << "Nemas! Pest.\n";
                }
                break;
            case 5:
                if (hrac.dvojity_r_high_honor)
                {
                    hrac.dead_eye_ted -= 30;
                    dmg = 65;
                    cout << "High honor revolver za 65 hp!\n";
                }
                else
                {
                    dmg = hrac.utok_bez_zbrane;
                    cout << "Pest.\n";
                }
                break;
            case 6:
                if (hrac.brokovnice_low_honor)
                {
                    hrac.dead_eye_ted -= 60;
                    dmg = 80;
                    cout << "Low Honor Brokovnice za 80 hp!\n";
                }
                else
                {
                    dmg = hrac.utok_bez_zbrane;
                    cout << "Pest.\n";
                }
                break;
            case 7:
                if (hrac.luk)
                {
                    hrac.dead_eye_ted -= 15;
                    dmg = 30;
                    cout << "Sip za 30 hp!\n";
                }
                else
                {
                    dmg = hrac.utok_bez_zbrane;
                    cout << "Nemas luk! Pest.\n";
                }
                break;
            default:
                dmg = hrac.utok_bez_zbrane;
                cout << "Pest za " << dmg << " hp.\n";
            }
            if (hrac.dead_eye_ted < 0)
                hrac.dead_eye_ted = 0;
            nepratele[cil].hp_n -= dmg;
            if (nepratele[cil].hp_n <= 0)
            {
                nepratele[cil].hp_n = 0;
                cout << nepratele[cil].jmeno_n << " byl porazen!\n";
            }
        }

        // Tah vsech zivych nepriatel
        for (int i = 0; i < pocet; i++)
        {
            if (nepratele[i].hp_n > 0)
            {
                cout << nepratele[i].jmeno_n << ": \"" << nepratele[i].hlasky[rand() % nepratele[i].pocet_hlasek] << "\"\n";
                cout << nepratele[i].jmeno_n << " utoči za " << nepratele[i].utok_n << " hp!\n";
                hrac.zivoty_ted -= nepratele[i].utok_n;
                if (hrac.zivoty_ted < 0)
                    hrac.zivoty_ted = 0;
            }
        }
        cekej();
    }

    if (hrac.zivoty_ted <= 0)
    {
        cout << "\n!!! PROHRALS !!! Hra konci.\n";
        return false;
    }

    cout << "\n=== VITEZSTVI! ===\n";
    int celk_xp = 0, celk_zlato = 0;
    for (int i = 0; i < pocet; i++)
    {
        celk_xp += nepratele[i].xp_n;
        if (nepratele[i].zlato_n == -1)
        {
            if (rand() % 2 == 0)
                celk_zlato += 10 + rand() % 20;
        }
        else
        {
            celk_zlato += nepratele[i].zlato_n;
        }
    }
    if (hrac.dvojity_r_high_honor || hrac.brokovnice_low_honor)
    {
        celk_xp += 10;
        celk_zlato += 15;
    }
    hrac.zkusenosti += celk_xp;
    hrac.zlato += celk_zlato;
    int de_obn = 15;
    hrac.dead_eye_ted = min(hrac.dead_eye_ted + de_obn, hrac.dead_eye);
    cout << "Ziskal jsi " << celk_xp << " XP, " << celk_zlato << " zlata, Dead Eye +" << de_obn << ".\n";
    zkontroluj_level(hrac);
    cekej();
    return true;
}

bool souboj_boss(postava &hrac, kun &muj_kun, nepritel &n)
{
    while (hrac.zivoty_ted > 0)
    {
        bool hrac_zmrazeni = false;
        aktualizuj_obrazovku(hrac, muj_kun, "Souboj s finalnim bossem\n Jeho ability: sance na paraliovani tebe\n");
        int nahodne_cislo = rand() % 100 + 1;
        if (n.hp_n > 0)
        {
            if (nahodne_cislo <= 30)
            {
                hrac_zmrazeni = true;
                cout << "Cronwall te zastavil svou statickou elektrinou\n nemuzes nic delat a on se doheeluje +5hp a dostane utok +1hp ";
            }
            if (n.hp_n > 0)
            {
                cout << n.jmeno_n << ": \"" << n.hlasky[rand() % n.pocet_hlasek] << "\"\n";
                cout << n.jmeno_n << " utoci pomoci " << n.zbran_n << " za " << n.utok_n << " hp!\n";
                hrac.zivoty_ted -= n.utok_n;
                if (hrac.zivoty_ted < 0)
                {
                    hrac.zivoty_ted = 0;
                }
            }

            cekej();
        }
        if (nahodne_cislo <= 30)
        {
            hrac_zmrazeni = true;
            cout << "Cronwall te zastavil svou statickou elektrinou\n nemuzes nic delat a on se doheeluje +5hp a dostane utok +1hp ";
        }
        if (hrac_zmrazeni == false && hrac.zivoty_ted > 0)
        {
            cout << "Co udelas:\n";
            cout << "(1) Utok pesti    [" << hrac.utok_bez_zbrane << " hp, 0 dead eye]\n";
            cout << "(2) Strelba revolverem  [20 hp, 10 dead eye]\n";
            if (hrac.brokovnice)
            {
                cout << "(3) Strelit z brokovnice  [50 hp, 45 dead eye]\n";
            }
            if (hrac.winchesterovka)
            {
                cout << "(4) Strelit z winchestrovky  [35 hp, 25 dead eye]\n";
            }
            if (hrac.dvojity_r_high_honor)
            {
                cout << "(5) Strelit z dvojiteho high honor revolveru  [65 hp, 30 dead eye]\n";
            }
        }
        if (hrac.brokovnice_low_honor)
        {
            cout << "(6) Strelit z low honor brokovnice  [80 hp, 60 dead eye]\n";
        }
        if (hrac.luk)
        {
            cout << "(7) Vystrelit sipku z luku  [30 hp, 15 dead eye]\n";
        }

        int volba;
        cin >> volba;

        // Dead Eye kontrola
        if (hrac.dead_eye_ted <= 0 && volba >= 2 && volba <= 7)
        {
            cout << "Nemas dostatek Dead Eye! Bijes se pesti.\n";
            volba = 1;
        }

        // Tah hrace
        if (volba == 1)
        {
            n.hp_n -= hrac.utok_bez_zbrane;
            cout << "Dal jsi mu ranu za " << hrac.utok_bez_zbrane << " hp\n";
        }
        else if (volba == 2)
        {
            hrac.dead_eye_ted -= 10;
            n.hp_n -= 20;
            cout << "Strelil jsi ho revolverem za 20 hp\n";
        }
        else if (volba == 3 && hrac.brokovnice)
        {
            hrac.dead_eye_ted -= 45;
            n.hp_n -= 50;
            cout << "Dal jsi mu poradnou slupku brokovnici za 50 hp!\n";
        }
        else if (volba == 4 && hrac.winchesterovka)
        {
            hrac.dead_eye_ted -= 25;
            n.hp_n -= 35;
            cout << "Strelil jsi ho winchestrovkou za 35 hp\n";
        }
        else if (volba == 5 && hrac.dvojity_r_high_honor)
        {
            hrac.dead_eye_ted -= 30;
            n.hp_n -= 65;
            cout << "Strelil jsi z dvojiteho high honor revolveru za 65 hp!\n";
        }
        else if (volba == 6 && hrac.brokovnice_low_honor)
        {
            hrac.dead_eye_ted -= 60;
            n.hp_n -= 80;
            cout << "Strelil jsi z low honor brokovnice za 80 hp!\n";
        }
        else if (volba == 7 && hrac.luk)
        {
            hrac.dead_eye_ted -= 15;
            n.hp_n -= 30;
            cout << "Vystrelil jsi sip za 30 hp!\n";
        }
        else
        {
            cout << "Neplatna volba — bijes se pesti za " << hrac.utok_bez_zbrane << " hp.\n";
            n.hp_n -= hrac.utok_bez_zbrane;
        }

        if (hrac.dead_eye_ted < 0)
        {
            hrac.dead_eye_ted = 0;
        }
    }
}
//  VESNICE

void vesnice(postava &hrac, kun &muj_kun, string nazev)
{
    aktualizuj_obrazovku(hrac, muj_kun, "Vitej ve vesnici " + nazev + "!");
    bool ve_vesnici = true;
    while (ve_vesnici)
    {
        cout << "\n=== VESNICE: " << nazev << " === Tvoje zlato: " << hrac.zlato << "$\n";
        cout << "(1) Lekar — doplnit HP na maximum               [30$]\n";
        cout << "(2) Vylepsit max HP                             [50$]\n";
        cout << "(3) Doplnit Dead Eye na maximum                 [20$]\n";
        cout << "(4) Vylepsit max Dead Eye                       [40$]\n";
        cout << "(5) Vylepsit utok bez zbrane                    [35$]\n";
        cout << "(6) Koupit brokovnici                           [80$]\n";
        cout << "(7) Koupit Winchester                           [90$]\n";
        cout << "(8) Nakrmit a ocistit kone                      [15$]\n";
        cout << "(0) Odjet z mesta\n";
        cout << "Volba: ";
        int volba;
        cin >> volba;

        switch (volba)
        {
        case 1:
            if (hrac.zlato >= 30)
            {
                hrac.zlato -= 30;
                hrac.zivoty_ted = hrac.zivoty;
                cout << "HP doplneno na maximum: " << hrac.zivoty << "\n";
            }
            else
                cout << "Malo zlata! Potrebujes 30$.\n";
            break;
        case 2:
            if (hrac.zlato >= 50)
            {
                hrac.zlato -= 50;
                hrac.zivoty += 20;
                cout << "Max HP zvysen: " << hrac.zivoty - 20 << " => " << hrac.zivoty << "\n";
            }
            else
                cout << "Malo zlata! Potrebujes 50$.\n";
            break;
        case 3:
            if (hrac.zlato >= 20)
            {
                hrac.zlato -= 20;
                hrac.dead_eye_ted = hrac.dead_eye;
                cout << "Dead Eye doplneno na maximum: " << hrac.dead_eye << "\n";
            }
            else
                cout << "Malo zlata! Potrebujes 20$.\n";
            break;
        case 4:
            if (hrac.zlato >= 40)
            {
                hrac.zlato -= 40;
                hrac.dead_eye += 20;
                cout << "Max Dead Eye zvysen: " << hrac.dead_eye - 20 << " => " << hrac.dead_eye << "\n";
            }
            else
                cout << "Malo zlata! Potrebujes 40$.\n";
            break;
        case 5:
            if (hrac.zlato >= 35)
            {
                hrac.zlato -= 35;
                hrac.utok_bez_zbrane += 3;
                cout << "Utok bez zbrane zvysen o 3 => " << hrac.utok_bez_zbrane << "\n";
            }
            else
                cout << "Malo zlata! Potrebujes 35$.\n";
            break;
        case 6:
            if (hrac.brokovnice)
                cout << "Uz mas brokovnici.\n";
            else if (hrac.zlato >= 80)
            {
                hrac.zlato -= 80;
                hrac.brokovnice = true;
                cout << "Brokovnice zakoupena!\n";
            }
            else
                cout << "Malo zlata! Potrebujes 80$.\n";
            break;
        case 7:
            if (hrac.winchesterovka)
                cout << "Uz mas Winchester.\n";
            else if (hrac.zlato >= 90)
            {
                hrac.zlato -= 90;
                hrac.winchesterovka = true;
                cout << "Winchester zakoupen!\n";
            }
            else
                cout << "Malo zlata! Potrebujes 90$.\n";
            break;
        case 8:
            if (hrac.zlato >= 15)
            {
                hrac.zlato -= 15;
                muj_kun.hunger_bar_k = 100;
                muj_kun.pece_o_kone = min(muj_kun.pece_o_kone + 10, 100);
                cout << "Kun je nakrmen a ostan.\n";
            }
            else
                cout << "Malo zlata! Potrebujes 15$.\n";
            break;
        case 0:
            ve_vesnici = false;
            break;
        default:
            cout << "Neplatna volba.\n";
        }
        if (volba != 0)
            cekej();
    }
}

// nepratele
nepritel opilec()
{
    nepritel n;
    n.jmeno_n = "Opily Gringo";
    n.hp_n = 25;
    n.hp_max_n = 25;
    n.utok_n = 2;
    n.ma_zbran = false;
    n.zbran_n = "Pesti";
    n.hlasky[0] = "Hic! Podrz mi klobouk!";
    n.hlasky[1] = "Kdo jsi ty, cizince? Hic!";
    n.hlasky[2] = "Vrazim se do tebe!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 10;
    n.je_boss = false;
    return n;
}
nepritel bandita()
{
    nepritel n;
    n.jmeno_n = "Bandita";
    n.hp_n = 40;
    n.hp_max_n = 40;
    n.utok_n = 6;
    n.ma_zbran = true;
    n.zbran_n = "Revolver";
    n.hlasky[0] = "Vzdej se nebo zemres!";
    n.hlasky[1] = "Tvoje zlato nebo zivot!";
    n.hlasky[2] = "Na tomhle zapade budes jen prach!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 15;
    n.je_boss = false;
    return n;
}
nepritel kojot()
{
    nepritel n;
    n.jmeno_n = "Divoki Kojot";
    n.hp_n = 30;
    n.hp_max_n = 30;
    n.utok_n = 5;
    n.ma_zbran = false;
    n.zbran_n = "Drápy a zuby";
    n.hlasky[0] = "AWOOOO!";
    n.hlasky[1] = "Ssss... Grrr!";
    n.hlasky[2] = "Vrrrr...";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 12;
    n.je_boss = false;
    return n;
}
nepritel had()
{
    nepritel n;
    n.jmeno_n = "Jedovaty Had";
    n.hp_n = 20;
    n.hp_max_n = 20;
    n.utok_n = 8;
    n.ma_zbran = false;
    n.zbran_n = "Kousnutí jedem";
    n.hlasky[0] = "Sss...";
    n.hlasky[1] = "Tss...";
    n.hlasky[2] = "Ssyyyyy...";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 12;
    n.je_boss = false;
    return n;
}
nepritel zbojnik()
{
    nepritel n;
    n.jmeno_n = "Hadac";
    n.hp_n = 35;
    n.hp_max_n = 35;
    n.utok_n = 7;
    n.ma_zbran = true;
    n.zbran_n = "Nuz";
    n.hlasky[0] = "Neber mi penize!";
    n.hlasky[1] = "Odtud zivy nepujdes!";
    n.hlasky[2] = "Uz jsem zabil stovky jako ty!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 14;
    n.je_boss = false;
    return n;
}
nepritel puma()
{
    nepritel n;
    n.jmeno_n = "Puma";
    n.hp_n = 45;
    n.hp_max_n = 45;
    n.utok_n = 10;
    n.ma_zbran = false;
    n.zbran_n = "Spáry a tesáky";
    n.hlasky[0] = "RRROAARRR!";
    n.hlasky[1] = "Sss...";
    n.hlasky[2] = "Grrrr...";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 20;
    n.je_boss = false;
    return n;
}
nepritel sup()
{
    nepritel n;
    n.jmeno_n = "Sup Lidozrout";
    n.hp_n = 28;
    n.hp_max_n = 28;
    n.utok_n = 4;
    n.ma_zbran = false;
    n.zbran_n = "Zob a drápy";
    n.hlasky[0] = "SKREEEE!";
    n.hlasky[1] = "Kaaaaw!";
    n.hlasky[2] = "SKREE SKREE!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 10;
    n.je_boss = false;
    return n;
}
nepritel opily_kovboj()
{
    nepritel n;
    n.jmeno_n = "Opily Kovboj";
    n.hp_n = 38;
    n.hp_max_n = 38;
    n.utok_n = 6;
    n.ma_zbran = true;
    n.zbran_n = "Revolver";
    n.hlasky[0] = "Nemam rad cizince!";
    n.hlasky[1] = "Tady je muj bar!";
    n.hlasky[2] = "Odtud to nevyjdes!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 13;
    n.je_boss = false;
    return n;
}
nepritel zlodej()
{
    nepritel n;
    n.jmeno_n = "Zlodej z prepadeni";
    n.hp_n = 42;
    n.hp_max_n = 42;
    n.utok_n = 7;
    n.ma_zbran = true;
    n.zbran_n = "Nuz";
    n.hlasky[0] = "Rychle zlato!";
    n.hlasky[1] = "Tohle bude rychle!";
    n.hlasky[2] = "Nikdo tu nic nevidel...";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 15;
    n.je_boss = false;
    return n;
}
nepritel tezky_bandita()
{
    nepritel n;
    n.jmeno_n = "Tezkoodeny Bandita";
    n.hp_n = 65;
    n.hp_max_n = 65;
    n.utok_n = 9;
    n.ma_zbran = true;
    n.zbran_n = "Brokovnice";
    n.hlasky[0] = "Tato cesta patri nam!";
    n.hlasky[1] = "Platte mydlne!";
    n.hlasky[2] = "Nevyjdete odtud!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 20;
    n.je_boss = false;
    return n;
}
nepritel mestsky_rvac()
{
    nepritel n;
    n.jmeno_n = "Mestsky Rvac";
    n.hp_n = 35;
    n.hp_max_n = 35;
    n.utok_n = 6;
    n.ma_zbran = false;
    n.zbran_n = "Pesti";
    n.hlasky[0] = "Wester chce boj!";
    n.hlasky[1] = "Jdeme si o to!";
    n.hlasky[2] = "Nosis pistole, ne zbabělost!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 13;
    n.je_boss = false;
    return n;
}
nepritel pijak()
{
    nepritel n;
    n.jmeno_n = "Pijak Whiskey";
    n.hp_n = 32;
    n.hp_max_n = 32;
    n.utok_n = 5;
    n.ma_zbran = true;
    n.zbran_n = "Lahev";
    n.hlasky[0] = "Hic... chces dostat?";
    n.hlasky[1] = "Whiskey nebo smrt!";
    n.hlasky[2] = "Tahle lahev ma i tebe!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 11;
    n.je_boss = false;
    return n;
}
nepritel dezertér()
{
    nepritel n;
    n.jmeno_n = "Vojensky Dezertér";
    n.hp_n = 55;
    n.hp_max_n = 55;
    n.utok_n = 8;
    n.ma_zbran = true;
    n.zbran_n = "Winchester";
    n.hlasky[0] = "Uz nechci slyset rozkazy!";
    n.hlasky[1] = "Zachran se kdo muzes!";
    n.hlasky[2] = "Pres moje telo!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 17;
    n.je_boss = false;
    return n;
}
nepritel cornwall_straz()
{
    nepritel n;
    n.jmeno_n = "cornwall_straz";
    n.hp_n = 48;
    n.hp_max_n = 48;
    n.utok_n = 8;
    n.ma_zbran = true;
    n.zbran_n = "Revolver";
    n.hlasky[0] = "Elegance i zlo!";
    n.hlasky[1] = "Tento kabat pokryje tvoji krev!";
    n.hlasky[2] = "Promiňte, musim te zastrelit.";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 17;
    n.je_boss = false;
    return n;
}
nepritel kovar()
{
    nepritel n;
    n.jmeno_n = "Zbesiły Kovar";
    n.hp_n = 60;
    n.hp_max_n = 60;
    n.utok_n = 10;
    n.ma_zbran = true;
    n.zbran_n = "Kladivo";
    n.hlasky[0] = "Bum! Bum! Bum!";
    n.hlasky[1] = "Budu te tepat jako kov!";
    n.hlasky[2] = "Zadne milosti!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 19;
    n.je_boss = false;
    return n;
}
nepritel ind_valecnik()
{
    nepritel n;
    n.jmeno_n = "Indiánský Válecník";
    n.hp_n = 50;
    n.hp_max_n = 50;
    n.utok_n = 8;
    n.ma_zbran = true;
    n.zbran_n = "Tomahawk";
    n.hlasky[0] = "Tato zeme patri nam!";
    n.hlasky[1] = "Nasi predci nas chrání!";
    n.hlasky[2] = "Ber nohy na záda!";
    n.pocet_hlasek = 3;
    n.zlato_n = -1;
    n.xp_n = 18;
    n.je_boss = false;
    return n;
}
// MINI-BOSSOVE
nepritel mb_henry()
{
    nepritel n;
    n.jmeno_n = "\"Krvavý Henry\" McCoy";
    n.hp_n = 120;
    n.hp_max_n = 120;
    n.utok_n = 14;
    n.ma_zbran = true;
    n.zbran_n = "Dvojity Revolver";
    n.hlasky[0] = "Henry McCoy se nezastavuje!";
    n.hlasky[1] = "Pohrebil jsem sto lidi jako ty!";
    n.hlasky[2] = "Pokud nemas prachy,tak si setri na rakev!";
    n.pocet_hlasek = 3;
    n.zlato_n = 50;
    n.xp_n = 40;
    n.je_boss = false;
    return n;
}
nepritel mb_nacelnik()
{
    nepritel n;
    n.jmeno_n = "Nacelnik Cerny Medved";
    n.hp_n = 140;
    n.hp_max_n = 140;
    n.utok_n = 12;
    n.ma_zbran = true;
    n.zbran_n = "Luk a Tomahawk";
    n.hlasky[0] = "Tato zem neplaci poplatek!";
    n.hlasky[1] = "Duch medveda bojuje se mnou!";
    n.hlasky[2] = "Tvoje krev napoji zemi predku!";
    n.pocet_hlasek = 3;
    n.zlato_n = 40;
    n.xp_n = 45;
    n.je_boss = false;
    return n;
}
// HLAVNI BOSS
nepritel boss_cornwall()
{
    nepritel n;
    n.jmeno_n = "\"Baron Ropy\" Harlan Cornwall Jr.";
    n.hp_n = 250;
    n.hp_max_n = 250;
    n.utok_n = 18;
    n.ma_zbran = true;
    n.zbran_n = "Legendarni Revolver a Elektricky Dynamit";
    n.hlasky[0] = "Mam penize i kulky — co mas ty?";
    n.hlasky[1] = "Tato zeme patri tomu kdo si ji koupí!";
    n.hlasky[2] = "Zaplatím kazdemu kdo ti sneze hlavu!";
    n.pocet_hlasek = 3;
    n.zlato_n = 200;
    n.xp_n = 100;
    return n;
}

// main

int main()
{
    srand((unsigned)time(nullptr));

    postava opilec;
    opilec.zivoty = 25;
    opilec.zivoty_ted = 25;
    opilec.utok_bez_zbrane = 2;

    postava hrac;
    kun muj_kun;
    int volba = 0;

    cout << "-------Vitam te cizince na divokem zapade-------\n";
    cout << "Za jakou postavu by jsi si pral hrat\n";
    cout << "1-Nacelnik Apacu\n2-Ropny magnat\n3-Bounty Hunter\n4-Greenhorn\n";

    bool jistota = true;
    while (jistota)
    {
        cout << "\nKlidne si muzes prohlednout specifikace postav a pak si teprve vybrat\n";
        cin >> volba;

        switch (volba)
        {
        case 1:
            hrac.jmeno = "Rychly Sip";
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
            hrac.luk = true;
            hrac.winchesterovka = false;
            hrac.brokovnice = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            hrac.pristup_rafinerie = false;
            hrac.pristup_velke_mesto = false;
            hrac.pratelstvi_s_indiany = true;
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
            hrac.luk = false;
            hrac.winchesterovka = false;
            hrac.brokovnice = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            hrac.pristup_rafinerie = true;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;
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
            hrac.luk = false;
            hrac.winchesterovka = true;
            hrac.brokovnice = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            hrac.pristup_rafinerie = false;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;
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
            hrac.luk = false;
            hrac.winchesterovka = false;
            hrac.brokovnice = false;
            hrac.dvojity_r_high_honor = false;
            hrac.brokovnice_low_honor = false;
            hrac.pristup_rafinerie = false;
            hrac.pristup_velke_mesto = true;
            hrac.pratelstvi_s_indiany = false;
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

    aktualizuj_obrazovku(hrac, muj_kun,
                         "Dojel jsi do mesta Valentine. Ztratil jsi svou zbran, ale jako by ti pralo\n"
                         "stesti, mistni Smith's Iron & Lead pro tebe jednu ma.\n"
                         "Taky mas moznost pojmenovat sveho kone.(pis vse dohromady, slova pripadne oddeluj podtrzitkem)");
    cin >> muj_kun.jmeno;
    aktualizuj_obrazovku(hrac, muj_kun, "Sveho kone jsi pojmenoval: ");
    cout << muj_kun.jmeno;

    aktualizuj_obrazovku(hrac, muj_kun,
                         "Nasednes na " + muj_kun.jmeno + ".\n"
                                                          "Po ceste do mistniho lokalu te nekdo shodi z kone\n"
                                                          "Je to nejaky mistni ozrala a vyzval te na souboj");
    cout << "\nUbral ti 1 Hp ! TED JSI NA RADE TY!";
    hrac.zivoty_ted -= 1;

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
                cout << "Zasadil jsi mu poradnou ranu a trochu se zapotacel\n Presto se ale zvednual a dal ti taky jednu\n";
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
                cout << "Zabijeni lidi kdyz jsou bezmocni snizuje tvoji cest.\n Tim ze to videli ostatni lide, jsi vsak dostal vice respektu\n";
            }
            break;
        }
    }

    if (hrac.zivoty_ted <= 0)
    {
        cout << "\n!!! PROHRALS !!! Opilec te dorazil. Hra konci.\n";
        return 0;
    }

    hrac.zkusenosti += 10;
    hrac.dead_eye_ted = min(hrac.dead_eye_ted + 5, hrac.dead_eye);
    zkontroluj_level(hrac);
    cekej();

    //  Valentine
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Jsi v mestecku VALENTINE.\n"
                         "Misto plne rvacek, whiskey a pochybnych obchodu.\n"
                         "Muzis se vybavit pred dalsi cestou.");
    cekej();
    vesnice(hrac, muj_kun, "Valentine");

    //  Bandita
    aktualizuj_obrazovku(hrac, muj_kun, "Z kere vyskoci BANDITA a chce tvoje zlato!");
    cekej();
    {
        nepritel m = bandita();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    // ==== M2: zbojnik ====
    aktualizuj_obrazovku(hrac, muj_kun, "Na ceste te ceka zradny zbojnik s desivym pohledem a nozem v ruce!");
    cekej();
    {
        nepritel m = zbojnik();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    // boj kojot a had
    aktualizuj_obrazovku(hrac, muj_kun, "Prochazis prerijemi. Najednou na tebe zautoci DIVOKY KOJOT a JEDOVATY HAD naraz!");
    cekej();
    {
        nepritel sk[2] = {kojot(), had()};
        if (!souboj_vice(hrac, muj_kun, sk, 2))
            return 0;
    }

    // MB
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Slysel jsi o nem. \"Krvavý Henry\" McCoy —\n"
                         "nejobavaneji pistolnik na jihozapade.\n"
                         "Sedi na koni uprostred cesty. Utoči prvni.");
    cekej();
    {
        nepritel mb = mb_henry();
        if (!souboj(hrac, muj_kun, mb, true))
            return 0;
    }

    // Riggs Station
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Po tezkem boji dorazis do RIGGS STATION.\n"
                         "Male sidlo u reky — ale maji doktora a trh.");
    cekej();
    vesnice(hrac, muj_kun, "Riggs Station");

    //  Puma
    aktualizuj_obrazovku(hrac, muj_kun, "Z lesa vyskoci PUMA! Velka a hladova.");
    cekej();
    {
        nepritel m = puma();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    //  Vojensky Dezertér
    aktualizuj_obrazovku(hrac, muj_kun, "Z lesa vyjde VOJENSKY DEZERTÉR — zbrane ma, ale autoritu ne.");
    cekej();
    {
        nepritel m = dezertér();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    //  2x Bandita
    aktualizuj_obrazovku(hrac, muj_kun, "Prepadeni na ceste! DVA BANDITE se vrhli z obou stran!");
    cekej();
    {
        nepritel sk[2] = {bandita(), tezky_bandita()};
        sk[0].jmeno_n = "Bandita Maly";
        if (!souboj_vice(hrac, muj_kun, sk, 2))
            return 0;
    }

    //  Puma + Sup
    aktualizuj_obrazovku(hrac, muj_kun, "Divoka priroda! PUMA a SUP zautocili najednou!");
    cekej();
    {
        nepritel sk[2] = {puma(), sup()};
        sk[0].jmeno_n = "Puma Samice";
        if (!souboj_vice(hrac, muj_kun, sk, 2))
            return 0;
    }

    //  Nacelnik Cerny Medved
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Na skalnim utese na tebe ceka NACELNIK CERNY MEDVED.\n"
                         "Brani zemi svych predku. Utoci prvni.");
    cekej();
    {
        nepritel mb = mb_nacelnik();
        if (!souboj(hrac, muj_kun, mb, true))
            return 0;
    }

    // Opily Kovboj + Zlodej
    aktualizuj_obrazovku(hrac, muj_kun, "U brodu reky te prepadnou OPILY KOVBOJ a ZLODEJ!");
    cekej();
    {
        nepritel sk[2] = {opily_kovboj(), zlodej()};
        if (!souboj_vice(hrac, muj_kun, sk, 2))
            return 0;
    }

    //  Pijak + Dezertér
    aktualizuj_obrazovku(hrac, muj_kun, "Dalsi prepadeni! PIJAK WHISKEY a VOJENSKY DEZERTÉR zautocili najednou!");
    cekej();
    {
        nepritel sk[2] = {pijak(), dezertér()};
        if (!souboj_vice(hrac, muj_kun, sk, 2))
            return 0;
    }

    //  Trio banditu
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Posledni zed pred rafinerií! TRI BANDITE v gangu blokuji jedinou cestu!\n"
                         "Musis se probojovat!");
    cekej();
    {
        nepritel sk[3] = {bandita(), tezky_bandita(), cornwall_straz()};
        if (!souboj_vice(hrac, muj_kun, sk, 3))
            return 0;
    }

    // Indiánský Válecník
    aktualizuj_obrazovku(hrac, muj_kun, "INDIANSKY VALECNIK strezi vstup do oblasti rafinerie!");
    cekej();
    {
        nepritel m = ind_valecnik();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }
    aktualizuj_obrazovku(hrac, muj_kun,
                         "Dojel jsi do posledni osady pred finalnim setkanim s Cornwallem\n"
                         "Doporucuji se vybavit pred dalsi cestou\n"
                         " Mozna uz poktas primo Cornwalla\n");
    cekej();
    vesnice(hrac, muj_kun, "Valentine");

    //  Cornwall_straz
    aktualizuj_obrazovku(hrac, muj_kun, "Pred samotnou rafinerií stoji elegantní pistolnik — Cornwalluv placeny straze.");
    cekej();
    {
        nepritel m = cornwall_straz();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    //  Kovar
    aktualizuj_obrazovku(hrac, muj_kun, "Uvnitr rafinerie te ceka ZBESILY KOVAR — posledni linie obrany pred bossem.");
    cekej();
    {
        nepritel m = kovar();
        if (!souboj(hrac, muj_kun, m))
            return 0;
    }

    // ==== HLAVNI BOSS: Cornwall ====
    aktualizuj_obrazovku(hrac, muj_kun,
                         "A tak je tu chvile. Ve velke hale rafinerie te ceka sam\n"
                         "\"BARON ROPY\" HARLAN CORNWALL JR.\n"
                         "Nejbohatsi, nejkrutejsi a nejnebezpecnejsi muz na zapade.\n"
                         "Hlavně pozor, vypada to ze spadl nekam elektriny a ma specialni schopnosti\n"
                         "Utoci prvni — a nema v planu ztratit.");
    cout << "\n=== FINALNI SOUBOJ ===\n";
    cekej();
    {
        nepritel boss = boss_cornwall();
        if (!souboj(hrac, muj_kun, boss, true))
            return 0;
    }

    // ============================================================
    //  KONEC — VITEZSTVI
    // ============================================================
    cout << "\033[2J\033[1;1H";
    cout << "\n";
    cout << "  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n";
    cout << "                  V I T E Z S T V I !\n";
    cout << "  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n";
    cout << "Cornwall padl. Rafinerie je volna.\n";
    cout << "Zapad je o trochu svobodnejsi — a ty jsi ten kdo to udelal.\n\n";
    vypis_postava(hrac);
    vypis_kun(muj_kun);
    cout << "\n\"Na tomhle zapade prezije jen nejsilnejsi.\n";
    cout << " A ty dnes dokázal, ze jsi jednim z nich.\"\n\n";
    cout << "  --- KONEC ---\n\n";

    return 0;
}