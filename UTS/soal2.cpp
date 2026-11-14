#include <iostream>
#include <iomanip>

using namespace std;

class DispenserAir{
    protected:
        string id;
        string merek;
        double kapasitas;
        double volumeAir;
    public:
        DispenserAir(string i, string m, double k) : id(i), merek(m), kapasitas(k), volumeAir(0) {}
        void isiUlang(double v) {
            if(v > 0) volumeAir += v;
            if(volumeAir > kapasitas) volumeAir = kapasitas;
        }
        virtual bool tuangAir(double v) {
            if(volumeAir - v <= 0) return false;
            volumeAir -= v;
            return true;
        }
        virtual void show() {
            cout << fixed << setprecision(1) << endl;
            cout << "------------------------------" << endl;
            cout << "ID Dispenser   : " << id << endl;
            cout << "Merek Dagang   : " << merek << endl;
            cout << "Kapasitas      : " << kapasitas <<  " mL";
        }
};

class SmartDispenser : public DispenserAir{
    private:
        bool pemanasAktif;
        double suhu;
        double totalAirDituang;
    public:
        SmartDispenser(string i, string m, double k) : DispenserAir(i, m, k), pemanasAktif(false), suhu(25), totalAirDituang(0) {}
        void nyalakanPemanas() {
            if(volumeAir >= 500){
                pemanasAktif = true;
                suhu = 92;
            }
        }
        void matikanPemanas() {
            pemanasAktif = false;
            suhu = 25;
        }
        bool tuangAir(double v) override {
            DispenserAir::tuangAir(v);
            if(DispenserAir:: tuangAir(v) == true) {
                totalAirDituang += v;
                return true;
            }
            return false;
        }
        void show() override {
            DispenserAir::show();
            cout << fixed << setprecision(1) << endl;
            cout << "------------------------------" << endl;
            if(pemanasAktif == true) cout << "Status Pemanas : " << "ON" << endl;
            if(pemanasAktif == false) cout << "Status Pemanas : " << "OFF" << endl;
            cout << "Suhu Air       : " << suhu << " Celcius" << endl;
            cout << "Volume Sisa    : " << volumeAir << " mL" << endl;
            cout << "Total Konsumsi : " << totalAirDituang <<  " mL";
        }
};

int main(){
    string id; string merek; double kapasitas;

    cin >> id >> merek >> kapasitas;

    SmartDispenser d(id, merek, kapasitas);

    int input; double vol;
    while(cin >> input){
        if(input == -9) break;

        if(input == 1){
            d.nyalakanPemanas();
        }
        if(input == 2){
            cin >> vol;
            d.isiUlang(vol);
        }
        if(input == 3){
            cin >> vol;
            d.tuangAir(vol);
        }
        if(input == 4){
            d.matikanPemanas();
        }
        if(input == 9){
            d.show();
        }
    }

    cout << "------------------------------" << endl;
    return 0;
}