#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
#include <optional>
#include <algorithm>
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

#define COUT(x) cout << x << "\n";




void
solve()
{
    int n;
    if (!(cin >> n))
    	return;
    string s;
    cin >> s;

    vll counts(3, 0);
    counts[0] = 1;
    int current_p = 0;
    rep(i, 0, n) {
        int val = (s[i] == '0' ? 1 : 2);
        current_p = (current_p + val) % 3;
        counts[current_p]++;
    }

    ll total = counts[0] * counts[1] + counts[0] * counts[2] + counts[1] * counts[2];

    ll subtract = 0;
    int current_L = 1;
    rep(i, 1, n) {
        if (s[i] != s[i - 1])
            current_L++;
        else {
            if (current_L >= 3)
                if (current_L % 2 == 0)
                    subtract += (ll)current_L * (current_L - 2) / 4;
                else {
                    ll m = (current_L - 1) / 2;
                    subtract += m * m;
                }
            current_L = 1;
        }
    }
    if (current_L >= 3)
        if (current_L % 2 == 0)
            subtract += (ll)current_L * (current_L - 2) / 4;
        else {
            ll m = (current_L - 1) / 2;
            subtract += m * m;
        }

    COUT(total - subtract)
}

int
main()
{
    fast_io;

    int t;
    if (!(cin >> t))
    	return 0;
    while (t--)
        solve();
    return 0;
}
