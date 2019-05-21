#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Graf {
public:
    vector<int> Noduri[100];
    int vizitat[100];
    int nrNoduri, nrMuchii;

    void citesteDinFisier(string numeFisier) {
        ifstream f(numeFisier);
        for (int i = 0; i < 100; i++) {
            Noduri[i].clear();
        }

        int nod1, nod2;
        f>>nrNoduri>>nrMuchii;
        for (int i = 0; i < nrMuchii; i++) {
            f>>nod1>>nod2;
            Noduri[nod1].push_back(nod2);
            Noduri[nod2].push_back(nod1);
        }

        f.close();
    }

    void afisare() {
        for (int i = 1; i <= nrNoduri; i++) {
            cout<<i<<": ";
            if (Noduri[i].empty())
                cout<<"niciun vecin";
            for (int j = 0; j < Noduri[i].size(); j++) {
                cout<<Noduri[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

};

int main()
{
    Graf graf;
    graf.citesteDinFisier("date.in");
    graf.afisare();

    return 0;
}
