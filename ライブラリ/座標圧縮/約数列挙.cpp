void divisor(ll n, vector<ll>& div) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) div.push_back(n / i);
        }
    }
    sort(all(div));
    return;
}
