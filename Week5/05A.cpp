#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string format_ribuan(long long gaji){
    string income = to_string(gaji);

    string hasil;
    int panjang = income.size();

    for (int i = 0; i < panjang; i++) {
        if (i > 0 && (panjang - i) % 3 == 0)
            hasil += ',';

        hasil += income[i];
    }

    return hasil;
}

class Karyawan {
    protected:
        string id, nama;

    public:
        Karyawan(string a, string b) : id(a), nama(b) {}
        string getId() { return id; }
        virtual double hitung_gaji() = 0;
};

class Tetap : public Karyawan {
    private:
        double gajiPokok;
        double tunjangan;
        double bonus;

    public:
        Tetap(string a, string b, double c, double d, double e) : Karyawan(a, b) ,gajiPokok(c), tunjangan(d), bonus(e) {}
        double hitung_gaji(){
            return gajiPokok + tunjangan + bonus;
        }
};

class Tahunan : public Karyawan {
    private:
        double kontrak;
        double tunjangan;
    public:
        Tahunan(string a, string b, double c, double d) : Karyawan(a,b), kontrak(c), tunjangan(d) {}
        double hitung_gaji(){
            return kontrak/12.0 + tunjangan;
        }
};

class Harian : public Karyawan {
    private: 
        double upah;
        double hari;
        double insentif;
    public:
        Harian(string a, string b, double c, double d, double e): Karyawan(a,b), hari(c), upah(d), insentif(e) {}
        double hitung_gaji(){
            return (upah * hari) + (insentif * hari);
        }
};

int main(){
    vector<Karyawan*>daftar;

    string baris;

    while(getline(cin, baris)){
        stringstream ss(baris);

        string temp;
        vector<string>tokens;

        while(getline(ss, temp, ',')){
            tokens.push_back(temp);
        }

        int tipe = stoi(tokens[0]);

        if(tipe == 1){
            daftar.push_back(new Tetap(tokens[1], tokens[2], stod(tokens[3]), stod(tokens[4]), stod(tokens[5])));
        }

        if(tipe == 2){
            daftar.push_back(new Tahunan(tokens[1], tokens[2], stod(tokens[3]), stod(tokens[4])));
        }
        
        if(tipe == 3){
            daftar.push_back(new Harian(tokens[1], tokens[2], stod(tokens[3]), stod(tokens[4]), stod(tokens[5])));
        }
    }

    for (auto x : daftar){
        long long gaji = llrint(x->hitung_gaji());
        cout << x->getId() << " : " << format_ribuan(gaji) << endl;
    }

    return 0;
}