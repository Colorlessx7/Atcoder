vector<int> compress(vector<int> a){
    vector<int> b = a;
    int n = a.size();
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    vector<int> ret(n);
	rep(i,n){
		ret[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
	}
    return ret;
}
