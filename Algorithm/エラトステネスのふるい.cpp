//~xまでの素数を列挙するもの　

void prime(int x){
    vector<bool> prime(x + 1,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i * i <= x + 1; ++i){
        if(prime[i]){
            for(int j = 2; i * j <= x + 1; ++j){
                prime[i * j] = 0;
            }
        }
    }
    for(int i = 0; i <= x + 1; i++){
        if(prime[i]){
            cout << i << endl;
        }
    }
    return 0;
}  

//ABC149Cより　xが与えられてそれ以上の素数を出力するもの

#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int Primecheckup(int x){
    vector<bool> prime(100004,1);//100004は6桁の素数の最初が100003だから　本来はxまでの配列を作る 1:素数　0:非素数
    prime[0] = 0;
    prime[1] = 0;//0と1は非素数
    for(int i = 2; i * i < 100004; ++i){//
        if(prime[i]){//すでに非素数判定ならスルー
            for(int j = 2; i * j < 100004; ++j){//素数の倍数は素数ではないので範囲内の素数の倍数を非素数判定に
                prime[i * j] = 0;
            }
        }
    }
    for(int i = x; i < 100004; i++){//x以上の素数を判定する処理
        if(prime[i]){
            return i;
        }
    }
    return 0;
}
int main(){
    int x;
    cin >> x;
    int ans = Primecheckup(x);
    cout << ans << endl;
    return 0;
}
