/*******************************************************************************
  Title          : babyname.h
  Author         : Stewart Weiss
  Created on     : September  7, 2016
  Description    : Interface to the Babyname class
  Purpose        : To provide methods for processing baby names
  Usage          : 
  Build with     : 
  Modifications  : 

  Notes
  Refer to the assignment for the specification of valid values for the data
  members and for the exact format of the output produced by print().
 
*******************************************************************************/
#ifndef __BABYNAME_H__
#define __BABYNAME_H__

#include "command.h"    // Needed for the types exported there

class Babyname
{
public:
    /** Babyname() - default constructor */
    Babyname();

    /** set() - set method for the class
     * assigns given values to the member variables, while validating values
     * method ensures that all parameters are within the allowed ranges
     * as defined in the specification
     * @param int 	year      [in]  birth year 
     * @param Gender    gender    [in]  baby's gender 
     * @param Ethnicity ethnicity [in]  mother's ethnicity 
     * @param string    name      [in]  name of baby
     * @param int       count     [in]  frequency (see comments)
     * @param int       rank      [in]  rank (see comments)
     * @pre   none
     * @post  object is assigned all valid values
     * @return bool    true if all values were set successfully; false otherwise
     */
    bool set( int       year, 
              Gender    gender, 
              Ethnicity ethnicity,
              string    name,
              int       count,
              int       rank
            );
    /** get() - get method for the class
     * retrieves values of the member variables, and passes to corresponding
     * parameters.
     * @param int year            [out]  birth year 
     * @param Gender    gender    [out]  baby's gender 
     * @param Ethnicity ethnicity [out]  mother's ethnicity 
     * @param string    name      [out]  name of baby
     * @param int       count     [out]  frequency (see comments)
     * @param int       rank      [out]  rank (see comments)
     * @pre   none
     * @post  object is assigned all valid values
     */
    void get( int       &  year, 
              Gender    &  gender, 
              Ethnicity &  ethnicity,
              string    &  name,
              int       &  count,
              int       &  rank
            );
    
    /** print() - prints the baby name data onto the given ostream 
     *  assuming it is already open for writing, in the format specified 
     * in the assignment.
     * @param ostream s   [inout]  ostream opened for  writing
     * @pre   the object has valid data
     * @post  if the object has valid data, then it is written to ostream 
     *        in the specified format and the ostream is updated
     */
    void Print ( ostream & s );

    /** Several friend functions that perform similar tasks;
     * Each is given two Babyname objects by constant reference and
     * returns true or false depending on whether one is less than or equal to
     * the other. 
     * is_less_by_rank(lt, rt) is true if and only if: 
     *  birth year of lt < birth year of rt 
     *     or they are equal and gender of lt < gender of rt, 
     *     or they are equal and ethnicity of lt < ethnicity of rt, 
     *     or they are equal and rank of lt < rank of rt. 
     * is_less_by_name( lt, rt) has the same logic except in the last
     *     case when name replaces rank.
     * The two is_equal functions return true if and only if year, gender,
     *     and ethnicity are equal and in the case of is_equal_name, the names
     *     are identical, and in the case of rank, the ranks are identical.
     */
    friend  bool is_less_by_rank(const Babyname & lt, const Babyname & rt );
    friend  bool is_equal_rank  (const Babyname & lt, const Babyname & rt );
    friend  bool is_less_by_name(const Babyname & lt, const Babyname & rt );
    friend  bool is_equal_name  (const Babyname & lt, const Babyname & rt );
    
   
private:
    int       birth_year;        // 2011 through 2014
    Gender    baby_gender;       // male or female
    Ethnicity mother_ethnicity;  // asian, black, hispanic, or white
    string    baby_name;         // any valid string
    int       name_count;        // >= 0
    int       name_rank;         // > 0
};


#endif /* __BABYNAME_H__ */


