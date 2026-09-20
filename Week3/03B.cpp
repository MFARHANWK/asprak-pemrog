#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

class Pegawai
{
    protected:
        string id;
        int usia;
        int tipe;
        int income;
    public:
        Pegawai() { id=""; usia=income=0; tipe=1; }
        void set(string pid, int u, int t ) {id=pid; usia=u; tipe=t; }
        string getID() { return id; }
        void show() { printf("%s %d %d\n", id.c_str(), tipe, income); } //kudu ditambahin c.str() supaya bisa di
};

class Tetap : public Pegawai {
    private: 
        int gajiPokok;
        int uangLembur;
    public:
        Tetap(string id, int usia, int tipe, int gajiPokok){
            set(id, usia, tipe);
            this->gajiPokok = gajiPokok;
            this->income = gajiPokok;
        }
        void setUangLembur(int uangLembur){
            this->uangLembur = uangLembur;
        }
        void addUangLembur(){
            this->income += this->uangLembur;
        }
};

class Harian : public Pegawai{
    private:
        int hari; // ini ga perlu karena ga diminta di soal
    public:
        Harian(string id, int usia, int tipe){
            set(id, usia, tipe);
        }
        void setUpahHarian(int upahHarian){
            income += upahHarian;
        }
};

int main(){
    int n;
    cin >> n;

    vector<Tetap>listTetap;
    vector<Harian>listHarian;

    string id; 
    int usia, tipe, gaji;

    for(int i = 0; i < n; i++){
        cin >> id >> usia >> tipe;

        if (tipe == 1) {
            cin >> gaji;
            Tetap t(id, usia, tipe, gaji);
            listTetap.push_back(t);

        }
        if (tipe == 2) {
            Harian h(id, usia, tipe);
            listHarian.push_back(h);
        }
    }

    string inp;
    cin >> inp;

    while(1){
        if (inp == "END") break;

        int pemasukan;
        cin >> pemasukan;

        for(auto &x : listTetap){ // ini kudu pake &x supaya object aslinya keubah, klo x doang gabisa
            if (inp == x.getID()){
                x.setUangLembur(pemasukan); // sbnrnya bisa bikin satu method aja yg isinya income+=pemasukan, tapi ini tuh best practice aja karna kita punya atribut uangLembur di classnya
                x.addUangLembur();
            }
        }
        for(auto &x : listHarian){ // ini kudu pake &x supaya object aslinya keubah, klo x doang gabisa
            if (inp == x.getID()){
                x.setUpahHarian(pemasukan);
            }
        }

        cin >> inp;
    }

    for (auto x : listTetap){ 
        x.show();
    }
    for (auto x : listHarian){
        x.show();
    }

    return 0;
}