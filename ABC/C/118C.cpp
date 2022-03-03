#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    cin >> n;
    int x = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(i == 0){
            x = a;
            continue;
        }
        x = gcd(x,a);
    }
    cout << x << endl;
    return 0;
}
//数学的考察問題
//モンスターがダメージを与える処理とユークリッドの互除法で
//正方形を取り除く処理が同じであることから
//全てのa[i]に対してgcdを取ったものが答えになる
