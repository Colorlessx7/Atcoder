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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n, m;
  cin >> n >> m;
  //s,cに関するpair配列(fi:s,se:c)
  vector<pair<int,char>> sc(m);
  //全条件の入力
  rep(i,m){
    cin >> sc[i].first >> sc[i].second;
    //桁数を文字列配列のindexで管理するため-1
    sc[i].first--;
  }
  int x = pow(10,n);
  //0~(10^x)-1まで回す
  rep(i,x){
    //t:iを文字列に変換
    string t = to_string(i);
    //iの桁数がnと一致していない場合は条件を満たさないのでコンティニュー
    //(Reading zeroとN桁未満のiを飛ばす)
    if(t.size() != n){
      continue;
    }
    //条件を満たすか
    bool flag = true;
    //全条件について回す
    //(s:何番目の桁か,c:その桁の数字)
    for(auto [s,c] : sc){
      //tのs桁目がcでない場合は条件を満たさないのでflagを下ろす
      if(t[s] != c){
        flag = false;
      }
    }
    //iが条件を満たすならiを出力して終了
    if(flag){
      cout << i << endl;
      return 0;
    }
  }
  //存在しない場合は-1を出力して終了
  cout << -1 << endl;
  return 0;
}
