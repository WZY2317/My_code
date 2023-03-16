#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>
using namespace std;

#include"UnionFindSet.h"

// 临接矩阵
namespace Matrix
{
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
	public:
		struct Edge
		{
			V _srci;
			V _dsti;
			W _w;

			Edge(const V& srci, const V& dsti, const W& w)
				:_srci(srci)
				, _dsti(dsti)
				, _w(w)
			{}

			bool operator<(const Edge& eg) const
			{
				return _w < eg._w;
			}

			bool operator>(const Edge& eg) const
			{
				return _w > eg._w;
			}
		};

		typedef Graph<V, W, MAX_W, Direction> Self;

		Graph() = default;

		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(vertexs[i]);
				_vIndexMap[vertexs[i]] = i;
			}

			// MAX_W 作为不存在边的标识值
			_matrix.resize(n);
			for (auto& e : _matrix)
			{
				e.resize(n, MAX_W);
			}
		}

		size_t GetVertexIndex(const V& v)
		{
			auto ret = _vIndexMap.find(v);
			if (ret != _vIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("不存在的顶点");
				return -1;
			}
		}

		void _AddEdge(size_t srci, size_t dsti, const W& w)
		{
			_matrix[srci][dsti] = w;
			if (Direction == false)
			{
				_matrix[dsti][srci] = w;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srci = GetVertexIndex(src);
			size_t dsti = GetVertexIndex(dst);

			_AddEdge(srci, dsti, w);
		}

		void BFS(const V& src)
		{
			size_t srcindex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);

			queue<int> q;
			q.push(srcindex);
			visited[srcindex] = true;
			size_t d = 1;
			size_t dSize = 1;

			while (!q.empty())
			{
				printf("%s的%d度好友:", src.c_str(), d);

				while (dSize--)
				{
					size_t front = q.front();
					q.pop();
					for (size_t i = 0; i < _vertexs.size(); ++i)
					{
						if (visited[i] == false && _matrix[front][i] != MAX_W)
						{
							printf("[%d:%s] ", i, _vertexs[i].c_str());
							visited[i] = true;
							q.push(i);
						}
					}
				}
				cout << endl;

				dSize = q.size();
				++d;
			}
			cout << endl;
		}

		void _DFS(size_t srcIndex, vector<bool>& visited)
		{
			printf("[%d:%s]->", srcIndex, _vertexs[srcIndex].c_str());
			visited[srcIndex] = true;
			// srcIndex->i
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (visited[i] == false && _matrix[srcIndex][i] != MAX_W)
				{
					_DFS(i, visited);
				}
			}
		}

		void DFS(const V& src)
		{
			size_t srcindex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);

			_DFS(srcindex, visited);
			cout << endl;
		}

		void Print()
		{
			// 打印顶点和下标映射关系
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << _vertexs[i] << "-" << i << " ";
			}
			cout << endl << endl;

			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << i << " ";
			}
			cout << endl;

			// 打印矩阵
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " ";
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (_matrix[i][j] != MAX_W)
						cout << _matrix[i][j] << " ";
					else
						cout << "#" << " ";
				}
				cout << endl;
			}
			cout << endl << endl;

			// 打印所有的边
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						cout << _vertexs[i] << "-" << _vertexs[j] << ":" << _matrix[i][j] << endl;
					}
				}
			}
		}

		W Kruskal(Self& minTree)
		{
			minTree._vertexs = _vertexs;
			minTree._vIndexMap = _vIndexMap;
			minTree._matrix.resize(_vertexs.size());
			for (auto& e : minTree._matrix)
			{
				e.resize(_vertexs.size(), MAX_W);
			}

			priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
					{
						pq.push(Edge(i, j, _matrix[i][j]));
					}
				}
			}

			W total = W();

			// 贪心算法，从最小的边开始选
			size_t i = 1;
			UnionFindSet ufs(_vertexs.size());
			while (i < _vertexs.size() && !pq.empty())
			{
				Edge min = pq.top();
				pq.pop();
				// 边不在一个集合，说明不会构成环，则添加到最小生成树
				if (ufs.FindRoot(min._srci) != ufs.FindRoot(min._dsti))
				{
					//cout << _vertexs[min._srci] << "-" << _vertexs[min._dsti] << ":" << _matrix[min._srci][min._dsti] << endl;

					minTree._AddEdge(min._srci, min._dsti, min._w);
					total += min._w;

					ufs.Union(min._srci, min._dsti);
					++i;
				}
			}

			if (i == _vertexs.size())
			{
				return total;
			}
			else
			{
				return W();
			}
		}

		W Prim(Self& minTree, const V& src)
		{
			minTree._vertexs = _vertexs;
			minTree._vIndexMap = _vIndexMap;
			minTree._matrix.resize(_vertexs.size());
			for (auto& e : minTree._matrix)
			{
				e.resize(_vertexs.size(), MAX_W);
			}

			size_t srci = GetVertexIndex(src);
			set<size_t> inSet;
			inSet.insert(srci);
			priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (_matrix[srci][i] != MAX_W)
				{
					pq.push(Edge(srci, i, _matrix[srci][i]));
				}
			}

			W total = W();
			while (inSet.size() < _vertexs.size() && !pq.empty())
			{
				Edge min = pq.top();
				pq.pop();

				// 防止环的问题
				if (inSet.find(min._srci) == inSet.end() || inSet.find(min._dsti) == inSet.end())
				{
					//cout << _vertexs[min._srci] << "-" << _vertexs[min._dsti] << ":" << _matrix[min._srci][min._dsti] << endl;

					minTree._AddEdge(min._srci, min._dsti, min._w);
					total += min._w;

					// 新入顶点的连接边进入队列
					for (size_t i = 0; i < _vertexs.size(); ++i)
					{
						if (_matrix[min._dsti][i] != MAX_W && inSet.find(i) == inSet.end())
						{
							pq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
						}
					}

					inSet.insert(min._dsti);
				}
			}

			if (inSet.size() == _vertexs.size())
			{
				return total;
			}
			else
			{
				return W();
			}
		}

		void PrinrtShotPath(const V& src, const vector<W>& dist, const vector<int>& parentPath)
		{
			size_t N = _vertexs.size();
			size_t srci = GetVertexIndex(src);

			for (size_t i = 0; i < N; ++i)
			{
				if (i == srci)
					continue;


				vector<int> path;
				int parenti = i;
				while (parenti != srci)
				{
					path.push_back(parenti);
					parenti = parentPath[parenti];
				}
				path.push_back(srci);


				reverse(path.begin(), path.end());
				for (auto pos : path)
				{
					cout << _vertexs[pos] << "->";
				}

				cout << dist[i] << endl;
			}
		}

		void Dijkstra(const V& src, vector<W>& dist, vector<int>& parentPath)
		{
			size_t N = _vertexs.size();
			size_t srci = GetVertexIndex(src);

			// vector<W> dist,记录srci-其他顶点最短路径权值数组
			dist.resize(N, MAX_W);
			// vector<int> parentPath 记录srci-其他顶点最短路径父顶点数组
			parentPath.resize(N, -1);

			// 标记是否找到最短路径的顶点集合S
			vector<bool> S;
			S.resize(N, false);

			// srci的权值给一个最小值，方便贪心第一次找到这个节点
			dist[srci] = W();

			// N个顶点更新N次
			for (size_t i = 0; i < N; ++i)
			{
				// 贪心算法：srci到不在S中路径最短的那个顶点u
				W min = MAX_W;
				size_t u = srci;
				for (size_t j = 0; j < N; ++j)
				{
					if (S[j] == false && dist[j] < min)
					{
						min = dist[j];
						u = j;
					}
				}
				S[u] = true;

				// 松弛算法：更新一遍u连接的所有边，看是否能更新出更短连接路径
				for (size_t k = 0; k < N; ++k)
				{
					// 如果srci->u + u->k 比 srci->k更短 则进行更新
					if (S[k] == false && _matrix[u][k] != MAX_W
						&& dist[u] + _matrix[u][k] < dist[k])
					{
						dist[k] = dist[u] + _matrix[u][k];
						parentPath[k] = u;
					}
				}
			}
		}

		bool BellmanFord(const V& src, vector<W>& dist, vector<int>& parentPath)
		{
			size_t N = _vertexs.size();
			size_t srci = GetVertexIndex(src);

			// vector<W> dist,记录srci-其他顶点最短路径权值数组
			dist.resize(N, MAX_W);
			// vector<int> parentPath 记录srci-其他顶点最短路径父顶点数组
			parentPath.resize(N, -1);

			// 先更新srci->srci为最小值
			dist[srci] = W();

			for (size_t k = 0; k < N - 1; ++k)
			{
				bool exchange = false;
				for (size_t i = 0; i < N; ++i)
				{
					for (size_t j = 0; j < N; ++j)
					{
						// srci->i + i->j < srci->j 则更新路径及权值 
						if (_matrix[i][j] != MAX_W
							&& dist[i] + _matrix[i][j] < dist[j])
						{
							dist[j] = dist[i] + _matrix[i][j];
							parentPath[j] = i;

							exchange = true;
						}
					}
				}

				if (exchange == false)
					break;
			}

			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					// 检查有没有负权回路
					if (_matrix[i][j] != MAX_W
						&& dist[i] + _matrix[i][j] < dist[j])
					{
						return false;
					}
				}
			}

			return true;
		}

		void FloydWarShall(vector<vector<W>>& vvDist, vector<vector<int>>& vvParentPath)
		{
			size_t N = _vertexs.size();
			vvDist.resize(N);
			vvParentPath.resize(N);

			// 初始化权值和路径矩阵
			for (size_t i = 0; i < N; ++i)
			{
				vvDist[i].resize(N, MAX_W);
				vvParentPath[i].resize(N, -1);
			}

			// 将直接相连的路径初始化
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					if (_matrix[i][j] != MAX_W)
					{
						vvDist[i][j] = _matrix[i][j];
						vvParentPath[i][j] = i;
					}
					else
					{
						vvParentPath[i][j] = -1;
					}

					if (i == j)
					{
						vvDist[i][j] = 0;
						vvParentPath[i][j] = -1;
					}
				}
			}

			// 依次用顶点k作为中转点更新最短路径
			for (size_t k = 0; k < N; ++k)
			{
				for (size_t i = 0; i < N; ++i)
				{
					for (size_t j = 0; j < N; ++j)
					{
						// i->k + k->j 比 i->j前面更新的距离更短，则更新
						if (vvDist[i][k] != MAX_W && vvDist[k][j] != MAX_W
							&& vvDist[i][k] + vvDist[k][j] < vvDist[i][j])
						{
							vvDist[i][j] = vvDist[i][k] + vvDist[k][j];
							vvParentPath[i][j] = vvParentPath[k][j];
						}
					}
				}

				// 打印权值和路径矩阵观察数据
				//for (size_t i = 0; i < N; ++i)
				//{
				//	for (size_t j = 0; j < N; ++j)
				//	{
				//		if (vvDist[i][j] == MAX_W)
				//		{
				//			//cout << "*" << " ";
				//			printf("%3c", '*');
				//		}
				//		else
				//		{
				//			//cout << vvDist[i][j] << " ";
				//			printf("%3d", vvDist[i][j]);
				//		}
				//	}
				//	cout << endl;
				//}
				//cout << endl;

				//for (size_t i = 0; i < N; ++i)
				//{
				//	for (size_t j = 0; j < N; ++j)
				//	{
				//		//cout << vvParentPath[i][j] << " ";
				//		printf("%3d", vvParentPath[i][j]);
				//	}
				//	cout << endl;
				//}
				//cout << "=================================" << endl;
			}
		}

	private:
		map<V, size_t> _vIndexMap;
		vector<V> _vertexs;			 // 顶点集合
		vector<vector<W>> _matrix;   // 存储边集合的矩阵
	};

	void TestGraph()
	{
		Graph<char, int, INT_MAX, true> g("0123", 4);
		g.AddEdge('0', '1', 1);
		g.AddEdge('0', '3', 4);
		g.AddEdge('1', '3', 2);
		g.AddEdge('1', '2', 9);
		g.AddEdge('2', '3', 8);
		g.AddEdge('2', '1', 5);
		g.AddEdge('2', '0', 3);
		g.AddEdge('3', '2', 6);

		g.Print();
	}

	void TestGraphDBFS()
	{
		string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<string, int> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);

		g1.BFS("张三");
		g1.DFS("张三");
	}

	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
		Graph<char, int> g(str, strlen(str));
		g.AddEdge('a', 'b', 4);
		g.AddEdge('a', 'h', 8);
		//g.AddEdge('a', 'h', 9);
		g.AddEdge('b', 'c', 8);
		g.AddEdge('b', 'h', 11);
		g.AddEdge('c', 'i', 2);
		g.AddEdge('c', 'f', 4);
		g.AddEdge('c', 'd', 7);
		g.AddEdge('d', 'f', 14);
		g.AddEdge('d', 'e', 9);
		g.AddEdge('e', 'f', 10);
		g.AddEdge('f', 'g', 2);
		g.AddEdge('g', 'h', 1);
		g.AddEdge('g', 'i', 6);
		g.AddEdge('h', 'i', 7);

		Graph<char, int> kminTree;
		cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
		kminTree.Print();

		Graph<char, int> pminTree;
		cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
		pminTree.Print();
	}

	void TestGraphDijkstra()
	{
		/*const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('y', 't', 3);
		g.AddEdge('y', 'x', 9);
		g.AddEdge('y', 'z', 2);
		g.AddEdge('z', 's', 7);
		g.AddEdge('z', 'x', 6);
		g.AddEdge('t', 'y', 2);
		g.AddEdge('t', 'x', 1);
		g.AddEdge('x', 'z', 4);

		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrinrtShotPath('s', dist, parentPath);*/

		// 图中带有负权路径时，贪心策略则失效了。
		// 测试结果可以看到s->t->y之间的最短路径没更新出来
		const char* str = "sytx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('t', 'y', -7);
		g.AddEdge('y', 'x', 3);

		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrinrtShotPath('s', dist, parentPath);
	}

	void TestGraphBellmanFord()
	{
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 6);
		g.AddEdge('s', 'y', 7);
		g.AddEdge('y', 'z', 9);
		g.AddEdge('y', 'x', -3);
		g.AddEdge('z', 's', 2);
		g.AddEdge('z', 'x', 7);
		g.AddEdge('t', 'x', 5);
		g.AddEdge('t', 'y', 8);
		g.AddEdge('t', 'z', -4);
		g.AddEdge('x', 't', -2);

		vector<int> dist;
		vector<int> parentPath;
		if (g.BellmanFord('s', dist, parentPath))
		{
			g.PrinrtShotPath('s', dist, parentPath);
		}
		else
		{
			cout << "存在负权回路" << endl;
		}

		// 微调图结构，带有负权回路的测试
		//const char* str = "syztx";
		//Graph<char, int, INT_MAX, true> g(str, strlen(str));
		//g.AddEdge('s', 't', 6);
		//g.AddEdge('s', 'y', 7);
		//g.AddEdge('y', 'x', -3);
		//g.AddEdge('y', 'z', 9);
		//g.AddEdge('y', 'x', -3);
		//g.AddEdge('y', 's', 1);  // 新增
		//g.AddEdge('z', 's', 2);
		//g.AddEdge('z', 'x', 7);
		//g.AddEdge('t', 'x', 5);
		//g.AddEdge('t', 'y', -8); // 更改
		//g.AddEdge('t', 'z', -4);
		//g.AddEdge('x', 't', -2);

		//vector<int> dist;
		//vector<int> parentPath;
		//if (g.BellmanFord('s', dist, parentPath))
		//{
		//	g.PrinrtShotPath('s', dist, parentPath);
		//}
		//else
		//{
		//	cout << "存在负权回路" << endl;
		//}
	}

	void TestFloydWarShall()
	{
		const char* str = "12345";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('1', '2', 3);
		g.AddEdge('1', '3', 8);
		g.AddEdge('1', '5', -4);
		g.AddEdge('2', '4', 1);
		g.AddEdge('2', '5', 7);
		g.AddEdge('3', '2', 4);
		g.AddEdge('4', '1', 2);
		g.AddEdge('4', '3', -5);
		g.AddEdge('5', '4', 6);

		vector<vector<int>> vvDist;
		vector<vector<int>> vvParentPath;
		g.FloydWarShall(vvDist, vvParentPath);

		// 打印任意两点之间的最短路径
		for (size_t i = 0; i < strlen(str); ++i)
		{
			g.PrinrtShotPath(str[i], vvDist[i], vvParentPath[i]);
			cout << endl;
		}
	}
}


// 临接表
namespace LinkTable
{
	template<class W>
	struct LinkEdge
	{
		int _srcIndex;
		int _dstIndex;
		W _w;
		LinkEdge<W>* _next;

		LinkEdge(const W& w)
			: _srcIndex(-1)
			, _dstIndex(-1)
			, _w(w)
			, _next(nullptr)
		{}
	};

	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef LinkEdge<W> Edge;
	public:
		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(vertexs[i]);
				_vIndexMap[vertexs[i]] = i;
			}

			_linkTable.resize(n, nullptr);
		}

		size_t GetVertexIndex(const V& v)
		{
			auto ret = _vIndexMap.find(v);
			if (ret != _vIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("不存在的顶点");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srcindex = GetVertexIndex(src);
			size_t dstindex = GetVertexIndex(dst);

			// 0 1
			Edge* sd_edge = new Edge(w);
			sd_edge->_srcIndex = srcindex;
			sd_edge->_dstIndex = dstindex;
			sd_edge->_next = _linkTable[srcindex];
			_linkTable[srcindex] = sd_edge;

			// 1 0
			// 无向图
			if (Direction == false)
			{
				Edge* ds_edge = new Edge(w);
				ds_edge->_srcIndex = dstindex;
				ds_edge->_dstIndex = srcindex;
				ds_edge->_next = _linkTable[dstindex];
				_linkTable[dstindex] = ds_edge;
			}
		}


	private:
		map<string, int> _vIndexMap;
		vector<V> _vertexs;			 // 顶点集合
		vector<Edge*> _linkTable;    // 边的集合的临接表
	};

	void TestGraph()
	{
		string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<string, int> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
	}
}
