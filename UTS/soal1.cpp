#include <iostream>
#include <iomanip>
using namespace std;

class DompetDigital{
    private:
        string nim;
        double saldo;
    public:
        DompetDigital(string n) : nim(n), saldo(0) {}
        void topup(double jumlah) {
            saldo += jumlah;
        }
        void pembayaran(double jumlah){
            if(saldo - jumlah >= 0) saldo -= jumlah;
        }
        double getSaldo(){
            return saldo;
        }
};

int main(){
    string nim;
    cin >> nim;

    DompetDigital d(nim);

    int tipe; 
    double jumlah;

    while(cin >> tipe){
        if(tipe == -9) break;
        cin >> jumlah;

        if(tipe == 1){
            d.topup(jumlah);
        }
        if(tipe == 2){
            d.pembayaran(jumlah);
        }
    }

    cout << nim << " " << fixed << setprecision(2) << d.getSaldo() << endl;

    return 0;
}
