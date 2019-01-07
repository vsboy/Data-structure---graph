class AdjMatGraph
{
private:
	SeqList Vertices;//��˳���洢�����Ϣ
	int Edge[MaxVertices][MaxVertices];//������洢��Ȩ�򲻴�Ȩ�ı�
	int numOfEdges;//����
public:
	AdjMatGraph(const int sz=MaxVertices);
	int GraphEmpty()//��ͼ�Ƿ��
	{
		return Vertices.ListEmpty();
	}
	int numOfVertices()//���ؽ����Ŀ
	{
		return Vertices.ListSize();
	}
	int numOfEdge()//���ر���
	{
		return numOfEdges;
	}
	VerT GetValue(int i);//���ؽ��i��ֵ
	int GetWeight(const int v1,const int v2);//ȡ��<v1,v2>��Ȩֵ
	void InsertVertex(const VerT &vertex);//������vertex
	void InsertEdge(const int v1,const int v2,int weight);//���뻡<v1,v2>��ȨΪweight
	void DeleteVertex(const int v);//ɾ�����i������������ı�
	void DeleteEdge(const int v1,const int v2);//ɾ����<v1,v2>
	int GetFirstNeighbor(const int v);//���ؽ��v��һ�����ڱߵ��±꣬�����ڱ߷���-1
	int GetNextNeighbor(const int v1,const int v2);//���ؽ��v1����<v1,v2>��һ���ڽӱߵĽ���±꣬���򷵻�-1
	void DepthFirstSearch(const int v,int visited[],void visit(VerT item));//�ӽ��v��ʼ������ȱ�����ͨͼ
	void BroadFirstSearch(const int v,int visited[],void visit(VerT item));//�ӽ��v��ʼ������ȱ�����ͨͼ
	void DepthFirstSearch(void visit(VerT item));//�ӽ��v��ʼ������ȱ�������ͨͼ
	void BroadFirstSearch(void visit(VerT item));//�ӽ��v��ʼ������ȱ�������ͨͼ
};
AdjMatGraph::AdjMatGraph(const int sz)
{
	for(int i=0;i<sz;i++)
		for(int j=0;j<sz;j++)
		{
			if(i==j)
				Edge[i][j]=0;
			else
				Edge[i][j]=MaxWeight;//�����
		}
		numOfEdges=0;
}
VerT AdjMatGraph::GetValue(int i)
{
	if(i<0||i>Vertices.ListSize())
	{
		cout<<"����i����"<<endl;
		exit(0);
	}
	return Vertices.GetData(i);
}
int AdjMatGraph:: GetWeight(const int v1,const int v2)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize())
	{
		cout<<"����v1,v2����1"<<endl;
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
		cout<<"����v1,v2����2"<<endl;
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
			for(i=v; i < Vertices.ListSize(); i++)//���������ƶ�
				for(j = 0; j < Vertices.ListSize(); j++)
					Edge[i][j]=Edge[i+1][j];
			for(i=0; i < Vertices.ListSize(); i++)//���������ƶ�
				for(j = v; j < Vertices.ListSize(); j++)
					Edge[i][j]=Edge[i][j+1];
				Vertices.Delete(v);
}
void AdjMatGraph::DeleteEdge(const int v1,const int v2)
{
	if(v1<0||v1>Vertices.ListSize()||v2<0||v2>Vertices.ListSize()||v1==v2)
	{
		cout<<"����v1,v2����3"<<endl;
		exit(0);
	}
	Edge[v1][v2]=MaxWeight;
	numOfEdges--;
}
int AdjMatGraph::GetFirstNeighbor(const int v)
{
	if(v<0||v>Vertices.ListSize())
	{
		cout<<"����v����"<<endl;
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
		cout<<"����v1,v2����4"<<endl;
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
	visited[v]=1;//����ǣ���ʾ�õ��Ѿ����ʹ���
	int adjV=GetFirstNeighbor(v);
	while(adjV!=-1)
	{
		if(!visited[adjV])
			DepthFirstSearch(adjV,visited,visit);//��adjV�����������ȱ���
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
















