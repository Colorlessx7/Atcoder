//エラトステネスの篩で素数判定をしたり
//素因数分解をしたりすることができる構造体

//コンストラクタ呼び出し Sieve 構造体変数名(n) //n:エラトステネスの篩をしたい範囲(配列なので10^7くらいが限界？)
//素数判定 isPrime(n) //nが素数か判定 素数ならtrue,そうでないならfalse(n:int)
//素因数分解した後の整数リスト入手 vector<int> a = factorList(n) //n=60ならaに2,2,3,5が格納されて帰ってくる(n:int)
//素因数部、指数部のpairリスト入手(int) vector<P> a = factor(n) //n=60なら(2,2),(3,1),(5,1)が格納されて帰ってくる(n:int)
//素因数部、指数部のpairリスト入手(ll) vector<pair<ll,int>> a = factor(n) //n=60なら(2,2),(3,1),(5,1)が格納されて帰ってくる(n:ll)

//参考:https://www.youtube.com/watch?v=-fTsuyin-a8
//https://github.com/atcoder/live_library/blob/master/prime.cpp

struct Sieve {
  //エラトステネスの篩を行う範囲0~n
  int n;
  //f:1を除く最小の因数が格納(0,1は例外処理で-1、素数は素数が格納
  //15などの合成数は最小の素因数(この場合は3*5なので3)が格納)
  //primes:素数列挙用
  vector<int> f, primes;
  //構造体Sieveのコンストラクタ(コンストラクタ処理時にエラトステネスの篩が行われる)
  Sieve(int n=1):n(n), f(n+1) {
    //isPrimeで0,1が素数として判定されるのを回避する
    f[0] = f[1] = -1;
    //0~nまででエラトステネスの篩を行う
    for (ll i = 2; i <= n; ++i) {
      //素数か判定し素数でないならコンティニュー
      //判定方法はf[i]に何も印が付いてない場合(初期状態の0)なら素数
      if (f[i]) continue;
      //以下は素数のみ処理
      //素数をprimesに格納
      primes.push_back(i);
      //素数なのでf[i]に最小の素因数である現在見ている素数iを格納
      f[i] = i;
      //現在見ている素数iの倍数にiを格納(boolエラトステネスでfalseにしている処理)
      //i*iだと7とかを見ている時に7*2,7*3とかの既に見た部分をスルーできるため高速化できる
      //+=iでiの倍数を順にnになるまで見ていく
      for (ll j = i*i; j <= n; j += i) {
        //素数iの倍数のまだ見ていない部分(見ている部分はより小さい素数の倍数)にiを格納する
        if (!f[j]) f[j] = i;
      }
    }
  }
  //xが素数か判定(sieveのコンストラクタで篩がなされた後f[x]にxが格納されていれば素数) 
  bool isPrime(int x) { return f[x] == x;}
  //素因数分解をしてそれを返すメンバ関数
  //例:60=2^2*3^1*5^1なので60が与えられたら2,2,3,5を格納する
  vector<int> factorList(int x) {
    vector<int> res;
    //素因数分解処理部分、xが最小の素因数で割り続けられた後1になったら終了
    while (x != 1 && x != 0) {
      //xという合成数or素数の最小の素因数f[x]をresに格納する
      res.push_back(f[x]);
      //xから最小の素因数f[x]を割る
      x /= f[x];
    }
    //素因数分解されたもの(60の場合2,2,3,5)を返す
    return res;
  }
  //素因数分解してfirstを素因数にsecondを指数にして返すメンバ関数
  //60なら2^2*3^1*5^1なので(2,2),(3,1),(5,1)を返す
  vector<P> factor(int x) {
    //素因数のリストをflに格納(60の時2,2,3,5)
    vector<int> fl = factorList(x);
    //例外処理(多分x=0,1の場合)
    if (fl.size() == 0) return {};
    //素因数分解の結果をランレングス圧縮したものを格納するpair配列(int版)
    //要素数1(素因数部:最小素因数,指数部:0)(計算結果で見ると1の状態)で初期化
    vector<P> res(1, P(fl[0], 0));
    //ランレングス圧縮処理部分
    for (int p : fl) {
      //末尾の素因数と同じものが来たら指数部を+1
      if (res.back().first == p) {
        res.back().second++;
      } else {
        //末尾の素因数と違うものが来たら(素因数部:新しい素因数,指数部:1)を追加
        res.emplace_back(p, 1);
      }
    }
    //素因数分解した素因数部と指数部のpairのリストresを返す
    return res;
  }
  //素因数分解の結果をランレングス圧縮したものを格納するpair配列(ll版)
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    //コンストラクタ上で判定された素数全てでpが元のxの素因数か判定
    for (int p : primes) {
      //素数pの指数部のカウンタ
      int y = 0;
      //xがpで割れる限りループ
      //xをpでわり、指数部を+1する処理を行う
      while (x%p == 0) x /= p, ++y;
      //上の処理終了後指数部が0でないならpが元のxの素因数なので
      //(素因数部:p,指数部:yをpush)
      if (y != 0) res.emplace_back(p,y);
    }
    //10^9+7などコンストラクタ上で制約上見れない大きい素因数とかを
    //ここで素因数のランレングス圧縮リストにpush
    if (x != 1) res.emplace_back(x,1);
    //素因数のpairリストを返す
    return res;
  }
};
