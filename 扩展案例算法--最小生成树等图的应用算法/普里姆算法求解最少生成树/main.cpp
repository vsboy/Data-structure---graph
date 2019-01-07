#include<iostream>
typedef char DataType;
const int SeqQMaxSize=100;
#include"SeqQueue.h"
const int MaxNode=100;
typedef char VerType;
typedef int  WType;
#include"AdjList.h"
#include"AdjListGraphLib.h"
#include"Prim.h"
using namespace std;
void main()
{
	int i;
	AdjList g(0);
	char a[]={'A','B','C','D','E','F','G'};
	RowColWeight rcw[]={{0,1,50},{0,2,60},{1,3,65},{1,4,40},{2,3,52},{2,6,45},{3,4,50},{3,5,30},{3,6,42},{4,5,70}};
	int n=7,e=10;
	AdjListCreateGraph(g,a,n,rcw,e);
	int treeV[7];
	for(i=0;i<7;i++)
		 treeV[i]=-1;
	WType weight[6];
	MinWeight m;
	Prim(g,0,6,treeV,weight);
	RowColWeight treeEdge[6];
	treeEdge[0].row=treeV[0];
	treeEdge[0].col=treeV[1];
	treeEdge[0].weight=weight[0];
	for(i=1;i<6;i++)
	{
		int *p=new int[7];
		Search(treeV[i+1],weight[i],rcw,10,p);
		for(int k=0;k<=i;k++)
			if(FindRepeatV(treeV[k],p,7)==1)
			{
				treeEdge[i].row=treeV[k];
				treeEdge[i].col=treeV[i+1];
				treeEdge[i].weight=weight[i];
				break;
			}
			delete []p;
	}
	cout<<"最小生成树的边权是："<<endl;
	for(i=0;i<6;i++)
		cout<<"边("<<a[treeEdge[i].row]<<","<<a[treeEdge[i].col]<<")"<<"权值"<<treeEdge[i].weight<<endl;
	}
