#include"hotspot.h"
using namespace std;

	Hotspot::Hotspot() {}
	
	Hotspot::Hotspot(string line) {
		string string1, string2, string3, string4, string5, string6, string7, string8, string9, stringHold;
		int ObjectID, start;
		double Lat, Long;
		for (int i = 0; i < line.length(); i++){
			if (string5 != "" && string6 == "" && line[i-11] == '.' && line[i-14] == ','){
				line.copy(stringHold, ((i-start)-14), start);
				string6 = stringHold;
				start = i-14;
				line.copy(stringHold, (i-start), start);
				string7 = stringHold;
				start = i;
				continue;
			}
			if (string5 != "" && string6 == "" && line[i] == ','){
				continue;
			}
			if (line[i] == ','){
				line.copy(stringHold, (i-start), start);
				start = i;
			}
			if (string1 == ""){
				string1 = stringHold;
				continue;
			}
			if (string2 == ""){
				string2 = stringHold;
				continue;
			}
			if (string3 == ""){
				string3 = stringHold;
				continue;
			}
			if (string4 == ""){
				string4 = stringHold;
				continue;
			}
			if (string5 == ""){
				string5 = stringHold;
				continue;
			}
			if (string8 == ""){
				string8 = stringHold;
				continue;
			}
			if (string9 == ""){
				string9 = stringHold;
			}
		}
		
		ObjectID = atoi(string1.c_str());
		Lat = atof (string7.c_str());
		Long = atof (string8.c_str());
		
		ObjectId = ObjectID;
		Boro = string2;
		Wifi_Type = string3;
		Provider = string4;
		Loc_Name = string5;
		Loc_Address = string6;
		Lati = Lat;
		Long = Long;
		SSID = string9;
	}
	
	Hotspot::Hotspot(const Hotspot& Hspot){
	ObjectId = Hspot.ObjectId;
	Boro = Hspot.Boro;
	Wifi_Type = Hspot.Wifi_Type;
	Provider = Hspot.Provider;
	Loc_Name = Hspot.Loc_Name;
	Loc_Address = Hspot.Address;
	Lati = Hspot.Lati;
	Longi = Hspot.Longi;
	SSID = Hspot.SSID;
		
	}
	
	Hotspot::Hotspot (int ID, string Borough, string Wifi_Typ, string Prov, string Loc_N, string Loc_A, double Lat, double Long, string SS){
		ObjectId = ID;
		Boro = Borough;
		Wifi_Type = Wifi_Typ;
		Provider = Prov;
		Loc_Name = Loc_N;
		Loc_Address = Loc_A;
		Lati = Lat;
		Longi = Long;
		SSID = SS;
	}
	
	void Hotspot::set(int ID, string Borough, string Wifi_Typ, string Prov, string Loc_N, string Loc_A, double Lat, double Long, string SS){
		ObjectId = ID;
		Boro = Borough;
		Wifi_Type = Wifi_Typ;
		Provider = Prov;
		Loc_Name = Loc_N;
		Loc_Address = Loc_A;
		Lati = Lat;
		Longi = Long;
		SSID = SS;
	}
	
	void Hotspot::get(int& ID, string& Borough, string& Wifi_Typ, string& Prov, string& Loc_N, string& Loc_A, double& Lat, double& Long, string& SS){
		ID = ObjectId;
		Borough = Boro;
		Wifi_Typ = Wifi_Type;
		Prov = Provider;
		Loc_N = Loc_Name;
		Loc_A = Loc_Address;
		Lat = Lati;
		Long = Longi;
		SS = SSID;
	}
	
	void Hotspot::print(ofstream& s){
		s << ObjectId << "," << Boro << "," << Wifi_Type << "," << Provider << "," << Loc_Name << "," << Loc_Address << "," << Lati << "," << Longi << "," << SSID << "\n";
	}
	
	void Hotspot::printID(ofstream& s){
		s << ObjectId << "\n";
	}
	
	bool operator < (const Hotspot & lt, const Hotspot & rt){
		if (lt.ObjectId < rt.ObjectId){
			return(true);
		}
		return false;
	}
	
	bool operator == (const Hotspot & lt, const Hotspot & rt){
		if (lt.ObjectId == rt.ObjectId){
			return(true);
		}
		return false;
	}
	
	bool operator == (const Hotspot & lt, int ID){
		if (lt.ObjectId == ID){
			return(true);
		}
		return false;
	}
	
	bool operator != (const Hotspot & lt, const Hotspot & rt){
		if (lt.ObjectId != rt.ObjectId){
			return(true);
		}
		return false;
	}
