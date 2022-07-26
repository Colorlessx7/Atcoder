// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
//座標圧縮用のライブラリ
struct CC {
  //初期化済みかどうかのbool変数(defaultは未初期化でコンストラクタでfalseになる)
  bool initialized;
  //座標圧縮配列
  vector<T> xs;
  //コンストラクタ
  CC(): initialized(false) {}
  //引数xを座標圧縮配列xsの末尾に格納する
  void add(T x) { xs.push_back(x);}
  //座標圧縮処理初期化
  void init() {
    //昇順に並べる(後に重複削除をするため)
    sort(xs.begin(), xs.end());
    //重複削除
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    //init関数で初期化したためtrueに
    initialized = true;
  }
  //引数xが何番目かを調べる関数(昇順に0indexedで何番目かが設定される)
  int operator()(T x) {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //upper_boundで得たindex-1としておくとxsに登録されていない値でも辻褄が合いやすい
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  //xs配列のi(:index)番目の値を返す関数
  T operator[](int i) {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //xsのi番目の値を返す
    return xs[i];
  }
  //座標圧縮配列のサイズを答える関数
  int size() {
    //座標圧縮初期化をしていないなら行う
    if (!initialized) init();
    //座標圧縮配列xsのサイズを答える
    return xs.size();
  }
};
