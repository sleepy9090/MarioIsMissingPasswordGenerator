/**
 ************************************************************************************************************************
 *
 *  @file                   MarioIsMissingPassGen.cpp
 *  @brief                  Mario is Missing! Password Generator
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   March 19th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   For use with the N.E.S. Version
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>
#include <stdint.h>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Get bits as int
 *
 * @param   tempArray Array holding area completion values
 * @param   start The starting int
 * @param   bits The number of bits as int
 *
 * @return  bits as int
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
uint32_t getBitsAsInt(uint32_t* tempArray, int start, int bits)
{
	uint32_t temp = 0x00;
	for (int i = start; i < (start + bits); i++)
	{
        if (tempArray[i] == 1)
        {
            temp |= (1 << (i - start));
        }
	}
	return temp & 0xFFFFFFFF;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Get user input
 *
 * @param   area The are to get input for
 *
 * @return  1 if area completed, 0 if not
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int getUserInput(string area)
{
    string input = "";
    int areaComplete = 0;
    while (true) {
        cout << area << "? (0 for no, 1 for yes): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> areaComplete)
        {
            if (areaComplete >= 0 && areaComplete <= 1)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }
    return areaComplete;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    const uint32_t x[3] = {7,15,20};
    const uint32_t y[3] = {3,8,1};

    uint32_t tempArray[6];
    uint32_t tempArray2[5];
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t k = 0;

    int newYorkComplete = 0;
    int romeComplete = 0;
    int sydneyComplete = 0;
    int sanFranciscoComplete = 0;
    int tokyoComplete = 0;
    int parisComplete = 0;
    int montrealComplete = 0;
    int moscowComplete = 0;
    int londonComplete = 0;
    int buenosAiresComplete = 0;
    int mexicoCityComplete = 0;
    int cairoComplete = 0;
    int nairobiComplete = 0;
    int beijingComplete = 0;
    int random = 0;

    cout << "Mario is Missing! password generator v 1.0" << endl;
    cout << "For use with the N.E.S." << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    newYorkComplete = getUserInput("New York completed");
    romeComplete = getUserInput("Rome completed");
    sydneyComplete = getUserInput("Syndey completed");
    sanFranciscoComplete = getUserInput("San Francisco completed");
    tokyoComplete = getUserInput("Tokyo completed");
    parisComplete = getUserInput("Paris completed");
    montrealComplete = getUserInput("Montreal completed");
    moscowComplete = getUserInput("Moscow completed");
    londonComplete = getUserInput("London completed");
    buenosAiresComplete = getUserInput("Buenos Aires completed");
    mexicoCityComplete = getUserInput("Mexico City completed");
    cairoComplete = getUserInput("Cairo completed");
    nairobiComplete = getUserInput("Nairobi completed");
    beijingComplete = getUserInput("Beijing completed");
    random = getUserInput("Random");

    // San Francisco to Tokyo
    tempArray2[0] = newYorkComplete;
    tempArray2[1] = romeComplete;
    tempArray2[2] = sydneyComplete;
    tempArray2[3] = sanFranciscoComplete;
    tempArray2[4] = tokyoComplete;
    i = getBitsAsInt(tempArray2, 0, 5);

    // Paris to Buenos Aires 
    tempArray2[0] = parisComplete;
    tempArray2[1] = montrealComplete;
    tempArray2[2] = moscowComplete;
    tempArray2[3] = londonComplete;
    tempArray2[4] = buenosAiresComplete; 
    j = getBitsAsInt(tempArray2, 0, 5);

    // Mexico City to Random
    tempArray2[0] = mexicoCityComplete;
    tempArray2[1] = cairoComplete;
    tempArray2[2] = nairobiComplete;
    tempArray2[3] = beijingComplete;
    tempArray2[4] = random; 
    k = getBitsAsInt(tempArray2, 0, 5);

    tempArray[0] = (i ^ x[0]) & 31;
    tempArray[1] = (j ^ x[1]) & 31;
    tempArray[2] = (k ^ x[2]) & 31;
    tempArray[3] = (i ^ y[0]) & 31;
    tempArray[4] = (j ^ y[1]) & 31;
    tempArray[5] = (k ^ y[2]) & 31;

    string password;
	for(int i = 0; i < 6; i++)
    {
        password += "0123456789?BCDFGHJKLMNPQRSTVWXYZ"[tempArray[i]];
    }
    cout << endl;
    cout << "Generated password: " << password << endl;

    return(0);
}

