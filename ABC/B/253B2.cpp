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
  int h, w;
  cin >> h >> w;
  //oの座標を格納(fi:y,se:x)
  vector<P> place;
  rep(i,h){
    rep(j,w){
      char c;
      cin >> c;
      if(c == 'o'){
        place.emplace_back(i,j);
      }
    }
  }
  //c++17の記法
  //一つ目のoの(i,j)=(a,b),二つ目のoの(i,j)=(c,d)
  auto [a,b] = place[0];
  auto [c,d] = place[1];
  //ans:o二つのマンハッタン距離(i同士、j同士の差分の合計)
  int ans = abs(a - c) + abs(b - d);
  cout << ans << endl;
  return 0;
}
