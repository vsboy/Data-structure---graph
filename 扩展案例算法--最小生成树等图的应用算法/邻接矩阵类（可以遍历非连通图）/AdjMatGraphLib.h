struct RowColWeight//����Ϣ��Ԫ��
{
	int row;
	int col;
	int weight;
};
void AdjMatCreateGraph(AdjMatGraph &G,DataType V[],int n,RowColWeight E[],int e)//��һ���洢��Ȩ��Ϣ����Ԫ��������ͼ
{
	int i;
	for( i=0;i<n;i++)
		G.InsertVertex(V[i]);//��䶥����Ϣ
	//cout<<E[2].col;
	for(i=0;i<e;i++)
		G.InsertEdge(E[i].row,E[i].col,E[i].weight);
		
}
void Print(char item)
{
	cout<<item<<" ";
}

