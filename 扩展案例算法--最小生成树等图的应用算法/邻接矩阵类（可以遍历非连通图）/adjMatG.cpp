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
	int n=7,e=12;//7个顶点，12条边
	AdjMatCreateGraph(g,a,n,rcw,e);
	cout << "当前的顶点个数为：" << g.numOfVertices() << endl;
    cout << "当前的边的条数为：" << g.numOfEdge() << endl;
	cout << "深度优先搜索序列为：";
	int *visited= new int[g.numOfVertices()];
	for(int i=0;i<g.numOfVertices();i++)
		visited[i]=0;
	g.DepthFirstSearch(0,visited,Print);
	cout <<endl<< "广度优先搜索序列为：";
	for(int i=0;i<g.numOfVertices();i++)
		visited[i]=0;
	g.BroadFirstSearch(0,visited,Print);
	delete []visited;
	g.DeleteEdge(0,2);
	g.DeleteEdge(2,0);
	cout <<endl<<"当前的顶点个数为：" << g.numOfVertices();
    cout <<endl<< "当前的边的条数为：" << g.numOfEdge() << endl;
	cout << "深度优先搜索序列为：";
	g.DepthFirstSearch(Print);
	cout <<endl<< "广度优先搜索序列为：";
	g.BroadFirstSearch(Print);
	cout<<endl;
}



