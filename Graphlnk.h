#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include"Seq.h"
#include<string>
#include <limits.h>
#include <cstdlib>
#include<fstream>
#include <sstream>
int DefaultVertices=100;
using namespace std;
class Edge
{
public:
string dest;//路由器终点号 
int cost;//路由器之间边的权值 
Edge*link;	
};
class Vertex
{ 
    public:
 	string start;//路由器起点号 
	Edge*adj;
};
class Graphlnk
{
	public:
	int maxVertices;  //图中结点最大数 
	int numEdges;   //图中边数的个数 
	int numVertices;//图中结点个数 
	Graphlnk();
	Graphlnk(int sz);
	int getWeight(int v1,int v2);
	bool insertVertex();//插入一个结点 
	bool insertEdge(int v1,int v2,int cost);//插入一条边 
	int getFirstNeighbor(int v);//v的第一个相邻结点
	int getNextNeighbor(int v,int w);//v的除w以外的结点 
	bool removeVertex(int v);//删除一个结点 
	bool removeEdge(int v1,int v2);//删除一条边 
	int getVertexPos(const string vertex)//获取结点的位置 
	{
		for(int i=0;i<30;i++)
		{
			if(NodeTable[i].start==vertex) return i;
		
		}	return -1;
	}	 
	Vertex *NodeTable;
	
 };
