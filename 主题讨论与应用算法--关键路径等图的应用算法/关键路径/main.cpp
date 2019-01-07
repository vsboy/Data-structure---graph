#include<iostream>
#include<iomanip>
#include"AOEgraph.h"
using namespace std;
void main()
{
	char a[11]={'A','B','C','D','E','F','G','H','I','J','K'};
	arcinfo e[15]={{0,1,3},{0,2,4},{1,3,2},{1,4,1},{2,4,3},{2,5,5},{3,6,6},{4,6,8},{4,7,4},{5,8,2},{6,10,7},{7,8,10},{7,9,4},{8,9,1},{9,10,6}};
	aoegraph mygraph(a,e,11,15);
	int early[11];
	int last[11];
	arcinfo keya[20];
	mygraph.keypath(early,last,keya);
}