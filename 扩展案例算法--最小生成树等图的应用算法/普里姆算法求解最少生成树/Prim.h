void Prim(AdjList &G,int v,int na,int a[],WType b[])//����a��b�ֱ��ʾ���ҹ�����ѡ��Ķ������кͱߵ�Ȩֵ
{
	int i,j,k;
	a[0]=v;
	for(i=0;i<na;i++)
	{
		MinWeight*p=new MinWeight[i+1];
			int count=0;
		for(j=0;j<=i;j++)//�ҳ�ÿһ���������СȨֵ
		{
			MinWeight m;
			if(GetMinWeight(G,a[j],m,a,na)==1)
				p[count++]=m;
		}
			MinWeight *temp=p;
			for(k=0;k<count;k++)//������СȨֵ
				if(p[k].w<temp->w)
					temp=&p[k];
				b[i]=temp->w;
				a[i+1]=temp->dist;
		delete []p;
	}
}







