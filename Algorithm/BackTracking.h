#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace Permutation
{
	// n���� �ڷᰡ �־����ϴ�.  1���� ����  n���� ���Ҹ� �̷�� �ֽ��ϴ�.
	// arr { 1, 2, 3 }
	// 2��  {1, 2} {1, 3} {2, 1} {2, 3} {3, 1} {3, 2}
	// ���� ���ڰ� �ߺ��� �ȵǰ� ������ �ϴ� ��	-

	int n = 3;
	int m = 2;
	int arr[3];
	bool visited[3];

	vector<int> vec;

	void Print()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length)
	{
		// ��� ���� ����. 
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = 0; i < n; i++)
		{
			// �̹� �湮������ �н��ض�. continue if(!visited[i]))
			if (visited[i]) continue;  // �̹� vec �����͸� �־����� ����ض�. ����ġ��.

			visited[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1);
			visited[i] = false;
			vec.pop_back();
		}
	}

	void Case01()	 // int main
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i+1;
			visited[i] = false;
		}
		BT(0);
	}
}

namespace Combine
{
	int n = 3;
	int m = 2;
	int arr[3];
	bool visited[3];

	vector<int> vec;

	void Print()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
	}

	void BT(int length, int start)
	{
		// ��� ���� ����. 
		if (length == m)
		{
			Print();
			return;
		}

		for (int i = start; i < n; i++)
		{
			// �̹� �湮������ �н��ض�. continue if(!visited[i]))
			if (visited[i]) continue;  // �̹� vec �����͸� �־����� ����ض�. ����ġ��.

			visited[i] = true;
			vec.push_back(arr[i]);
			BT(length + 1, i + 1);
			visited[i] = false;
			vec.pop_back();
		}
	}

	void Case02()	 // int main
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
			visited[i] = false;
		}
		BT(0, 0);
	}
}
