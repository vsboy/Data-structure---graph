#include<iostream>
typedef char DataType;
const int MaxListSize=100;
const int SeqQMaxSize=100;
#include"SeqList.h"
#include"SeqQueue.h"
const int MaxVertices=100;
const int MaxWeight=100000;
typedef char VerT;
#include"AdjMatGraph.h"
#include"AdjMatGraphLib.h"
using namespace std;
void main()
{
	AdjMatGraph g;
	char a[]={'A','B','C','D','E','F','G'};
	RowColWeight rcw[]={{0,1,1},{0,2,1},{1,3,1},{1,4,1},{2,5,1},{2,6,1},
	{1,0,1},{2,0,1},{3,1,1},{4,1,1},{5,2,1},{6,2,1}};
	int n=7,e=12;//7�����㣬12����
	AdjMatCreateGraph(g,a,n,rcw,e);
	cout << "��ǰ�Ķ������Ϊ��" << g.numOfVertices() << endl;
    cout << "��ǰ�ıߵ�����Ϊ��" << g.numOfEdge() << endl;
	cout << "���������������Ϊ��";
	int *visited= new int[g.numOfVertices()];
	for(int i=0;i<g.numOfVertices();i++)
		visited[i]=0;
	g.DepthFirstSearch(0,visited,Print);
	cout <<endl<< "���������������Ϊ��";
	for(int i=0;i<g.numOfVertices();i++)
		visited[i]=0;
	g.BroadFirstSearch(0,visited,Print);
	delete []visited;
	g.DeleteEdge(0,2);
	g.DeleteEdge(2,0);
	cout <<endl<<"��ǰ�Ķ������Ϊ��" << g.numOfVertices();
    cout <<endl<< "��ǰ�ıߵ�����Ϊ��" << g.numOfEdge() << endl;
	cout << "���������������Ϊ��";
	g.DepthFirstSearch(Print);
	cout <<endl<< "���������������Ϊ��";
	g.BroadFirstSearch(Print);
	cout<<endl;
}



