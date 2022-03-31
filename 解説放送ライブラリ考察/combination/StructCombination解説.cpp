using mint = modint1000000007;
const int mod = 1000000007;
//組み合わせの個数nCkを求める構造体
struct combination {
  //fact:階乗
  //ifact:階乗の逆元
  vector<mint> fact, ifact;
  //combinationのコンストラクタ
  //このコンストラクタの中で階乗とその逆元をそれぞれ求めている
  //計算量O(n+logP)
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    //0!は1なので1で初期化
    fact[0] = 1;
    //1!~n!までをmodintを取りつつ計算し、階乗を格納する配列に格納
    //(計算内容は1!に2をかけたら2!になるようなもの)
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    //.inv()でn!の逆元だけをを計算(O(1))(これがifactの初期化)
    //逆元はフェルマーの小定理である数のxmodp(p:素数)の逆元が
    //x'=x^(p-2)となることを利用してACLmodint上で計算している
    ifact[n] = fact[n].inv();
    //(1/n!)にnをかけたら(n-1)!の逆元になることを利用して
    //最初のn!の逆元から乗数を-1しながらかけることを繰り返すことで0!~n!までの逆元を求める
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  //nCk(mod10^9+7)を計算するメンバ関数(演算子()をオーバーロードして関数みたいにしている)
  //コンストラクタで処理した後にc(n,k)と呼び出すと(cは自分でつけた名前(可変))
  //nCkmod10^9+7を返す
  mint operator()(int n, int k) {
    //組み合わせ計算における計算できないエラー入力を防ぐ
    if (k < 0 || k > n) return 0;
    //組み合わせの計算はnCk=nPk/k!=n!/k!*(n-k)!
    //一番右の式の除算部分をk!の逆元と(n-k)!の逆元にして全てかけて返す
    return fact[n]*ifact[k]*ifact[n-k];
  }
}; 
