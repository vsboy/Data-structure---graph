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
	int n=7,e=6;//7�����㣬12����
	AdjListCreateGraph(g,a,n,rcw,e);
	cout << "��ǰ�Ķ������Ϊ��" << g.NumOfVer() << endl;
    cout << "��ǰ�ıߵ�����Ϊ��" << g.NumOfEdge() << endl;
	cout << "���������������Ϊ��";
	int *visited= new int[g.NumOfVer()];
	for(int i=0;i<g.NumOfVer();i++)
		visited[i]=0;
	g.DepthFirstSearch(0,visited,Print);
	cout<<endl;
	cout<<"��һ���ڽӱ� "<<g.GetNextNeighbor(1,3)<<endl;//��һ���ڽӱߵĽ��
	cout <<endl<< "���������������Ϊ��";
	for(int i=0;i<g.NumOfVer();i++)
		visited[i]=0;
	g.BroadFirstSearch(0,visited,Print);
	delete []visited;
	//ɾ��һ����
	cout<<"ɾ����(0,2)"<<endl;
	g.DeleteEdge(0,2);
	cout <<endl<<"��ǰ�Ķ������Ϊ��" << g.NumOfVer();
    cout <<endl<< "��ǰ�ıߵ�����Ϊ��" << g.NumOfEdge() << endl;
	cout << "���������������Ϊ��";
	g.DepthFirstSearch(Print);
	cout <<endl<< "���������������Ϊ��";
	g.BroadFirstSearch(Print);
	cout<<endl;
	//ɾ��һ������
	cout<<"ɾ������B"<<endl;
	g.DeleteVertice(1);
	cout <<endl<<"ɾ������1�󶥵����Ϊ��" << g.NumOfVer();
    cout <<endl<< "ɾ������1��ߵ�����Ϊ��" << g.NumOfEdge() << endl;
	cout << "���������������Ϊ��";
	g.DepthFirstSearch(Print);
	cout <<endl<< "���������������Ϊ��";
	g.BroadFirstSearch(Print);
	cout<<endl;
}



