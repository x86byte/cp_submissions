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
ll		ctr = 0;
size_t h_g = 5;
size_t w_g = 5;
vector<vll> g(h_g, vll(w_g));

ll
gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

ll
lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

ll
power(ll b, ll e)
{
    ll res = 1; b %= MOD;
    while (e > 0)
    {
    	if (e & 1)
    		res = (res * b) % MOD;
    	b = (b * b) % MOD; e >>= 1;
    }
    return res;
}

ll
ceil_div(ll a, ll b)
{
	return (a + b - 1) / b;
}

struct
DSU
{
    vi parent, rank;
    DSU(int n) {
        parent.resize(n + 1); rank.resize(n + 1, 0);
        iota(all(parent), 0);
    }
    int find(int i) {
        if (parent[i] == i)
        	return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
            	swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j])
            	rank[root_i]++;
        }
    }
};

void g_p(optional<vector<vll>> g = vector<vll>(h_g, vll(h_g)), size_t H = h_g, size_t W = w_g)
{
    auto gg = g.value_or(vector<vll>(H, vll(W, 0)));
    for(auto i : gg){
        for(auto d:i)
            cout << d;
        cout << endl;
    }
}

void
dfs(int u, int p, const vector<vi>& adj, vi& visited) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !visited[v]) dfs(v, u, adj, visited);
    }
}

bool
check(ll mid)
{
    return true;
}

void
solve_search(ll low, ll high) {
    ll ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
}

void
solve()
{
    int n;
    if (!(cin >> n)) return;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    ll min_sum = 0;
    int current_min = a[0];
    
    rep(i, 0, n) {
        if (a[i] < current_min) {
            current_min = a[i];
        }
        min_sum += current_min;
    }
    
    cout << min_sum << "\n";
}

int
main()
{
    fast_io;
    int t;
    if (!(cin >> t))
        return 0;
    while (t--) {
        solve();
    }
    return 0;
}
