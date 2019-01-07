#include<iostream>
typedef char DataType;
const int SeqQMaxSize=100;
#include"SeqQueue.h"
const int MaxNode=100;
typedef char VerType;
typedef int  WType;
#include"AdjList.h"
#include"AdjListGraphLib.h"
using namespace std;
void Print(char item)
{
	cout<<item<<" ";
}
void main()
{
	AdjList g(0);
	char a[]={'A','B','C','D','E','F','G'};
	RowColWeight rcw[]={{0,1,1},{0,2,1},{1,3,1},{1,4,1},{2,5,1},{2,6,1}};
	int n=7,e=6;//7个顶点，12条边
	AdjListCreateGraph(g,a,n,rcw,e);
	cout << "当前的顶点个数为：" << g.NumOfVer() << endl;
    cout << "当前的边的条数为：" << g.NumOfEdge() << endl;
	cout << "深度优先搜索序列为：";
	int *visited= new int[g.NumOfVer()];
	for(int i=0;i<g.NumOfVer();i++)
		visited[i]=0;
	g.DepthFirstSearch(0,visited,Print);
	cout<<endl;
	cout<<"下一个邻接边 "<<g.GetNextNeighbor(1,3)<<endl;//下一条邻接边的结点
	cout <<endl<< "广度优先搜索序列为：";
	for(int i=0;i<g.NumOfVer();i++)
		visited[i]=0;
	g.BroadFirstSearch(0,visited,Print);
	delete []visited;
	//删除一条边
	cout<<"删除边(0,2)"<<endl;
	g.DeleteEdge(0,2);
	cout <<endl<<"当前的顶点个数为：" << g.NumOfVer();
    cout <<endl<< "当前的边的条数为：" << g.NumOfEdge() << endl;
	cout << "深度优先搜索序列为：";
	g.DepthFirstSearch(Print);
	cout <<endl<< "广度优先搜索序列为：";
	g.BroadFirstSearch(Print);
	cout<<endl;
	//删除一个顶点
	cout<<"删除顶点B"<<endl;
	g.DeleteVertice(1);
	cout <<endl<<"删除顶点1后顶点个数为：" << g.NumOfVer();
    cout <<endl<< "删除顶点1后边的条数为：" << g.NumOfEdge() << endl;
	cout << "深度优先搜索序列为：";
	g.DepthFirstSearch(Print);
	cout <<endl<< "广度优先搜索序列为：";
	g.BroadFirstSearch(Print);
	cout<<endl;
}



