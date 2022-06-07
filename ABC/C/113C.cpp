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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //n:県の数,m:市の数
  ll n, m;
  cin >> n >> m;
  //f[i]:i県の市の誕生年の集合(fi:誕生年、se:都市番号)
  vector<set<P>> f(n+1);
  //id[i]:i番目の市の認識番号
  vector<string> id(m); 
  //各都市の情報の入力
  rep(i,m){
    ll p, y;
    cin >> p >> y;
    f[p].insert({y,i});
  }
  //認識番号を作る
  rep2(i,n){
    //l:上6桁の認識番号,lf:都市番号を文字列に
    string lf = to_string(i);
    ll ln = lf.size();
    ll l1 = 6-ln;
    string l;
    //先頭に0をつけれるだけ追加
    rep(j,l1){
      l += '0';
    }
    //文字列を合体
    l += lf;
    //cnt:都市の誕生順につける番号
    ll cnt = 1;
    //誕生順に認識番号の下6桁を作る
    for(auto p : f[i]){
      //r:下6桁の認識番号,rf:誕生順の番号を文字列に
      string rf = to_string(cnt);
      ll rn = rf.size();
      ll r1 = 6-rn;
      string r;
      //先頭に0をつけれるだけ追加
      rep(j,r1){
        r += '0';
      }
      //文字列を合体
      r += rf;
      //上6桁と下6桁を組み合わせ、認識番号としてidに登録
      id[p.second] = l + r;
      //都市の誕生順の番号を進める
      cnt++;
    }
  }
  //各認識番号を出力
  rep(i,m){
    cout << id[i] << endl;
  }
  return 0;
}
