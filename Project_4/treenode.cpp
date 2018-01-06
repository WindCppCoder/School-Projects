#include"treenode.h"

TreeNode::TreeNode(){
	Hotspot HotSpot;
	Left = NULL;
	Right = NULL;
}

TreeNode::TreeNode(const Hotspot &hSpot, TreeNode* left, TreeNode* right){
	Hotspot HotSpot;
	HotSpot = hSpot;
	Left = left;
	Right = right;
}

bool operator < (const TreeNode & lt, const TreeNode & rt){
	if (lt.HotSpot < rt.HotSpot){
		return true;
	}
	else
		return false;
}

bool operator < (const TreeNode & lt, int id){
	if (lt.HotSpot < id){
		return true;
	}
	else
		return false;
}

bool operator > (const TreeNode & lt, int id){
	if (lt.HotSpot > id){
		return true;
	}
	else
		return false;
}

bool operator == (const TreeNode & lt, int rt){
	if (lt.HotSpot == rt){
		return true;
	}
	else
		return false;
}

bool operator == (const TreeNode & lt, const TreeNode & rt){
	if (lt.HotSpot == rt.HotSpot){
		return true;
	}
	else
		return false;
}
