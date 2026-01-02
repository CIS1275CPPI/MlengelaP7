# Astrology
## Total Program points: 100 points – hand calculations 20 points, and correct use of structs 20 points.

Begin by writing pseudocode for Program 6.  Then write hand calculations for this test case:
Birthday is March 25.  Make sure the sign, the element, and the compatible signs are correct, and that the correct horoscope is being selected.  

## This is a multi-file program:
It uses the user’s birthday (no year) and responds with their sign and a horoscope for that birthday.  The month is entered as 1-12 and the day as 1 – the last day of the month.  You will validate the numbers entered by the user before running the rest of the program.

## Here are sign names and their dates: 
Use these dates so we are all on the same page, so to speak.

| Aries         | March 21 - April 1910 |
| ------------- | --------------------- |
| Taurus        | April 20 - May 20  |
| Gemini        | May 21 - June 21  |
| Cancer        | June 22 - July 22 |
| Leo           | July 23 - August 22 |
| Virgo         | August 23 - September 22 |
| Libra         | September 23 - October 22 |
| Scorpio       | October 23 - November 21 |
| Sagittarius   | November 22 - December 21 |
| Coprasicorn   | December 22 - January 19 |
| Aquarius      | January 20 - February 18 |
| Pisces        | February 19 - March 20 |

__There are four Elements:__ Fire, Earth, Air, and Water.  Each has three zodiac signs.

According to some astrologers, a person is most comfortable with their own sign and the other two signs in their Element.  The program will display the signs that would be most compatible for the birthday person.

Therefore, the program determines the Element for that sign and the other two signs of the same element and displays them to the user. Here are the Elements and 3 Signs in each Element: 

FIRE (Aries, Leo, Sagittarius)

EARTH (Taurus, Virgo, Capricorn)

AIR (Gemini, Libra, Aquarius)

WATER (Cancer, Scorpio, Pisces).  

The program will first show your class header by calling the Header and Intro functions.  You may combine these, but you should give a full description of the[program in the intro part. Then declare variables, including struct objects for both structs.  Call _FillHoroscopes_ to add data to the array of horoscopes.  

__Begin__ a do-while loop (play loop). Call _AskForNameAndBirthday_. Then, validate the dates given by the user by calling _ValidateBirthday_.  If the dates are valid, continue by calling _FindMySign_ and then _FindCompatibleSigns_. 

__Finally__, call _WriteHoroscope_ to write the Horoscope information summary into a file and to return the summary called results to the main to display to the user. Use stringstream to create a nicely formatted message relaying all of the information to the user:  Name, sign, element, and the other compatible signs of the element. Convert the stringstream to a string and "return it" to main by pointer.

Ask for the filename in the _WriteHoroscope_ function, open an output file stream, and open the file.  Check that the file is open. If the file is not open, return false. If it is open, write the string to the file. Close the file and return true. 

__In main__, check the bool return.  If it is false, report that to the user.  If true, tell the user the filename.  In either case, cout the string with the information summary.

There should also be an else in main which matches the if (user date input was valid).  It should contain a message saying that they did not enter a valid day or month.

Ask the user if they want to try another birthday and horoscope.  If yes, loop to the top of the do-while and repeat, otherwise drop to the Good-bye message.

## Here are the two structs you will use:
NUM is a constant declared in the .h file and has a value of 12. 

<img width="750" height="378" alt="image" src="https://github.com/user-attachments/assets/fcd09e4a-499e-41c6-9976-2becab781e62" />

## You will need these functions: 

| **Return Type**  | **Function Name** | **Arguments** | **Description**                                                     |
| -------------    | ------------------| --------------| ---------------------------------------------------------------------|
| __void__  | WriteHeader  | () | Write the class header | 
| __void__  | WriteIntro  | ()  | Write information explaining the program |
| __void__  | FillHoroscopes | (AstrologyData &data) | Fill the horoscopes array in the AstrologyData struct with a horoscope for each sign |
| __void__  | AskForNameAndBirthday | (MyChart &stro) | Ask the user's name and birthday |
| __bool__  | ValidateBirthday  | (MyChart &stro) | Verify birthday is a valid date. (example: cannot be 2/30 or -1/15)  |
| __void__  | FindMySign  | (MyChart &stro) | Determine which sign is the users based on the given birthdate |
| __void__  | FindCompatibleSigns | (MyChart &stro) | Determine which element is the users based on the sign and then determine the compatible signs in that element |
| __bool__  | WriteHoroscope  | (MyChart &stro, AstrologyData &data, string *filename, string *results ) | Write out all of the information obtained using a string created by a stringstream and return the string via the results pointer. Also obtain a filename from the user, return to main via the filename pointer, and write the results string to a file. Return true for successfully writing to the file or false if it was unable |
| __bool__  | DoAnotherHoroscope | () | Ask user if they would like to try again. Return true for yes, false for no |
| __void__  | SayGoodbye | () | Print a goodbye message to the screen |  

Be sure to  call ALL of the functions from main. Use pointers and references as described. 

# Sources:
# Usage: 
# Core Features:
# Contributions:
