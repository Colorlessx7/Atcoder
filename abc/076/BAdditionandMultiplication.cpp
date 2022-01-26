#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    int y = 1;
    for (int i = 0; i < N; i++)
    {
        if (y * 2 >= y + K){
            y += K;
        }else {
            y *= 2;
        }
    }
    cout << y << endl;
    
}
