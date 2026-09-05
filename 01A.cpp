#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    double mean = double(a+b+c+d)/4;
    
    cout << fixed << setprecision(2) << mean << endl;

    return 0;
}