#pragma once
#include <iostream>

// 20개의 카드가 뒤집어져있습니다.
// 카드를 모두 앞면으로 뒤집는 경우를 구하고 있습니다.
// 단, 이미 앞면인 카드는 다시 뒤집을 수 없습니다.(중복 선택이 불가능합니다.)
// 가장 많은 횟수로 모든 카드를 앞면으로 돌리는 수를 몇번인가요?

void Case001(int n)
{
	// 1 ~ n 까지의 합을 구하는 문제였습니다.
	std::cout << n(n + 1) / 2;
}