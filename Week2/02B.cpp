#include <iostream>
#include <iomanip>
using namespace std;

class Orang {
    private:
        string nama;
        int usia;
        double tinggi, berat;
    public:
        Orang(string n, int u, double t, double b) {
            nama = n;
            usia = u;
            tinggi = t;
            berat = b;
        } 
        void show() {
            cout << nama << " | " << usia << " | " << fixed << setprecision(2) <<  tinggi << " | " << fixed << setprecision(2) << berat << endl;
        }
};

int main(){
    string n; 
    int u; 
    double t; 
    double b;

    getline(cin, n);
    cin >> u >> t >> b;

    Orang o(n,u,t,b);
    o.show();

    return 0;
}