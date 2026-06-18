#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void
solve()
{
    int n;
    if (!(cin >> n))
    	return;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 0)
    	return;

    ll current_snowball = a[0];
    ll max_pile = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < current_snowball)
            current_snowball += a[i];
        else
            current_snowball = a[i];
        max_pile = max(max_pile, current_snowball);
    }

    cout << max_pile << "\n";
}

int
main()
{
    fast_io;
    int t;
    if (!(cin >> t)) return 0;
    while (t--)
        solve();
    return 0;
}
