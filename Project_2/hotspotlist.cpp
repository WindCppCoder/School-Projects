#include"hotspotlist.h"
using namespace std;

	HotspotList::HotspotList() { }
	
	int HotspotList::write(ofstream& s){
		int Rec_Num = 0;
		if (hotspotlist.head == NULL){
			s << "Hotspot List was empty, \n Please try again \n";
			return (0);
		}
		Hotspot* Curr = hotspotlist.head;
		else {
			while (Curr->next != hotspotlist.head){
				//s << Hotspot.ObjectID << "," << Hotspot.Boro << "," << Hotspot.Wifi_Type << "," << Hotspot.Provider << "," << Hotspot.Loc_Name << "," << Hotspot.Loc_Address << "," << Hotspot.Lati << "," << Hotspot.Longi << "," << Hotspot.SSID << "\n";	hoping Curr.print is equivalent
				Curr.print(s); //Curr points to a Hotspot record object, it should be calling the print function for that object Curr is currently pointing towards
				Curr = Curr->next; //Curr now points to the Hotspot record the previous (at the stage of .print) had the pointer .next pointing towards
				Rec_Num++;
			}
			Curr.print(s);	//Curr is pointing towards the last Hotspot record in HotspotList, so have to print that last one out
			Rec_Num++;
			return (Rec_Num);
		}
	}
	
	double HotspotList::distance(double Lat, double Lon, double dist, ofstream& s){
		const double R = 6372.8		//radius of the dearth in km
		const double TO_RAD = M_PI / 180.0;	//conversion of degrees to rads
		string Bor, Wif, Pro, Loc_Na, Loc_Ad, SSI;
		int ID;
		double Lati, Long, Dista;
		
		Hotspot* Curr = hotspotlibrary.head;
		while (Curr->next != hotspotlibrary.tail){
			Hotspot copy(Curr);
			copy.get(ID, Bor, Wif, Pro, Loc_Na, Loc_A, Lati, Long, SSI);
			double haversine ( double Lat, double Lon, double Lati, double Long){
				Lat = TO_RAD * Lat;
				Lati = TO_RAD * Lati;
				double dLat = (Lati - Lat) /2;
				double dLon = (Long - Lon) /2;
				double a = sin(dLat);
				double b = sin(dLon);
				
				Dista = (2 * R * asin(sqrt(a*a + cos(Lat) * cost(Lati) * b *b)));
			}
			if (Dista < dist){
				copy.printID(s);
			}
			Curr = Curr->next;
		}
		
		
	}
	
	int HotspotList::insert(const Hotspot & to_Be_Inserted){
		if (hotspotlist.head == NULL){	//handles if inserting the first Hotspot Record into an empty HotspotList
			hotspotlist.head = to_Be_Inserted;
			hotspotlist.tail = to_Be_Inserted;
			to_Be_Inserted->next = hotspotlist.head;
			to_Be_Inserted->prev = hotspotlist.head;
			return(1);
		}

		if (to_Be_Inserted < hotspotlist.head){//handles if inserting into the first "slot" of a non-empty List
//look at the friend functions in hotspotlist.h to understand why you didn't put .ObjectId in here
			to_Be_Inserted->next = hotspotlist.head;
			hotspotlist.head = to_Be_Inserted;
			to_Be_Inserted->next->prev = to_Be_Inserted;
			to_Be_Inserted->prev = hotspotlist.tail;
			return(1);
		}
		
		if (hotspotlist.tail < to_Be_Inserted){//handles if inserting into the last slot of a non-empty List
			to_Be_Inserted->prev = hotspotlist.tail;
			to_Be_Inserted->next = hotspotlist.head;
			hotspotlist.tail->next = to_Be_Inserted;
			hotspotlist.tail = to_Be_Inserted;
			return(1);
		}
		Hotspot* Curr = hotspotlist.head->next;//starts Curr at the second element in the linked List
		while (Curr->next != HotspotList.head->next){	//while Curr.next is not pointing to the second element in the List i.e. Curr is at the start of the linked list
			if (to_Be_Inserted == Curr){	//if the record to be inserted is equal to any record currently in HotspotList; it will not be inserted
				return(0);
			}
			if (to_Be_Inserted < Curr){
				to_Be_Inserted->prev = Curr->prev;
				to_Be_Inserted->next = Curr;
				to_Be_Inserted->prev->next = to_Be_Inserted;
				Curr->prev = to_Be_Inserted;
				return(1);
			}
			else (
				Curr = Curr->next;
			)
		}
		return(0);
	}

	int HotspotList::insert(const HotspotList & hlist, bool isSorted){
		if (isSorted){
			if (hotspotlist.head == NULL){		//start of block dealing with if HotspotList is empty
				hotspotlist.head = hlist.head;
				hotspotlist.head = hlist.tail;
				
				if (hlist.head == NULL){
					return(0);
				}
				else(if hlist.head == hlist.tail){
					hotspotlist.head = hlist.head;
					hotspotlist.tail = hlist.tail;
					return(1);
				}
				else(){
					int track = 1;
					Hotspot* Curr = hlist.head->next;
					while (Curr->next != hlist->next){
						Curr = Curr->next;
						track++;
					}
					return(track);
				}
			}					//end of block dealing with if HotspotList is empty
			
			else () {				//start of block which deals with a populated HotspotList
				if (hlist.head == NULL){	//if hlist is empty
					return(0);
				}
				else(if (hlist.head == hlist.tail)){	//if hlist is a single record
					if (hotspotlist.tail < hlist.head){
						hlist.head->prev = hotspotlist.tail;
						hlist.head->next = hotspotlist.head;
						hotspotlist.tail->next = hlist.head;
						hotspotlist.head->prev = hlist.head;
						hotspotlist.tail = hlist.head;
						return(1);
					}
					Hotspot* Curr = hotspotlist.head;
					if (hlist.head < Curr){
						hlist.head->next = hotspotlist.head;
						hlist.head->prev = hotspotlist.tail;
						hotspotlist.head = hlist.head;
						hotspotlist->next->prev = hotspotlist.head;
						hotspotlist->prev->next = hotspotlist.head;
						return(1);
					}
					while (Curr < hlist.head){
						Curr = Curr->next;
						if(Curr == hlist.head){
							return(0);
						}
					}
					if (hlist.head < Curr){
						hlist.head->next = Curr;
						hlist.head->prev = Curr->prev;
						Curr->prev->next = hlist.head;
						Curr->prev = hlist.head;
						return(1);
					}
				}
				else(){				//if HotspotList is populated and hlist is more than a single record
					Hotspot* Curr = hotspotlist.head;
					if (hlist.head < Curr){	//if hlist starts with a record that is already lower than the first record in HotspotList  
					// ** have not accounted for having a list with 42, 45 and inserting a 41, 43, 47 **	Consider creating something to go back from hlist.tail until hlist.tail(substitute it with something to hold nodes) < Curr.next
						int track = 1;
						Hotspot* butt = hlist.head->next;
						while (butt->next != hlist.head->next){
							butt = butt->next;
							track++;
						}
						hlist.tail->next = Curr;
						hlist.head->prev = Curr->prev;
						Curr->prev->next = hlist.head;
						Curr->prev = hlist.tail;
						hotspotlist.head = hlist.head;
						return(track);
					}
					if (hotspotlist.tail < hlist.head){	//if hlist.head is already greater than the last record of HotspotList
						int track = 1;
						Hotspot* butt = hlist.head->next;
						while (butt->next != hlist.head->next){
							butt = butt->next;
							track++;
						}
						hlist.head->prev = hotspotlist.tail;
						hlist.tail->next = hotspotlist.head;
						hotspotlist.tail->next = hlist.head;
						hotspotlist.head->prev = hlist.tail;
						hotspotlist.tail = hlist.tail;
						return(track);
					}
					else(){			//all other occurences; i.e. when inserting between records of HotspotList
						int track = 1;
						while (Curr < hlist.head){
							Curr = Curr->next;
							if(Curr == hlist.head){
								Hotspot* Butt = Curr->next;
								track = track -1;
								Curr->next->prev = Curr->prev;
								Curr->prev->next = Curr->next;
								Curr->next = NULL;
								Curr->prev = NULL;
								delete Curr;
								Curr = Butt;
							}
							track++;
						}
						if (hlist.head < Curr){
							hlist.tail->next = Curr;
							hlist.head->prev = Curr->prev;
							Curr->prev->next = hlist.head;
							Curr->prev = hlist.tail;
							return(track);
						}
					}
				}
			}
		}
		else() {		//if isSorted is false
			if(hotspotList.head == NULL){	//start of block where HotspotList is empty
				if (hlist.head == NULL){
					return(0);
				}
				if (hlist.head == hlist.tail){
					hotspotlist.head = hlist.head;
					hotspotlist.tail = hlist.tail;
					hotspotlist.head->next = hotspotlist.head;
					hotspotlist.head->prev = hotspotlist.head;
					return(1);
				}
				else (){
					int track = 0;
					Hotspot* Curre = hlist.head->next;	//starts Curre at the second record of hlist
					Hotspot* Butt = hotspotlist.head;	//starts at the very top of HotspotList
					while (Curre->prev != hlist.tail){
						if (insert (Curre) == 1){	//since calling a function which uses Curr pointer as well, made it Curre to distinguish use
							track++;
						}
						Curre = Curre->next;
					}
					if (insert(Curre) ==1){			//Curre should be at the first record of hlist
						track++;
					}
					return(track);
				}
			}				//end of block where HotspotList is empty
			
			else(){			//if HotspotList is populated by something
				if (hlist.head == NULL){
					return(0);
				}
				if (hlist.head == hlist.tail){
					if (insert(hlist.head) == 1){
						return(1);
					}
					else 
						return(0);
				}
				int track = 0;
				Hotspot* Curre = hlist.head->next;
				while (Curre->prev != hlist.tail){
					if (insert(Curre) == 1){
						track++;
					}
					Curre = Curre->next;
				}
				if (insert(Curre) == 1){
					track++;
				}
				return(track);
			}
		}
	}
	
	int HotspotList::remove(int ID){
		if (hotspotlist.head == NULL){
			return(0);
		}
		if (hotspotlist.tail.ObjectId == ID){
			hotspotlist->tail->prev->next = hotspotlist.head;//the record prev is pointing to has its "next" pointer changed so that it points to the .head
			hotspotlist.head->prev = hotspotlist.tail->prev;//the first Hotspot record in the linked List's "prev" pointer is now pointing to the Hotspot record pointed to by the HotspotList.tail
			//~HotspotList.tail();// the Hotspot record pointed to by .tail calls its own destructor
			hotspotlist.tail = hotspotlist.head->prev;//.tail is now pointing to the 'last' Hotspot record in the linked List again
			return(1);
		}
		
		Hotspot* Curr = hotspotlist.head;
		if (Curr.ObjectId == ID){
			hotspotlist.head = Curr->next;//.head now points to the second Hotspot record in the linked List
			Curr->next = NULL;
			hotspotlist.tail->next = hotspotlist.head;//.tail's "next" pointer is now pointing to the second Hotspot record in the linked List, effectively making it point to the first record in the List
			Curr->prev = NULL;
			hotspotlist.head->prev = hotspotlist.tail;//first record in the list's "prev" pointer now points to the tail of the List
			delete Curr;
			return(1);
		}
		Curr = Curr->next;
		
		while (Curr->next != hotspotlist.head->next){
			if (Curr.ObjectId == ID){
				Curr->next->prev = Curr->prev;
				Curr->prev->next = Curr->next;
				Curr->next = NULL;
				Curr->prev = NULL;
				delete Curr;
				return(1);
			}
			Curr = Curr->next;
		}
		return(0);
	}
	
	int HotspotList::size(){
		if (hotspotlist.head == NULL){
			return(0);
		}
		/**
			come back to this, not sure this one works
		*/
		if (hotspotlist.head == hotspotlist.tail){
			return(1);
		}
		
		int track = 1;
		Hotspot* Curr = hotspotlist.head->next;
		while (Curr->next != hotspotlist.head->next){
			track++;
			Curr = Curr->next;
		}
		return(track);
	}
	
	int HotspotList::retrieve(int ID, Hotspot& Hold){
		if (hotspotlist.head == NULL){
			return(0);
		}
		if (hotspotlist.head.ObjectId == ID){
			Hold = hotspotlist.head;
			return(1);
		}
		Hotspot* Curr = hotspotlist.head->next;
		while (Curr->next != hotspotlist.head->next){
			if (Curr.ObjectId == ID){
				Hold = Curr;
				return(1);
			}
		}
		return(0);
	}
	
	int HotspotList::make_empty(){
		if (hotspotlist.head == NULL){
			return(0);
		}
		if (hotspotlist.head == hotspotlist.tail){
			hotspotlist.head->next == NULL;
			hotspotlist.head->prev == NULL;
			delete hotspotlist.head;
			return(1);
		}
		
		Hotspot* Curr = hotspotlist.head;
		int track = 0;
		Curr->prev->next = NULL;
		while (Curr->next != NULL){
			Hotspot* Holder = Curr->next;
			Curr->prev = NULL;
			Curr->next = NULL;
			delete Curr;
			Curr = Holder;
			track++;
		}
		return(track);
	}
