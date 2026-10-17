#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    float m; cin >> m;

    vector<float>total_bobot;
    float bobot;


    for(int i = 0; i < n; i++){
        cin >> bobot;
        total_bobot.push_back(bobot);
    }

    sort(total_bobot.begin(), total_bobot.end(), greater<float>());

    float total = 0;

    int j;
    for(j = 0; j < n; j++){
        if(total < m) total += total_bobot[j];
        else break;
    }

    if(total >= m) cout << j << endl;
    else cout << -1 << endl;

    return 0;
}