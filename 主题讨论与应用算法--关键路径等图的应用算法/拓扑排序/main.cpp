#include<iostream>
#include<iomanip>
#include"AOVgraph.h"
using namespace std;
void main()
{
	int i;
	char a[9]={'A','B','C','D','E','F','G','H','I'};
	edge e[11]={{0,2},{0,7},{1,2},{1,3},{1,4},{2,3},{3,5},{3,6},{4,5},{7,8},{8,6}};
	tp degree[9];
	char tporder[9];
	for(i=0;i<9;i++)
	{
		degree[i].degree=0;
		degree[i].sortflag=0;
	}
	aovgraph mygraph(a,e,9,11);
	mygraph.tpsort(degree,tporder);
	cout<<"该AOV图的一个拓扑序列为："<<endl;
	for(i=0;i<8;i++)
		cout<<setw(2)<<tporder[i]<<"--->";
	cout<<tporder[i]<<endl;
}