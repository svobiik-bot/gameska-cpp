using namespace std;
#include <iostream>
#include <iomanip>

int main()
{
    cout << "Test barev\n";

    // Základní barvy
    cout << "\033[31mCervena (31)\033[0m  ";
    cout << "\033[32mZelena (32)\033[0m   ";
    cout << "\033[33mZluta (33)\033[0m" << endl;
    cout << "\033[34mModra (34)\033[0m    ";
    cout << "\033[35mFialova (35)\033[0m  ";
    cout << "\033[36mAzurova (36)\033[0m" << endl;

    // Westernová paleta (Rozšířená)
    cout << "Westernove barvy (256 barev):" << endl;

    // Hnědá pro koně
    cout << "\033[38;5;94mBarva 94: Mustang (Hneda)\033[0m" << endl;

    // Zlatá pro dolary
    cout << "\033[38;5;220mBarva 220: Zlate pruty\033[0m" << endl;

    // Oranžová pro oheň
    cout << "\033[38;5;208mBarva 208: Taborovy ohen\033[0m" << endl;

    // Šedá pro kov
    cout << "\033[38;5;244mBarva 244: Tvuj revolver\033[0m" << endl;

    // Krev/Honor
    cout << "\033[38;5;52mBarva 52: Temna krev (Low Honor)\033[0m" << endl;

    cout << "Staci pouzit kód: \\033[38;5;CISLOm" << endl;

    auto print_color = [](int n, string label)
    {
        cout << "\033[38;5;" << n << "m" << setw(4) << n << ": " << left << setw(15) << label << "\033[0m";
    };

    cout << "==========================================================" << endl;
    cout << "       VELKY VZORNIK BAREV PRO DIVOKY ZAPAD               " << endl;
    cout << "==========================================================" << endl;

    cout << "--- KONE A KÜZE (HNEDE) ---" << endl;
    print_color(94, "Mustang");
    print_color(130, "Sedlo");
    print_color(52, "Tmavá kůže");
    cout << endl;
    print_color(166, "Rezavá");
    print_color(172, "Okrová");
    print_color(238, "Černý kůň");
    cout << endl;
    cout << "--- PRIRODA A LESY (ZELENE) ---" << endl;
    print_color(22, "Hluboký les");
    print_color(28, "Tráva");
    print_color(34, "Léčení");
    cout << endl;
    print_color(64, "Olivová");
    print_color(106, "Mech");
    print_color(2, "Klasická zel.");
    cout << endl;

    cout << "--- PENIZE A DEAD EYE (Zlate / Zlute) ---" << endl;
    print_color(220, "Ryzí zlato");
    print_color(214, "Oranž. zlato");
    print_color(11, "Dead Eye");
    cout << endl;
    print_color(136, "Bronz");
    print_color(178, "Mince");
    print_color(226, "Jasná žlutá");
    cout << endl;

    cout << "--- ZBRANE A KOV (Sede / Modre) ---" << endl;
    print_color(240, "Ocel");
    print_color(244, "Revolver");
    print_color(250, "Stříbro");
    cout << endl;
    print_color(235, "Karbon");
    print_color(60, "Modrá ocel");
    print_color(18, "Noční modř");
    cout << endl;

    cout << "--- KREV A NEBEZPECI (Cervene) ---" << endl;
    print_color(196, "Jasná krev");
    print_color(160, "Low Honor");
    print_color(124, "Temná rudá");
    cout << endl;
    print_color(202, "Oheň");
    print_color(208, "Dynamit");
    print_color(1, "Základní čer.");
    cout << endl;

    cout << "--- OSTATNI (Fialove / Azurove) ---" << endl;
    print_color(93, "Legendární");
    print_color(129, "Magická");
    print_color(39, "Voda/Nebe");
    cout << endl;
    print_color(44, "Tipy/UI");
    print_color(51, "Jasná modrá");
    print_color(15, "Bílá");
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "Pro pouziti v kodu napis: \"\\033[38;5;CISLOm\" " << endl;
    cout << "Priklad: cout << \"\\033[38;5;220m\" << \"Zlato\" << \"\\033[0m\";" << endl;
    cout << "==========================================================" << endl;

    return 0;
}