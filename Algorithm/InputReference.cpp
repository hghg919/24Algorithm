#include "InputReference.h"

#include <iostream>


void InputExample()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// �ǹ� : stdio.h - iosteram�� ����ȭ ���ش�.
	// ���� <- iostream, stdio.h

	// std::cout << "MY Name : "
	// std:: cin >>     
	// std::endl; "\n"
	// ���� �������� cin ������ (�ڵ����� ����). 0.0n��

	std::cout << "My ";
	printf("Name");


	//  std::endl;   '\n'
	// std::endl; ->   std::cout << 'n' << std::flush;   ���� ������ �����.
	// Hello World! -13char
	// buffer �ִ� max 1��
	// 769 Hello World! ��� std::flush 1�� ����
	// 769 std::endl;         std::flsuh 769�� ����  (0.01��)
	// 10�� �Է�
	// O(n) <- (n^2)
}
