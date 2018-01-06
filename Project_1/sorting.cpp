#include"sorting.h"
using namespace std;

bool is_less_by_rank(const Babyname &lt, const Babyname &rt){
	if (lt.birth_year < rt.birth_year){
		return 1;
	}
	
	else {if (lt.birth_year == rt.birth_year && lt.baby_gender < rt.baby_gender){
			return 1;
		}
		
		else{if (lt.baby_gender == rt.baby_gender && lt.mother_ethnicity < rt.mother_ethnicity){
				return 1;
			}
			
			else{if (lt.mother_ethnicity == rt.mother_ethnicity && lt.name_rank > rt.name_rank){
					return 1;
				}
				else return 0;
			}
		}
	}
}


bool is_equal_rank (const Babyname & lt, const Babyname & rt){
	if (lt.birth_year == rt.birth_year && lt.baby_gender == rt.baby_gender && lt.mother_ethnicity == rt.mother_ethnicity && lt.name_rank == rt.name_rank){
		return 1;
	}
	else return 0;
}


bool is_less_by_name(const Babyname & lt, const Babyname & rt){
	if (lt.birth_year < rt.birth_year){
		return 1;
	}
	
	else {if (lt.birth_year == rt.birth_year && lt.baby_gender < rt.baby_gender){
			return 1;
		}
		
		else{if (lt.baby_gender == rt.baby_gender && lt.mother_ethnicity < rt.mother_ethnicity){
				return 1;
			}
			
			else{if (lt.mother_ethnicity == rt.mother_ethnicity){
					if (lt.baby_name.length() < rt.baby_name.length()){
						for (int i = 0; i < lt.baby_name.length()-1; i++){
							if (lt.baby_name[i] < rt.baby_name[i]){
								return 1;
							}
						}
					}
				}
					else {if (lt.baby_name.length() > rt.baby_name.length()){
							for (int i = 0; i < rt.baby_name.length()-1; i++){
								if (lt.baby_name[i] < rt.baby_name[i]){
									return 1;
								}
							}
						}
						else {if (lt.baby_name.length() == rt.baby_name.length()){
						
							for (int i = 0; i < lt.baby_name.length()-1; i++){
								if (lt.baby_name[i] < rt.baby_name[i]){
									return 1;
								}
							}
						       }
							else return 0;
						}
					}
			}
		}
	}
}


bool is_equal_name (const Babyname & lt, const Babyname & rt){
	if (lt.birth_year == rt.birth_year && lt.baby_gender == rt.baby_gender && lt.mother_ethnicity == rt.mother_ethnicity){
		if (lt.baby_name.length() != rt.baby_name.length() ){
			return 0;
		}
		
		for (int i = 0; i < lt.baby_name.length()-1; i++){
			if (lt.baby_name[i] != rt.baby_name[i]){
				return 0;
			}
		}
		return 1;
	}
}

