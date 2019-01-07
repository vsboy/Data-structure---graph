#include<iostream>
using namespace std;
#include"AdjMGraph.h"
void main()
{
	MSPath s[5]={MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5)};
	TPath  t[5]={TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1)};
	char a[5]={'A','B','C','D','E'};
	int  weight[25]={10000,50,10,10000,45,10000,10000,15,10000,10,20,10000,10000,15,10000,10000,20,10000,10000,35,10000,10000,10000,30,10000};
	int w[5]={10000,10000,10000,10000,10000};
	AdjMGraph mygraph(weight,a,5);
	mygraph.djspath(s,t,5,4,w);
	s[2].printpath();
}