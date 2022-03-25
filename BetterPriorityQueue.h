#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H
#include "Graph.h"
#include <vector>

#include <string>
#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;



struct DNode {
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const {
		return node == other.node;
	}
};

class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue { 

    public:
        bool Contains(DNode node);
        bool Update(DNode node);
        string ToString();
        static string DnodeToString(DNode node);

	private:
    
    
        vector<DNode> pQueue;




};


#endif