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
//組み合わせ計算用関数(nC2)
ll choose2(ll n){
    return n*(n-1)/2;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        //入力後0indexにしたいので全て-1
        a[i]--;
    }
    //aiの分布用の配列、制約で1<=ai<=nなのでsize＝n
    vector<ll> cnt(n);
    rep(i,n){
        //添字に対応するaiが出てきたらcnt[ai]を+1
        cnt[a[i]]++;
    }
    //組み合わせの総数
    ll tot = 0;
    //組み合わせの総数の計算
    rep(i,n){
        tot += choose2(cnt[i]);
    }
    //一つ取り除いた時の処理
    rep(i,n){
        ll ans = tot;
        //組み合わせの総数から取り除いた数字の分の組み合わせをひく(xC2)
        ans -= choose2(cnt[a[i]]);
        //取り除いた分小さくなった組み合わせの計算をして足す(x-1C2)
        ans += choose2(cnt[a[i]]-1);
        //都度出力
        cout << ans << endl;
    }
    return 0;
}
//数学的考察で解く問題
//一つ数字が消えた時に答えがどのくらい変化するのかを考えて
//全体の組み合わせの総数を計算した後に
//都度変化量を引いて出力し戻すを繰り返す
//例として1:3,2:2なら1を消したら組み合わせの総数から
//-3C2した後に+2C2すれば良い
