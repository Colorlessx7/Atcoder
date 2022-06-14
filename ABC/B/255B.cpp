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
  //n:人数,k:明かりを持つ人数
  int n, k;
  cin >> n >> k;
  //明かりを持つ人のid
  vector<int> a(k);
  rep(i,k){
    cin >> a[i];
    //0indexed調整
    a[i]--;
  }
  //(xi,yi):i人目の座標(x,y)
  vector<int> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  //すべての人が少なくとも1つの明かりによって照らされるために必要な明かりの強さの最小値
  double ans = 0;
  //r[i]:人iに一番近い明かりから人iまでの距離
  vector<double> r(n);
  //全ての人についてループ
  rep(i,n){
    //minを取る為最大初期化
    r[i] = 1e18;
    //明かりを持った人についてのループ
    rep(j,k){
      //dx:i人目のx座標とj番目のidの人(明かり持ち)のx座標の差分
      double dx = x[i]-x[a[j]];
      //dy:i人目のy座標とj番目のidの人(明かり持ち)のy座標の差分
      double dy = y[i]-y[a[j]];
      //dist:i人目の人とj番目のidの人(明かり持ち)間のユークリッド距離(sqrt(dx^2+dy^2))
      double dist = sqrt(dx*dx + dy*dy);
      //r[i]をdistのminを取ることでi人目の明かりまでの最短距離にする
      r[i] = min(r[i],dist);
    }
    //最も近い明かりが最も遠い人に合わせてRを設定すればすべての人が少なくとも1つの明かりによって照らされる
    //ため、最も近い明かりの距離が最大なら更新する
    ans = max(ans,r[i]);
  }
  printf("%.10f\n",ans);
  return 0;
}
