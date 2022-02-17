/*compress関数 
引数 処理したい配列1
入力例 8,100,33,33,33,12,6,1211
出力例 1,4,3,3,3,2,0,5
(0~配列サイズ-1以下で出力される 数字の被りあり 被りがあっても次の数列が飛ばされることはない)

参考:https://drken1215.hatenablog.com/entry/2021/08/09/235400

処理説明*/

vector<int> compress(vector<int> a){
    //事前準備 座標圧縮したい配列のコピーの用意
	vector<int> b = a;
	//座標圧縮処理の回数を格納 これは座標圧縮したい配列のサイズと一致
    int n = a.size();
	//昇順にsort
    sort(b.begin(),b.end());
	//重複要素の消去
    b.erase(unique(b.begin(),b.end()),b.end());
	//座標圧縮した結果を格納する配列の用意
    vector<int> ret(n);
	//二分探索法でa[i]が何番目に小さいかを判定しそれを格納
	//lower_boundで判定用のb配列のa[i]以上の要素が現れる最初の位置のイテレータが得られる
	//それを判定用のb配列の最初のイテレータで引くとa[i]がbの中で何番目かが得られる
	//0からになっているので1からにしたい場合は+1する
	rep(i,n){
		ret[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
	}
	//結果を返す
    return ret;
}
