#include <iostream>
#include <iomanip>
using namespace std;

double pi = 3.14;

class Bidang {
    protected:
        string id;
    public:
        Bidang(string i) : id(i) {}
        virtual double hitungLuas() = 0;
};

class Lingkaran : public Bidang {
    protected:
        double radius;
    public:
        Lingkaran(string i, double r) : Bidang(i), radius(r) {}
        double hitungLuas() override {
            return pi * radius * radius;
        }
};

class Segitiga : public Bidang {
    private:
        double alas;
        double tinggi;
    public:
        Segitiga(string i, double a, double t): Bidang(i), alas(a), tinggi(t) {}
        double hitungLuas() override {
            return alas * tinggi / 2;
        }
};

class SegiEmpat : public Bidang {
    private:
        double panjang;
        double lebar;
    public:
        SegiEmpat(string i, double p, double l): Bidang(i), panjang(p), lebar(l) {}
        double hitungLuas() override {
            return panjang * lebar;
        }
};

class Silinder : public Lingkaran{
    private:
        double tinggi;
    public: 
        Silinder(string i,double r, double t) : Lingkaran(i, r), tinggi(t) {}
        double hitungLuas() override {
            return 2 * pi * radius * (radius + tinggi);
        }
};

int main(){
    int n; 
    cin >> n;

    vector<Bidang*>bangun;

    string id, tipe;
    double a, b;

    for(int i = 0; i < n; i++){
        cin >> id >> tipe;

        if (tipe == "Lingkaran"){
            cin >> a;
            bangun.push_back(new Lingkaran(id, a));
        }
        if (tipe == "Segitiga"){
            cin >> a >> b;
            bangun.push_back(new Segitiga(id, a, b));
        }
        if (tipe == "Segiempat"){
            cin >> a >> b;
            bangun.push_back(new SegiEmpat(id, a, b));
        }
        if (tipe == "Silinder"){
            cin >> a >> b;
            bangun.push_back(new Silinder(id, a, b));
        }
    }

    int start, end;
    double totalLuas = 0;
    cin >> start;

    while(1){
        if(start == -9) break;

        cin >> end;

        for (int i = start - 1; i < end; i++){
            totalLuas += bangun[i]->hitungLuas();
        }

        cout << start << "-" << end << " : " << totalLuas << endl;

        totalLuas = 0;

        cin >> start;
    }


    return 0;
}