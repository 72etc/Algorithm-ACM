#include<iostream>
#include<vector>     //std::vector
#include <algorithm> //std::count
using namespace std;

const int N = 100;
int dimes[] = { 1, 2, 5, 10 };
int arr[N + 1] = { 1 };
vector<int> vv;

int coinExchangeRecursion(int n, int m) //�ݹ鷽ʽʵ�֣��������
{
	if (n == 0) {
		int i;
		for (i = 0; i < sizeof(dimes) / sizeof(int); i++) {
			int cnt = count(vv.begin(), vv.end(), dimes[i]);
			cout << dimes[i] << ": " << cnt << "\t";
		}
		cout << endl;
		return 1;
	}   //�����ݹ������
	if (n < 0 || m == 0)
		return 0;
	vv.push_back(dimes[m - 1]);
	int yes = coinExchangeRecursion(n - dimes[m - 1], m);
	vv.pop_back();
	int no = coinExchangeRecursion(n, m - 1);
	return (no + yes);
	//��Ϊ������������û�л���ǰӲ�ң���ô�Ƕ��٣����ϣ�������˵�ǰӲ�ң���ֵ���٣���ʱ���Ƕ����ֶһ�������
}

int coinExchange(int n)   //�ǵݹ�ʵ��
{
	int i, j;
	for (i = 0; i < sizeof(dimes) / sizeof(int); i++)   //i��0 ~ 3     ��Ϊÿ��arr[j]��Ҫ��һ���Ǽ���һ���dimes[i]����������Ҫ����һ��
	{
		for (j = dimes[i]; j <= n; j++)
			//��arr[j]��ʱ�򣬿��Կ���arr[j] = arr[j] + arr[j-dimes[i]]��
			//��Ӧ������ĵݹ鷽ʽ��arr[j]���� coinExchangeRecursion(n, m-1)��
			//arr[j-dimes[i]]����coinExchangeRecursion(n-dimes[m-1], m)
			arr[j] += arr[j - dimes[i]];
	}
	return arr[n];
}

int main(int argc, char *argv[])
{
	int num = coinExchangeRecursion(N, 4);
	cout << num << endl;

	int num2 = coinExchange(N);
	cout << num2 << endl;

	return 0;
}