//���������ÿһ��������·��ʱ���󵽵ĸ���·��
class AdjMGraph;
class TPath
{
	friend class AdjMGraph;
	int pathlength;
	int sourcevex;//��ʾ���ɶ���sourcevex����ĵ��·��
public:
	TPath(int x,int y)
	{
		pathlength=x;
		sourcevex=y;
	}
	void clear()
	{
		pathlength=10000;
		sourcevex=-1;
	}
};