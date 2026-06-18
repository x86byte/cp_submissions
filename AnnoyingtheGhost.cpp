#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <optional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef long double ld;
using   psi = pair<string, int>;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<psi> vpsi;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pref(r) for(auto i : r) cout << i;
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

const int	MOD = 1e9 + 7;
const ll	INF = 1e18;
const		ld PI = acos(-1.0);






void
solve()
{
    int n;
    if (!(cin >> n)) return;
    vll a(n), b(n);
    rep(i, 0, n)
    	cin >> a[i];
    rep(i, 0, n)
    	cin >> b[i];

    vll a_sorted = a;
    sort(all(a_sorted));
    rep(i, 0, n) {
        if (a_sorted[i] > b[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    vi c(n);
    rep(k, 0, n) {
        int count_a = upper_bound(all(a_sorted), b[k]) - a_sorted.begin();
        c[k] = count_a - (k + 1);
    }

    vi p(n);
    vector<bool> used(n, false);
    rep(i, 0, n) {
        int Li = lower_bound(all(b), a[i]) - b.begin();
        int K = n - 1;
        rep(k, Li, n)
            if (c[k] == 0) {
                K = k;
                break;
            }

        int target_j = -1;
        rep(s, Li, K + 1) {
            if (!used[s]) {
                target_j = s;
                break;
            }
        }

        p[i] = target_j;
        used[target_j] = true;
        rep(k, Li, target_j)
            c[k]--;
    }

    ll inv = 0;
    rep(i, 0, n) {
        rep(k, i + 1, n)
            if (p[i] > p[k])
            	inv++;
    }
    cout << inv << "\n";
}

int
main()
{
    fast_io;
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
