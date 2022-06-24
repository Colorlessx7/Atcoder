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
  ll q;
  cin >> q;
  //個数管理
  map<ll,ll> mp;
  //存在管理
  set<ll> st;
  //クエリ処理
  rep(qi,q){
    //クエリの種類
    ll t;
    cin >> t;
    if(t == 1){
      //x:多重集合Sに入れる数字
      ll x;
      cin >> x;
      //多重集合の個数管理をしているmapでxの個数を1増やす
      mp[x]++;
      //多重集合内にxが存在するのでsetにxを格納
      st.insert(x);
    }else if(t == 2){
      //x:多重集合Sから消す数字の種類,c:多重集合から消すxの消す個数
      ll x, c;
      cin >> x >> c;
      //n:多重集合内のxの個数
      ll n = mp[x];
      //多重集合Sからxをc個削除(c個存在しない場合あるだけ削除)
      mp[x] -= min(c,n);
      //xが多重集合S内に存在しない場合存在する数字を管理するsetからxを削除
      if(mp[x] == 0){
        st.erase(x);
      }
    }else {
      //itr1:多重集合内に存在する数字の中での最小値が格納されている場所のイテレータ
      auto itr1 = st.begin();
      //itr2:多重集合内に存在する数字の中での最大値が格納されている場所のイテレータ
      //ただend()だと最大値の一つ先の場所を指すのでイテレータの場所を-1する(rbeginなら一発)
      auto itr2 = st.end();
      itr2--;
      //イテレータに*をつけると値を取れるので(Sの最大値)−(Sの最小値)を出力
      cout << *itr2 - *itr1 << endl;
    }
  }
  return 0;
}
