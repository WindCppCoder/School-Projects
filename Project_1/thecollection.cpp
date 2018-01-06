#include"thecollection.h"
using namespace std;

		BabyCollection::BabyCollection() { } 
		
		int BabyCollection::getLimit(){
			return Baby_Name.size()-1;
		}
		
		void BabyCollection::getCollection(int i, int &year, Gender &gender, Ethnicity &ethnicity, string &name, int &count, int &rank){
			year = Baby_Year[i];
			gender = Baby_Gender[i];
			ethnicity = Mother_Ethnicity[i];
			name = Baby_Name[i];
			count = Baby_Name_Count[i];
			rank = Baby_Name_Rank[i];
		}
		
		void BabyCollection::addCollection(string line){
		string Syear, gender, ethnicity, name, Scount, Srank;
		int startPoint = 0;
		int endPoint = 0;
		for (int i = 0; i<line.length()-1; i++){
			if ((line[i] < 'Z' && line[i] > 'A') || (line[i] > '0' && line[i] < '9') || line[i] == ' '){
				return;
			}
			else {
				endPoint = i;
			}
			if (startPoint != endPoint) {
				if (Syear == ""){
					Syear = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
				if (gender == ""){
					gender = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
				if (ethnicity == ""){
					ethnicity = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
				if (name == ""){
					name = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
				if (Scount == ""){
					Scount = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
				if (Srank == ""){
					Srank = line.substr(startPoint, (endPoint-startPoint));
					startPoint = endPoint;
					return;
				}
			}
		}
		int tempNumb;
		Gender tempGend;
		Ethnicity tempEthn;
		
			if (gender == "FEMALE"){
				tempGend = female;
			}
			if (gender == "MALE"){
				tempGend = male;
			}
			if (ethnicity == "WHITE NON HISPANIC"){
				tempEthn = white;
			}
			if (ethnicity == "BLACK NON HISPANIC"){
				tempEthn = black;
			}
			if (ethnicity == "ASIAN AND PACIFIC ISLANDER"){
				tempEthn = asian;
			}
			if (ethnicity == "HISPANIC"){
				tempEthn = hispanic;
			}
			tempNumb = atoi(Syear.c_str());
			Baby_Year.push_back(tempNumb);
			
			Baby_Gender.push_back(tempGend);
			Mother_Ethnicity.push_back(tempEthn);
			Baby_Name.push_back(name);
			
			tempNumb = atoi(Scount.c_str());
			Baby_Name_Count.push_back(tempNumb);
			
			tempNumb = atoi(Srank.c_str());
			Baby_Name_Rank.push_back(tempNumb);
			
			tempNumb = 0;
		}
		
		
		void BabyCollection::sortByRank(){
			int tYear,tYear2,tYear3,tYear4, tCount,tCount2,tCount3,tCount4, tRank,tRank2,tRank3,tRank4;
			Gender tGender,tGender2,tGender3,tGender4;
			Ethnicity tEthnicity, tEthnicity2,tEthnicity3,tEthnicity4;
			string tName,tName2,tName3,tName4;
			Babyname BabyName1;
			Babyname BabyName2;
			Babyname BabyName3;
			Babyname BabyName4;
			for(int i = 1; i<Baby_Year.size()-2; i++){
				getCollection(i, tYear, tGender, tEthnicity, tName, tCount, tRank);
				BabyName1.set(tYear, tGender, tEthnicity, tName, tCount, tRank);
				
				getCollection(i-1, tYear2, tGender2, tEthnicity2, tName2,tCount2, tRank2);
				BabyName2.set(tYear2, tGender2, tEthnicity2, tName2,tCount2, tRank2);
				for(int j = 0; j<i; j++){
					BabyCollection::getCollection(j, tYear3, tGender3, tEthnicity3, tName3, tCount3,tRank3);
					BabyName3.set(tYear3, tGender3, tEthnicity3, tName3, tCount3,tRank3);
					
					BabyCollection::getCollection(j+1, tYear4, tGender4, tEthnicity4, tName4,tCount4, tRank4);
					BabyName4.set(tYear4, tGender4, tEthnicity4, tName4,tCount4, tRank4);
					if (is_less_by_rank(BabyName4, BabyName3)){
						swap(Baby_Name[j+1],Baby_Name[j]);
						swap(Baby_Year[j+1],Baby_Year[j]);
						swap(Baby_Gender[j+1],Baby_Gender[j]);
						swap(Mother_Ethnicity[j+1],Mother_Ethnicity[j]);
						swap(Baby_Name_Count[j+1],Baby_Name_Count[j]);
						swap(Baby_Name_Rank[j+1],Baby_Name_Rank[j]);
					}
				}
				if (is_less_by_rank(BabyName2, BabyName1)){
					swap(Baby_Name[i+1],Baby_Name[i]);
					swap(Baby_Year[i+1],Baby_Year[i]);
					swap(Baby_Gender[i+1],Baby_Gender[i]);
					swap(Mother_Ethnicity[i+1],Mother_Ethnicity[i]);
					swap(Baby_Name_Count[i+1],Baby_Name_Count[i]);
					swap(Baby_Name_Rank[i+1],Baby_Name_Rank[i]);
				}
			}
		}
		
		void BabyCollection::sortByName(){
			int tYear,tYear2,tYear3,tYear4, tCount,tCount2,tCount3,tCount4, tRank,tRank2,tRank3,tRank4;
			Gender tGender,tGender2,tGender3,tGender4;
			Ethnicity tEthnicity, tEthnicity2,tEthnicity3,tEthnicity4;
			string tName,tName2,tName3,tName4;
			Babyname BabyName1;
			Babyname BabyName2;
			Babyname BabyName3;
			Babyname BabyName4;
			for(int i = 1; i<Baby_Year.size()-2; i++){
				getCollection(i, tYear, tGender, tEthnicity, tName, tCount, tRank);
				BabyName1.set(tYear, tGender, tEthnicity, tName, tCount, tRank);
				
				getCollection(i-1, tYear2, tGender2, tEthnicity2, tName2,tCount2, tRank2);
				BabyName2.set(tYear2, tGender2, tEthnicity2, tName2,tCount2, tRank2);
				for(int j = 0; j<i; j++){
					getCollection(j, tYear3, tGender3, tEthnicity3, tName3, tCount3,tRank3);
					BabyName3.set(tYear3, tGender3, tEthnicity3, tName3, tCount3,tRank3);
					
					getCollection(j+1, tYear4, tGender4, tEthnicity4, tName4,tCount4, tRank4);
					BabyName4.set(tYear4, tGender4, tEthnicity4, tName4,tCount4, tRank4);
					
					if (is_less_by_name(BabyName4, BabyName3)){
						swap(Baby_Name[j+1],Baby_Name[j]);
						swap(Baby_Year[j+1],Baby_Year[j]);
						swap(Baby_Gender[j+1],Baby_Gender[j]);
						swap(Mother_Ethnicity[j+1],Mother_Ethnicity[j]);
						swap(Baby_Name_Count[j+1],Baby_Name_Count[j]);
						swap(Baby_Name_Rank[j+1],Baby_Name_Rank[j]);
					}
				}
				if (is_less_by_name(BabyName2, BabyName1)){
					swap(Baby_Name[i+1],Baby_Name[i]);
					swap(Baby_Year[i+1],Baby_Year[i]);
					swap(Baby_Gender[i+1],Baby_Gender[i]);
					swap(Mother_Ethnicity[i+1],Mother_Ethnicity[i]);
					swap(Baby_Name_Count[i+1],Baby_Name_Count[i]);
					swap(Baby_Name_Rank[i+1],Baby_Name_Rank[i]);
				}
			}
		}
		
		void BabyCollection::getMax(Gender g, int y, Ethnicity e){
		int maxCount = 0;
		int tYear, tCount, tRank;
		Gender tGender;
		Ethnicity tEthnicity;
		string tName;
		Babyname BabyName;
			if (g == 0){
				g = any_gender;
			}
			if (e == 0){
				e = any_ethnicity;
			}
			if (y == 0){
				for (int year=2011; year<2015; year++){
					for (int i = 0; i<Baby_Year.size()-1; i++){
						if (g == Baby_Gender[i] && y == Baby_Year[i] && e == Mother_Ethnicity[i] && Baby_Name_Count[maxCount] <= Baby_Name_Count[i]){
							maxCount = i;
						}
					}
				}
			}
			for (int i = 0; i<Baby_Year.size()-1; i++){
				if (g == Baby_Gender[i] && y == Baby_Year[i] && e == Mother_Ethnicity[i] && Baby_Name_Count[maxCount] <= Baby_Name_Count[i]){
					maxCount = i;
				}
			}
			getCollection(maxCount, tYear, tGender, tEthnicity, tName, tCount, tRank);
			BabyName.set(tYear, tGender, tEthnicity, tName, tCount, tRank);
			
			ofstream myFile ("results");
			if (myFile.is_open()){
				BabyName.Print(myFile);
			}
			myFile.close();
		}
		
		void BabyCollection::getCount(string n, int y, Ethnicity e){
			int counter = 0;
			if (e == 0){
				e = any_ethnicity;
			}
			if (y == 0){
				for (int year=2011; year<2015; year++){
					for (int i = 0; i<Baby_Year.size()-1; i++){
						if ( n == Baby_Name[i] && year == Baby_Year[i] && e == Mother_Ethnicity[i]){
							counter +=1;
						}
					}
				}
				ofstream myFile ("results");
				if (myFile.is_open()){
					myFile << "There were " << counter << " babies born in the given years whose mother was of the given ethnicity with the name " << n << "\n";
				}
				myFile.close();
			}
			if (y != 0){
				for (int i = 0; i<Baby_Year.size(); i++){
					if (n == Baby_Name[i] && y == Baby_Year[i] && e == Mother_Ethnicity[i]){
						counter +=1;
					}
				}
				ofstream myFile ("results");
				if (myFile.is_open()){
					myFile << "There were " << counter << " babies born in the year " << y << " whose mother was of the given ethnicity with the name " << n << "\n";
				}
				myFile.close();
			}
		}

