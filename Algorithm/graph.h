#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace virus
{
	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	int n, m;      // n ��ǻ�ͼ�, m(��)�� ��
	int count = 0; // 1�� ��ǻ�Ϳ� ����� ��ǻ���� ��

	void DFS(int node) // ���� ����� ��ǻ��(Vertex, node)
	{
		for (int i = 0; graph[node].size(); i++)
		{
			int current = graph[node][i];

			if (visited[current]) continue;

			visited[current] = true;
			count++;
			DFS(current);
		}
	}

	void Example01()
	{
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;	  // ��ǻ��, ����

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// ��ǻ�� 1 ����
		visited[1] = true;		
		DFS(1);

		cout << count << '\n';
	}
}

namespace GraphVec
{
	int n, m;

	// n ������ ����,  m ������ ����

	vector<vector<int>> graph;



	void Print()
	{
		n = 6, m = 4;

		graph = vector<vector<int>>(n);

		// �Է�

		for (int i = 0; i < m; i++)  // i�� ���� ���� ��ŭ �Է°��� �޾ƿɴϴ�.
		{								   
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// ����

		for (int i = 0; i < n; i++)
		{
			sort(graph[i].begin(), graph[i].end());
		}

		

		// ���

		for (int i = 0; i < n; i++)
		{
			cout << "[" << i << "] : ";

			for (int j = 0; j < m; j++)
			{
				// graph[i].����� �����Ͱ� ���� �� ������ ����̾���.
				if (j < graph[i].size())
				{
					cout << graph[i][j] << ' ';
				}
				else
				{
					cout << "@";	    // 0 ���� ���� 1���� ����,. 
				}				
			}
			cout << '\n';
		}


	}
}

namespace InputGraph
{
   // ���ڿ� ���·� 2���� �迭�� ǥ���϶�
   // string : char �迭 [0] -> 1

	const int n = 4;
	const int m = 6;

	vector<vector<int>> graph(n, vector<int>(m, 0)); // 4x6 �迭 0 �Ҵ�

	void Show()
	{
		// cin >> n >> m;
		// �Է�
		for (int i = 0; i < n; i++)
		{
			string inputString;
			cin >> inputString;

			for (int j = 0; j < m; j++)
			{
				graph[i][j] = inputString[j] - '0';
			}
		}

		// ���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}

	}
}
