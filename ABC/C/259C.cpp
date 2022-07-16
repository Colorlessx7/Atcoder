#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  string s, t;
  cin >> s >> t;
  //ランレングス圧縮配列(i番目の同じ文字の集合がfiの文字がseの個数分存在)
  vector<pair<char,int>> sc;
  vector<pair<char,int>> tc;
  int sx = s.size();
  int tx = t.size();
  char c;
  int cnt = 0;
  //ランレングス圧縮
  rep(i,sx){
    if(i == 0){
      c = s[i];
      cnt++;
    }else {
      if(c != s[i]){
        sc.push_back({c,cnt});
        c = s[i];
        cnt = 1;
      }else {
        cnt++;
      }
    }
    if(i == sx-1){
      sc.push_back({c,cnt});
    }
  }
  cnt = 0;
  rep(i,tx){
    if(i == 0){
      c = t[i];
      cnt++;
    }else {
      if(c != t[i]){
        tc.push_back({c,cnt});
        c = t[i];
        cnt = 1;
      }else {
        cnt++;
      }
    }
    if(i == tx-1){
      tc.push_back({c,cnt});
    }
  }
  int scsz = sc.size();
  int tctz = tc.size();
  //文字が変わる回数が違う場合sはtにできないのでNoを出力して終了
  if(scsz != tctz){
    cout << "No" << endl;
    return 0;
  }
  //各ランレングス圧縮の要素について処理
  rep(i,scsz){
    //文字が違う場合
    if(sc[i].first != tc[i].first){
      cout << "No" << endl;
      return 0;
    }
    //sのi番目の要素の文字数がtのi番目の要素の文字数より多い場合
    if(sc[i].second > tc[i].second){
      cout << "No" << endl;
      return 0;
    }
    //sのi番目の要素の文字数がtのi番目の要素の文字数より少なく、かつ
    //sのi番目の要素の文字数が1で文字数を増やせない場合
    if(sc[i].second < tc[i].second && sc[i].second == 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
