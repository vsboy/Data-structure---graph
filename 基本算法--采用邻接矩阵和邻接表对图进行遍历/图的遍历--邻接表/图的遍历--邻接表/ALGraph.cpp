#include <iostream>
using namespace std;
#include "ALGraph.h"                 //����ͷ�ļ�

template <class DataType>
ALGraph<DataType>::ALGraph(DataType a[ ], int n, int e)
{
	ArcNode *s;
	int i, j, k;
	vertexNum = n; arcNum = e;
	for (i = 0; i < vertexNum; i++)     //���붥����Ϣ����ʼ�������
	{ 
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;      
	}
	for (k = 0; k < arcNum; k++)        //��������ÿһ����
	{ 
		cout<<"������ߵ������������ţ�";
		cin >> i >> j;                 //���������������������ı��
		s = new ArcNode; s->adjvex = j;  //����һ���߱���s
		s->next = adjlist[i].firstedge;     //�����s���뵽��i���߱�ı�ͷ
		adjlist[i].firstedge = s;
	}
}

template <class DataType>
ALGraph<DataType>::~ALGraph( )
{
	ArcNode *p;
	for(int i=0; i<vertexNum; i++)
	{
		p=adjlist[i].firstedge;
		while(p!=NULL)                                              //ѭ��ɾ��
		{
			adjlist[i].firstedge=p->next;
			delete p;                                                 //�ͷŽ��ռ�
			p=adjlist[i].firstedge;
		}
	}
}

template <class DataType>
void ALGraph<DataType>::DFSTraverse(int v)
{
	ArcNode *p; int j;
	cout<<adjlist[v].vertex;  visited[v] = 1;
    p = adjlist[v].firstedge;             //����ָ��pָ�򶥵�v�ı߱�
	while (p != NULL)                //������������v���ڽӵ�j
	{
		j = p->adjvex;
		if (visited[j] == 0) DFSTraverse(j);
		p = p->next;           
	}
}

template <class DataType>
void ALGraph<DataType>::BFSTraverse(int v)
{
	int front =-1, rear = -1;   //��ʼ������, ������в���˳��洢�Ҳ��ᷢ�����
	int Q[MaxSize];
    ArcNode *p;
	cout<<adjlist[v].vertex; visited[v] = 1; Q[++rear] = v;   //�����ʶ������
	while (front != rear)           //�����зǿ�ʱ
	{
		v = Q[++front];
		p = adjlist[v].firstedge;       //����ָ��pָ�򶥵�v�ı߱�
		while (p != NULL) 
		{
			int j = p->adjvex;
			if (visited[j] == 0) {
				cout<<adjlist[j].vertex; visited[j]=1;Q[++rear]=j;
			}
			p=p->next;
		}
	}
}