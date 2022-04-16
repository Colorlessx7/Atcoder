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
ll h, w;
//以降のbool配列のサイズを指定(制約1500より少し大きい値)
const ll MX = 1505;
//探索の向きを示す配列 上左下右
vector<ll> di = {-1,0,1,0};
vector<ll> dj = {0,-1,0,1};
//座標は全て0indexedで扱う
//光源の座標の位置について trueなら(i,j)に光源がある
vector<vector<bool>> light(MX,vector<bool>(MX));
//壁の位置について trueなら(i,j)に壁がある
vector<vector<bool>> wall(MX,vector<bool>(MX));
//光が届くかどうか trueなら(i,j)は光源から壁にあたらず光が届く
vector<vector<bool>> ok(MX,vector<bool>(MX));
//メモ化再帰に使うbool配列
//(i,j)のマスをすでに探索してmemoにその時の結果を残しているかどうかのbool配列
//方向を変える毎に初期化する
vector<vector<bool>> visited(MX,vector<bool>(MX));
//すでに光が届いたか探索しているマスについて再判定しないように
//(i,j)に光が届くのかを格納するbool配列
vector<vector<bool>> memo(MX,vector<bool>(MX));
//向きvの光によって(i,j)が照らされているかどうか判定する再帰関数
bool f(ll v, ll i, ll j){
  //上4つは現在の再帰関数内の条件だけで最終的に光に(i,j)が照らされるかわかる場合の処理
  //最後の一つだけわからないので再帰して判定していく
  //範囲外(配列外参照)回避 範囲外なら光が来ないので再帰元にfalseを返す
  if(i < 0 || j < 0 || i >= h || j >= w){
    return false;
  }
  //壁がtrueならそこに壁があり光は来ないので再帰元にfalseを返す
  if(wall[i][j]){
    return false;
  }
  //光源がtrueならそこが光なので再帰元にtrueを返す
  if(light[i][j]){
    return true;
  }
  //(i,j)にすでに訪れているならその時の結果memoのT/Fを再帰元に返す
  if(visited[i][j]){
    return memo[i][j];
  }
  //(i,j)に到着して処理したのでvisitedをtrueにしておく
  visited[i][j] = true;
  //メモ化再帰の再帰部分
  //上記の全ての条件を満たさない場合はここで
  //di,djの値によって上左下右の方向に探索を再帰の形で進め
  //その結果をmemo[i-2][j],[i-1][j],[i][j](上に探索するパターン)
  //というようにmemoに格納しながら再帰元に帰していく
  return memo[i][j] = f(v, i + di[v], j + dj[v]);
}
int main(){
  ll n, m;
  cin >> h >> w >> n >> m;
  //光源の座標の入力と設定
  rep(i,n){
    ll r, c;
    cin >> r >> c;
    //0indexed処理
    r--; c--;
    //(r,c)に光源があるように設定
    light[r][c] = true;
  }
  //壁の座標の入力と設定
  rep(i,m){
    ll r, c;
    cin >> r >> c;
    //0indexed処理
    r--; c--;
    //(r,c)に壁があるように設定
    wall[r][c] = true;
  }
  //okのテーブルを更新する処理
  //探索の向き4方向について回す(上左下右の順)
  rep(v,4){
    //探索する向きが変わったタイミングでvisitedを初期化する
    //これにより処理によって光が曲がったりするのを防ぐ
    rep(i,h){
      rep(j,w){
        visited[i][j] = false;
      }
    }
    //全マスについて光が届くかの判定を行う
    rep(i,h){
      rep(j,w){
        //メモ化再帰の開始(メモ化再帰が終了するとif文の判定が処理され
        //光が届くなら(i,j)のokがtrueになり、届かないならif文を処理しない)
        if(f(v,i,j)){
          ok[i][j] = true;
        }
      }
    }
  }
  //ans:光が届くマス数
  ll ans = 0;
  //光が届くマスの数を集計
  rep(i,h){
    rep(j,w){
      //ok[i][j]がtrueなら光が届くのでインクリメント
      if(ok[i][j]){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//解説放送のメモ化再帰解法
//HHKBのE問題にて90度回転させながら処理する方法はやっているらしい
//探索の向きと反映される光の向きが逆になる
//(上に再帰関数で探索していくと光源の下方向の向きの光に照らされるかの判定ができる)
