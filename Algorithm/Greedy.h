#pragma once

#include <iostream>

// �Ž����� ����
// n���� 5���� 2������ �Ž����ִµ�,
// 5������ �Ž����� ��, ���� ���� 2������ �Ž����ְ�, ���࿡ �ܵ��� ������ -1, �ܵ��� �� �� ����Ѵ�.

int CountRemainCoin(int n)
{
	// �Ž����� ������ ������ ������ִ� �Լ�
	int money = n;

	// 5���� �ִ밡 �ƴ� ��쿡�� ������ false;
	// 13�� ���̽� return ���ֱ� ���ؼ�, 5�� ¥���� �������� �Ž��� �� �� �ִ� ���̽��� �˻�.

	for (int i = 0; i * 5 <= n; i++)
	{
		int remain = n - i * 5;

		if (remain % 2 == 0)
		{
			int totalCoins = i + remain / 2;
			money = std::min(money, totalCoins);
		}
	}

	return money == n ? -1 : money;


	// 13�� �� �� �� ���̽��� ����� �� ����.
	//int coin5 = money / 5;
	//int remain = money % 5;
	//
	//int coin2 = remain / 2;
	//
	//if (coin2 % 2 != 0)
	//{
	//	return -1;
	//}
	//else
	//{
	//	return coin5 + coin2;
	//}
}


// ���� ��ȣ  14916 �Ž����� ����
void Case001()
{
	int n;
	std::cin >> n;



}

// ���� ��ȣ 
void Case002()
{

}

// ���� ��ȣ 11399 ATM ����
void Case003()
{

}