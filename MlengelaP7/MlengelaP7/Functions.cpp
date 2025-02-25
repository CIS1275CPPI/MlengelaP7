/***************************************************************************************************
* Program: Astrology.
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 22 November 2021.
* Purpose: This program calculates and displays the signs
* that would be most compatible for the birthday person. According to some astrologers,
* a person is most comfortable with their own sign and the other two signs in their Element.
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>

#include "functions.h"

/*******************************************************************************
* The description of the program. 
********************************************************************************/
static int GetElement(int sign)
{
    /******************************************************
    * Get the element of the program. 
    *******************************************************/
    int element = -1;

    switch (sign)
    {
    case 0: case 4: case  8: element = 0; break;
    case 1: case 5: case  9: element = 1; break;
    case 2: case 6: case 10: element = 2; break;
    case 3: case 7: case 11: element = 3; break;
    }

    return(element);
}
 /************************************************************
 * Get the compatible sign in the element
 *************************************************************/
static void GetCompatibleSigns(int sign, int* firstPtr, int* secondPtr)
{
    *firstPtr = *secondPtr = -1;

    switch (sign)
    {
    case 0: *firstPtr = 4; *secondPtr = 8; break;
    case 1: *firstPtr = 5; *secondPtr = 9; break;
    case 2: *firstPtr = 6; *secondPtr = 10; break;
    case 3: *firstPtr = 7; *secondPtr = 11; break;

    case 4: *firstPtr = 0; *secondPtr = 8; break;
    case 5: *firstPtr = 1; *secondPtr = 9; break;
    case 6: *firstPtr = 2; *secondPtr = 10; break;
    case 7: *firstPtr = 3; *secondPtr = 11; break;

    case 8: *firstPtr = 0; *secondPtr = 4; break;
    case 9: *firstPtr = 1; *secondPtr = 5; break;
    case 10: *firstPtr = 2; *secondPtr = 6; break;
    case 11: *firstPtr = 3; *secondPtr = 7; break;
    }
}
/***********************************************************************
* Determine which element is the users based on the sign and then
************************************************************************/
static string DoFormat(AstrologyData& data, int sign, int element, int compatibleOne, int compatibleTwo)
{
    stringstream out;

    out <<
        "Sign: " << data.signs[sign] << ", " <<
        "Element: " << data.elementNames[element] << ", " <<
        "CompatibleSigns: (" << data.signs[compatibleOne] << ", " << data.signs[compatibleTwo] << ")";

    return(out.str());
}
/*****************************************************************************
* Determine the compatible signs in that element.
******************************************************************************/
static string DoFormat(AstrologyData& data, int sign)
{
    int first = 0;
    int second = 0;

    GetCompatibleSigns(sign, &first, &second);

    return(DoFormat(data, sign, GetElement(sign), first, second));
}
/***********************************************************************************
* Write the class header
************************************************************************************/
void WriteHeader(void)
{
    cout << "Clark Kent" << "\n";
    cout << "CIS 1275 - C++ Programming I" << "\n";
    cout << "\n";
}
/**************************************************************************************
* Write information explaining the program
***************************************************************************************/
void WriteIntro(void)
{
    cout << "Astrology" << "\n";
    cout << "Prompt the user for their birthday and validate the input\n";
    cout << "Determine the user's astrological chart which we'll write to a file\n";
    cout << "Let the user quit the program or enter another birthday\n";
    cout << "\n";
}
/*************************************************************************************
* Fill the horoscopes array in the AstrologyData struct with a horoscope for each sign
**************************************************************************************/
void FillHoroscopes(AstrologyData& data)
{
    for (int i = 0; i < NUM; i++)
        data.horoscopes[i] = DoFormat(data, i);
}
/**********************************************************************************
* Ask the users name and birthday. 
***********************************************************************************/
void AskForNameAndBirthday(MyChart& astro)
{
    cout << "Please enter your name: ";
    cin >> astro.myName;

    cout << "Please enter your birth month: ";
    cin >> astro.month;

    cout << "Please enter your birth day: ";
    cin >> astro.day;
    
}
/*************************************************************************************
* Verify birthday is a valid date. (example: cannot be 2/30 or -1/15)
*************************************************************************************/
bool ValidateBirthday(MyChart& astro)
{
    
    int lastDayOfMonth = 31;

    if (astro.month < 1 || astro.month > 12)
    {
       
            return(false);
    }

    switch (astro.month)
    {
    case 2:                          lastDayOfMonth = 28; break;
    case 4: case 6: case 9: case 11: lastDayOfMonth = 30; break;
    }

    if (astro.day < 1 || astro.day > lastDayOfMonth)
    {
        return(false);
    }
    return(true);
}
/*******************************************************************************
* Determine which sign is the users based on the given birthdate.
*********************************************************************************/
void FindMySign(MyChart& astro)
{
    int signNumber = -1;

    switch (astro.month)
    {
    case  4: signNumber = 0;  if (astro.day > 19) signNumber++;   break;
    case  5: signNumber = 1;  if (astro.day > 20) signNumber++;   break;
    case  6: signNumber = 2;  if (astro.day > 21) signNumber++;   break;
    case  7: signNumber = 3;  if (astro.day > 22) signNumber++;   break;
    case  8: signNumber = 4;  if (astro.day > 22) signNumber++;   break;
    case  9: signNumber = 5;  if (astro.day > 22) signNumber++;   break;
    case 10: signNumber = 6;  if (astro.day > 22) signNumber++;   break;
    case 11: signNumber = 7;  if (astro.day > 21) signNumber++;   break;
    case 12: signNumber = 8;  if (astro.day > 21) signNumber++;   break;
    case  1: signNumber = 9;  if (astro.day > 19) signNumber++;   break;
    case  2: signNumber = 10; if (astro.day > 18) signNumber++;   break;
    case  3: signNumber = 11; if (astro.day > 20) signNumber = 0; break;
    }

    astro.mySign = signNumber;
}
/**********************************************************************************
* Determine which element is the users based on the sign 
* and then determine the compatible signs in that element.
***********************************************************************************/
void FindCompatibleSigns(MyChart& astro)
{
    astro.myElement = GetElement(astro.mySign);

    int first = 0;
    int second = 0;

    GetCompatibleSigns(astro.mySign, &first, &second);

    astro.compatibleSigns[0] = first;
    astro.compatibleSigns[1] = second;
}
/**********************************************************************************
* Write the info obtained using string created by a stringstream. Get the filename
* from the user via filename pointer. Write the result to the file. 
* Return true to the successfully writing to the file or false if it is unabled. 
***********************************************************************************/
bool WriteHoroscope(MyChart& astro, AstrologyData& data, string* filename, string* results)
{
    *results =
        "Name: " + astro.myName + ", " +
        DoFormat(data, astro.mySign, astro.myElement, astro.compatibleSigns[0], astro.compatibleSigns[1]);

    cout << "Please enter the filename: ";
    cin >> *filename;

    ofstream output(*filename);

    if (!output)
        return(false);

    output << *results << "\n";

    return(true);
}
/*******************************************************************************
* Get the imput. Ask user if they would like to try again.
* Return true for yes, false for no
********************************************************************************/
bool DoAnotherHoroscope(void)
{
    cout << "Try another birthday and horoscope? ";

    string input;
    cin >> input;

    if (input.size() > 0 && tolower(input[0]) == 'n')
        return(false);

    return(true);
}
/***********************************************************************************
* Print a goodbye message to the screen.
************************************************************************************/
void SayGoodbye(void)
{
    cout << "Goodbye!\n";
}

