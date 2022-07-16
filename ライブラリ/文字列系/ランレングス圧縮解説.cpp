//文字列sからfi=文字,se=個数の配列を返す
void rle(const string &s, vector<P> &res){
  for(char c : s){
    if(res.size() > 0 && res.back().first == c){
      res.back().second++;
    }else {
      res.emplace_back(c,1); 
    }
  }
}
//vector<P> a;
//rle(s,a);
