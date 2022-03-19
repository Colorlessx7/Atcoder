#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    ll h, w, C, q;
    cin >> h >> w >> C >> q;
    vector<ll> t(q),n(q),c(q);
    rep(i,q){
        cin >> t[i] >> n[i] >> c[i];
    }
    //重複確認用set
    set<P> st;
    //埋まってない残りの行・列の数確認用
    ll hc = h, wc = w;
    //重複確認用の比較数字
    ll cnt = 1;
    //最終的に色iが何個あるかを格納する配列
    vector<ll> ans(C);
    //後ろからループ
    rep3(i,q){
        //重複確認用setに突っ込むためのpair作成
        P x = make_pair(t[i],n[i]);
        //setに格納
        st.insert(x);
        ll sz = st.size();
        //重複しているか確認,重複していたら比較用のcntを調整しコンティニュー
        if(cnt != sz){
            cnt = sz;
            cnt++;
            continue;
        }
        //行か列かを判定
        if(t[i] == 1){
            //行の場合埋められる横の要素の数だけその色の数を足す
            ans[c[i]-1] += wc;
            //その後横一列埋めたので縦の埋められる要素は1つ減るから-1
            hc--;
        }else if(t[i] == 2){
            //列の場合は色を行の場合と同様に足すが、足す値と
            //その後に-1する要素が逆になる
            ans[c[i]-1] += hc;
            wc--;
        }
        //次の要素を見るまでに重複確認用の数字を調整
        cnt++;
    }
    //答えを出力
    rep(i,C){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
//後ろから考える問題
//後ろの処理で埋めたものはその前の要素で上書きできないことを利用する
//重複部分を塗るのは前に塗ったほうが塗らなかった場合と同じになるので
//setで重複を判定して処理させない
//後ろから考えて1行塗るとその前までに塗れる行が1行減る
//列にも同じことが言える
//塗れる量は１行塗る場合その時点で塗れる列の数に相当する
//列には逆のことが言える
