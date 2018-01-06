/******************************************************************************
  Title          : sorting.h
  Author         : Windhaw Chia Chang
  Created on     : September  25, 2017
  Description    : Interface for the boolean sorting functions
  Purpose        : Contains functions that return true under certain conditions
  Modifications  :
 
******************************************************************************/
#ifndef __SORTING_H__
#define __SORTING_H__
#include<iostream>
#include<string>
#include"command.h"
#include"babyname.h"

/**
	is_less_by_rank(const Babyname & lt, const Babyname & rt) returns true if lt.year and gender and ethnicity AND rank is "less" 
	than that of rt; else it returns false
*/
bool is_less_by_rank(const Babyname & lt, const Babyname & rt);
/**
	is_equal_rank(const Babyname & lt, const Babyname & rt) returns true if lt.year and gender and ethnicity and rank is exactly
	the same as that of rt; else it returns false
*/
bool is_equal_rank  (const Babyname & lt, const Babyname & rt);
/**
	is_less_by_name(const Babyname & lt, const Babyname & rt) returns true if lt.year and gender and ethnicity and NAME is "less" 
	than that of rt; else it returns false
*/
bool is_less_by_name(const Babyname & lt, const Babyname & rt);
/**
	is_equal_name(const Babyname & lt, const Babyname & rt) returns true if lt.year and gender and ethnicity and NAME is exactly
	the same as that of rt; else it returns false
*/
bool is_equal_name  (const Babyname & lt, const Babyname & rt);

#endif /* __SORTING_H__*/
