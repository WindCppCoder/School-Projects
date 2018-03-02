#include"tree.h"

//not finished
Tree::Tree(const string& treedata){
	string temp;
	temp = treedata;
	string first, second, third, fourth, fifth, sixth, seventh, eigth, ninth, tenth; //order to take from input string: second, third, fourth, fifth, first, sixth, eigth, seventh, ninth, tenth
	//15th column has " "
	
	istringstream ss(temp);
	getline(ss, second, ',');	//at the second column after this
	for (int i = 0; i < 2; i++){
		ss.ignore(256,',');
	}				//at the fourth column after this
	getline(ss, third, ',');	//at the fifth column after this
	for (int i = 0; i < 2; i++){
		ss.ignore(256,',');
	}				//at the seventh column after this
	getline(ss, fourth, ',');	//at the eigth column after this
	getline(ss, fifth, ',');	//at the ninth column after this
	ss.ignore(256,',');		//at the tenth column after this
	getline(ss, first, ',');	//at the eleventh column after this
	for (int i = 0; i < 4; i++){
		ss.ignore(256,',');
	}				//at the 15th column after this (column with possible " " marks)
	char single;
	if (ss.get(single) == "\"")
		ss.ignore(256,'"');	//passed the quotation marks of the 15th column, at the 16th column after this
	else {
		ss.ignore(256,',');	//passed the 15th column but had no quotation marks
	}
	for (int i = 0; i < 9; i++){
		ss.ignore(256, ',');
	}				//at the 25th column after this
	getline(ss, sixth, ',');	//at the 26th column after this
	getline(ss, eigth, ',');	//at the 27th column after this
	for (int i = 0; i < 3; i++){
		ss.ignore(256, ',');
	}				//at the 30th column after this
	getline(ss, seventh, ',');	//at the 31st column after this
	for (int i = 0; i < 7; i++){
		ss.ignore(256, ',');
	}				//at the 38th column after this
	getline(ss, ninth, ',');	//at the 39th column after this
	getline(ss, tenth, ',');	//at the 40th column after this; but this should be the final parameter
	
	//assign all values correctly; may need to modify strings: second, third, eigth, ninth and tenth into proper values
	species = first;

	ID = atoi(second.c_str());

	dbh = atoi(third.c_str());
	
	
	status = fourth;
	health = fifth;
	address = sixth;
	boro = seventh;
	

	zipcode = atoi(eigth.c_str());

	lat = atof(ninth.c_str());

	longi = atof(tenth.c_str());
	
}

ostream& operator << (ostream & os, const Tree & t){
	os << t.species << "," << t.ID << "," << t.dbh << "," << t.status << "," << t.health << "," << t.address << "," << t.boro << "," << t.zipcode << "," << t.lat << "," << t.longi << endl;
}

string Tree::write(){
	stringstream temp;
	temp << species << "\t" << ID << "\t" << dbh << "\t" << status << "\t" << health << "\t" << address << "\t" << boro << "\t" << zipcode << "\t" << lat << "\t" << longi;
	string hold;
	hold = temp.str();
	return hold;
}
