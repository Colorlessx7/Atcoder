#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i <= N; i++)
int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int y = 0;
    int count = 0;
    rep(i,A){
        rep(j,B){
            rep(k,C){
                if(X == i * 500 + j * 100 + k * 50){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}
