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
//満足度の低下係数
vector<ll> c(26);
//コンテストjをやった日iに上昇する満足度s
vector<vector<ll>> s(365,vector<ll>(26));
//
const ll k = 4;

auto start = std::chrono::system_clock::now();
inline double get_time() {
  auto end = std::chrono::system_clock::now();
  auto dur = end - start;
  double msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
  return msec;
}
 
double timelimit = 1950;
inline bool check_time() {
  auto end = chrono::system_clock::now();
  auto dur = end - start;
  auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
  if (msec >= timelimit) return false;
  return true;
}

struct State{
  //メンバ変数
  vector<ll> out;
  ll score;
  vector<vector<ll>> ds;
  ll old_p, new_p;

  //コンストラクタ
  State(){
    //コンストラクタで初期解を貪欲法を用いて設定
    rep(d,D){
      ll max_score = LLONG_MIN;
      ll best_i = 0;
      rep(i,26){
        out.push_back(i);
        score = compute_score();
        if(max_score < score){
          max_score = score;
          best_i = i;
        }
        out.pop_back();
      }
      out.push_back(best_i);
    }
    //dsの設定をする関数
    new_();
  }
  //貪欲法の評価関数計算関数
  ll compute_score(){
    ll pre_score = 0;
    vector<ll> last(26,0);
    ll n = out.size();
    rep(d,n){
      last[out[d]] = d + 1;
      rep(i,26){
        pre_score -= c[i] * ((d + 1) - last[i]);
      }
      pre_score += s[d][out[d]];
    }
    ll fin = min(n + k, D);
    replr(d,n,fin){
      rep(i,26){
        pre_score -= c[i] * ((d + 1) - last[i]);
      }
    }
    return pre_score;
  }
  //changeの計算に必要な関数
  ll cost(ll a,ll b){
    ll d = b - a;
    return (d * (d - 1) / 2); 
  }
  //配列dsの初期設定をする関数
  void new_(){
    ds.resize(26);
    rep(d,D){
      ds[out[d]].push_back(d+1);
    }
    score = compute_score();
  }
  //d日目のコンテストをold_iからnew_iに変える時のスコアの変動を高速に計算する関数
  ll change(ll d, ll new_i){
    //ここだけオリジナルなので怖い
    ll new_score = score;
    //old_i:d日目にやるコンテストの種類(変更前)
    ll old_i = out[d];
    //p:ds[old_i]の配列の中の要素がd+1になっている場所の添字
    old_p = 0;
    ll ds_old_i_size = ds[old_i].size();
    rep(i,ds_old_i_size){
      if(ds[old_i][i] == d+1){
        old_p = i;
        break;
      }
    }
    ll prev = 0;
    if(old_p-1 >= 0){
      prev = ds[old_i][old_p-1];
    }
    ll next = D + 1;
    if(old_p+1 < ds_old_i_size){
      next = ds[old_i][old_p+1];
    }
    //ds[old_i].erase(ds[old_i].begin()+old_p);
    new_score += (cost(prev,d+1) + cost(d+1,next) - cost(prev,next)) * c[old_i];
    ll ds_new_i_size = ds[new_i].size();
    new_p = ds_new_i_size;
    rep(i,ds_new_i_size){
      if(ds[new_i][i] > d+1){
        new_p = i;
        break;
      }
    }
    prev = 0;
    if(new_p-1 >= 0){
      prev = ds[new_i][new_p-1];
    }
    next = D + 1;
    if(new_p < ds_new_i_size){
      next = ds[new_i][new_p];
    }
    //ds[new_i].insert(ds[new_i].begin()+new_p,d+1);
    new_score -= (cost(prev, d + 1) + cost(d + 1, next) - cost(prev, next)) * c[new_i];
    new_score += s[d][new_i] - s[d][old_i];
    out[d] = new_i;
    return new_score;
  }

  void run(){
    srand((unsigned) time(NULL));
    while(check_time()){
      ll d = rand() % D;
      ll q = rand() % 26;
      ll old = out[d];
      ll new_score = change(d,q);
      if(score > new_score){
        out[d] = old;
      }else {
        ds[out[d]].erase(ds[out[d]].begin()+old_p);
        ds[q].insert(ds[q].begin()+new_p,d+1);
        out[d] = q;
        score = new_score;
      }
      //cout << score << endl;
    }
  }
};

//入力部
void input(){
  cin >> D;
  c = vector<ll>(26);
  s = vector(365,vector<ll>(26)); 
  rep(i,26){
    cin >> c[i];
  }
  rep(i,D){
    rep(j,26){
      cin >> s[i][j];
    }
  }
  return;
}

//main
int main(){
  input();
  State state;
  state.run();
  //cout << state.score << endl;
  rep(i,D){
    cout << state.out[i] + 1 << endl;
  }
  return 0;
}

//run周りで配列外参照を起こしているため要検証
