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
  ll n, m;
  cin >> n >> m;
  //筒m個をqueueの配列として確保
  vector<queue<ll>> a(m);
  //筒の中のボールの数(最初2*n個固定だから取り出す時だけカウントして最後にcnt=2*nか判定した方が良さそう)
  ll cnt = 0;
  //各筒の中のボールの設定
  rep(i,m){
    //筒の中のボールの個数
    ll k;
    cin >> k;
    rep(j,k){
      //筒の中のボールの色
      ll aa;
      cin >> aa;
      //0indexed調整
      aa--;
      //筒に入れる
      a[i].push(aa);
    }
  }
  //ボールを順番に処理するためのqueue 1:色,2:筒
  queue<P> que;
  //筒の場所を格納(id[i]:i色のボールが元々あった筒の番号を示す)
  //-1:色iのボールが見つかっていない場合に格納(初期状態)
  vector<ll> id(n,-1);
  //予備の情報格納先
  ll f;
  //初めに全ての筒の一番上のボールを取り出す処理
  rep(i,m){
    //筒iの先頭の色xのボールを取り出す
    ll x = a[i].front();
    //筒の中身を進める
    a[i].pop();
    //筒からボールを取り出したのでカウンタを+1
    cnt++;
    //取り出したボールを処理用のqueに格納(x色,筒i)
    que.push({x,i});
  }
  //取り出したボールを処理しつつ、それ以降のボールを取り出し処理する処理
  while(que.size()){
    //処理用のqueからボールの情報を取り出す
    P s = que.front();
    //色x
    ll x = s.first;
    //筒i
    ll i = s.second;
    //ボールの情報を取り出したのでqueの情報を進める
    que.pop();
    //同じ色xのボールが発見されていない場合の処理
    if(id[x] == -1){
      //筒iからx色のボールを取り出したのでid[x]にiを格納
      id[x] = i;
    }else {
      //すでに同じ色のボールが発見されている場合の処理(ボールを消しつつ筒からボールを出す)
      //元々発見していた色xのボールが元々あった筒(id[x])にまだボールが残っている場合に処理
      if(a[id[x]].size()){
        //色xのボールが元々あった筒(a[id[x]])からボールを取り出す(f:取り出したボールの色)
        f = a[id[x]].front();
        //筒a[id[x]]からボールを取り出したのでqueueから先頭の情報を削除
        a[id[x]].pop();
        //ボールを取り出したのでカウンタを+1
        cnt++;
        //取り出したボールの情報を処理用のqueに格納(f:色の番号,id[x]:筒の番号)
        que.push({f,id[x]});
      }
      //新しく発見した色xのボールが元々あった筒(i)にまだボールが残っている場合に処理
      if(a[i].size()){
        //色xのボールが元々あった筒(a[i])からボールを取り出す(f:取り出したボールの色)
        f = a[i].front();
        //筒a[i]からボールを取り出したのでqueueから先頭の情報を削除
        a[i].pop();
        //ボールを取り出したのでカウンタを+1
        cnt++;
        //取り出したボールの情報を処理用のqueに格納(f:色の番号,i:筒の番号)
        que.push({f,i});
      }
      //同じ色のボールを2つ見つけて削除したのでxのボールが元々入っていた筒
      //の情報を初期化(特に意味はないので消しても問題ない)
      id[x] = -1;
    }
  }
  //元々のボールの個数が2*nで取り出したボールがちょうど2*nでない場合No,ちょうど2*nならYes
  if(cnt != 2 * n){
    cout << "No" << endl;
  }else {
    cout << "Yes" << endl;
  }
  return 0;
}
//vector<queue<ll>>で解く解法
//初期状態のrep(i,m)でqueに突っ込むだけにして判定は全部whileの部分でやった方が良さそう
