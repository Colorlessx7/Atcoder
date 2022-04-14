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
  //sを変換元、tを変換先として考える
  string s,t;
  cin >> s >> t;
  //文字列の長さをnと置く
  ll n = s.size();
  //以下よりアルファベットa~zを0~25として扱う
  //アルファベット26文字をグラフの頂点として
  //gをsの文字から変換されるtの文字についての有向グラフとする
  vector<vector<ll>> g(26);
  //hをtの文字に変換されるsの文字についての有向グラフとする
  vector<vector<ll>> h(26);
  //グラフの辺の設定
  //hをgに一本化すると頂点に対する辺の数が必ず2以上になり、
  //変換先、変換元が複数個存在するか判定できなくなる
  //hを無かったことにすると、chokudai-redcoderのような
  //本来Noのものが変換先、変換元のどちらかのグラフしかないせいでYesになってしまう
  rep(i,n){
    g[s[i]-'a'].push_back(t[i]-'a');
    h[t[i]-'a'].push_back(s[i]-'a');
  }
  //重複を無視しつつグラフの辺の次数を調べるためにsetを使う
  set<ll> st;
  //変換元に関する有向グラフgの各頂点に対して辺の次数を調べ、
  //それが2以上だったらNoを出力して終了
  rep(i,26){
    //x:頂点iから行ける頂点
    //xに被りがある可能性があるためg[i].size()で判定できない
    for(ll x : g[i]){
      //iから行ける頂点xをsetに格納
      st.insert(x);
    }
    //辺の次数が2以上ならNoを出力し終了
    if(st.size() > 1){
      cout << "No" << endl;
      return 0;
    }
    //頂点の次数を調べたら都度clear
    st.clear();
  }
  //上と同じことを変換先に関する有向グラフhについて行う
  rep(i,26){
    for(ll x : h[i]){
      st.insert(x);
    }
    if(st.size() > 1){
      cout << "No" << endl;
      return 0;
    }
    st.clear();
  }
  cout << "Yes" << endl;
  return 0;
}
//ある文字について複数の変換先があってはいけない
//ある文字について複数の変換元があってはいけない
//というルールをチェックして判定する
