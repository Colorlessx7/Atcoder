/*vector<bool> primes;
vector<ll> d;
const ll M = 1e6;*/
void prime(){
  primes[0] = primes[1] = 0;
  for(ll i = 2; i <= M; ++i){
    if(!primes[i]){
      continue;
    }
    d.push_back(i);
    for(ll j = i*i; j <= M; j += i){
      primes[i * j] = 0;
    }
  }
  return;
}
