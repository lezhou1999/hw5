#include"BetterPriorityQueue.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


#include <iostream>


bool BetterPriorityQueue::Contains(DNode node){

    pQueue = priority_queue::c;

    for(size_t i =0;i<pQueue.size();i++){
        if(pQueue.at(i) == node){
            return true;
        
        }
    }
    return false;

}

bool BetterPriorityQueue::Update(DNode node){


    pQueue = priority_queue::c;
    bool output = false;
    priority_queue::c.clear();

    for(size_t i =0;i<pQueue.size();i++){

        

        if(pQueue.at(i)==node && pQueue.at(i).pri>node.pri){

            pQueue.erase(pQueue.begin()+i);
            pQueue.push_back(node);
            output = true;

        }
            


    }

    for(size_t i =0 ; i<pQueue.size();i++){
        priority_queue::push(pQueue.at(i));
    }

    return output;

    


   
}


string BetterPriorityQueue:: ToString(){

    pQueue = priority_queue::c;
    string toString = "[";
    for (size_t i = 0; i <pQueue.size(); i++){
        toString.append("(");
        toString.push_back(pQueue.at(i).node->key);
        toString.append(": " + to_string(pQueue.at(i).pri)+")");
        if(i!=pQueue.size()-1){
            toString.append(", ");
        }
    }
    toString.append("]");
    return toString;

}

string BetterPriorityQueue:: DnodeToString(DNode thisNode){

    string toString = "(";
    toString.push_back(thisNode.node->key);
    toString.append(": " + to_string(thisNode.pri)+")");
    return toString;

}