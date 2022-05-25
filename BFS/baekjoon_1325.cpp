#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include <string.h>
using namespace std;

vector<int> vec[10001];
bool check[10001];

int main()
{
	int n, m;
	cin >> n >> m;

	int from, to;
	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to;
		vec[to].push_back(from);
	}
	vector<int> ans;
	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(check, 0, 10001);
		queue<int> q;
		int cnt = 1;
		check[i] = true;
		q.push(i);

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (auto n : vec[now])
			{
				if (check[n]) continue;

				q.push(n);
				check[n] = true;
				++cnt;
			}

		}

		if (max < cnt)
		{
			ans.clear();
			max = cnt;
			ans.push_back(i);
		}
		else if (max == cnt)
			ans.push_back(i);

	}


	sort(ans.begin(), ans.end());
	for (auto n : ans)
	{
		cout << n << " ";
	}


	return 0;
}