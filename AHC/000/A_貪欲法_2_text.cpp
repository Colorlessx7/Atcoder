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

//日数
ll D = 365;
//c[i]:コンテストiを行わなかったことによる満足度の低下係数
vector<ll> c(26);
//s[i][j]:i日目にコンテストjを行った時に上昇する満足度
vector<vector<ll>> s(365,vector<ll>(26));
//
const ll k = 4;

//入力部
void input(){
  //日数の入力
  cin >> D;
  //コンテストi毎の満足度の低下係数の入力
  rep(i,26){
    cin >> c[i];
  }
  //i日目にコンテストjを行った時の満足度の上昇量の入力
  rep(i,D){
    rep(j,26){
      cin >> s[i][j];
    }
  }
  return;
}

//評価関数計算関数(引数out:out[i]でi日目に行うコンテストの種類(D日分あるわけではない))
ll evaluate(vector<ll> &out){
  //下のnからn日分コンテストを決めた時の最終的な満足度のスコア(0初期化し、以降の処理に使う)
  ll score = 0;
  //last[i]:コンテストiを最後に行った日がいつか(0初期化)(コンテストiを行わない場合0,行う場合は日によって1~Dをとる)
  vector<ll> last(26,0);
  //n:何日分行うコンテストの種類を決めたか
  ll n = out.size();
  //行うコンテストの種類を決めた日数n日分についてのループ
  rep(d,n){
    //d+1日目にコンテストout[d]を行ったのでlastに登録する
    //(dは0indexedなので+1する)
    last[out[d]] = d + 1;
    //d日目にコンテストout[d]を行ったことによる、全てのコンテストについての満足度の低下の計算をするループ(i:コンテストの種類)
    //(毎日処理するため、コンテストを行わなかった場合の減少が日数が経つごとに重くなる)
    rep(i,26){
      //c[i]:コンテストiを行わなかったことによる満足度の低下係数
      //(d+1)-last[i]:コンテストiを行わなかった日数
      score -= c[i] * ((d + 1) - last[i]);
    }
    //コンテストout[d]を行ったことによって上昇する満足度を加算
    //上昇する満足度はs[d][out[d]]でこれは配列sのd日目にコンテストout[d]を行った時の満足度の上昇量を示す
    score += s[d][out[d]];
  }
  //
  ll fin = min(n + k, D);
  replr(d,n,fin){
    rep(i,26){
      score -= c[i] * ((d + 1) - last[i]);
    }
  }
  return score;
}

//貪欲法を解く関数
vector<ll> solve(){
  //i日目にコンテストt[i]を行う(初期状態は何も決まっていない状態で
  //一日毎にscoreが一番高くなるコンテストの種類を末尾に追加していく)
  vector<ll> out;
  //コンテストを行う日数に関するループ(d日目にどのコンテストをやるか決めていく)
  rep(d,D){
    //max_score:d日目でどのコンテストをやるのが一番満足度が高くなるかを検証するための変数(maxをとっていくため最小値で初期化)
    ll max_score = LLONG_MIN;
    //best_i:d日目にやると一番d日目時点での満足度が高くなるコンテストの種類(0初期化)
    ll best_i = 0;
    //全てのコンテストの種類についてループ
    rep(i,26){
      //d日目に仮にコンテストiをやる時の満足度を計算するためにコンテストiをoutの末尾に追加
      out.push_back(i);
      //d日目に仮にコンテストiをやる時の満足度を計算
      ll score = evaluate(out);
      //d日目にコンテストiをやった時が他のコンテストをやる場合より満足度が大きくなる場合に処理
      if(max_score < score){
        //d日目にとる満足度の最大値を更新
        max_score = score;
        //d日目にどのコンテストをやるのが最適かを更新
        best_i = i;
      }
      //検証するためにつけた仮のd日目のコンテスト番号(outの末尾の値)を削除
      out.pop_back();
    }
    //全コンテストについて検証し、d日目にコンテストbest_iをやるのが最適だとわかったので
    //outの末尾にbest_iを格納し、d日目にコンテストbest_iを行うよう決める
    out.push_back(best_i);
  }
  //コンテストの日にち毎の種類を全て決めたのでそれをmain関数に返す
  return out;
}

//main
int main(){
  //入力処理
  input();
  //貪欲法を解き、何日目にどのコンテストを行うかを決めた配列outをansを返す
  vector<ll> ans = solve();
  //何日目にどのコンテストをやることに決めたかを出力(コンテストの番号が0indexedなので+1する)
  rep(i,D){
    cout << ans[i] + 1 << endl;
  }
  return 0;
}

//k=4,102'969'449点
////k=0~26とした時の最大コストを測定
//k=4の時最大でそこを基準としてkの絶対値の差が大きくなるほどスコアが下がっていく
//0:
//1:
//2:98168006
//3:101765811
//4:102969449
//5:102059998
//6:101467967
//7:99617969
//8:
//9:96463298
//10:
//11:93191798
//12:
//13:89362833
//14:
//15:
//16:
//17:
//18:
//19:
//20:
//21:
//22:
//23:
//24:
//25:
//26:71599362
