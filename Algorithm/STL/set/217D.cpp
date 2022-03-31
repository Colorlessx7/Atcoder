#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    ll l, q;
    cin >> l >> q;
    //木材の両端と切断位置を格納するset
    set<int> s;
    //木材の最初の状態の左端と右端をsetに格納
    s.insert(0);
    s.insert(l);
    rep(i,q){
        ll c, x;
        cin >> c >> x;
        if(c == 1){
            //切断位置をsetに格納
            s.insert(x);
        }
        if(c == 2){
            //itr:x以上の値が現れる最初の位置のイテレータを取得
            auto itr = s.lower_bound(x);
            //x以上の値が現れる最初の位置が木材の右端となる
            //*を使うことでイテレータが示す場所の値を代入できるようにする
            int right = *itr;
            //イテレータを左に一つ移動する
            --itr;
            //x以下の値が現れる最初の位置が木材の左端となる
            int left = *itr;
            //木材の右端の長さから左端の長さを引いたものが木材の長さとなる
            int ans = right - left;
            cout << ans << endl;
        }
    }
    return 0;
}
//xを含む木材の左端と右端を素早く求める方法として平衡二分探索木がある
//c++ではsetが平衡二分探索木でできているためsetを活用する
//
