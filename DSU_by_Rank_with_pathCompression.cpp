class dsu {
public:
	vector<ll> par;
	vector<ll> rank;
	ll noOfComponets;
	dsu(ll n) {
		par.resize(n);
		rank.resize(n);
		for (ll i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 1;
		}
		noOfComponets = n;
	}
	ll getSuperParent(ll x) {
		if (par[x] == x) return x;
		return par[x] = getSuperParent(par[x]);
	}
	void unite(ll x, ll y) {
		ll superParx = getSuperParent(x);
		ll superPary = getSuperParent(y);
		if (superPary == superParx) return;
		if (rank[superParx] < rank[superPary]) {
			par[superParx] = superPary;
		}
		else if (rank[superParx] > rank[superPary]) {
			par[superPary] = superParx;
		}
		else {
			par[superParx] = superPary;
			rank[superPary]++;
		}
		noOfComponets--;
	}
};
