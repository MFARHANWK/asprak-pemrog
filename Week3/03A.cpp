#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class PersegiPanjang{
    private:
        int panjang;
        int lebar;

    public: 
        PersegiPanjang(int p, int l){
            panjang = p;
            lebar = l;
        }
        int hitungLuas(){
            return panjang * lebar;
        }
};

int main(){
    int n, k;
    cin >> n >> k;

    vector<int>arr;


    int panjang,lebar;
    for(int i = 0; i < n; i++){
        cin >> panjang >> lebar;
        PersegiPanjang p(panjang, lebar);
        arr.push_back(p.hitungLuas());
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < 3; i++){
        cout << arr[i] << endl;
    }

    return 0;
}