#include<iostream>
using namespace std;
class SeqList
{
private:
	DataType data[MaxListSize];
	int size;
public:
	SeqList(void);
	~SeqList(void);
	int ListSize(void)const;//����Ԫ�صĸ���size��
int ListEmpty(void)const;//��շ���1�����򷵻�0��
int Find(DataType & item)const;//����Ԫ��item�ڱ��е�λ�ê�
DataType GetData(int pos)const;//����λ��pos��Ԫ�ت�
void Insert(const DataType & item,int pos);//��λ��pos����Ԫ��item��
DataType Delete(const int pos);//ɾ��λ��pos��Ԫ�ز�����
	void ClearList(void);//�ѱ���ժ�
};
SeqList::SeqList(void):size(0){}
SeqList::~SeqList(void){}
int SeqList::ListSize(void)const
{
	return size;
}
int SeqList::ListEmpty(void)const
{
	if(size==0) 
     return 0;
	else 
		return 1;
}
int SeqList::Find(DataType & item)const
{
	if(size==0)
		return-1;
int i=0;
while(i<size && item!=data[i])i++;//Ѱ��item
if(i<size)
return i;
else
return-1;
}

DataType SeqList::GetData(int pos)const
{
if(pos<0||pos>size-1)//ȡ��Ԫ����ű�����0��size-1֮��
	{
		cout<<"����posԽ�����!"<<endl;
exit(1);//����1��ʾ�����˳�
}
return data[pos];
}
void SeqList::Insert(const DataType & item,int pos)
{
int i;
if(size==MaxListSize)
{
cout<<"˳��������޷����룡"<<endl;
exit(1);
}
	if(pos<0||pos>size)//��pos����sizeʱ��ʾ���������
{
cout<<"����posԽ�����!"<<endl;
exit(1);
}
//�Ӻ���ǰ��ǰһ��Ԫ��Ǩ�Ƶ���һ��Ԫ��λ��ֱ���洢λ��posΪֹ
for(i=size;i>pos;i--)data[i]=data[i-1];
data[pos]=item;//��posλ�ò���item
size++;//����Ԫ�ظ���size��1
}
DataType SeqList::Delete(const int pos)
{
if(size==0)
{
cout<<"˳����ѿ���Ԫ�ؿ�ɾ��"<<endl;
exit(1);
}
if(pos<0||pos>size-1)//ɾ��Ԫ����ű�����0��size-1֮��
{
cout<<"����posԽ�����!"<<endl;
exit(1);
}
DataType temp=data[pos];
//��pos��size-2���Ԫ������,data��size-1������data��size-2���Ъ�
for(int i=pos;i<size-1;i++)data[i]=data[i+1];
size--;//����Ԫ�ظ���size��1��
return temp;
};
void SeqList::ClearList(void)
{
size=0;//����Ԫ�ظ���size��Ϊ��ʼ��ֵ��
};

