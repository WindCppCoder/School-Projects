/******************************************************************************
  Title          : command.h
  Author         : Stewart Weiss
  Created on     : September  5, 2016
  Description    : Interface for the command class
  Purpose        : The Command class represents a command object
  Modifications  : September 8, 2017
                   New command added

  Notes:
  This header file provides the interface to the Command class, as well as to
  a few types that are required in order to use this class, specifically the 
  following enumerated types:
    Command_type
    Gender
    Ethnicity
  All of the member functions required to utilize this class are here. 
  There is no need to modify this class and it should not be modified!
 
******************************************************************************/
#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <iostream>

using namespace std;

/*******************************************************************************   
                                 Exported Types
*******************************************************************************/

/** Command_type: 
    An enumerated type to represent the different types of commands. This is  
    more efficient than storing command types as strings. Notice that the last
    value of the type is num_Command_types, which is simply a count of how many
    values the type contains. It is a useful method of counting, because as long
    as you insert new values before it, it remains valid.
*/
typedef enum   
{
    print = 0,
    sort_byname,
    sort_byrank,
    getmax,
    getcount,
    bad_command,
    null,
    num_Command_types
} Command_type;

/** Gender
    This is an enumerated type to represent two possible genders plus a 
    wildcard value named "any" that means either gender.
*/
typedef enum
{
    female = 0,
    male,
    any_gender
} Gender;

/** Ethnicity
    This represents the different ethnic groups that might be associated to an
    individual name in the dataset. The wildcard "any" represents any ethnic
    group.
*/
typedef enum
{
    asian = 0,
    black,
    hispanic,
    white,
    any_ethnicity,
    num_ethnicities
} Ethnicity;

/*******************************************************************************   
                              Command Class Interface
*******************************************************************************/

class Command
{
public:
    /** Command()  A default constructor for the class 
     */
    Command ();

    /** get_next(istream & in) resets the values of the command object on
     * which it is called to the values found at the current read pointer of 
     * the istream in, provided in.eof() is false.
     * @param istream in [inout]  an istream already opened for reading
     * @pre   istream in is open for reading and in.eof() is false
     * @post  If in.eof() is false on entry to this constructor, then
     *        the command is re-initialized to the values found in the input
     *        stream in, and the istream pointer is advanced to the next line. 
     *        If the command is invalid, then when typeof() is called on it, 
     *        it will return bad_command. 
     *        If in.eof() is true on entry, then the Command_type is set
     *        to null and the remaining values are undefined.
     * @return true if the command was initialized to something other than a
     *        bad_command, and false otherwise.
     */
    bool get_next (istream & in );

    /** typeof() returns the type of the Command on which it is called.
     * @pre  None
     * @post None, as this is a const method
     * @return A value of Command_type, depending on the type of the command
             object.
     */
    Command_type type_of () const;

    /** args() sets the values of its parameters to the argument values of
     * the Command object on which it is called. If the Command object is a 
     * bad_command, or if it is a sort_byname, sort_byrank, or null command
     * then the result is set to false and the remaining parameter values are
     * undefined. Otherwise, the Command_type should be getmax, getcount, or 
     * print and the appropriate values are copied from the current values in 
     * the Command object, meaning 
     * if print, then the filename, and 
     * if getmax, then the birth_year, gender, and ethnicity, and 
     * if getcount, the name, birth_year, and ethnicity.
     * @pre  Command_type is initialized to a valid value
     * @post Either result == false or all members are
     *       set to the values in the object.
     */ 
    void  get_args (string    & outfile,
                string    & b_name,
                int       & b_year, 
                Gender    & m_gender, 
                Ethnicity & m_ethnicity,
                bool      & result) const;

private:
    Command_type type;       // The type of the Command object
    string       filename;   // If a print command, the name of the file
    string       birth_name; // The name argument on the command line, if given
    int          birth_year; // The birth year argument on the command line
    Gender       gender;     // The gender argument passed on the command line
    Ethnicity    ethnicity;  // The ethnicity argument passed on the command line.

};

#endif /* __COMMAND_H__ */

