

#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

// This file is not used for part 1


//Time Complexity is O(n^2) because there is a while loop and a for loop in the while loop
int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){\

	// your code goes here
    BetterPriorityQueue BetterPQ;
    vector<GraphNode*> currentNode = g-> GetNodes();
    bool containStart = false;
    bool containEnd = false;

    //check start and end is exit or not. if start exist, give value 0 and other node's value is max number
    for(size_t i = 0; i<currentNode.size();i++){
        DNode cur;
        if(currentNode.at(i)==start){
            containStart = true;
            cur.pri = 0;
            cur.node = start;
        }else{
            if(currentNode.at(i)==end){
            containEnd = true;
            }
            cur.pri = INT_MAX;
            cur.node = currentNode.at(i);
        }
        BetterPQ.push(cur);

    }
    if(containStart==false || containEnd == false){
        return INT_MAX;
    }

    
    //key idea of dijstra 
    while (BetterPQ.top().node!=end){

        int curWeight = BetterPQ.top().pri;
        DNode curNode = BetterPQ.top();
        BetterPQ.pop();
        vector<GraphEdge*> storeEdges = g->GetEdges(curNode.node);
        for(size_t i = 0; i<storeEdges.size();i++){
            DNode adjacent;
            adjacent.node = storeEdges.at(i)->to;
            if(curWeight!= INT_MAX){
                adjacent.pri = storeEdges.at(i)->weight+ curWeight;
            }else{
                adjacent.pri = INT_MAX;
            }
            BetterPQ.Update(adjacent);

        }
    }
    return BetterPQ.top().pri;



	
}


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	cout << g->ToString() << endl;
	
	int ans = dijkstra(g->NodeAt(0), g->NodeAt(g->Order()-2), g);
	assert(ans == 20);

	delete g;
	
	
	cout << "passed!" << endl;
	
	return ans;
}


int main(){
	
	int ans = DijkstraTest();
	cout << "ans: "  << ans << endl;
	
	return 0;
}
