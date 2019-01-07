void Prim(AdjList &G,int v,int na,int a[],WType b[])//数组a和b分别表示查找过程中选择的顶点序列和边的权值
{
	int i,j,k;
	a[0]=v;
	for(i=0;i<na;i++)
	{
		MinWeight*p=new MinWeight[i+1];
			int count=0;
		for(j=0;j<=i;j++)//找出每一结点所有最小权值
		{
			MinWeight m;
			if(GetMinWeight(G,a[j],m,a,na)==1)
				p[count++]=m;
		}
			MinWeight *temp=p;
			for(k=0;k<count;k++)//查找最小权值
				if(p[k].w<temp->w)
					temp=&p[k];
				b[i]=temp->w;
				a[i+1]=temp->dist;
		delete []p;
	}
}







