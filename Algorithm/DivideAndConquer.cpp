#include "DivideAndConquer.h"
#include <iostream>
#include <vector>



// ����
void MergeSort(int list[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(list, left, mid); // ���� ���� 
		MergeSort(list, mid + 1, right); // ������ ����
		Merge(list, left, mid, right);// merge
	}
}

// ������ ����
void Merge(int list[], int left, int mid, int right)
{
	int leftidx = left;
	int rightidx = mid + 1;

	std::vector<int> sorted;

	// ���� ��Ʈ�� ������ ��Ʈ�� ���ؼ� ���� �� ���� ���ĵ� ������ ������ �Ѵ�.
	while (leftidx <= mid && rightidx <= right)
	{
	    // ���Ͽ��� ������ ���� ��쿡 sorted ���� index �����Ѵ�.
	    // ���࿡ ���� �ߺ��� �Ǹ� ���� �ε����� ����Ѵ�.
		if (list[leftidx] <= list[rightidx])
		{
			sorted.push_back(list[leftidx]);
			//sorted[key] = list[leftidx];
			leftidx++;
		}
		else if (list[leftidx] > list[rightidx])
		{
			sorted.push_back(list[rightidx]);
			rightidx++;
			//sorted[key] = list[rightidx];
		}
	}

	// ���� �����Ͱ� �ִٸ� ������ش�.

	if (rightidx >= left)
	{
		for (int i = leftidx; i <= mid; i++)
		{
			sorted.push_back(list[i]);
		}
	}
	else
	{
		for (int i = rightidx; i <= right; i++)
		{
			sorted.push_back(list[i]);
		}
	}

	// ���ĵ� �����͸� list������ �������ش�. 

	for (int i = 0; i < sorted.size(); i++)
	{
		list[left + i] = sorted[i];
	}

	//while (leftidx <= mid) 
	//{
	//	sorted[key++] = list[leftidx++];	
	//}
	//
	//while (rightidx <= right)
	//{
	//	sorted[key++] = list[rightidx++];
	//}

	

}

// search Largest k'th number : k��°�� ū ���ڸ� ã�� ���

int QuickSelect(std::vector<int>& nums, int k)
{
	// ����� 1�� ��쿡�� nums[0]
	int length = nums.size();
	if (length == 1) return nums[0];

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �����̶�� ��´�.
	// �׸��� �ǹ��� �ش��ϴ� ���ڸ� ���� ���������� �ű��.
	int pivotIndex =  rand() % length;
	int lastIdx = length - 1;
	std::swap(nums[pivotIndex], nums[lastIdx]);

	// ������ �׻� �ǹ����� �۰�, �������� �׻� �ǹ����� ũ��.
	int leftIdx = 0;
	int rightIdx = lastIdx - 1; // lastIndex - 1
	int pivot = nums[lastIdx];

	while (leftIdx <= rightIdx) //���� �����ʺ��� �۰ų� ������ ��� �ݺ��ϼ���
	{
		if (nums[leftIdx] <= pivot) // �񱳸� �ؼ� �ǹ����� �۰ų� ���� �� idx ����
		{
			leftIdx++;
			continue;
		}
		if (pivot < nums[rightIdx]) // ������ ���� �ǹ����� ũ�� idx �߸��� ���� ã�� ������ ����
		{
			rightIdx--;
			continue;
		}

		std::swap(nums[leftIdx], nums[rightIdx]); // left(�ǹ� ���� ū��), right(�ǹ� ���� ���� ��) ��ȯ 
	}

	std::swap(nums[leftIdx], nums[lastIdx]); // nums leftIdx�� lastIdx�� �����ض�.

	if (leftIdx == length - k)	 // O(n) ã�´�.
	{
		return nums[leftIdx];
	}
	else if (leftIdx < length - k)	// �ǹ��� ��ġ�� ã�� ��ġ���� ���� ��� ( ������ ���� �˻��ϸ� �ȴ�.)
	{
		std::vector<int> rightPart(nums.begin() + leftIdx + 1, nums.end());
		return QuickSelect(rightPart, k);
	}
	else if(leftIdx > length - k)  // �ǹ��� ��ġ�� ã�� ��ġ���� ū ��� (���� �������� �˻��Ѵ�)
	{
		std::vector<int> leftPart(nums.begin(), nums.begin() + leftIdx);
		return QuickSelect(leftPart, k - (length - leftIdx));
	}
	

	return 0;	  // k��° �ε����� �� ���� return�ϼ���.
}

void QuickSort(std::vector<int>& nums, int begin, int end)
{
	// ����� 1�� ��쿡�� nums[0]
	int length = end - begin + 1;
	if (length <= 1)
	{
		return;
	}

	// ������ ���ڸ� �����ؼ� �� ���ڸ� �����̶�� ��´�.
	// �׸��� �ǹ��� �ش��ϴ� ���ڸ� ���� ���������� �ű��.
	int pivotIndex = (begin + end) / 2;
		//rand() % length;
	int lastIdx = length - 1;
	std::swap(nums[pivotIndex], nums[lastIdx]);

	// ������ �׻� �ǹ����� �۰�, �������� �׻� �ǹ����� ũ��.
	int leftIdx = 0;
	int rightIdx = lastIdx - 1; // lastIndex - 1
	int pivot = nums[lastIdx];

	while (leftIdx <= rightIdx) //���� �����ʺ��� �۰ų� ������ ��� �ݺ��ϼ���
	{
		if (nums[leftIdx] <= pivot) // �񱳸� �ؼ� �ǹ����� �۰ų� ���� �� idx ����
		{
			leftIdx++;
			continue;
		}
		if (pivot < nums[rightIdx]) // ������ ���� �ǹ����� ũ�� idx �߸��� ���� ã�� ������ ����
		{
			rightIdx--;
			continue;
		}

		std::swap(nums[leftIdx], nums[rightIdx]); // left(�ǹ� ���� ū��), right(�ǹ� ���� ���� ��) ��ȯ 
	}

	std::swap(nums[leftIdx], nums[lastIdx]); // nums leftIdx�� lastIdx�� �����ض�.

	// �ǹ��� ����  ��,�츦 ������. QuickSelect

	QuickSort(nums, leftIdx + 1, lastIdx);
	QuickSort(nums, begin, leftIdx - 1);


}




