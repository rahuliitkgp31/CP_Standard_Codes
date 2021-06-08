#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool valid(ll num, ll i, ll j, vector<vector<ll> >& v) {
    //checking row
    for (ll row = 0; row < v.size(); row++) {
        if (v[row][j] == num) return false;
    }
    //checking col
    for (ll col = 0; col < v[0].size(); col++) {
        if (v[i][col] == num) return false;
    }
    ll px = (i / 3) * 3;
    ll py = (j / 3) * 3;
    for (ll row = px; row < px + 3; row++) {
        for (ll col = py; col < py + 3; col++) {
            if (v[row][col] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<ll> >& v, ll i, ll j) {
    if (i >= v.size()) {
        for (ll ii = 0; ii < v.size(); ii++) {
            for (ll jj = 0; jj < v[0].size(); jj++) {
                cout << v[ii][jj] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    if (j >= v[0].size()) {
        return solveSudoku(v, i + 1, 0);
    }
    if (v[i][j] != 0) return solveSudoku(v, i, j + 1);
    for (ll num = 1; num <= 9; num++) {
        if (valid(num, i, j, v)) {
            v[i][j] = num;
            bool x = solveSudoku(v, i, j + 1);
            if (x) {
                return true;
            }
        }
    }
    v[i][j] = 0;
    return false;
}

int main() {
    vector<vector<ll> > v({{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    });
    solveSudoku(v, 0, 0);
    return 0;
}