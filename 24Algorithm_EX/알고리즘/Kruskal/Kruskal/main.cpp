//Prob2_Kruskal

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4819)

#define NODENUM 7
#define LINENUM 11

using namespace std;

class Edge
{
private:
	int node[2];
	int distance;
public:
	Edge(int node1, int node2, int distance_)
	{
		node[0] = node1;
		node[1] = node2;
		distance = distance_;
	}

	int first_node()
	{
		return this->node[0];
	}

	int second_node()
	{
		return this->node[1];
	}

	int showDistance()
	{
		return this->distance;
	}

	// ���� ��� ������ ������ ���� ������ ������
	bool operator < (Edge &edge)
	{
		return this->distance < edge.distance;
	}
};

// �θ� ��带 ã�ư��� �Լ�
int getParent(int arr[], int x)
{
	if (x == arr[x]) return x;

	// ���� 2-1)
	/* �� �θ� ��尡 1�� �ƴ� ��� ��� ã���� return�� �����Ͻÿ� */
	return x;
}

// �θ� ��带 ã�Ƽ� ��ġ�� �Լ�
void unionParent(int arr[], int a, int b)
{
	a = getParent(arr, a);
	b = getParent(arr, b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

// �θ� ��带 ã�Ƽ� ������ �ƴ��� �Ǵ��ϴ� �Լ�
int findParent(int arr[], int a, int b)
{
	a = getParent(arr, a);
	b = getParent(arr, b);

	// ���� 2-2) 
	/* �� �θ� ��尡 ������ ����Ŭ�̰� �ƴϸ� ����Ŭ�� �ƴ� ������ �ǵ��� return�� �����Ͻÿ� */
	return 1;
}


int main()
{
	// �Ʒ��� �����ȣ, ���� �����Ͽ� �Է��ؾ� ��
	system("mode con cols=80 lines=30 | title KOCCA [Problem 2]");

	printf("�� [����2] ������ \n�� �����ȣ: �����ȣ ���� \n�� ��    ��: ���� ����\n");
	printf("\n��  Kruskal Algrithm �� \n");

	vector<Edge> v;
	// ��� ���� �Է�, ����(ù��° ���, �ι�° ���, ���� ���)
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(5, 7, 73));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(3, 5, 20));

	// ���� ��뿡 ���� �������� ����(������ ������ �̿�)
	sort(v.begin(), v.end());

	int lines[LINENUM] = { 0 };			// ���õ� ���� ������ �Է��ϱ� ���� �迭
	int line_number = 0;				// ���õ� ���� ������ �Է��ϱ� ���� �ε��� ����
	int nodes[NODENUM + 1] = { 0 };		// ��� ����
	int sum = 0;

	for (int i = 1; i <= NODENUM; i++)	// ��� ���� nodes[]�� ����
	{
		nodes[i] = i;
	}

	for (int i = 0; i < v.size(); i++)
	{
		// continue;
		if (findParent(nodes, v[i].first_node(), v[i].second_node()) == 1)
		{
			// ����Ŭ�� �Ǵ� �������� ũ�罺Į �ߺ� ������
			printf("����Ŭ ���� ���� ���� %d - %d �Ÿ� %d\n", v[i].first_node(), v[i].second_node(), v[i].showDistance());
		}
		// ���� �� ������ ������ �ٸ� �θ� ����̸� ��, ����Ǿ� ���� ������ 
		else
		{
			// �ϴ� �θ� ��带 ��(����)���ְ� 
			// ���� 2-3)
			/* �� �� �κп� �ּ��� �´� ������ �Լ��� ����Ͽ� ���ȭ���� �������� �����Ͻÿ� */

			// Ŭ�罺Į ���� ���� �� ���
			printf("ũ�罺Į �ּҺ�� ���� %d - %d �Ÿ� %d\n", v[i].first_node(), v[i].second_node(), v[i].showDistance());

			// �Ÿ��� lines[] �迭�� �ְ� 
			lines[line_number] = v[i].showDistance();
			// lines[] �迭�� �ε��� ������ +1 ����
			line_number++;
		}
	}

	// Ŭ�罺Į ���� ���� �� ���
	for (int i = 0; i < line_number; i++)
	{
		sum += lines[i];
	}

	printf("\n�ּҺ�� ����Ʈ�� �� : %d\n", sum);

	scanf_s("%d");
}
