//Dla każdego słowa z pliku nowe.txt wypisz to słowo oraz dwie liczby rozdzielone spacją
//oznaczające:
//• liczbę wystąpień danego słowa w pliku slowa.txt,
//• liczbę wystąpień odbicia lustrzanego danego słowa w pliku slowa.txt.
#include <fstream>
#include <string>
using namespace std;

string reverse(string napis) {
    string s = "";
    for (int n = napis.length() - 1; n >= 0; n--) {
        char znak = napis[n];
        s = s + znak;
    }
    return s;

};
const int ROZMIAR_SLOWA = 1000;
string slowa[ROZMIAR_SLOWA];
const int ROZMIAR_NOWE = 25;
string nowe[ROZMIAR_NOWE];

int main() {

    string a, b, x;
    int t[1000];
    int r[1000];
    ifstream we("slowa.txt"), wy("nowe.txt");
    ofstream wn("wynik5b.txt");
    for (int licznik = 0; !we.eof() && licznik < ROZMIAR_SLOWA; licznik++) {

        we >> slowa[licznik];
    }
    for (int licznik = 0; !wy.eof() && licznik < ROZMIAR_NOWE; licznik++) {

        wy >> nowe[licznik];
    }

    for (int i = 0; i < ROZMIAR_NOWE; i++)
    {
        string slowo_z_nowe = nowe[i];
        string odw_z_nowe = reverse(slowo_z_nowe);
        int norma = 0;
        int odw = 0;
        for (int j = 0; j < ROZMIAR_SLOWA; j++)
        {
            string slowo = slowa[j];
            if (slowo_z_nowe == slowo) norma++;
            if (odw_z_nowe == slowo) odw++;
        }

        wn << slowo_z_nowe << '\t' << norma << '\t' << odw << '\n';

    }


    we.close();
    wy.close();
    wn.close();

    return 0;
}
