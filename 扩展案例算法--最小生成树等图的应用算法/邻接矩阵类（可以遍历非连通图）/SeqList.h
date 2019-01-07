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
	int ListSize(void)const;//返回元素的个数size
int ListEmpty(void)const;//表空返回1；否则返回0
int Find(DataType & item)const;//返回元素item在表中的位置
DataType GetData(int pos)const;//返回位置pos的元素
void Insert(const DataType & item,int pos);//在位置pos插入元素item
DataType Delete(const int pos);//删除位置pos的元素并返回
	void ClearList(void);//把表清空
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
while(i<size && item!=data[i])i++;//寻找item
if(i<size)
return i;
else
return-1;
}

DataType SeqList::GetData(int pos)const
{
if(pos<0||pos>size-1)//取的元素序号必须在0至size-1之间
	{
		cout<<"参数pos越界出错!"<<endl;
exit(1);//参数1表示出错退出
}
return data[pos];
}
void SeqList::Insert(const DataType & item,int pos)
{
int i;
if(size==MaxListSize)
{
cout<<"顺序表已满无法插入！"<<endl;
exit(1);
}
	if(pos<0||pos>size)//当pos等于size时表示插入在最后
{
cout<<"参数pos越界出错!"<<endl;
exit(1);
}
//从后向前把前一个元素迁移到后一个元素位置直到存储位置pos为止
for(i=size;i>pos;i--)data[i]=data[i-1];
data[pos]=item;//在pos位置插入item
size++;//数据元素个数size加1
}
DataType SeqList::Delete(const int pos)
{
if(size==0)
{
cout<<"顺序表已空无元素可删！"<<endl;
exit(1);
}
if(pos<0||pos>size-1)//删除元素序号必须在0至size-1之间
{
cout<<"参数pos越界出错!"<<endl;
exit(1);
}
DataType temp=data[pos];
//从pos至size-2逐个元素左移,data［size-1］移入data［size-2］中
for(int i=pos;i<size-1;i++)data[i]=data[i+1];
size--;//数据元素个数size减1
return temp;
};
void SeqList::ClearList(void)
{
size=0;//数据元素个数size置为初始化值
};

