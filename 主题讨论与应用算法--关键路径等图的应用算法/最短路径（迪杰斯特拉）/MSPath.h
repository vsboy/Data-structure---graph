//��������ҵ���·��������
class AdjMGraph;
class MSPath
{
	//public:
	friend  class AdjMGraph;
	int *path;//������·������Ϣ����2 3 1 0 -1��ʾ����2������0��·����-1��ʾ�ĵ㲻����
	int pathlength;//·������
	int n;//�������Ŀ
	int flag;//��ʾ����ŵĶ����Ƿ����Ѿ��ҵ������·���Ķ���
	public:
	MSPath(int ncount)
	{
		path=new int[ncount];
		for(int i=0;i<ncount;i++)
			path[i]=-1;
		pathlength=0;
		n=ncount;
		flag=0;
	}
	void printpath()//���·��
	{
		for(int i=0;i<n;i++)
		{
			if(path[i]==-1)
				break;
			else
				cout<<path[i]<<"  ";
		}
		cout<<endl;
		cout<<"����";
		cout<<pathlength<<endl;
	}
	int getpathlength()//ȡ·������
	{
		return pathlength;
	}
	int getflag()//�ж��Ƿ��ǲ��ҹ��ĵ�
	{
		return flag;
	}

};
	