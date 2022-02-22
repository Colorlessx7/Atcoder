//priority_queueではこのqueueにpushで格納すると自動的にqueueの中身が昇順か降順に並ぶ
//変数の定義は
//priority_queue<int,vector<int>,greater<int>> という感じで
//1:要素の型(int,double,ll等) 2:内部コンテナの型(vector<int>,vector<ll>等) 3:比較関数(昇順greater<int>,降順less<int>)という感じ
//a.push(x)	優先度付きキュー a に要素 x を追加します。
//a.pop()	a の中の最も小さい要素（設定によっては、最も大きい要素）を取り除きます。
//a.top()	a の中の最も小さい要素（設定によっては、最も大きい要素）の値を返す関数です。
//a.size()	a の要素数を返す関数です。
//a.empty()	a の要素数が 0 の場合 true、1 以上である場合 false を返す関数です。
//参考資料:https://cpprefjp.github.io/reference/queue/priority_queue.html

//ABC234Dより

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
    }
    //優先度付きqueue 小さい値が先頭に来るようにしたいので
    //要素の型:int(1つめ)内部コンテナ:vector(デフォルト)昇順:greater(デフォルトはless)
    priority_queue<int,vector<int>,greater<int>> q;
    //下準備としてi=0~k-2のk-1個分(ギリギリk番目に大きい値が発生しない範囲)
    //優先度付きqueueにpush
    rep(i,k-1){
        q.push(p[i]);
    }
    //k番目に大きい値が発生するp[i]から最後までのループ処理
    for(int i = k-1; i < n; i++){
        //優先度付きqueueにpush
        q.push(p[i]);
        //追加時にqueueのサイズがkを超えていたら
        //queueの先頭(ずれてk+1番目に大きい値になったもの)を除去する
        while(q.size() > k){
            q.pop();
        }
        //都度queueの先頭(k番目に大きい値)を出力する
        cout << q.top() << endl;
    }
    return 0;
}
//priority_queueでの解
//k個分の値を格納したpriority_queueを使う
