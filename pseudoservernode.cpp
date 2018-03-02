#include"pseudoservernode.h"

PseudoServerNode::PseudoServerNode(){
	next = NULL;
	data = "";
}

PseudoServerNode::PseudoServerNode(string line){
	next = NULL;
	data = line;
}

PseudoServerNode::PseudoServerNode(string line, PseudoServerNode* connection){
	next = connection;
	data = line;
}

void PseudoServerNode::setData(string line){
	data = line;
}

void PseudoServerNode::setNode(PseudoServerNode* connection){
	next = connection;
}
