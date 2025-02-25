/***************************************************************************************************
* Program: Astrology.
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: 22 November 2021.
* Purpose: This program calculates and displays the signs
* that would be most compatible for the birthday person. According to some astrologers,
* a person is most comfortable with their own sign and the other two signs in their Element.
***************************************************************************************************/
#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>

using namespace std;

static const int NUM = 12;

struct AstrologyData
{
    string signs[NUM]
    {
       "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo",
       "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"
    };

    string horoscopes[NUM];
    string elementNames[4]{ "Fire", "Earth", "Air", "Water" };
};

struct MyChart
{
    int month{ 1 };
    int day{ 1 };
    string myName;
    int mySign{ 0 };
    int myElement{ 0 };
    int compatibleSigns[2]{ 0, 1 };
};

void WriteHeader(void);
void WriteIntro(void);
void FillHoroscopes(AstrologyData& data);
void AskForNameAndBirthday(MyChart& astro);
bool ValidateBirthday(MyChart& astro);
void FindMySign(MyChart& astro);
void FindCompatibleSigns(MyChart& astro);
bool WriteHoroscope(MyChart& astro, AstrologyData& data, string* filename, string* results);
bool DoAnotherHoroscope(void);
void SayGoodbye(void);
 
#endif!_FUNCTION_H