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
  //(i,j)とするとiからjに変換するならtrueしないならfalse
  vector<vector<bool>> f(26,vector<bool>(26)); 
  rep(i,n){
    //sのi文字目(変換元)をaとする
    ll a = s[i] - 'a';
    //tのi文字目(変換先)をbとする
    ll b = t[i] - 'a';
    //aからbに変換するのでtrueに
    f[a][b] = true;
  }
  //変換元について処理
  rep(i,26){
    ll cnt = 0;
    //グラフとして見た時の頂点iの次数をカウント
    rep(j,26){
      //iからjに辺が繋がっているか
      if(f[i][j]){
        cnt++;
      }
    }
    //次数が2以上ならNo出力し終了
    if(cnt >= 2){
      cout << "No" << endl;
      return 0;
    }
  }
  //上と同じことを変換先について処理
  rep(j,26){
    ll cnt = 0;
    rep(i,26){
      if(f[i][j]){
        cnt++;
      }
    }
    if(cnt >= 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
//ある文字について複数の変換先があってはいけない
//ある文字について複数の変換元があってはいけない
//というルールをチェックして判定する

//解説の解法(これ)は文字列を元にf[i][j]:文字iを文字jに変換するか
//のbool二次元配列を作って各iのf[i][j]=trueとなるjの個数を見て2以上ならNo
//各jのf[i][j]=trueとなるiの個数を見て2以上ならNo
//二つの条件を抜けたらYesとする方法がある
