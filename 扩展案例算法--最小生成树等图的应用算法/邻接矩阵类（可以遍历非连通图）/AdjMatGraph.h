class AdjMatGraph
{
private:
	SeqList Vertices;//用顺序表存储结点信息
	int Edge[MaxVertices][MaxVertices];//用数组存储带权或不带权的边
	int numOfEdges;//边数
public:
	AdjMatGraph(const int sz=MaxVertices);
	int GraphEmpty()//判图是否空
	{
		return Vertices.ListEmpty();
	}
	int numOfVertices()//返回结点数目
	{
		return Vertices.ListSize();
	}
	int numOfEdge()//返回边数
	{
		return numOfEdges;
	}
	VerT GetValue(int i);//返回结点i的值
	int GetWeight(const int v1,const int v2);//取边<v1,v2>的权值
	void InsertVertex(const VerT &vertex);//插入结点vertex
	void InsertEdge(const int v1,const int v2,int weight);//插入弧<v1,v2>，权为weight
	void DeleteVertex(const int v);//删除结点i和与他相关联的边
	void DeleteEdge(const int v1,const int v2);//删除弧<v1,v2>
	int GetFirstNeighbor(const int v);//返回结点v第一条相邻边的下标，无相邻边返回-1
	int GetNextNeighbor(const int v1,const int v2);//返回结点v1除了<v1,v2>下一条邻接边的结点下标，无则返回-1
	void DepthFirstSearch(const int v,int visited[],void visit(VerT item));//从结点v开始深度优先遍历连通图
	void BroadFirstSearch(const int v,int visited[],void visit(VerT item));//从结点v开始广度优先遍历连通图
	void DepthFirstSearch(void visit(VerT item));//从结点v开始深度优先遍历非连通图
	void BroadFirstSearch(void visit(VerT item));//从结点v开始广度优先遍历非连通图
};
AdjMatGraph::AdjMatGraph(const int sz)
{
	for(int i=0;i<sz;i++)
		for(int j=0;j<sz;j++)
		{
			if(i==j)
				Edge[i][j]=0;
			else
				Edge[i][j]=MaxWeight;//无穷大
		}
		numOfEdges=0;
}
VerT AdjMatGraph::GetValue(int i)
{
	if(i<0||i>Vertices.ListSize())
	{
		cout<<"参数i有误"<<endl;
		exit(0);
	}
	return Vertices.GetData(i);
}
int AdjMatGraph:: GetWeight(const int v1,const int v2)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize())
	{
		cout<<"参数v1,v2有误1"<<endl;
		exit(0);
	}
	return Edge[v1][v2];
}
void AdjMatGraph::InsertVertex(const VerT &vertex)
{
	Vertices.Insert(vertex,Vertices.ListSize());
}
void AdjMatGraph::InsertEdge(const int v1,const int v2,int weight)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize())
	{
		cout<<"参数v1,v2有误2"<<endl;
		exit(0);
	}
	Edge[v1][v2]=weight;
	numOfEdges++;
}
void AdjMatGraph::DeleteVertex(const int v)
{
	int i,j;
	for(i = 0; i < Vertices.ListSize(); i++)
		for(j = 0; j < Vertices.ListSize(); j++)
			if((i == v || j == v) && Edge[i][j] > 0 && Edge[i][j] < MaxWeight)
				{
					Edge[i][j] = MaxWeight;
					numOfEdges--;
				}
			for(i=v; i < Vertices.ListSize(); i++)//整行向上移动
				for(j = 0; j < Vertices.ListSize(); j++)
					Edge[i][j]=Edge[i+1][j];
			for(i=0; i < Vertices.ListSize(); i++)//整列向左移动
				for(j = v; j < Vertices.ListSize(); j++)
					Edge[i][j]=Edge[i][j+1];
				Vertices.Delete(v);
}
void AdjMatGraph::DeleteEdge(const int v1,const int v2)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize()||v1==v2)
	{
		cout<<"参数v1,v2有误3"<<endl;
		exit(0);
	}
	Edge[v1][v2]=MaxWeight;
	numOfEdges--;
}
int AdjMatGraph::GetFirstNeighbor(const int v)
{
	if(v<0||v>Vertices.ListSize())
	{
		cout<<"参数v有误"<<endl;
		exit(0);
	}
	for(int col=0;col<Vertices.ListSize();col++)
		if(Edge[v][col]>0 && Edge[v][col]<MaxWeight)
			return col;
		return -1;
}
int AdjMatGraph::GetNextNeighbor(const int v1,const int v2)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize())
	{
		cout<<"参数v1,v2有误4"<<endl;
		exit(0);
	}
	for(int col=v2+1;col<Vertices.ListSize();col++)
		if(Edge[v1][col]>0 && Edge[v1][col]<MaxWeight)
			return col;
		return -1;
}
void AdjMatGraph::DepthFirstSearch(const int v,int visited[],void visit(VerT item))
{
	visit(GetValue(v));
	visited[v]=1;//作标记，表示该点已经访问过了
	int adjV=GetFirstNeighbor(v);
	while(adjV!=-1)
	{
		if(!visited[adjV])
			DepthFirstSearch(adjV,visited,visit);//以adjV点进行深度优先遍历
		adjV=GetNextNeighbor(v,adjV);
	}
}
void AdjMatGraph::BroadFirstSearch(const int v,int visited[],void visit(VerT item))
{
	int u,adjV;
	SeqQueue queue;
	visit(GetValue(v));
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
				visit(GetValue(adjV));
				visited[adjV]=1;
				queue.QInsert(adjV);
			}
			adjV=GetNextNeighbor(u,adjV);
		}
	}
}
void AdjMatGraph::DepthFirstSearch(void visit(VerT item))
{
	int *visited=new int[numOfVertices()];
	int i;
	for(i=0;i<numOfVertices();i++)
		visited[i]=0;
	for(i=0;i<numOfVertices();i++)
		if(!visited[i])
			DepthFirstSearch(i,visited,visit);
		delete []visited;
}
void AdjMatGraph:: BroadFirstSearch(void visit(VerT item))
{
	int *visited=new int[numOfVertices()];
	int i;
	for(i=0;i<numOfVertices();i++)
		visited[i]=0;
	for(i=0;i<numOfVertices();i++)
		if(!visited[i])
			BroadFirstSearch(i,visited,visit);
		delete []visited;
}
















