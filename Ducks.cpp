#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    
    int Quantity = 0, MaxWidth;

    vector<pair<int, int>> ducks(Quantity + 1, make_pair(0, 0));
    
    ifstream fin;
    fin.open("Ducks.txt");

    int it = 0;
    while (!fin.eof())
    {
        if (Quantity == 0)
        {
            fin >> Quantity; fin >> MaxWidth;
            ducks.assign(Quantity + 1, make_pair(0, 0));
        }

        fin >> ducks[it].first;
        fin >> ducks[it].second;
        it++;
    }

    fin.close();

    vector<vector<int>> T(Quantity + 1, vector<int>(MaxWidth + 1, 0));

    for (int i = 1; i <= Quantity; i++) {
        int Height = ducks[i-1].first;
        int Width = ducks[i-1].second;
        for (int j = Width; j <= MaxWidth; j++) {
            T[i][j] = max(T[i-1][j], T[i-1][j - Width] + Height);
        }
    }

    cout << T[Quantity][MaxWidth] << endl;

    return 0;
}