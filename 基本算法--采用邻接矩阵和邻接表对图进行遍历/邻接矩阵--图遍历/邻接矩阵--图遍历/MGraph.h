#ifndef MGraph_H                    //����ͷ�ļ�
#define MGraph_H

const int MaxSize = 10;           //ͼ����ඥ�����

template <class DataType>
class MGraph
{
public:
   MGraph(DataType a[ ], int n, int e);    //���캯������������n������e���ߵ�ͼ
   ~MGraph( ) { }                     //��������Ϊ��
   void DFSTraverse(int v);              //������ȱ���ͼ
   void BFSTraverse(int v);               //������ȱ���ͼ
private:
    DataType vertex[MaxSize];          //���ͼ�ж��������
    int arc[MaxSize][MaxSize];          //���ͼ�бߵ�����
    int vertexNum, arcNum;             //ͼ�Ķ������ͱ���
};
#endif