#include"Graph.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;


#include <iostream>

Graph ::~Graph(){

    for(size_t i = 0 ;i<nodes.size();i++){
        delete nodes.at(i);
    }
    for(size_t i = 0 ;i<graph.size();i++){
        for(size_t j = 0 ;j<graph[i].size();j++){
        delete graph.at(i).at(j);
        }
    }

}

GraphNode * Graph:: AddNode(char key, int data){
    for(size_t i = 0;i<nodes.size();i++){
        if(nodes.at(i)->key==key){
            throw invalid_argument("node already exist.");
        }
    }
        
    GraphNode *graphNode = new GraphNode{key,data};
    nodes.push_back(graphNode);
    graph.push_back({});
    return graphNode;


}
		
        
GraphEdge * Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    bool have = false;

        
    for(size_t i = 0;i<nodes.size();i++){
        if(nodes.at(i)->key==gn1->key){
           have = true;
        }
        if (nodes.at(i)->key==gn2->key){
            have = true;
        }
    }
    if(have == false ){
        throw invalid_argument("egde already exist");
    }
    GraphEdge *edges = new GraphEdge{gn1,gn2,weight};
    for(size_t i = 0; i < graph.size();i++){
        if(nodes.at(i)->key == gn1->key){
            graph[i].push_back(edges);
        }
    }
    return edges;

}
		
string Graph:: NodesToString() const{

    string nodeString = "[";
    for(size_t i = 0; i<nodes.size()-1;i++){
        nodeString = nodeString+"(";
        nodeString.push_back(nodes.at(i)->key);
        nodeString = nodeString+":" + std::to_string(nodes.at(i)->data)+"), ";
        }
        
        nodeString = nodeString+"(";
        nodeString.push_back(nodes.at(nodes.size()-1)->key);
        nodeString = nodeString+":" + std::to_string(nodes.at(nodes.size()-1)->data)+")]";

    return nodeString;

    }
string Graph :: ToString() const{

    string tostring="";
    for(size_t i =0;i<graph.size();i++){
        tostring.push_back(nodes.at(i)->key);
        tostring+= " | ";
        for(size_t j =0;j<graph.at(i).size();j++){
            tostring.append("[(");
            tostring.push_back(graph.at(i).at(j)->from->key);
            tostring.append(":"+to_string(graph.at(i).at(j)->from->data)+")->(");
            tostring.push_back(graph.at(i).at(j)->to->key);
            tostring.append(":"+to_string(graph.at(i).at(j)->to->data)+") w:"+to_string(graph.at(i).at(j)->weight)+"]");
            
            if(j!=graph.at(i).size()-1){tostring+=", ";}
            //ask wenrong how to not add last ", "
        }
        
            


        tostring.append("\n");
    }
    return tostring;
}



string Graph:: GraphNodeToString(const GraphNode *gn){
    string nodeToString="(";
    nodeToString.push_back(gn->key);
    nodeToString.append( ":" + to_string(gn->data) + ")");
    return nodeToString;

}
string Graph:: GraphEdgeToString(const GraphEdge *ge){

    string edgeToString="[(";
    edgeToString.push_back(ge->from->key);
    edgeToString.append( ":" + to_string(ge->from->data) + ")->(");
    edgeToString.push_back(ge->to->key);
    edgeToString.append( ":" + to_string(ge->to->data) + ") w:"+to_string(ge->weight)+"]");
    return edgeToString;

}
		
const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{

    int idx = 0;
    for(size_t i=0;i<nodes.size();i++){
        if(nodes.at(i)->key==gn->key && nodes.at(i)->data==gn->data){
            for(size_t i =0;i<graph.size();i++){
                if(nodes.at(i)->key==gn->key){
                    idx = i;
                }   
            }   
        }else{
            throw invalid_argument("node is not exist");
        }
    }
   
    
    return graph.at(idx);

}


const vector<GraphNode*>& Graph::GetNodes() const{
    return nodes;

}

const GraphNode* Graph ::NodeAt(unsigned int idx) const{
    if(idx<0||idx>=nodes.size()){
        throw invalid_argument("invalid input of idx");
    }
    
    return nodes.at(idx);

}		
size_t Graph:: Size() const{

    size_t count=0;
    for(size_t i =0 ;i < graph.size();i++){
        for(size_t j = 0 ; j < graph.at(i).size();j++){
            count++;
        }
    }
    return count;

}// the number of edges
size_t Graph::Order() const{
    return nodes.size();

} // the number of nodes
