//Program.cpp
//Problem Statement - 

#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Author: Varun Goyal (@govarun)

#define f(i, n) for(int i=0;i<(n);++i)
#define fa(i, a, n) for(int i=(a);i<=(n);++i)
#define fd(i, a, n) for(int i=(a);i>=(n);--i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define ull unsigned long long
#define debug cerr
#define d0(x) debug <<#x<<" = "<<x<<' '
#define d1(x) debug <<"> "<<#x<<" = "<<x<<'\n'
#define d2(x, y) debug <<"> "<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<'\n'
#define d3(x, y, z) debug <<"> "<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<' '<<#z<<" = "<<z<<'\n'
#define endl '\n'
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< pair<int, int> > vpii;
inline bool EQ(double a, double b) { 
return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n, m;
// vector <int> adj[maxn];
// bool vis[maxn];
// int depth[maxn];
// int p[maxn];
// queue <int> q;

void pre(){

    
}


void solve();

int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int TC = 1;
    // cin >> TC;
    while(TC--){    
        solve();
    }

    return 0;
}

int getIndex(int x, int y) {
	return y * m + x;
	// i is y and j is x
}

bool isValid(int x, int y) {
	if (x >= 0 && y >= 0 && x < m && y < n) {
		return true;
	}
	return false;
}

void dfs(vpii & v1, int x, int y, char a[], bool vis[]) {
	vis[getIndex(x, y)] = 1;

	if(isValid(x - 1, y) && !vis[getIndex(x - 1, y)] && a[getIndex(x - 1, y)] == '.') {
		v1.pb({x - 1, y});
		dfs(v1, x - 1, y, a, vis);
	}

	if(isValid(x + 1, y) && !vis[getIndex(x + 1, y)] && a[getIndex(x + 1, y)] == '.') {
		v1.pb({x + 1, y});
		dfs(v1, x + 1, y, a, vis);
	}

	if(isValid(x, y - 1) && !vis[getIndex(x, y - 1)] && a[getIndex(x, y - 1)] == '.') {
		v1.pb({x, y - 1});
		dfs(v1, x, y - 1, a, vis);
	}

	if(isValid(x, y + 1) && !vis[getIndex(x, y + 1)] && a[getIndex(x, y + 1)] == '.') {
		v1.pb({x, y + 1});
		dfs(v1, x, y + 1, a, vis);
	}

}

void solve(){
	int k; cin >> n >> m >> k;
	vpii v1;
	char a[n * m];
	bool vis[n * m]; fill(vis);
	pii root;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[m * i + j];
			if (a[m * i + j] == '.') {
				root.ff = j;
				root.ss = i;
			}
		}

	}

	v1.pb({root.ff, root.ss});

	dfs(v1, root.ff, root.ss, a, vis);

	for (int i = 0; i < k; ++i) {
		int ind = v1.size() - i;
		a[getIndex(v1[ind].ff, v1[ind].ss)] = 'X';
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[m * i + j];
		}
		cout << endl;

	}
   
}
