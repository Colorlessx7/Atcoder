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
  //ラムダ式
  //二分探索の中点Dを光の照らす範囲に仮に設定した時に全ての人n人が光に照らされるかを判定する関数
  auto solve = [&](ll D){
    //flag[i]:i人目の人が光に照らされるなら1,照らされないなら0(boolでいい)
    vector<int> flag(n,0);
    //全ての光源について試す
    rep(i,k){
      //全ての人について試す
      rep(j,n){
        //dx:光源iと人jのx軸での差分
        ll dx = x[a[i]] - x[j];
        //dy:光源iと人jのy軸での差分
        ll dy = y[a[i]] - y[j];
        //dist:光源iと人jのユークリッド距離(二分探索のmidと同様に整数性を保つため根号を一旦無視する)
        ll dist = dx*dx+dy*dy;
        //光源iと人jとの距離がD以下なら人jが光源iからDの範囲内にいて照らされるのでflag[i]を立てる
        //逆に考えるとdist>Dなら処理されない(この時二分探索で設定した光源の範囲より
        //光源と人の距離が遠くなり、人jが照らされなくなるのでflag[j]が0のままになる)
        if(dist <= D){
          flag[j] = 1;
        }
      }
    }
    //全ての人について回す
    rep(i,n){
      //flag[i]が0ならどこの光源からも光が届かない人がいるのでfalseで返す
      if(flag[i] == 0){
        return false;
      }
    }
    //全員光に照らされたのでtrueで返す
    return true;
  };
  const ll INF = 1e18;
  //光の最小距離を0に、光の最大距離を10^18に設定する(left:ok,right:ng)
  //二分探索の距離はユークリッド距離をsqrt(mid)とするとmidを使って行う(整数性を保つ)
  ll left = INF, right = 0;
  //二分探索の実行(最終的にleftが光が届く限界距離、rightが光が届かない限界距離になる)
  while(left - right > 1){
    //中点を選ぶ
    ll mid = (left + right) / 2;
    //光の届く範囲をmidと仮定した時に全員に光が届くなら処理
    if(solve(mid)){
      //midまでの範囲に光が届くのでokの極であるleftをmidまで移動させて次の二分探索へ
      left = mid;
    }else {
      //光の届く範囲をmidと仮定した時に全員に光が届かないなら処理
      //midまでの範囲だと光が届かないのでngの極であるrightをmidまで移動させて次の二分探索へ
      right = mid;
    }
  }
  //setprecision(10)で桁数を10桁に設定できる
  //(fixedがあることにより小数点以下の桁が10桁表示されるように設定される)
  //leftが光が届く限界距離(根号をかけてない状態)なので根号を計算に入れて出力する
  cout << fixed << setprecision(10) << sqrtl(left) << endl;
  return 0;
}
