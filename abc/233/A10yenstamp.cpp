#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    while(x < y){
        x += 10;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
