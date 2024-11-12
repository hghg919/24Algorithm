#include <iostream>
#include "timeChecker.h"
#include "Sort.h"
#include "InputReference.h"
#include "Pow.h"
#include "DivideAndConquer.h"
#include "DynamicProgramming.h"
#include "BackTracking.h"
#include "array2D.h"
#include "graph.h"
#include "MST.h"
#include "AStar.h"
#include "Regular Expression.h"

int main()
{
	std::cout << "Hello World!" << std::endl;

	BubbleExample();
	SelectionExample();
	InsertSortExample();
	CountSort();
	InputExample();

	std::cout << std::endl;
	std::cout << "a�� ������ ���ϱ� :" << " ";
	std::cout <<Pow(3, 5);

	std::cout << "���� ���� " << std::endl;
	
	int list[8] = {7, 6, 5, 8, 3, 5, 9 , 1 };

	MergeSort(list, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		std::cout << list[i] << " ";
	}

	std::cout << "�� ����" << std::endl;

	srand(time(0));

	std::vector<int> someVec = { 10, 5 , 8, 2, 7 , 4 };

	//std::cout << QuickSelect(someVec, 2);

	QuickSort(someVec, 0, someVec.size() - 1);

	for (int num : someVec)
	{
		std::cout << num << " ";
	}

	system("cls");

	std::cout << "��� ��� : �Ǻ���ġ ����" << std::endl;

	int count = 10;

	std::cout << "�Ǻ���ġ �� ���:" << Fibonacci(count) << std::endl;
	std::cout << "�Ǻ���ġ �� �ð�:" << measureExecutionTime(Fibonacci, count) << "ms" << std::endl;

	std::cout << "���� ��ȹ�� ��� : �Ǻ���ġ ����" << std::endl;

	std::cout << "�Ǻ���ġ �� ���:" << Fibonacci_DP(count) << std::endl;
	std::cout << "�Ǻ���ġ �� �ð�:" << measureExecutionTime(Fibonacci_DP, count) << "ms" << std::endl;


	std::cout << "��� ������ ���� (�޸������̼�)" << std::endl;

	std::vector<int> stairs = { 10, 20, 15 , 25, 10 ,20 , 80 };

	std::cout << "����� ���� (" << stairs.size() << ")�� �ִ� �� : " << StairCount(stairs) << std::endl;

	std::cout << "����" << endl;
	Permutation::Case01();
	std::cout << "����" << endl;
	Combine::Case02();

	system("cls");
	//Board::Case1();
	//Board::Case2();
	//Board::Case3();
	//GraphVec::Print();
	//InputGraph::Show();
	InputWeight::Show();
	InputWeight::Show2();
	InputGraph::Show001();

	system("cls");
	FoundPath::GetBoard();
	Express();
}