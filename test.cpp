#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

const int maxn = 1050;
ll graph[maxn + 1][maxn + 1];
vector<int> e[maxn + 1];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i <= n; i++) {
		e[i].clear();
	}
}

void addEdge(int a, int b, ll w) {
	e[a].push_back(b);
	e[b].push_back(a);
	graph[a][b] += w;
}

bool bfs(vector<int>& p, vector<ll>& a, int n, int s, int t) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = 0;
	}
	queue<int> q;
	q.push(s);
	a[s] = LLONG_MAX;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < e[x].size(); i++) {
			int y = e[x][i];
			ll temp = graph[x][y];
			if (!a[y] && temp > 0) {
				p[y] = x;
				a[y] = min(a[x], temp);
				q.push(y);
			}
		}
		if (a[t]) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s;
	int t;

	int k, p;
	while (cin >> k >> p) {

		if (k == 0 && p == 0) break;



		s = 0;
		t = k + p + 1;

		init(t);

		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			int in;
			cin >> in;
			sum += in;
			addEdge(p + i, t, in);
		}

		for (int i = 1; i <= p; i++) {
			addEdge(s, i, 1);
			int c;
			cin >> c;
			while (c--) {
				int in;
				cin >> in;
				addEdge(i, p + in, 1);
			}
		}

		vector<int> pa(k + p + 2);
		vector<ll> a(k + p + 2, 0);

		ll ans = 0;

		while (bfs(pa, a, t, s, t)) {
			for (int u = t; u != s; u = pa[u]) {
				graph[pa[u]][u] -= a[t];
				graph[u][pa[u]] += a[t];
			}
			ans += a[t];
		}

		(sum == ans) ? cout << 1 << endl : cout << 0 << endl;
	}
	return 0;
}
