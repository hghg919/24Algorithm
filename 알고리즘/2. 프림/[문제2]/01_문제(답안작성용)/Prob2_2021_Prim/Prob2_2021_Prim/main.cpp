// �����˰���(Prim's algorithm)����1

#include <iostream>
using namespace std;

#define marked 		-1 		// �湮���� Ȯ��, ����Ŭ�� �������� �ʰ��ϱ����� ��
#define NODE_NUM	7 		// ���(����)�� ��
#define INF 		9999	//���Ѵ밪

//* ��
// ����ġ�� �������� ���� �� �� ������ �������ֽÿ�
// (�� // ���� 2-1) �־��� �׷����� �������� 4����� ��������� �ϼ��Ͻÿ�.(5��)
//*/

int primData[NODE_NUM][NODE_NUM] =
{
	{ 0,   67,	INF, 28,  17,  INF, 12 },
	{ 67,  0,	INF, 24,  62,  INF, INF},
	{ INF, INF, 0,   INF, 20,  37,  INF},
	{ 28,  24,  INF, 0,   INF, INF, 13 },
	{ 17,  62,  20,  INF, 0,   45,  28 },	// �� // ������ ����
	{ INF, INF, 37,  INF, 45,  0,   INF},		// �� // ������ ����
	{ 12,  INF,	INF, 13,  28,  INF, 0  }  // �� // ������ ����
}; // ���� ���

void PRIM(int n, int distance[NODE_NUM][NODE_NUM]);// �Լ��� ���� ����


int main()
{
	// �Ʒ��� �����ȣ, ���� �����Ͽ� �Է��ؾ� ��
	system("mode con cols=80 lines=30 | title KOCCA [Problem 2]");
	printf("�� [����2] ������ \n�� �����ȣ: �����ȣ ���� \n�� ��    ��: ���� ����\n");
	printf("\n��  Prim Algorithm �� \n");

	cout << "==Prim's algorithm MST(Minimum Spanning Tree)==" << endl;
	PRIM(NODE_NUM, primData);

	scanf_s("%d");
}


void PRIM(int n, int distance[NODE_NUM][NODE_NUM])
{
	int nNodeNum, nCheckPrimNode, nCheckCycleNdoe, nCntPrimNode, primNode[NODE_NUM];
	int nMinDist[NODE_NUM], nNewMin;
	int nSumWeight = 0;

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nMinDist[nNodeNum] = distance[0][nNodeNum]; 	// ������
		primNode[nNodeNum] = 0; 						//���� �ʱⰪ 0��° ����
	}

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nCntPrimNode = 1; 								// ����ī���� ���(����) 1
		nNewMin = nMinDist[1];

		for (nCheckPrimNode = 2; nCheckPrimNode < n; nCheckPrimNode++)
			if (nMinDist[nCheckPrimNode] < nNewMin) {
				//* �� // ���� 2-2) �Ʒ��� ���ÿ� �°� �ڵ带 �ۼ��Ͻÿ�. (10��)
				// ����ġ�� �������� ���� �� �� ������ ����
				// ( �� �ڵ� �߰� �ۼ��� �κ�)
				nNewMin = nMinDist[nCheckPrimNode];
				// �ش� ������带 ����������(����)�� ����
				nCntPrimNode = nCheckPrimNode;
			}
	
		cout << nCntPrimNode << " �� ����� ����ġ(edge):" << " ";
		cout << nNewMin; 								// ����ġ=�ּҺ��=�ִܰŸ�=�ּҽð�
		cout << "\n";

		nSumWeight = nSumWeight + nNewMin; 				// ����ġ �հ�

		primNode[nCntPrimNode] = marked;				//�湮�ϸ� -1�� ó��, ����Ŭ�� �������� �ʰ� �ϱ����ؼ�
		nMinDist[nCntPrimNode] = INF; 					//�ʱⰪ���� ����ġ ���Ѵ밪 9999 ����

		for (nCheckCycleNdoe = 1; nCheckCycleNdoe < n; nCheckCycleNdoe++) {
			//* �� // ���� 2-3) �Ʒ��� ���ÿ� �°� �ڵ带 �ۼ��Ͻÿ�. (5��)
			// ������ ��� �߿��� ����Ŭ�� �������� �ʰ� ����ġ �����ϵ��� �� ����� �ϼ��Ͻÿ�.
			if ((primNode[nCheckCycleNdoe] != marked) 
				&&
				(distance[nCheckCycleNdoe][nCntPrimNode] < nMinDist[nCheckCycleNdoe])
				) 
			{
				// �ּҰ����� ����ġ �����Ͻÿ�.
				// ( �� �ڵ� �߰� �ۼ��� �κ�)
				nMinDist[nCheckCycleNdoe] = distance[nCntPrimNode][nCheckCycleNdoe];
				// �ּҰ��� ���� ����ġ�� ����(���)
				primNode[nCheckCycleNdoe] = nCntPrimNode;		
			}
		}
	}
	cout << "\n ����ġ ��= " << nSumWeight;
}

