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
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n),b(k);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,k){
    cin >> b[i];
    //食品のidを0indexedで
    b[i]--;
  }
  //おいしさの最大
  int mx = 0;
  //最大調査
  rep(i,n){
    chmax(mx,a[i]);
  }
  //嫌いな食品調査
  rep(i,k){
    //嫌いな食品b[i]のおいしさa[b[i]]がおいしさの最大mxならYesを出力し終了
    if(a[b[i]] == mx){
      cout << "Yes" << endl;
      return 0;
    }
  }
  //おいしさが最大の食品に嫌いなものが存在しなかったのでNoを出力し終了
  cout << "No" << endl;
  return 0;
}
