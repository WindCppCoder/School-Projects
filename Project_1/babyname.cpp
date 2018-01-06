#include<iostream>
#include<string>
#include"thecollection.h"
#include"babyname.h"

using namespace std;
	Babyname::Babyname(){ }
	
	bool Babyname::set( int		year,
		 	Gender		gender,
			Ethnicity	ethnicity,
		 	string		name,
		  	int		count,
		  	int 		rank
		){
		
			if (year >= 2011 && year <= 2014){
				birth_year = year;
			}
			else return 0;
			
			if (gender >= 0 && gender <= 2){
				baby_gender = gender;
			}
			else return 0;
			
			if (ethnicity >= 0 && ethnicity <= 4){
				mother_ethnicity = ethnicity;
			}
			else return 0;
			
			if (name.length() > 0 && name.length() <= 16){
				baby_name = name;
			}
			else return 0;
			
			if (count > 0){
				name_count = count;
			}
			else return 0;
			
			if (rank > 0){
				name_rank = rank;
			}
			else return 0;
			
			return 1;
		}
		
	void Babyname::get( int		& year,
		  	Gender		& gender,
		 	Ethnicity	& ethnicity,
		  	string		& name,
		  	int		& count,
		  	int		& rank
		){
			year = birth_year;
			gender = baby_gender;
			ethnicity = mother_ethnicity;
			name = baby_name;
			count = name_count;
			rank = name_rank;
		}
	
	void Babyname::Print ( ostream & s){
		int tYear, tCount, tRank;
		Gender tGender;
		Ethnicity tEthnicity;
		string tName;
		
		for (int i = 0; i < BabyCollection().getLimit(); i++){
			BabyCollection().getCollection(i, tYear, tGender, tEthnicity, tName, tCount, tRank);
			set(tYear, tGender, tEthnicity, tName, tCount, tRank);
			string tempGend;
			string tempEthn;
			if (tGender == female){
				tempGend = "FEMALE";
			}
			if (tGender == male){
				tempGend = "MALE";
			}
			if (tEthnicity == white){
				tempEthn = "WHITE NON HISPANIC";
			}
			if (tEthnicity == black){
				tempEthn = "BLACK NON HISPANIC";
			}
			if (tEthnicity == asian){
				tempEthn = "ASIAN AND PACIFIC ISLANDER";
			}
			if (tEthnicity == hispanic){
				tempEthn = "HISPANIC";
				
			
			}
			
			s << tYear << "," << tempGend << "," << tempEthn << "," << tName << "," << tCount << "," << tRank << "\n";
		}
	}
