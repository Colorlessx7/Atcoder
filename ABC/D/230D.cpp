#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, d;
  cin >> n >> d;
  //n枚の壁の区間[l,r]をpairで持つ(今回は(r,l)として持つ)
  vector<P> p(n);
  rep(i,n){
    //今回はlとrの関係が崩れないようにrを昇順にsortしたいので
    //first,secondを逆にする(下のsortの部分を参照)
    cin >> p[i].second >> p[i].first;
  }
  //pairのsortのデフォルトはfirstを基準に昇順でsortして
  //firstが同じならsecondを基準に昇順でsortする
  sort(all(p));
  //ans:最小必要パンチ回数(区間スケジューリングのアルゴリズムと同じためその答えと一致する)
  //x:最後にパンチした右端の座標(最初はどこも破壊できない
  //壁の左端lよりxが小さいなら壊せない判定なので-1で初期化)
  //壁の右端rについてはrを基準に昇順に並べた以上
  //現在の壁のrが以降の壁のrより小さいことは確定していて
  //前に遡って考える必要がないためxは最後の1回分だけ持っておけば良い
  ll ans = 0, x = -1; 
  //c++17からpairのfirst,secondを今回だとr,lのように取り扱えるようになった
  //壁n枚について回す
  for(auto [r,l] : p){
    //最後のパンチで壊れるかどうかの判定(区間(パンチ範囲と壁の範囲)が被っているか) 
    //lがx以下ならパンチの範囲内に壁があるため壁が壊れ、この壁を考える必要がなくなる
    if(l <= x){
      continue;
    }
    //最後のパンチで今見ている壁が壊れない場合
    //追加でパンチする必要があるため+1
    ans++;
    //最後にパンチした右端の座標の更新
    //一つ前のパンチで壊れなかった壁の右端rを問題分の意味のxとして
    //パンチの範囲が[r,r+d-1]となるため
    //最後にパンチした右端の座標はr+d-1に更新される
    x = r + d - 1;
  }
  cout << ans << endl;
  return 0;
}
//区間スケジューリング問題に似た問題で貪欲法で解く
//壁の右端の座標rについて昇順にsortし
