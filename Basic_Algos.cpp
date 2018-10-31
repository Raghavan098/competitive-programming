/*
	This program implements:

		1 - BFS
		2 - DFS (Iterative and Recursive)
		3 - Dijkstra
		4 - Prim's Algorithm
		5 - Kruskal's Algorithm
		6 - Topological Sort
		7 - Strongly Connected Components
*/
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>
#include<queue>
#include<stack>
using namespace std;

template <typename V, typename W> class Graph{
	protected:
		enum stateNode{
			notVisited,
			visited,
			inStack
		};
		class Heap{
				struct Node{
					int v;
					W priority;

					Node(int v, W p){
						this->v = v;
						this->priority = p;
					}
				};

				vector<Node> a;
				int size;
				vector<int> pos;
				bool minHeap;

				int parent(int i){
					return (i-1)/2;
				}

				int left(int i){
					return 2*i + 1;
				}

				int right(int i){
					return 2*i + 2;
				}

				bool compare(W a, W b){
					if(minHeap) return a < b;
					return a > b;
				}

				void swap(Node &a, Node &b){
					Node t = a;
					a = b;
					b = t;

					swap(pos[a.v], pos[b.v]);
				}

				void swap(int &a, int &b){
					int t = a;
					a = b;
					b = t;
				}

			public:

				Heap(int l, W inf, bool mh = true);
				void top_down_heapify(int i);
				void bottom_up_heapify(int i);
				void update(int i, W k);
				int top();
		};

		struct Edge{
			int d;
			W wt;

			Edge(int v, W w){
				d = v;
				wt = w;
			}
		};

		vector<vector<Edge> > adjList;
		unordered_map<V, int> vertices;
		vector<V> invVertices;
		const W INF;
		int size;

		void dfs_visit(int rt, int &t, vector<bool> &visit, vector<int> &discoveryTime, vector<int> &finishTime, vector<int> &pi);
		void vertices_increasing_finish_time_visit(int rt, vector<bool> &visit, vector<int> &sortedVertices);
		bool check_cycle_visit(int i, vector<stateNode> &state);

	public:

		Graph(W x) : INF(x){
			this->size = 0;
		}
		void insert_node(V newNode);
		void insert_edge(V src, V dest, W wt = 1);
		void bfs(V rt);
		void dfs_iterative(V rt);
		void dfs_recursive();
		bool check_cycle();
		vector<int> vertices_increasing_finish_time();
		Graph get_transpose();
		void strongly_connected_components();
		void dijkstra(V rt);
};

/* Graph Functions - START */
template <typename V, typename W> void Graph<V, W>::insert_node(V newNode){
	vertices[newNode] = this->size;
	invVertices.push_back(newNode);
	adjList.push_back(vector<Edge>());
	this->size++;
}

template <typename V, typename W> void Graph<V, W>::insert_edge(V src, V dest, W wt){
	adjList[vertices[src]].push_back(Edge(vertices[dest], wt));
}

template <typename V, typename W> void Graph<V, W>::bfs(V rt){
	int root = vertices[rt];
	vector<bool> visit(this->size, true);
	vector<int> pi(this->size);
	queue<int> q;

	q.push(root);
	visit[root] = false;
	pi[root] = root;

	while(!q.empty()){
		root = q.front();
		q.pop();

		//Visit function
		cout<<"Node: "<<invVertices[root]<<"\t Pi("<<invVertices[root]<<"): "<<invVertices[pi[root]]<<endl;

		for(typename vector<Edge>::iterator i = adjList[root].begin(); i != adjList[root].end(); ++i){
			if(visit[i->d]){
				q.push(i->d);
				pi[i->d] = root;
				visit[i->d] = false;
			}
		}
	}
}

template <typename V, typename W> void Graph<V, W>::dfs_iterative(V rt){
	int root = vertices[rt];
	vector<bool> visit(this->size, true);
	vector<int> pi(this->size);
	stack<int> s;

	s.push(root);
	pi[root] = root;

	while(!s.empty()){
		root = s.top();
		s.pop();

		if(visit[root]){
			//Visit function
			cout<<"Node: "<<invVertices[root]<<"\t Pi("<<invVertices[root]<<"): "<<invVertices[pi[root]]<<endl;

			visit[root] = false;
		}

		for(typename vector<Edge>::iterator i = adjList[root].begin(); i != adjList[root].end(); ++i){
			if(visit[i->d]){
				s.push(i->d);
				pi[i->d] = root;
			}
		}
	}
}

template <typename V, typename W> void Graph<V, W>::dfs_recursive(){
	vector<bool> visit(this->size, true);
	//1 - discovery time, 2 - Finish time, 3 - Pi values
	vector<int> discoveryTime(this->size);
	vector<int> finishTime(discoveryTime), pi(discoveryTime);
	int t = 0;

	for(int i = 0; i < this->size; ++i){
		if(visit[i]){
			dfs_visit(i, t, visit, discoveryTime, finishTime, pi);
		}
	}

	for(int i = 0; i < this->size; ++i){
		cout<<"Node: "<<invVertices[i]<<"\t Pi("<<invVertices[i]<<"): "<<invVertices[pi[i]]<<"\t Discovery Time: "<<discoveryTime[i]<<"\t Finish Time: "<<finishTime[i]<<endl;
	}
}

template <typename V, typename W> void Graph<V, W>::dfs_visit(int rt, int &t, vector<bool> &visit, vector<int> &discoveryTime, vector<int> &finishTime, vector<int> &pi){
	visit[rt] = false;
	discoveryTime[rt] = t++;

	for(typename vector<Edge>::iterator i = adjList[rt].begin(); i != adjList[rt].end(); ++i){
		if(visit[i->d]){
			pi[i->d] = rt;
			dfs_visit(i->d, t, visit, discoveryTime, finishTime, pi);
		}
	}

	finishTime[rt] = t++;
}

template <typename V, typename W> vector<int> Graph<V, W>::vertices_increasing_finish_time(){
	vector<bool> visit(this->size, true);
	vector<int> sortedVertices;

	for(int i = 0; i < this->size; ++i){
		if(visit[i]){
			vertices_increasing_finish_time_visit(i, visit, sortedVertices);
		}
	}

	return sortedVertices;
}

template <typename V, typename W> void Graph<V, W>::vertices_increasing_finish_time_visit(int rt, vector<bool> &visit, vector<int> &sortedVertices){
	visit[rt] = false;

	for(typename vector<typename Graph<V, W>::Edge>::iterator i = this->adjList[rt].begin(); i != this->adjList[rt].end(); ++i){
		if(visit[i->d]){
			vertices_increasing_finish_time_visit(i->d, visit, sortedVertices);
		}
	}

	sortedVertices.push_back(rt);
}

template <typename V, typename W> void Graph<V, W>::dijkstra(V rt){
	int root = vertices[rt];
	Heap m(this->size, INF);
	vector<W> dist(this->size, INF);
	vector<int> pi(this->size);

	m.update(root, 0);
	pi[root] = root;
	dist[root] = 0;

	for(int i = 0; i < this->size; ++i){
		root = m.top();
		if(dist[root] == INF) break;	//All connected nodes have been visited

		for(typename vector<Edge>::iterator j = adjList[root].begin(); j != adjList[root].end(); ++j){
			if(dist[root] + j->wt < dist[j->d]){
				dist[j->d] = dist[root] + j->wt;
				m.update(j->d, dist[j->d]);
				pi[j->d] = root;
			}
		}
	}

	for(int i = 0; i < this->size; ++i){
		if(dist[i] != INF)
			cout<<"Node: "<<invVertices[i]<<"\t Distance: "<<dist[i]<<"\t Pi("<<invVertices[i]<<"): "<<invVertices[pi[i]]<<endl;
	}
}

template <typename V, typename W> Graph<V, W> Graph<V, W>::get_transpose(){
	Graph<V, W> transpose = *this;
	transpose.adjList = vector<vector<Edge> >(this->size);

	for(int i = 0; i < this->size; ++i){
		for(typename vector<Edge>::iterator j = adjList[i].begin(); j != adjList[i].end(); ++j){
			transpose.adjList[j->d].push_back(Edge(i, j->wt));
		}
	}

	return transpose;
}

template <typename V, typename W> void Graph<V, W>::strongly_connected_components(){
	vector<int> sortedVertices(vertices_increasing_finish_time());
	Graph<V, W> transpose = get_transpose();
	vector<bool> visit(this->size, true);
	vector<vector<int> > scc;

	for(vector<int>::reverse_iterator i = sortedVertices.rbegin(); i != sortedVertices.rend(); ++i){
		if(visit[*i]){
			vector<int> temp;
			transpose.vertices_increasing_finish_time_visit(*i, visit, temp);
			scc.push_back(temp);
		}
	}

	int count = 1;
	for(vector<vector<int> >::iterator i = scc.begin(); i != scc.end(); ++i){
		cout<<"Component "<<count++<<":"<<endl;
		for(vector<int>::iterator j = i->begin(); j != i->end(); ++j){
			cout<<invVertices[*j]<<" ";
		}
		cout<<endl;
	}
}

template <typename V, typename W> bool Graph<V, W>::check_cycle_visit(int rt, vector<stateNode> &state){
	state[rt] = inStack;

	for(typename vector<typename Graph<V, W>::Edge>::iterator i = this->adjList[rt].begin(); i != this->adjList[rt].end(); ++i){
		if(state[i->d] == notVisited && check_cycle_visit(i->d, state)){
			return true;
		}
		else if(state[i->d] == inStack){
			return true;
		}
	}

	state[rt] = visited;
	return false;
}

template <typename V, typename W> bool Graph<V, W>::check_cycle(){
	vector<stateNode> state(this->size, notVisited);

	for(int i = 0; i < this->size; ++i){
		if(state[i] == notVisited){
			if(check_cycle_visit(i, state)){
				return true;
			}
		}
	}
	return false;
}
/* Graph Functions - END */

/* Heap Functions - START */
template <typename V, typename W> Graph<V, W>::Heap::Heap(int l, W inf, bool mh){
	this->size = l;
	minHeap = mh;

	for(int i = 0; i < this->size; ++i){
		a.push_back(Node(i, inf));
		pos.push_back(i);
	}
}

template <typename V, typename W> void Graph<V, W>::Heap::top_down_heapify(int i){
	int l = left(i), r = right(i);
	int j = i;
	while(r < this->size){
		j = (compare(a[l].priority, a[r].priority) ? l : r);

		if(compare(a[i].priority, a[j].priority)){
			break;
		}
		else{
			swap(a[i], a[j]);
			i = j;
			l = left(i);
			r = right(i);
		}
	}

	if(l == this->size-1 && compare(a[l].priority, a[j].priority)){
		swap(a[l], a[j]);
	}
}

template <typename V, typename W> void Graph<V, W>::Heap::update(int i, W k){
	if(compare(a[pos[i]].priority, k)){
		a[pos[i]].priority = k;
		top_down_heapify(pos[i]);
	}
	else{
		a[pos[i]].priority = k;
		bottom_up_heapify(pos[i]);
	}
}

template <typename V, typename W> int Graph<V, W>::Heap::top(){
	swap(a[0], a[--this->size]);
	top_down_heapify(0);
	return a[this->size].v;
}

template <typename V, typename W> void Graph<V, W>::Heap::bottom_up_heapify(int i){
	int p = parent(i);
	while(p > 0){
		if(compare(a[i].priority, a[p].priority)){
			swap(a[p], a[i]);
			i = p;
			p = parent(i);
		}
		else{
			break;
		}
	}

	if(compare(a[i].priority, a[p].priority)){
		swap(a[p], a[i]);
	}
}
/* Heap Functions - END */

template <typename V, typename W> class UndirectedGraph : public Graph<V, W>{
	protected:
		//Struct required for kruskal's algorithm. Since local template structs not allowed, its defined here
		struct kruskalEdge{
			int n1, n2;
			W wt;

			static bool lessThan(kruskalEdge e1, kruskalEdge e2){
				return e1.wt < e2.wt;
			}

			static bool greaterThan(kruskalEdge e1, kruskalEdge e2){
				return e1.wt > e2.wt;
			}

			kruskalEdge(int a, int b, int w){
				n1 = a;
				n2 = b;
				wt = w;
			}
		};
	public:
		UndirectedGraph(W x) : Graph<V, W>(x) {}
		void insert_edge(V node1, V node2, W wt = 1);
		void span_tree_prim(V rt, bool min = true);
		void span_forest_kruskal(bool min = true);
};

template <typename V, typename W> void UndirectedGraph<V, W>::insert_edge(V node1, V node2, W wt){
	Graph<V, W>::insert_edge(node1, node2, wt);
	Graph<V, W>::insert_edge(node2, node1, wt);
}

template <typename V, typename W> void UndirectedGraph<V, W>::span_tree_prim(V rt, bool min){
	int root = this->vertices[rt];
	int newInf = this->INF * ((min) ? 1 : -1);
	vector<bool> visit(this->size, true);
	typename Graph<V, W>::Heap m(this->size, newInf, min);
	vector<W> connEdge(this->size, newInf);
	vector<int> pi(this->size);

	m.update(root, 0);
	pi[root] = root;
	connEdge[root] = 0;

	for(int i = 0; i < this->size; ++i){
		root = m.top();
		visit[root] = false;
		if(connEdge[root] == newInf) break;	//All connected nodes have been visited

		for(typename vector<typename Graph<V, W>::Edge>::iterator j = this->adjList[root].begin(); j != this->adjList[root].end(); ++j){
			if(visit[j->d] && ((min) ? (j->wt < connEdge[j->d]) : (j->wt > connEdge[j->d]))){
				connEdge[j->d] = j->wt;
				m.update(j->d, connEdge[j->d]);
				pi[j->d] = root;
			}
		}
	}

	for(int i = 0; i < this->size; ++i){
		if(connEdge[i] != newInf)
			cout<<"Node: "<<this->invVertices[i]<<"\t Edge Weight: "<<connEdge[i]<<"\t Pi("<<this->invVertices[i]<<"): "<<this->invVertices[pi[i]]<<endl;
	}
}

template <typename V, typename W> void UndirectedGraph<V, W>::span_forest_kruskal(bool min){
	vector<kruskalEdge> edgeList;

	int temp = 0;
	for(typename vector<vector<typename Graph<V, W>::Edge> >::iterator i = this->adjList.begin(); i != this->adjList.end(); ++i, ++temp){
		for(typename vector<typename Graph<V, W>::Edge>::iterator j = i->begin(); j != i->end(); ++j){
			if(j->d >= temp){
				kruskalEdge newEdge(temp, j->d, j->wt);
				edgeList.push_back(newEdge);
			}
		}
	}

	sort(edgeList.begin(), edgeList.end(), ((min) ? (kruskalEdge::lessThan) : (kruskalEdge::greaterThan)));

	vector<int> compSize(this->size, 1);	//Size of each component
	vector<int> getComp;	//Keeping track of the component each vertex belongs to
	vector<vector<kruskalEdge> > spanForest(this->size);	//Keeping track of trees

	for(int i = 0; i < this->size; ++i){
		getComp.push_back(i);
	}

	for(typename vector<kruskalEdge>::iterator i = edgeList.begin(); i != edgeList.end(); ++i){
		if(getComp[i->n1] != getComp[i->n2]){
			int minSizeComp = getComp[i->n1], maxSizeComp = getComp[i->n2];
			if(compSize[minSizeComp] > compSize[maxSizeComp]){
				minSizeComp = getComp[i->n2];
				maxSizeComp = getComp[i->n1];
			}

			compSize[maxSizeComp] += compSize[minSizeComp];
			compSize[minSizeComp] = 0;

			for(typename vector<kruskalEdge>::iterator j = spanForest[minSizeComp].begin(); j != spanForest[minSizeComp].end(); ++j){
				spanForest[maxSizeComp].push_back(*j);
				getComp[j->n1] = maxSizeComp;
				getComp[j->n2] = maxSizeComp;
			}
			spanForest[minSizeComp].clear();
			//Adding the new edge
			spanForest[maxSizeComp].push_back(*i);
			getComp[i->n1] = maxSizeComp;
			getComp[i->n2] = maxSizeComp;
		}
	}
	int ans = 0;
	for(int i = 0; i < this->size; ++i){
		if(compSize[i]){
			for(typename vector<kruskalEdge>::iterator j = spanForest[i].begin(); j != spanForest[i].end(); ++j){
				ans+=j->wt;
				// cout<<"Node 1: "<<this->invVertices[j->n1]<<"\t Node 2: "<<this->invVertices[j->n2]<<"\t Edge Weight: "<<j->wt<<endl;
			}
		}
	}
	cout<<ans<<endl;
}

template <typename V, typename W> class DAG : public Graph<V, W>{
	public:
		void insert_edge(V src, V dest, W wt = 1);
		DAG(W x) : Graph<V, W>(x) {}
		void topological_sort();
};

template <typename V, typename W> void DAG<V, W>::insert_edge(V src, V dest, W wt){
	// Graph<V, W>::insert_edge(src, dest, wt);
	DAG<V, W> temp = *this;
	temp.Graph<V, W>::insert_edge(src, dest, wt);

	if(temp.check_cycle()){
		cout<<"Unable to add edge ("<<src<<", "<<dest<<", "<<wt<<") to DAG!\n";
		// this->adjList[this->vertices[src]].pop_back();
	}
	else{
		Graph<V, W>::insert_edge(src, dest, wt);
	}
}

template <typename V, typename W> void DAG<V, W>::topological_sort(){
	vector<int> topologicalSort(Graph<V, W>::vertices_increasing_finish_time());
	for(vector<int>::reverse_iterator i = topologicalSort.rbegin(); i != topologicalSort.rend(); ++i){
		cout<<this->invVertices[*i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	UndirectedGraph<int, int> a(numeric_limits<int>::max());
	for(int i=0;i<=n;i++){
		a.insert_node(i);
	}
	int x,y,w;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		a.insert_edge(x,y,w);
	}
	a.span_forest_kruskal();

	return 0;
}
