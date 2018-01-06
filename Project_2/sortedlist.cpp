//#include"sortedlist.h"
using namespace std;
	
	template<class T>
	SortedList <T>::SortedList();
	
	template<class T>
	int SortedList <T>::insert(const T & to_Be_Inserted){
		if (SortedList.head == NULL){	//handles if inserting the first Hotspot Record into an empty HotspotList
			SortedList.head = to_Be_Inserted;
			SortedList.tail = to_Be_Inserted;
			to_Be_Inserted->next = SortedList.head;
			to_Be_Inserted->prev = SortedList.head;
			return(1);
		}

		if (to_Be_Inserted < SortedList.head){//handles if inserting into the first "slot" of a non-empty List
//look at the friend functions in hotspotlist.h to understand why you didn't put .ObjectId in here
			to_Be_Inserted->next = SortedList.head;
			SortedList.head = to_Be_Inserted;
			to_Be_Inserted->next->prev = to_Be_Inserted;
			to_Be_Inserted->prev = SortedList.tail;
			return(1);
		}
		
		if (SortedList.tail < to_Be_Inserted){//handles if inserting into the last slot of a non-empty List
			to_Be_Inserted->prev = SortedList.tail;
			to_Be_Inserted->next = SortedList.head;
			SortedList.tail->next = to_Be_Inserted;
			SortedList.tail = to_Be_Inserted;
			return(1);
		}
		Hotspot* Curr = SortedList.head->next;//starts Curr at the second element in the linked List
		while (Curr->next != SortedList.head->next){	//while Curr.next is not pointing to the second element in the List i.e. Curr is at the start of the linked list
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
	
	template<class T>
	 int SortedList <T>::remove(int ID){
		if (SortedList.head == NULL){
			return(0);
		}
		if (SortedList.tail.ObjectId == ID){
			SortedList.tail->prev->next = SortedList.head;//the record prev is pointing to has its "next" pointer changed so that it points to the .head
			SortedList.head->prev = SortedList.tail->prev;//the first Hotspot record in the linked List's "prev" pointer is now pointing to the Hotspot record pointed to by the HotspotList.tail
			//~HotspotList.tail();// the Hotspot record pointed to by .tail calls its own destructor
			SortedList.tail = SortedList.head->prev;//.tail is now pointing to the 'last' Hotspot record in the linked List again
			return(1);
		}
		
		Hotspot* Curr = SortedList.head;
		if (Curr.ObjectId == ID){
			SortedList.head = Curr->next;//.head now points to the second Hotspot record in the linked List
			Curr->next = NULL;
			SortedList.tail->next = SortedList.head;//.tail's "next" pointer is now pointing to the second Hotspot record in the linked List, effectively making it point to the first record in the List
			Curr->prev = NULL;
			SortedList.head->prev = SortedList.tail;//first record in the list's "prev" pointer now points to the tail of the List
			delete Curr;
			return(1);
		}
		Curr = Curr->next;
		
		while (Curr->next != SortedList.head->next){
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
	
	template<class T>
	 int SortedList <T>::size(){
		if (SortedList.head == NULL){
			return(0);
		}
		/**
			come back to this, not sure this one works
		*/
		if (SortedList.head == SortedList.tail){
			return(1);
		}
		
		int track = 1;
		Hotspot* Curr = SortedList.head->next;
		while (Curr->next != SortedList.head->next){
			track++;
			Curr = Curr->next;
		}
		return(track);
	}
	
	template<class T>
	 int SortedList <T>::make_empty(){
		if (SortedList.head == NULL){
			return(0);
		}
		if (SortedList.head == SortedList.tail){
			SortedList.head->next = NULL;
			SortedList.head->prev = NULL;
			delete SortedList.head;
			return(1);
		}
		
		Hotspot* Curr = SortedList.head;
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
