#include <iostream>
using namespace std;

int Partion(int Ary[], int s, int e)
{
	if (!Ary || s >= e)
	{
		return s;
	}

	int s1 = s;
	int e1 = e;
	int temp = Ary[s1];

	while (s1 < e1)
	{
		while (s1 < e1 && Ary[e1] >= temp)
		{
			e1--;
		}
		Ary[s1] = Ary[e1];

		while (s1 < e1 && Ary[s1] <= temp)
		{
			s1++;
		}
		Ary[e1] = Ary[s1];
	}

	Ary[s1] = temp;

	return s1;
}

void QSort(int Ary[], int s, int e)
{
	if (!Ary || s >= e)
	{
		return;
	}

	int mid = Partion(Ary, s, e);
	QSort(Ary, s, mid-1);
	QSort(Ary, mid + 1, e);
}

void Print(int Ary[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ",  Ary[i]);
	}

	printf("\n");
}


void MergeSort(int Ary[], int s, int e)
{
	if (!Ary || s >= e)
	{
		return;
	}

	int mid = (s + e) / 2;
	int s1 = s, e1 = mid;
	int s2 = mid+1, e2 = e;
	MergeSort(Ary, s1, e1);
	MergeSort(Ary, s2, e2);

	int count = e - s + 1;
	int *pTmpAry = new int[count];

	int k = 0;
	while (s1 <= e1 && s2 <= e2)
	{
		while (s1 <= e1 && Ary[s1] <= Ary[s2])
		{
			pTmpAry[k++] = Ary[s1++];
		}

		while (s2 <= e2 && Ary[s2] <= Ary[s1])
		{
			pTmpAry[k++] = Ary[s2++];
		}
	}

	while (s1 <= e1)
	{
		pTmpAry[k++] = Ary[s1++];
	}
	
	while (s2 <= e2)
	{
		pTmpAry[k++] = Ary[s2++];
	}

	for (int i = 0; i < count; i++)
	{
		Ary[s++] = pTmpAry[i];
	}

	delete pTmpAry;
	pTmpAry = nullptr;
}

int main()
{
	int Ary[] = {8, 10, 5, 4, 3, 12, 10, 9, 4, 56, 43, 78, 27};
	int count = sizeof(Ary) / sizeof(int);
	//QSort(Ary, 0, count-1);
	MergeSort(Ary, 0, count - 1);
	Print(Ary, count);

	system("pause");

	return 0;
}
