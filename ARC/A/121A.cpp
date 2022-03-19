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
using P = pair<int,int>;
bool compare1(tuple<ll,ll,int> a, tuple<ll,ll,int> b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) < get<1>(b);
    }else {
        return true;
    }
}
bool compare2(tuple<ll,ll,int> a, tuple<ll,ll,int> b){
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) < get<1>(b);
    }
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }else {
        return true;
    }
}
int main(){
    int n;
    cin >> n;
    vector<tuple<ll,ll,int>> xy(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        xy[i] = make_tuple(x,y,i);
    }
    set<int> st;
    vector<pair<ll,ll>> ch(8);
    ll x2, y2, i2;
    int sz = 1;
    int cnt = 0;
    sort(all(xy),compare1);
    rep(i,n){
        if(st.size() >= n||st.size() > 1){
            break;
        }
        x2 = get<0>(xy[i]);
        y2 = get<1>(xy[i]);
        i2 = get<2>(xy[i]);
        st.insert(i2);
        if(sz == st.size()){
            sz++;
            ch[cnt] = make_pair(x2,y2);
            cnt++;
        }
    }
    rep3(i,n){
        if(st.size() >= n||st.size() > 3){
            break;
        }
        x2 = get<0>(xy[i]);
        y2 = get<1>(xy[i]);
        i2 = get<2>(xy[i]);
        st.insert(i2);
        if(sz == st.size()){
            sz++;
            ch[cnt] = make_pair(x2,y2);
            cnt++;
        }
    }
    sort(all(xy),compare2);
    rep(i,n){
        if(st.size() >= n||st.size() > 5){
            break;
        }
        x2 = get<0>(xy[i]);
        y2 = get<1>(xy[i]);
        i2 = get<2>(xy[i]);
        st.insert(i2);
        if(sz == st.size()){
            sz++;
            ch[cnt] = make_pair(x2,y2);
            cnt++;
        }
    }
    rep3(i,n){
        if(st.size() >= n||st.size() > 7){
            break;
        }
        x2 = get<0>(xy[i]);
        y2 = get<1>(xy[i]);
        i2 = get<2>(xy[i]);
        st.insert(i2);
        if(sz == st.size()){
            sz++;
            ch[cnt] = make_pair(x2,y2);
            cnt++;
        }
    }
    vector<ll> ans;
    n = st.size();
    rep(i,n){
        rep(j,i){
            ll f = max(abs(ch[j].first-ch[i].first),abs(ch[j].second-ch[i].second));
            ans.push_back(f);
        }
    }
    sort(allr(ans));
    cout << ans[1] << endl;
    return 0;
}
//解説を見たが自分の発想とほぼ同じで実動してAC
