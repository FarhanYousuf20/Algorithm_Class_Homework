// Problem link : https://cses.fi/problemset/result/5132198/

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
        return (x.second < y.second);
}

void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> movie(n);
        for(int i = 0; i < n; i++) {
                cin >> movie[i].first >> movie[i].second;
        }
        sort(movie.begin(), movie.end(), cmp);

        int ans = 1, last = movie[0].second;
        for(int i = 1; i < n; i++) {
                if(movie[i].first >= last) {
                        ans++;
                        last = movie[i].second;
                }
        }

        cout << ans << endl;
}

signed main() {
        solve();
        return 0;
}
