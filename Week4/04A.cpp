#include <iostream>
#include <iomanip>

using namespace std;

double pi = 3.1425;

class Bangun{
    public:
        virtual double hitungLuas() = 0;
};

class Persegi : public Bangun{
    private:
        double sisi;
    
    public:
        Persegi(double s) : sisi(s){}
        double hitungLuas(){
            return sisi * sisi;
        }
};

class Lingkaran : public Bangun{
    private:
        double radius;
    public:
        Lingkaran(double r) : radius(r){}
        double hitungLuas(){
            return pi * radius * radius;
        }
};

class Bangun3d : public Bangun {
    public:
        virtual double hitungVolume() = 0;
};

class Kubus : public Bangun3d {
    private:
        double sisi;
    public:
        Kubus(double s) : sisi(s){}
        double hitungLuas(){
            return 6 * sisi * sisi;
        }
        double hitungVolume(){
            return sisi * sisi * sisi;
        }
};

class Bola : public Bangun3d {
    private:
        double radius;
    public:
        Bola(double r) : radius(r){}
        double hitungLuas(){
            return 4 * pi * radius * radius;
        }
        double hitungVolume(){
            return 4.0/3.0 * pi * radius * radius * radius;
        }
};


int main(){
    int n; 
    cin >> n;

    char inp; // kok dibikin di luar for? supaya inisialisasi variabelnya cuma sekali, klo ngga tar inisialisasi variabelnya dilakukan tiap perulangan
    double sisi;
    double totalLuas = 0;
    double totalVolume = 0;

    for(int i = 0; i < n; i++){
        cin >> inp >> sisi;
        
        if (inp == 'L'){
            Lingkaran l(sisi);
            totalLuas += l.hitungLuas();
        }
        if (inp == 'P'){
            Persegi p(sisi);
            totalLuas += p.hitungLuas();
        }
        if (inp == 'B'){
            Bola b(sisi);
            totalLuas += b.hitungLuas();
            totalVolume += b.hitungVolume();
        }
        if (inp == 'K'){
            Kubus k(sisi);
            totalLuas += k.hitungLuas();
            totalVolume += k.hitungVolume();
        }
    }

    cout << fixed << setprecision(2);
    cout << totalLuas << endl;
    cout << totalVolume << endl;

    return 0;
}