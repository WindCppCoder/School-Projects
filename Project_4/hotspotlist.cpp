#include"hotspotlist.h"

HotspotList::HotspotList(){
	
	size = 0;
	root = new TreeNode;
}

HotspotList::~HotspotList(){
	if (root != NULL){
		TreeNode* r;
		r = root;
		make_empty(r);
	}
}

int HotspotList::write(ostream & x, TreeNode* stem){

	if (stem == NULL){
		return 0;
	}
	int countLeft, countRight;
	countLeft = write(x, stem->Left);
	stem->HotSpot.print(x);
	countRight = write(x, stem->Right);
	
	return 1+countLeft+countRight;
}


int HotspotList::insert(const Hotspot& to_be_inserted, TreeNode* stem){
	TreeNode* new_ptr;
	
	new_ptr = new TreeNode();
	
	new_ptr->HotSpot = to_be_inserted;
	
	if (*new_ptr == *stem){
		return 0;
	}
	
	if (stem->HotSpot == 0){
		*stem = *new_ptr;
		stem->HotSpot.print();
		update_size(1);
		return 1;
	}
	
	if (*new_ptr < *stem){
		if (stem->Left == NULL){
			stem->Left = new_ptr;
			update_size(1);
			return 1;			
		}
		
		else {
			delete new_ptr;
			new_ptr = NULL;
			return insert(to_be_inserted, stem->Left);
		}
	}
	else{
		if (stem->Right == NULL){
			stem->Right = new_ptr;
			update_size(1);
			return 1;
		}
		
		else{
			delete new_ptr;
			new_ptr = NULL;
			return insert(to_be_inserted, stem->Right);
		}
	}
}
int HotspotList::insert_node(const TreeNode* hold){
	if (hold->Left != NULL && hold->Right != NULL){
		insert(hold->HotSpot, root);
		return 1+insert_node(hold->Left) + insert_node(hold->Right);
	}
	if (hold->Left == NULL && hold->Right != NULL){
		insert(hold->HotSpot, root);
		return 1+insert_node(hold->Right);
	}
	if (hold->Left != NULL && hold->Right == NULL){
		insert(hold->HotSpot, root);
		return 1+insert_node(hold->Left);
	}
	if (hold->Left == NULL && hold->Right == NULL){
		insert(hold->HotSpot, root);
		return 1;
	}
}

int HotspotList::insert(const HotspotList & hlist){
	if (hlist.root == NULL){
		return 0;
	}
	if (hlist.root->Left != NULL && hlist.root->Right != NULL){
		return insert_node(hlist.root->Left) + insert_node(hlist.root->Right);
	}
	if (hlist.root->Left != NULL && hlist.root->Right == NULL){
		return insert_node(hlist.root->Left);
	}
	if (hlist.root->Left == NULL && hlist.root->Right != NULL){
		return insert_node(hlist.root->Right);
	}
	if (hlist.root->Left == NULL && hlist.root->Right == NULL){
		return insert(hlist.root->HotSpot, root);
	}
	
}

Hotspot HotspotList::findLowest(TreeNode*& h){
	if (h->Left == NULL && h->Right == NULL){
		Hotspot temp;
		temp = h->HotSpot;
		delete h;
		h = NULL;
		return temp;
	}
	if (h->Left == NULL && h->Right != NULL){
		Hotspot temp;
		temp = h->HotSpot;
		h = h->Right;
		return temp;
		
	}
	if (h->Left != NULL){
		return findLowest(h->Left);
	}
}

int HotspotList::remove(int ID, TreeNode*& x){
	if (x == NULL){
		return 0;
	}
	
	if (*x == ID && (x->Right != NULL && x->Left == NULL)){
		Hotspot temp;
		temp = findLowest(x);
		x->HotSpot = temp;
		update_size(-1);
		return 1;
	}
	
	if (*x == ID && (x->Right == NULL && x->Left != NULL)){
		Hotspot temp;
		temp = findLowest(x->Left);
		x->HotSpot = temp;
		update_size(-1);
		return 1;
	}
	
	if (*x == ID && (x->Right == NULL && x->Left == NULL)){
		delete x;
		x = NULL;
		update_size(-1);
		return 1;
	}
	
	if (*x < ID){
		return remove (ID, x->Right);
	}
	
	if (*x > ID){
		return remove(ID, x->Left);
	}
}

void HotspotList::update_size(int num){
	size = size + num;
}

int HotspotList::get_size(){
	return size;
}

int HotspotList::find(int ID, Hotspot& x, TreeNode* h){
	if (h == NULL){
		return 0;
	}
	if (*h == ID){
		x = root->HotSpot;
		return 1;
	}
	
	if (*h < ID){
		return find (ID, x, h->Right);
	}
	
	if (*h > ID){
		return find (ID, x, h->Left);
	}
}

int HotspotList::make_empty(TreeNode*& r){
	while (r->Right != NULL && r->Left != NULL){
		findLowest(r);
	}
	delete r;
	r = NULL;
}

void HotspotList::print_single(Hotspot x, ofstream& out){
	x.print(out);
}

void HotspotList::print_ID(int ID, ofstream& out){
	out << ID << "\n";
}

Hotspot HotspotList::find (const Hotspot& x){
	int i;
	Hotspot temp;
	temp = x;
	temp.get_int(i);
	if (find (i, temp, root) == 1){
		return x;
	}
	else{
		Hotspot returned;
		return returned;
	}
}

Hotspot HotspotList::findMin(){
	TreeNode* h;
	h = root;
	findMine(h);
}

Hotspot HotspotList::findMine(TreeNode* h){
	Hotspot temp;
	if (h->Left != NULL){
		return findMine(h->Left);
	}
	if (h->Left == NULL){
		temp = h->HotSpot;
		return temp;
	}
}

void HotspotList::print (ostream& out){
	out << write(out, root) << "\n";
}

void HotspotList::clear(){
	make_empty(root);
}

void HotspotList::insert (const Hotspot& x){
	insert(x, root);
}

void HotspotList::remove(const Hotspot& x){
	int i;
	Hotspot temp;
	temp = x;
	temp.get_int(i);
	remove(i, root);
}

void HotspotList::traverse(double lon, double lat, double distance, ofstream& out){
	
	in_order(root, lon, lat, distance, out);
}

void HotspotList::traverse(string& tempStr, ofstream& out){
	in_order(root, tempStr, out);
}

void HotspotList::in_order(TreeNode* r, string& tempStr, ofstream& out){
	if (r == NULL){
		return;
	}
	
	if (r->Left == NULL && r->Right == NULL){
		string temp2;
		r->HotSpot.get_boro(temp2);
		if (temp2 == tempStr){
			int tempId;
			r->HotSpot.get_int(tempId);
			print_ID(tempId, out);
		}
		return;
	}
	
	if (r->Left != NULL && r->Right == NULL){
		string temp2;
		r->HotSpot.get_boro(temp2);
		if (temp2 == tempStr){
			int tempId;
			r->HotSpot.get_int(tempId);
			print_ID(tempId, out);
		}
		in_order(r->Left, tempStr, out);
		return;
	}
	if (r->Left == NULL && r->Right != NULL){
		string temp2;
		r->HotSpot.get_boro(temp2);
		if (temp2 == tempStr){
			int tempId;
			r->HotSpot.get_int(tempId);
			print_ID(tempId, out);
		}
		in_order(r->Right, tempStr, out);
		return;
	}
}

void HotspotList::in_order(TreeNode* r, double longi, double lati, double distance, ofstream& out){
	if (r == NULL){
		return;
	}
	
	if (r->Left == NULL && r->Right == NULL){
		double tempLat, tempLon;
		r->HotSpot.get_lat_lon(tempLat, tempLon);
		if (distance > (r->HotSpot.calc_dist(lati, longi, tempLat, tempLon))){
			print_single(r->HotSpot, out);
		}
		return;
	}
	
	if (r->Left != NULL && r->Right == NULL){
		double tempLat, tempLon;
		r->HotSpot.get_lat_lon(tempLat, tempLon);
		if (distance > (r->HotSpot.calc_dist(lati, longi, tempLat, tempLon))){
			print_single(r->HotSpot, out);
		}
		in_order(r->Left, longi, lati, distance, out);
		return;
	}
	if (r->Left == NULL && r->Right != NULL){
		double tempLat, tempLon;
		r->HotSpot.get_lat_lon(tempLat, tempLon);
		if (distance > (r->HotSpot.calc_dist(lati, longi, tempLat, tempLon))){
			print_single(r->HotSpot, out);
		}
		in_order(r->Right, longi, lati, distance, out);
		return;
	}
}
