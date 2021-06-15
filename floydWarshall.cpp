#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void floydWarshall(vector<vector<ll> >& g) {
    ll n = g.size();
    vector<vector<ll> > dis(g);
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    ll flag = 0;
    for (ll i = 0; i < n; i++) {
        if (dis[i][i] < 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "Negative weight cycle is present" << endl;
    }
    else {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cout << dis[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<vector<ll> > v({ { 0, 5, INT_MAX, 10 },
        { INT_MAX, 0, 3, INT_MAX },
        { INT_MAX, INT_MAX, 0, 1 },
        { INT_MAX, INT_MAX, INT_MAX, 0 }
    });
    floydWarshall(v);
    return 0;
}