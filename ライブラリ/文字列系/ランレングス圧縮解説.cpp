//ランレングス圧縮関数
//s:ランレングス圧縮を行いたい文字列,res:i番目の要素のfi=文字,se=個数
void rle(const string &s, vector<P> &res){
  //全ての文字列について処理
  for(char c : s){
    //一番最初の文字でなく、かつ文字cが一つ前の文字と同じ場合に処理
    if(res.size() > 0 && res.back().first == c){
      //末尾の要素の文字が1個追加されたので末尾のsecondを+1する
      res.back().second++;
    }else {
      //一番最初の文字または、文字cが一つ前の文字と違う場合に処理
      //末尾に文字cと個数1のpairを格納
      res.emplace_back(c,1); 
    }
  }
}
//vector<P> a;
//rle(s,a);
