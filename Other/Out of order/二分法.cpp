#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
int n,num[50000],x;
bool flag = false;
bool cmp(int a,int b){
	return a < b; //��С������� 
}
int main()
{
	do{
		if(flag)
			printf("��Ǹ����������ݹ��࣬���������룡\n");
		scanf("���������ݸ���: %d\n",&n);
		flag = true;
	}while(n>50000);
	for(int i=0 ; i<n ; i++)
		scanf("%d",&num[i]);
	sort(num , num+n , cmp);
	printf("������ҪѰ�ҵ�����: %d\n",x);
	int left = 0,right = n-1,bck = -1;
	while(left != right){
		int mid = (left + right) / 2;
		if(num[mid] < y)
			left = mid + 1;
		else if(num[mid] > y)
			right = mid - 1;
		else{
			bck = mid;
			break;
		}
	}
	if(bck == -1)
		printf("��Ǹ���ṩ������û���ҵ���\n");
	else
		printf("�ṩ�������������%dλ��\n",bck+1);
	return 0;
}
