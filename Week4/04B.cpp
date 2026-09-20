#include <iostream>
#include <vector>
using namespace std;

class Kendaraan {
protected:
    string nomorPlat;
    string jenisKendaraan;
    int jamMasuk;
    int jamKeluar;

public:
    Kendaraan(string np, string jk, int jm, int jkl): nomorPlat(np), jenisKendaraan(jk), jamMasuk(jm), jamKeluar(jkl) {}
    int hitungDurasi() {
        return jamKeluar - jamMasuk;
    }
    virtual int hitungTarif() = 0;
    virtual void tampilkanInfo() = 0;
};

class Mobil : public Kendaraan {
private:
    int kapasitasPenumpang;
public:
    Mobil(string np, string jk, int jm, int jkl, int kp): Kendaraan(np, jk, jm, jkl), kapasitasPenumpang(kp) {}
    int hitungTarif() {
        if (hitungDurasi() <= 1)
            return 5000;
        else
            return 5000 + ((hitungDurasi() - 1) * 3000);
    }
    void tampilkanInfo() {
        cout << "Kendaraan       : Mobil\n";
        cout << "Nomor Plat      : " << nomorPlat << "\n";
        cout << "Jenis Kendaraan : " << jenisKendaraan << "\n";
        if (jamMasuk < 10) {
            cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (0" << jamMasuk << ":00 - ";
        }else {
            cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (" << jamMasuk << ":00 - ";
        }

        if (jamKeluar < 10) {
            cout << "0" << jamKeluar << ":00)\n";
        } else{
            cout << jamKeluar << ":00)\n";
        }
        cout << "Kapasitas       : " << kapasitasPenumpang << " Penumpang\n";
        cout << "Total Tarif     : Rp " << hitungTarif() << "\n";
    }
};

class Motor : public Kendaraan {
private:
    string jenisMotor;
public:
    Motor(string np, string jk, int jm, int jkl, string jmtr): Kendaraan(np, jk, jm, jkl), jenisMotor(jmtr) {}
    int hitungTarif() {
        if (hitungDurasi() <= 1)
            return 2000;
        else
            return 2000 + ((hitungDurasi() - 1) * 1000);
    }
    void tampilkanInfo() {
        
        cout << "Kendaraan       : Motor\n";
        cout << "Nomor Plat      : " << nomorPlat << "\n";
        cout << "Jenis Kendaraan : " << jenisKendaraan << "\n";
        if (jamMasuk < 10) {
            cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (0" << jamMasuk << ":00 - ";
        }else {
            cout << "Durasi Parkir   : " << hitungDurasi() << " Jam (" << jamMasuk << ":00 - ";
        }

        if (jamKeluar < 10) {
            cout << "0" << jamKeluar << ":00)\n";
        } else{
            cout << jamKeluar << ":00)\n";
        }
        cout << "Tipe Motor      : " << jenisMotor << "\n";
        cout << "Total Tarif     : Rp " << hitungTarif() << "\n";
    }
};

int main() {
    int n;
    cin >> n;
    vector<Kendaraan*> data;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "Mobil") {
            string np, jenis;
            int jm, jkl, kp;
            cin >> np >> jenis >> kp >> jm >> jkl;
            Kendaraan* mobil = new Mobil(np, jenis, jm, jkl, kp);
            data.push_back(mobil);
        } else if (command == "Motor") {
            string np, jmtr, jenis;
            int jm, jkl;
            cin >> np >> jenis >> jmtr >> jm >> jkl;
            Kendaraan* motor = new Motor(np, jenis, jm, jkl, jmtr);
            data.push_back(motor);
        }
    }

    for (int i = 0; i < data.size(); i++) {
        cout << "--- DATA PARKIR KENDARAAN " << i + 1 << " ---" << endl;
        data[i]->tampilkanInfo();
        cout << "\n";
    }

    return 0;
}
