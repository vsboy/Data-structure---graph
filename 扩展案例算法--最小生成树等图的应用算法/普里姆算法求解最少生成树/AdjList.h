//用结构体定义邻接表中边的信息
struct Edge
{
	int dist;//下标
	WType weight;//权值
	Edge *next;//指向下一个领接边的指针
	Edge(){};
	Edge(int n,WType w)//构造函数
	{
		dist=n;
		weight=w;
		next=NULL;
	}
};
//定义结点信息
struct VerticeType
{
	VerType data;//结点内容
	Edge*firstAdj;//第一条邻接边
};
class AdjList
{
private:	
	VerticeType Vertice[MaxNode];//MaxNode为定义的最大结点数
	int numOfVertice;//结点数目
	int numOfEdge;//边数
	int typeFlag;//区分有向图还是无向图，定义0为无向图，1 为有向图
public:
	AdjList(int flag=0);//构造函数
	~AdjList(void);//析构函数
	int AdjListEmpty()//邻接表判空
	{
		return (numOfVertice==0);
	}
	int AdjListFull()//邻接表判满
	{
		return(numOfVertice==MaxNode);
	}
	int NumOfVer()
	{
		return numOfVertice;
	}
	int NumOfEdge()
	{
		return numOfEdge;
	}
	VerType GetItem(const int i);//获取序号为i的结点内容
	WType GetWeight(int v1,int v2);//获取边<v1,v2>的权
	void InsertVertice(VerType item);//插入一个结点
	void InsertEdge(int v1,int v2,WType w);//插入边<v1,v2>权值为w
	void DeleteVertice(int v);//删除下标为v的结点
	void DeleteEdge(int v1,int v2);//删除边<v1,v2>
	int GetFirstNeighbor(const int v);//返回结点v第一条相邻边的下标，无相邻边返回-1
	int GetNextNeighbor(const int v1,const int v2);//返回结点v1除了<v1,v2>下一条邻接边的结点下标，无则返回-1
	void DepthFirstSearch(const int v,int visited[],void visit(VerType item));//从结点v开始深度优先遍历连通图
	void BroadFirstSearch(const int v,int visited[],void visit(VerType item));//从结点v开始广度优先遍历连通图
	void DepthFirstSearch(void visit(VerType item));//从结点v开始深度优先遍历非连通图
	void BroadFirstSearch(void visit(VerType item));//从结点v开始广度优先遍历非连通图
	Edge*GetAdj(int v);//获得指向序号v的结点的第一邻接边的指针
	
};
AdjList::AdjList(int flag)
{
	typeFlag=flag;
	for(int i=0;i<MaxNode;i++)
		Vertice[i].firstAdj=NULL;
	numOfVertice=0;
	numOfEdge=0;
}
AdjList::~AdjList(void)
{
	for(int i=0;i<numOfVertice;i++)
	{
		Edge*p,*q;
		p=Vertice[i].firstAdj;
		while(p)
		{
			q=p->next;
			delete p;
			p=q;
		}
	}
}
VerType AdjList:: GetItem(const int i)//获取序号为i的结点内容
	{
		if (i<0||i>=numOfVertice)
		{
			cout<<"结点序号i有误！";
			exit(0);
		}
		return Vertice[i].data;
	}
	WType AdjList:: GetWeight(int v1,int v2)//获取边<v1,v2>的权
	{
		if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1和v2的值不合法，无法找到边<v1,v2>的权";
				exit(0);
		}
		Edge*first;
		first=Vertice[v1].firstAdj;
		while(first->next!=NULL && first->dist!=v2)
		{
			first=first->next;
		}
		if(first->dist==v2)
			return first->weight;
		else
		{
			cout<<"边<v1,v2>的权不存在";
			exit(0);
		}
	}
void AdjList::InsertVertice(VerType item)
{
	if(AdjListFull())
	{
		cout<<"邻接表已满，无法插入新的顶点";
		exit(0);
	}
	Vertice[numOfVertice++].data=item;
}
void AdjList::InsertEdge(int v1,int v2,WType w)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1和v2的值不合法，无法插入边<v1,v2>";
				exit(0);
		}
	Edge*p;
	if(!typeFlag)//无向图
	{
		p=new Edge(v2,w);//插入边(v1,v2)
		if(Vertice[v1].firstAdj==NULL)//第一次插入
			Vertice[v1].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v1].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v2)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//插在第一个结点之后
			{
				p->next=Vertice[v1].firstAdj;
				Vertice[v1].firstAdj=p;
			}
			else//插在pre之后
			{
				p->next=pre->next;
				pre->next=p;
			}
		}
		p=new Edge(v1,w);//插入边(v2,v1)
		if(Vertice[v2].firstAdj==NULL)//第一次插入
			Vertice[v2].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v2].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v1)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//插在第一个结点之后
			{
				p->next=Vertice[v2].firstAdj;
				Vertice[v2].firstAdj=p;
			}
			else//插在pre之后
			{
				p->next=pre->next;
				pre->next=p;
			}
		}

		numOfEdge++;

	}
	else//有向图
	{
		 p=new Edge(v2,w);//插入边<v1,v2>
		if(Vertice[v1].firstAdj==NULL)//第一次插入
			Vertice[v1].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v1].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v2)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//插在第一个结点之后
			{
				p->next=Vertice[v1].firstAdj;
				Vertice[v1].firstAdj=p;
			}
			else//插在pre之后
			{
				p->next=pre->next;
				pre->next=p;
			}
		}
		numOfEdge++;
	}
}
void AdjList::DeleteVertice(int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"序号为v的结点不存在，无法删除！";
			exit(0);
		}
		//删除邻接表中其它顶点与v的关联边
	Edge*p,*q;
	p=Vertice[v].firstAdj;//删除v结点关联的边
	for(int i=v;i<numOfVertice-1;i++)//删除结点
	{
		Vertice[i].data=Vertice[i+1].data;
		Vertice[i].firstAdj=Vertice[i+1].firstAdj;
	}
	numOfVertice--;
	while(p!=NULL)
	{
		numOfEdge--;
		q=p->next;
		delete p;
		p=q;
	}
	//删除包含顶点vv的边，需要注意的是原有邻接边的序号发生改变
	//即所有邻接边序号中比贝删除结点序号大的都要减去1
	Edge*temp;
    for(int j=0;j<numOfVertice;j++)
	{
		p=Vertice[j].firstAdj;
		q=NULL;
		while(p!=NULL&&p->dist<v)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v)//删除的是第一个邻接边
		{
			Vertice[j].firstAdj=p->next;
			delete p;
			if(typeFlag)
				numOfEdge--;
		}
		else if(p!=NULL&&p->dist==v)
		{
			q->next=p->next;
			delete p;
			if(typeFlag)
				numOfEdge--;
		}
	}
	for(int j=0;j<numOfVertice;j++)
		{
			p=Vertice[j].firstAdj;
			q=NULL;
			while(p!=NULL&&p->dist<=v)
			{
				q=p;
				p=p->next;
			}
			if(p!=NULL)
			{
				temp=p;
				while(temp!=NULL)
				{
					temp->dist--;
					temp=temp->next;
				}
			}
	}
}
void AdjList::DeleteEdge(int v1,int v2)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1和v2的值不合法，无法删除边<v1,v2>";
				exit(0);
		}
	if(typeFlag)//有向图删除边<v1,v2>
	{
		Edge*p,*q;
		q=NULL;
		p=Vertice[v1].firstAdj;
		while(p&&p->dist!=v2)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v2)//删除第一个结点
		{
			Vertice[v1].firstAdj=p->next;
			delete p;
				numOfEdge--;
		}
		if(q!=NULL&&p->dist==v2)//删除p
		{
			q->next=p->next;
			delete p;
			numOfEdge--;
		}
	}
	else//无向图
	{
		Edge*p,*q;
		q=NULL;
		p=Vertice[v1].firstAdj;//删除边(v1,v2)
		while(p&&p->dist!=v2)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v2)
		{
			Vertice[v1].firstAdj=p->next;
			delete p;
		}
		if(q!=NULL&&p->dist==v2)
		{
			q->next=p->next;
			delete p;
		}
		numOfEdge--;
		q=NULL;
		p=Vertice[v2].firstAdj;//删除边(v2,v1)
		while(p&&p->dist!=v1)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v1)
		{
			Vertice[v2].firstAdj=p->next;
			delete p;
		}
		if(q!=NULL&&p->dist==v1)
		{
			q->next=p->next;
			delete p;
		}
	}
}
int AdjList::GetFirstNeighbor(const int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"序号为v的结点不存在，无法找到他的第一条邻接边！";
			exit(0);
		}
	Edge*p=Vertice[v].firstAdj;
	if(p)
		return p->dist;
	return -1;
}
int AdjList::GetNextNeighbor(const int v1,const int v2)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1和v2的值不合法，无法找到<v1,v2>的下一邻接边";
				exit(0);
		}
	Edge*p=Vertice[v1].firstAdj;
	while (p)
	{
		if(p->next&&p->dist==v2)
			return p->next ->dist ;
		else
			p=p->next ;
	}
	return -1;
}
void AdjList::DepthFirstSearch(const int v,int visited[],void visit(VerType item))
{
	visit(GetItem(v));
	visited[v]=1;//作标记，表示该点已经访问过了
	int adjV=GetFirstNeighbor(v);
	while(adjV!=-1)
	{
		if(!visited[adjV])
			DepthFirstSearch(adjV,visited,visit);//以adjV点进行深度优先遍历
		adjV=GetNextNeighbor(v,adjV);
	}
}
void AdjList::BroadFirstSearch(const int v,int visited[],void visit(VerType item))
{
	int u,adjV;
	SeqQueue queue;
	visit(GetItem(v));
	visited[v]=1;
	queue.QInsert(v);
	while(!queue.QueueEmpty())
	{
		u=queue.QDelete();
		adjV=GetFirstNeighbor(u);
		while(adjV!=-1)
		{
			if(!visited[adjV])
			{
				visit(GetItem(adjV));
				visited[adjV]=1;
				queue.QInsert(adjV);
			}
			adjV=GetNextNeighbor(u,adjV);
		}
	}
}
void AdjList::DepthFirstSearch(void visit(VerType item))//有向图和非连通图深度优先遍历
{
	int *visited=new int[NumOfVer()];
	for(int i=0;i<NumOfVer();i++)
		visited[i]=0;
	for(int i=0;i<NumOfVer();i++)
		if(!visited[i])
			DepthFirstSearch(i,visited,visit);
		delete []visited;
}
void AdjList:: BroadFirstSearch(void visit(VerType item))//有向图和非连通图广度优先遍历
{
	int *visited=new int[NumOfVer()];
	for(int i=0;i<NumOfVer();i++)
		visited[i]=0;
	for(int i=0;i<NumOfVer();i++)
		if(!visited[i])
			BroadFirstSearch(i,visited,visit);
		delete []visited;
}
Edge* AdjList::GetAdj(int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"序号为v的结点不存在，无法找到指向他的第一条邻接边的指针！";
			exit(0);
		}
	Edge*p=Vertice[v].firstAdj;
	return p;
}





		






















