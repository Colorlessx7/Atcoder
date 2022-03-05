#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
//構造体frac:傾き(xとy)を分数でそのまま小数にせず有理数として残すためのstructを作る
//注意点として0/0のケースは想定していない
struct frac{
    ll a, b;
    //コンストラクタを読んだときに既約分数にするという作業をする
    //:以降は初期化子リスト
    //main関数からの参照渡しになりコンストラクタ内で初期化できない為
    //初期化子リストでx[i] - x[j]を_a,y[i] - y[j]を_bとして参照渡しで受け取り
    //それをa(_a),b(_b)とすることでa,bとしてfrac内で扱えるようにしている
    //(ll _a = 0, ll _b = 1)はここで渡される値で初期化できないため適当な値で初期化している
    frac(ll _a = 0, ll _b = 1): a(_a),b(_b) {
        //分母が0の時は特殊ケースなのでa=1にしてreturn
        if(b == 0){
            a = 1;
            return;
        }
        //分母がマイナスだとまずいので分子分母に-1を掛けて正規化
        if(b < 0){
            a = -a;
            b = -b;
        }
        //既約分数にするために割るべき数は分子分母の最小公倍数なので
        //aとbのgcdをとる この時分母bは上の処理でマイナスにはなっていないが
        //aはマイナスになっている可能性があるのでaに絶対値absをかけておく
        //aが0の時はgcdがbになる
        ll g = gcd(abs(a),b);
        //既約分数にするために割るべき数gを割って既約分数にする
        a /= g;
        b /= g;
        //ここまでがコンストラクタ
    }
    //比較関数
    //比較関数があればsetに突っ込めるのであとはやり放題
    //コピーコンストラクタ? 引数名:x
    //stlのコンテナとして使うので比較演算子<をオーバーロードする必要がある
    //(他に比較演算子<をstlを使うのにオーバーロードする必要がある例)
    //mapのKeyとして構造体を使う場合
    //priority_queueの要素の型として構造体を使う場合
    //構造体の配列に対してsort関数を使う場合
    bool operator<(const frac &x) const {
        //left < right でtrueを返すように実装
        //元々setに格納されていたfrac型の傾きa,bと今setに格納しようとして、
        //コピーコンストラクタx上でfracコンストラクタ通りの初期化をしたa,b
        //つまりx.a,x.bが a/b < x.a/x.bになるようにsetに格納する
        //setの使用上a/b==x.a/x.bなら格納されず > ならsetの次のイテレータのa,bと
        //比較を開始する a/b < x.a/x.bこの式を移項するとa * x.b < x.a * bとなる
        return a * x.b < x.a * b;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    //構造体fracを型としてsetを宣言
    set<frac> st;
    //rep(i,n)rep(j,i)で重複なく数えることができる
    rep(i,n){
        rep(j,i){
            //構造体fracで既約分数にしてからsetにinsert
            //fracにはx[i] - x[j]をa,y[i] - y[j]をbとして渡す
            st.insert(frac(x[i] - x[j],y[i] - y[j]));
        }
    }
    //setに格納した傾きは向きを考慮していないため*2する
    cout << st.size() * 2 << endl;
    return 0;
}
//構造体を駆使して傾きを既約分数にしてsetに格納する問題
//既約分数は分子分母の最大公約数が1になる分数
