#include"hotspot.h"

Hotspot::Hotspot(){
	ObjectId = 0;
	Boro = "";
	Type = "";
	Provider = "";
	Name = "";
	Location = "";
	Latitude = 0.0;
	Longitude = 0.0;
	SSID = "";
}

/*
	When using this constructor, put it within a try block and have the next line 'catch' (int e), if e == 0 then skip over using this constructor as the string is invalid
	also throw 0 if strings start or end with a space ' ' since they are also invalid
*/
Hotspot::Hotspot(const string str){
	istringstream iss(str);
	string firstF, secondF, thirdF, fourthF, fifthF, sixthF, seventhF, eigthF, ninthF;
	getline(iss, firstF, ',');
	getline(iss, secondF, ',');
	getline(iss, thirdF, ',');
	getline(iss, fourthF, ',');
	getline(iss, fifthF, ',');
	getline(iss, sixthF, ',');
	getline(iss, seventhF, ',');
	getline(iss, eigthF, ',');
	getline(iss, ninthF);
	
	Hotspot exception;
	for(int i = 0; i<ninthF.length(); i++){
		if (ninthF[i] == ','){
			throw exception;
		}
	}
	if (firstF[firstF.length()-1] == ' '){
		throw exception;
	}
	
	if (secondF[0] == ' ' || secondF[secondF.length()-1] == ' '){
		throw exception;
	}
	
	if (thirdF[0] == ' ' || thirdF[thirdF.length()-1] == ' '){
		throw exception;
	}
	
	if (fourthF[0] == ' ' || fourthF[fourthF.length()-1] == ' '){
		throw exception;
	}
	
	if (fifthF[0] == ' ' || fifthF[fifthF.length()-1] == ' '){
		throw exception;
	}
	
	if (sixthF[0] == ' ' || sixthF[sixthF.length()-1] == ' '){
		throw exception;
	}
	
	if (seventhF[0] == ' ' || seventhF[seventhF.length()-1] == ' '){
		throw exception;
	}
	
	if (eigthF[0] == ' ' || eigthF[eigthF.length()-1] == ' '){
		throw exception;
	}
	
	if (ninthF[0] == ' '){
		throw exception;
	}
	
	ObjectId = atoi (firstF.c_str());
	Boro = secondF;
	Type = thirdF;
	Provider = fourthF;
	Name = fifthF;
	Location = sixthF;
	Latitude = atof (seventhF.c_str());
	Longitude = atof (eigthF.c_str());
	SSID = ninthF;
}

Hotspot::Hotspot(const Hotspot& to_be_copied){
	ObjectId = to_be_copied.ObjectId;
	Boro = to_be_copied.Boro;
	Type = to_be_copied.Type;
	Provider = to_be_copied.Provider;
	Name = to_be_copied.Name;
	Location = to_be_copied.Location;
	Latitude = to_be_copied.Latitude;
	Longitude = to_be_copied.Longitude;
	SSID = to_be_copied.SSID;
}

Hotspot::Hotspot(int ID, string Borou, string Typ, string Prov, string Nam, string Loc, double Lat, double Long, string SS){
	ObjectId = ID;
	Boro = Borou;
	Type = Typ;
	Provider = Prov;
	Name = Nam;
	Location = Loc;
	Latitude = Lat;
	Longitude = Long;
	SSID = SS;
}

void Hotspot::set(int ID, string Borou, string Typ, string Prov, string Nam, string Loc, double Lat, double Long, string SS){
	ObjectId = ID;
	Boro = Borou;
	Type = Typ;
	Provider = Prov;
	Name = Nam;
	Location = Loc;
	Latitude = Lat;
	Longitude = Long;
	SSID = SS;
}

void Hotspot::get(int& ID, string& Borou, string& Typ, string& Prov, string& Nam, string& Loc, double& Lat, double& Long, string& SS){
	ID = ObjectId;
	Borou = Boro;
	Typ = Type;
	Prov = Provider;
	Nam = Name;
	Loc = Location;
	Lat = Latitude;
	Long = Longitude;
	SS = SSID;
}

void Hotspot::get_int(int& ID){
	ID = ObjectId;
}

void Hotspot::get_lat_lon(double& lat, double& lon){
	lat = Latitude;
	lon = Longitude;
}

void Hotspot::get_boro(string& temp){
	temp = Boro;
}

void Hotspot::set_int(int ID){
	ObjectId = ID;
}

void Hotspot::print(ostream& s){
	s << ObjectId << ',' << Boro << ',' << Type << ',' << Provider << ',' << Name << ',' << Location << ',' << Latitude << ',' << Longitude << ',' << SSID << "\n";
}

void Hotspot::print(){
	cout << ObjectId << ',' << Boro << ',' << Type << ',' << Provider << ',' << Name << ',' << Location << ',' << Latitude << ',' << Longitude << ',' << SSID << "\n";
}

double Hotspot::calc_dist(double lat1, double lon1, double lat2, double lon2){
	const double R = 6372.8;
	const double TO_RAD = M_PI / 180.0;
	lat1 = TO_RAD * lat1;
	lat2 = TO_RAD * lat2;
	lon1 = TO_RAD * lon1;
	lon2 = TO_RAD * lon2;
	double dLat = (lat2 - lat1)/2;
	double dLon = (lon2 - lon1)/2;
	double a = sin(dLat);
	double b = sin(dLon);
		
	return 2*R*asin(sqrt(a*a+cos(lat1)*cos(lat2)*b*b));
}

bool operator < (const Hotspot& lt, const Hotspot& rt){
	if (lt.ObjectId < rt.ObjectId){
		return true;
	}
	else
		return false;
}

bool operator < (const Hotspot& lt, int id){
	if (lt.ObjectId < id){
		return true;
	}
	else
		return false;
}

bool operator > (const Hotspot & lt, int id){
	if (lt.ObjectId > id){
		return true;
	}
	else
		return false;
}

bool operator == (const Hotspot& lt, int rt){
	if (lt.ObjectId == rt){
		return true;
	}
	else
		return false;
}

bool operator == (const Hotspot& lt, const Hotspot& rt){
	if (lt.ObjectId == rt.ObjectId){
		return true;
	}
	else
		return false;
}



