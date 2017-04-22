#include "iostream"
#include "array"
#include "queue"

using namespace std;
array<array<int,20>, 20> map;

struct Edge
{
	int s, t, next;
};


int *level_;
int *head_;
Edge *edge_;
int node_number_;
int count_;

int main(int arg, char * args[]) {

	int **adj_table;
	int node_count;
	initGraph(adj_table,node_count);

	return -1;
}

void addEdge(int s, int t, int flow)
{
	//正向边
	edge_[count_].s = s;
	edge_[count_].t = t;
	edge_[count_].next = head_[s];
	head_[s] = count_++;
	//反向边
	edge_[count_].s = t;
	edge_[count_].t = s;
	edge_[count_].next = head_[t];
	head_[t] = count_++;
}

void initGraph(int **adj_table, int nodeCount)
{
	memset(head_, -1, nodeCount * sizeof(int));
	memset(edge_, -1, 2 * nodeCount * sizeof(int));
	count_ = 0;
	for (int i = 0; i<nodeCount; i++)
	{
		for (int j = 0; j<nodeCount; j++)
		{
			if (i != j && adj_table[i][j] != 0)
			{
				addEdge(i, j, adj_table[i][j]);
			}
		}
	}
}

bool bfsLevel(int startnode, int endnode) {
	if (startnode == endnode) { return false; }
	std::queue<int> mqueue;
	while (!mqueue.empty())
		mqueue.pop();
	memset(level_, -1, node_number_ * sizeof(int));
	mqueue.push(startnode);
	while (!mqueue.empty()) {
		int cur_start_node = mqueue.front(); mqueue.pop();
		if (cur_start_node == endnode) return true;
		for (int cur_edge = head_[cur_start_node];
			cur_edge != -1; cur_edge = edge_[cur_edge].next) {
			int cur_t = edge_[cur_edge].t;
			if (level_[cur_t] == -1)
			{
				level_[cur_t] = level_[cur_start_node] + 1;
				mqueue.push(cur_t);
			}
		}
	}
	return false;
}