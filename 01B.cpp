#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    int min; 
    cin >> min;

    vector<double>scores;

    int input;
    cin >> input;
    while(input != -1){
        scores.push_back(input);
        cin >> input;
    }

    double total = 0;
    int passed = 0;

    for (auto x : scores) {
        if (x >= min) {
            total += x;
            passed++;
        }
    }

    double mean = total / passed;

    double sigma = 0;
    for (auto x : scores) {
        if (x >= min) {
            sigma += (x - mean) * (x - mean);
        }
    }

    double variance = sigma / (passed - 1);

    cout << fixed << setprecision(2) << mean << " " << fixed << setprecision(2) << variance << endl;

    return 0;
}