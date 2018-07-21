#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int father[200050];
int sum[200050];
int N,M;
struct len{
	int st,ed,dis;
}res;
void init(){
	for(int i=0 ; i<=N ; i++)
		father[i] = i;
	memset(sum,0,sizeof sum);
}
int findFather(int x){
	if(x != father[x]){
		int temp = findFather(father[x]);
		sum[x] += sum[father[x]];
	/*
		1����> 2����> 3����> 4 
		sum[2] = sum[2] + sum[1];
		sum[3] = sum[3] + sum[2];
		sum[4] = sum[4] + sum[3];
		����ڵ� S, a�ĸ��ڵ� b 
		���� aS = ab + bS (aS��ʾa��S����)
	*/
		father[x] = temp;	
	}
	return father[x];
}
int main()
{
	while(scanf("%d%d",&N,&M) != EOF){
		init();
		int ans = 0;
		for(int i=1 ; i<=M ; i++){
			scanf("%d%d%d",&res.st,&res.ed,&res.dis);
			res.st --;
	//	��Ҫ!
			int findst = findFather(res.st);
			int finded = findFather(res.ed);
			if(findst != finded){
				father[findst] = finded;
				sum[findst] = -sum[res.st] + res.dis + sum[res.ed];
	/*
		��a,b�ĸ��ڵ�ֱ�ΪA,B (a<b)
		���� AB = Aa + ab + bB = -aA + ab + bB
	*/
			}
			else if(abs(sum[res.st] - sum[res.ed]) != res.dis)
				ans ++;
		}
		printf("%d\n",ans);
	}
    return 0;  
}
