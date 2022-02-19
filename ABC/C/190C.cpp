#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k),d(k);
    rep(i,k){
        cin >> c[i] >> d[i];
    }
    //2^k ループ上限
    int k2 = 1 << k;
    int ans = 0;
    //bit全探索 s:人がc,dの皿のどっちかのパターンを示す2進数
    rep(s,k2){
        //1~Nまでなので+1配列を用意
        vector<int> dish(n+1);
        rep(i,k){
            //2進数のi桁目をとる
            //sが10110でiが2だったらsが00101となり
            //これと&1をすると下1桁が取り出せる。この桁はi桁目
            //i桁目が1ならi人目はdの皿、0ならcの皿にいれる
            if(s>>i&1){
                dish[d[i]]++;
            }else {
                dish[c[i]]++;
            }
        }
        //その時の条件を満たしている個数now
        int now = 0;
        rep(i,m){
            //どっちかが空ならダメなのでコンティニュー
            if(dish[a[i]] == 0){
                continue;
            }
            if(dish[b[i]] == 0){
                continue;
            }
            //条件を満たすのでインクリメント
            now++;
        }
        //maxとって最大が答え
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}
//bit全探索 2択であるため2進数で考える
//人がどっちの皿にボールを入れるかを全探索して
//条件に沿うかをifで判定して計上する
