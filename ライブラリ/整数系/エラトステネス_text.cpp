//エラトステネスの篩で素数かどうかを判定するための配列
vector<bool> primes;
//列挙した素数を格納する配列
vector<ll> d;
//問題の条件k=p*q^3<=nからとりうる最大の素数はq<=nの三乗根より
//10^6くらいまでとなる
const ll M = 1e6;
//エラトステネスの篩をする関数
void prime(){
  //0,1は素数ではないので0
  primes[0] = primes[1] = 0;
  //最初の素数である2から判定する最大値のMまで回す
  for(ll i = 2; i <= M; ++i){
    //primes[i]=0ならiは素数ではないのでコンティニュー
    if(!primes[i]){
      continue;
    }
    //iは素数なので素数配列dに格納
    d.push_back(i);
    //i^2から素数iの倍数[i*j]を全てfalseにする
    for(ll j = i*i; j <= M; j += i){
      //素数iの倍数は素数でないのでfalseに
      primes[i * j] = 0;
    }
  }
  return;
}
