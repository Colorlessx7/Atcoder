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
  string s,t;
  cin >> s >> t;
  ll n = s.size();
  //アルファベットa~zを0~25として添字で扱う
  //st:変換元のアルファベットiに対応する変換先のアルファベットを格納(0~25の範囲外の-1で初期化)
  vector<ll> st(26,-1);
  //ed:変換先のアルファベットiに対応する変換元のアルファベットを格納
  vector<ll> ed(26,-1);
  rep(i,n){
    //sのi文字目(変換元)をaとする
    ll a = s[i] - 'a';
    //tのi文字目(変換先)をbとする
    ll b = t[i] - 'a';
    //aから何になるか、何からbになるかが一方でも決まっているなら処理
    if(st[a] != -1 || ed[b] != -1){
      //下のelseの処理ですでに決まったある文字の変換先、変換元
      //に反するものが今処理しているi番目の文字で与えられたらNoを出力して終了
      if(st[a] != b || ed[b] != a){
        cout << "No" << endl;
        return 0;
      }
    }else {
      //aから何になるか、何からbになるかが決まってない場合処理
      //aからbになるように処理
      st[a] = b;
      ed[b] = a;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
//解説放送の解法
//ある文字について複数の変換先があってはいけない
//ある文字について複数の変換元があってはいけない
//というルールをチェックして判定する
//その方法としてある文字について最初にきた変換先、変換元を
//それぞれ固定して、それに反するものが以降の文字で出てきたらNoを
//出て来なかったらYesを出力させる
