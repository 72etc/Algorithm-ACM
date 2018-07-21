/**
* BFPRT�㷨��ǰKС�����⣩
*
* author    ���㣨Limer��
* date      2017-01-25
* mode      C++
*/

#include<iostream>
#include<algorithm>
using namespace std;

int InsertSort(int  array[], int left, int right);                 //�������򣬷�����λ���±�
int GetPivotIndex(int  array[], int left, int right);              //������λ������λ���±�
int Partition(int array[], int left, int right, int pivot_index);  //������λ������λ�����±���л��֣����طֽ����±�
int BFPRT(int array[], int left, int right, const int & k);        //���kС��������λ�õ��±�

int main()
{
	int k = 5;
	int array[] = { 80,5,7,2,4,21,24,5,62,70,11,45,77,22 };
	int len = sizeof(array) / sizeof(int);
	cout << "ԭ���飺";
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
	cout << endl;

	cout << "��" << k << "СֵΪ��" << array[BFPRT(array, 0, len - 1, k)] << endl;

	cout << "�任������飺";
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}

/* �������򣬷�����λ���±� */
int InsertSort(int array[], int left, int right)
{
	int temp;
	int j;
	for (int i = left + 1; i <= right; i++)
	{
		temp = array[i];
		j = i - 1;
		while (j >= left && array[j] > temp)
			array[j + 1] = array[j--];
		array[j + 1] = temp;
	}

	return ((right - left) >> 1) + left;
}

/* ������λ������λ���±� */
int GetPivotIndex(int array[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(array, left, right);

	int sub_right = left - 1;
	for (int i = left; i + 4 <= right; i += 5)
	{
		int index = InsertSort(array, i, i + 4);  //�ҵ����Ԫ�ص���λ�����±�
		swap(array[++sub_right], array[index]);   //���η������
	}

	return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

/* ������λ������λ�����±���л��֣����طֽ����±� */
int Partition(int array[], int left, int right, int pivot_index)
{
	swap(array[pivot_index], array[right]);  //�ѻ�׼������ĩβ

	int divide_index = left;  //���ٻ��ֵķֽ���
	for (int i = left; i < right; i++)
	{
		if (array[i] < array[right])
			swap(array[divide_index++], array[i]);  //�Ȼ�׼С�Ķ��������
	}

	swap(array[divide_index], array[right]);  //���ѻ�׼������
	return divide_index;
}

int BFPRT(int array[], int left, int right, const int & k)
{
	int pivot_index = GetPivotIndex(array, left, right);            //�õ���λ������λ���±�
	int divide_index = Partition(array, left, right, pivot_index);  //���л��֣����ػ��ֱ߽�
	int num = divide_index - left + 1;
	if (num == k)
		return divide_index;
	else if (num > k)
		return BFPRT(array, left, divide_index - 1, k);
	else
		return BFPRT(array, divide_index + 1, right, k - num);
}