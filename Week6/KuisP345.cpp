#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double pi = 3.14;

class Ruang2d{
    protected:
        int id;
        string tipe;
    public:
        Ruang2d(int a, string b) : id(a), tipe(b) {}
        virtual double hitungLuas() = 0;
        virtual void show() = 0; 
};

class Lingkaran : public Ruang2d {
    private:
        double radius;
    public:
        Lingkaran(int a, string b,double c) : Ruang2d(a,b), radius(c) {}
        double hitungLuas() override {
            return pi * radius * radius;
        }
        void show() override {
            cout << "-----------------------------" << endl;
            cout << "Nomor Objek    : " << id << endl;
            cout << "Bidang         : " << tipe << endl;
            cout << "Jari-jari      : " << radius<< endl;
            cout << "Luas Permukaan : " << fixed << setprecision(2) << hitungLuas() << endl;
        }
};

class Segitiga : public Ruang2d {
    private:
        double alas;
        double tinggi;
    public: 
        Segitiga(int a, string b, double c, double d) : Ruang2d(a,b), alas(c), tinggi(d) {}
        double hitungLuas() override {
            return alas * tinggi / 2;
        }
        void show() override {
            cout << "-----------------------------" << endl;
            cout << "Nomor Objek    : " << id << endl;
            cout << "Bidang         : " << tipe << endl;
            cout << "Alas           : " << alas << endl;
            cout << "Tinggi         : " << tinggi << endl;
            cout << "Luas Permukaan : " << fixed << setprecision(2) << hitungLuas() << endl;
        }
};

class SegiEmpat : public Ruang2d {
    protected:
        double panjang;
        double lebar;
    public: 
        SegiEmpat(int a, string b, double c, double d) : Ruang2d(a,b), panjang(c), lebar(d) {}
        virtual double hitungLuas() override {
            return panjang * lebar;
        }
        void show() override {
            cout << "-----------------------------" << endl;
            cout << "Nomor Objek    : " << id << endl;
            cout << "Bidang         : " << tipe << endl;
            cout << "Panjang        : " << panjang << endl;
            cout << "Lebar          : " << lebar << endl;
            cout << "Luas Permukaan : " << fixed << setprecision(2) << hitungLuas() << endl;
        }
};

class Persegi : public SegiEmpat {
    public: 
        Persegi(int a, string b, double c) : SegiEmpat(a,b,c,c) {}
        double hitungLuas() override {
            return panjang * panjang;
        }
        void show() override {
            cout << "-----------------------------" << endl;
            cout << "Nomor Objek    : " << id << endl;
            cout << "Bidang         : " << tipe << endl;
            cout << "Panjang Sisi   : " << panjang << endl;
            cout << "Luas Permukaan : " << fixed << setprecision(2) << hitungLuas() << endl;
        }
};


int main(){
    vector <Ruang2d*> v;
    
    int n;
    cin >> n;

    double totalLuas = 0;

    string tipe; 
    double a,b; // a dan b sebagai variabel untuk sisi (panjang, lebar, radius)
    for (int i = 0; i < n; i++){
        cin >> tipe;

        if(tipe == "Segitiga"){
            cin >> a >> b;
            Ruang2d* bangun = new Segitiga(i + 1, tipe, a, b);
            v.push_back(bangun);
        }
        else if(tipe == "Lingkaran"){
            cin >> a;
            Ruang2d* bangun = new Lingkaran(i + 1, tipe, a);
            v.push_back(bangun);
        }
        else if(tipe == "Segiempat"){
            cin >> a >> b;
            Ruang2d* bangun = new SegiEmpat(i + 1, tipe, a, b);
            v.push_back(bangun);
        }
        else if(tipe == "Persegi"){
            cin >> a;
            Ruang2d* bangun = new Persegi(i + 1, tipe, a);
            v.push_back(bangun);
        }
    }

    double inp1, inp2;
    cin >> inp1 >> inp2;

    for (int i = inp1-1; i < inp2; i++){
        v[i]->show();
        totalLuas += v[i]->hitungLuas();
    }

    cout << "-----------------------------" << endl;
    cout << "TOTAL LUAS     : " << totalLuas << endl;
    cout << "-----------------------------" << endl;

    return 0;
}