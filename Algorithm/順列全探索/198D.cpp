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
  vector<string> s(3);
  //文字列3つの入力
  rep(i,3){
    cin >> s[i];
  }
  //(アルファベット:倍率)を格納するmap
  //のちに(アルファベット:対応する順列の数字)としても使う
  map<char,ll> mp;
  //s1,s2,s3の最初の桁のアルファベットを格納
  //(最初の桁に0を使えないためそれを検出する用)
  set<char> heads;
  rep(i,3){
    //例として3472を考えると3472=1000*3+100*4+10*7+1*2となる(SUM(係数*桁の数字))
    //これをアルファベットでやる
    //例として、send+more-money=0の時
    //1000*s+100*e+10*n+1*d+1000*m+100*o+10*r+1*e-10000*m+1000*o+100*n+10*e+1*y=0
    //よってs:1000,e:91,n:-90,d:1,m:-9000,o:-900,r:10,y:-1 という感じで倍率を抽出する
    //sの桁が固定ではないので係数の初期値をS1,S2については1,S3については-1として
    //桁を進める毎に係数を10倍していく(そのため文字列を逆にして下の桁を前から見れるようにする)
    reverse(all(s[i]));
    //係数 S1,S2は1で初期化
    ll co = 1;
    //S1+S2=S3をS1+S2-S3=0として扱う
    //3番目の文字列(i=2)だけ係数をマイナスにする
    if(i == 2){
      co = -1;
    }
    //上記のようにアルファベット毎の倍率を抽出する処理
    //文字列s3つの全桁について1桁ずつ回す
    for(char c : s[i]){
      //アルファベットの倍率(上記)を計算する処理
      mp[c] += co;
      //次の桁を見るために倍率を10枚する
      co *= 10;
    }
    //sを逆にしたので戻す
    reverse(all(s[i]));
    //s1,s2,s3の最初の桁のアルファベットを格納
    heads.insert(s[i][0]);
  }
  //覆面算S1+S2=S3の中に文字が11個以上存在するなら
  //アルファベット1種類と数字1種類が対応しなくなるため
  //UNSOLVABLEを出力して終了
  if(mp.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  //覆面算のアルファベットと対応させる数字(0~9)についての配列
  vector<int> p(10);
  //指定された値から始まる整数列を生成(今回はpを0~9で埋める)
  iota(all(p),0);
  //順列全探索(O(10!))
  do{
    //アルファベットxと対応させる順列pの添字
    ll i = 0;
    //アルファベットと数字を対応させた後のS1+S2-S3の結果
    ll tot = 0;
    //アルファベット:倍率のmapの全アルファベットについて回す
    //mapに格納されているkeyのアルファベットの順に順列pの数字を割り当てていく
    for(auto x : mp){
      //s1,s2,s3の先頭のアルファベットが0にならないように確認するために
      //cに順列pの数字に対応させたいアルファベットを格納
      char c = x.first;
      //順列pの数字に対応させたいアルファベットの倍率をcoに格納
      ll co = x.second;
      //順列全探索の過程でs1,s2,s3の先頭の文字が0になってしまったら
      //問題の条件と異なってしまうのでtotを0にしようがない数字にして処理する
      if(p[i] == 0 && heads.count(c)){
        tot = 1e18;
      }
      //s1+s2-s3の値にアルファベットに対応させた順列pの数字*アルファベットの倍率coをたす
      //全てのアルファベットについて処理したときにtot=s1+s2-s3の値になる
      tot += co * p[i];
      //あるアルファベットについて処理したので次のアルファベットを処理するために
      //順列pの添字を進める
      ++i;
    }
    //S1+S2-S3=0なら覆面算が解けるので処理
    if(tot == 0){
      //アルファベットxと対応させる順列pの添字
      i = 0;
      //出力させるためにmapの使い方を
      //(アルファベット:倍率)から(アルファベット:対応する順列の数字)に変える
      for(auto& x : mp){
        //アルファベットのvalueに順列の値を格納
        x.second = p[i];
        //順列のカウンタを進める
        ++i;
      }
      //s1,s2,s3を数字に変換して出力する作業
      rep(i,3){
        //x:s1,s2,s3の数字に変換した後の値(今から変換)
        ll x = 0;
        //文字列sを前から処理
        for(char c : s[i]){
          //大きい桁から埋めていくような処理
          x = x * 10 + mp[c];
        }
        //変換した数字を出力
        cout << x << endl;
      }
      //覆面算の解法が複数ある場合があるため1個出力したら終了
      return 0;
    }
  }while(next_permutation(all(p)));
  //S1+S2-S3=0となるアルファベットと数字の組み合わせが存在しない場合
  //覆面算が解けないのでUNSOLVABLEを出力して終了
  cout << "UNSOLVABLE" << endl;
  return 0;
}
//覆面算問題
//S1 + S2 = S3 となるアルファベットの対応関係を探す
