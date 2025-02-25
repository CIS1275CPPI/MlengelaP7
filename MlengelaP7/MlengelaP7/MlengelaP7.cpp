/***************************************************************************************************
* Program: Astrology.
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 22 November 2021.
* Purpose: This program calculates and displays the signs 
* that would be most compatible for the birthday person. According to some astrologers,
* a person is most comfortable with their own sign and the other two signs in their Element.
***************************************************************************************************/
#include <iostream>
#include "functions.h"

int main()
{
    WriteHeader();

    WriteIntro();

    AstrologyData data;

    FillHoroscopes(data);

    bool DoAnotherHoroscope(void);
/**************************************************************************
* We need to start a while loop and validate the date given. 
***************************************************************************/
    do
    {
        MyChart astro;

        AskForNameAndBirthday(astro);

        if (!ValidateBirthday(astro))
        {
            cout << "Invalid birthday: " << astro.month << " / " << astro.day << "\n";
            continue;
        }

        FindMySign(astro);
        FindCompatibleSigns(astro);

        string filename;
        string result;

        if (!WriteHoroscope(astro, data, &filename, &result))
        {
            cout << "Error writing file: " << filename << "\n";
        }
        else
        {
            cout << "Wrote file: " << filename << "\n";
        }

        cout << result << "\n";
  
    } while (DoAnotherHoroscope());
/********************************************************************
* Print a goodbye message to the screen. 
*********************************************************************/
    SayGoodbye();

    return 0;
}

