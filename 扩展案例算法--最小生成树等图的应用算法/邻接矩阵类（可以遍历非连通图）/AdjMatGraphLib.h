struct RowColWeight//边信息三元组
{
	int row;
	int col;
	int weight;
};
void AdjMatCreateGraph(AdjMatGraph &G,DataType V[],int n,RowColWeight E[],int e)//用一个存储边权信息的三元组来生成图
{
	int i;
	for( i=0;i<n;i++)
		G.InsertVertex(V[i]);//填充顶点信息
	//cout<<E[2].col;
	for(i=0;i<e;i++)
		G.InsertEdge(E[i].row,E[i].col,E[i].weight);
		
}
void Print(char item)
{
	cout<<item<<" ";
}

