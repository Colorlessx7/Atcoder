#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
ll powans(ll i){
    ll ret = i;
    rep(j,4){
        ret *= i;
    }
    return ret;
}
int main(){
    ll x;
    cin >> x;
    ll a, b;
    bool frag = false;
    rep2(i,120){
        for(ll j = i - 1; j >= -i; j--){
            ll al = powans(i);
            ll bl = powans(j);
            if(al - bl == x){
                a = i;
                b = j;
                frag = true;
                break;
            }
        }
        if(frag){
            break;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
//A,Bのとりうる値が少ないので二重ループ全探索
//10^9は9桁ではなく10桁なのがWAを生み出した
//A,Bのとりうる値の最大を考える上で
//Aを決めた時にBはA-1~-Aまでしか値を取らない
//Aを定めた時A^5-B^5が一番小さくなるのはB=A-1の時
//よってA^5-B-5が10^9を切り超えるところまで全探索すれば良い
