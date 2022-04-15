void prime(int x,vector<bool> &prime){
  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2; i * i <= x + 1; ++i){
    if(prime[i]){
      for(int j = 2; i * j <= x + 1; ++j){
        prime[i * j] = 0;
      }
    }
  }
  return;
}
//vector<bool> primes(x,1);
//prime(x,primes);
