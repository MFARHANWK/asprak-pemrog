#include <iostream>
using namespace std;

class MinumanKemasan{
    private:
        string namaProduk;
        int kapasitas;
        int isiSekarang;

    public:
        MinumanKemasan(string nama, int kap){
            namaProduk = nama;
            kapasitas = kap;
            isiSekarang = kap;
        }
        void minum(int jumlah){
            isiSekarang -= jumlah;
            if(isiSekarang < 0) isiSekarang = 0;
        }

        void isiUlang(int jumlah){
            isiSekarang += jumlah;
            if(isiSekarang > kapasitas) isiSekarang = kapasitas;
        }

        void show(){
            cout << "Nama Produk : " << namaProduk << endl;
            cout << "Kapasitas   : " << kapasitas << " ml" << endl;
            cout << "Isi Sekarang: " << isiSekarang << " ml" << endl;
        }
};

int main(){
    string nama; 
    int kap;
    cin >> nama >> kap;

    MinumanKemasan minuman(nama, kap);

    string input;
    cin >> input;

    while(1){
        if(input == "minum"){
            int jumlah; 
            cin >> jumlah;
            minuman.minum(jumlah);
        }
        else if(input == "isi"){
            int jumlah; 
            cin >> jumlah;
            minuman.isiUlang(jumlah);
        }
        else if(input == "show"){
            minuman.show();
            break;
        }
        cin >> input;
    }

    return 0;
}
