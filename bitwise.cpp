#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>
#include <math.h>

using namespace std;

// forward declarations for functions
void byteToDecimalStr(unsigned char, char*);
void byteToBinaryStr(unsigned char, char*);
void byteToHexStr(unsigned char, char*);

// global declarations for string space
char inputStr[5];
char decimalOut[4];
char binaryOut[9];
char hexOut[3];

/* The main function goes inputs and outputs, calling the helper functions
   as necessary to do formatting. */
int main(int argc, char* argv[])
{
   int num1, num2;
   unsigned char num1byte, num2byte, opresult, AandBbyte, AxorBbyte, ArightBbyte, AleftBbyte, AorBbyte;

   // Totally ignore the program arguments and launch right into prompts.
   cout << "Welcome to the Bitwise Operator Demonstrator." << endl << endl;
 	 while (1)   // bad form but I promise I'll break out of the infinite loop
   {
		  cout << "Would you like to continue? (y/n)";
		  cin >> inputStr;
		  // Common versions of 'no'
		  if (!(strcmp(inputStr, "N")) || !(strcmp(inputStr, "n")) ||
			    !(strcmp(inputStr, "NO")) || !(strcmp(inputStr, "no")) ||
			    !(strcmp(inputStr, "No"))) break;  // see, I promised to break out

		  // Common versions of 'yes'
		  if (!(strcmp(inputStr, "Y")) || !(strcmp(inputStr, "y")) ||
			    !(strcmp(inputStr, "YES")) || !(strcmp(inputStr, "yes")) ||
			    !(strcmp(inputStr, "Yes")))
      {
				 cout << "Ok, then let's get your first number between 0 and 255: ";
				 cin >> num1;

				 while(1)    // he did it again!
         {
					  // let's do some error checking before we move on
					  if ((num1 < 0) || (num1 > 255))
						   cout << "Parameters must be between 0 and 255." << endl;
					  else break;

					  // If we didn't break, we need to try again...
					  cout << "Let's try that again ... Your first number? ";
					  cin >> num1;
				    while (num1 < 0 || num1 > 255)
            {
				 	     cin >> num1;
					     // not a numeric character, probably
					     // clear the failure and pull off the non-numeric character
					    if (cin.fail())
              {
						     cin.clear();
					    }
				   }
				}

				cout << "Good! Now let's get your second number between 0 and 255: ";
				cin >> num2;

				while(1)    // and again(!) with the infinite loop!
        {
					 // let's do some error checking before we move on
					 if ((num2 < 0) || (num2 > 255))
						  cout << "Parameters must be between 0 and 255." << endl;
					 else break;

					 // If we didn't break, we need to try again...
					 cout << "Let's try that again ... Your second number? ";
					 cin >> num2;
				   while (num2 < 0 || num2 > 255)
           {
				 	    cin >> num2;
					    // not a numeric character, probably
					    // clear the failure and pull off the non-numeric character
					    if (cin.fail())
              {
						     cin.clear();
					    }
				   }
				}

				// We have two numbers, let's move on
				cout << endl << "Terrific, let's see what happens when we apply bitwise operators:" << endl;

				// force inputs to 8 bits
				num1byte = (char)num1;
				num2byte = (char)num2;

				// print header
				cout << "         Decimal    Hexidecimal    Binary" << endl;

				// format input 1 and print
				byteToDecimalStr(num1byte, (char*)&decimalOut);
				byteToHexStr(num1byte, (char*)&hexOut);
				byteToBinaryStr(num1byte, (char*)&binaryOut);
				cout << "A =        " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;

				// format input 2 and print
				byteToDecimalStr(num2byte, (char*)&decimalOut);
				byteToHexStr(num2byte, (char*)&hexOut);
				byteToBinaryStr(num2byte, (char*)&binaryOut);
				cout << "B =        " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;

				AandBbyte = (char)num1 & (char)num2;
				byteToDecimalStr(AandBbyte, (char*)&decimalOut);
				byteToHexStr(AandBbyte, (char*)&hexOut);
				byteToBinaryStr(AandBbyte, (char*)&binaryOut);
				cout << "A & B =    " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;
				
				AorBbyte = (char)num1 | (char)num2;
				byteToDecimalStr(AorBbyte, (char*)&decimalOut);
				byteToHexStr(AorBbyte, (char*)&hexOut);
				byteToBinaryStr(AorBbyte, (char*)&binaryOut);
				cout << "A | B =    " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;
				
				AxorBbyte = (char)num1 ^ (char)num2;
				byteToDecimalStr(AxorBbyte, (char*)&decimalOut);
				byteToHexStr(AxorBbyte, (char*)&hexOut);
				byteToBinaryStr(AxorBbyte, (char*)&binaryOut);
				cout << "A ^ B =    " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;
				
				ArightBbyte = (char)num1 >> (char)num2;
				byteToDecimalStr(ArightBbyte, (char*)&decimalOut);
				byteToHexStr(ArightBbyte, (char*)&hexOut);
				byteToBinaryStr(ArightBbyte, (char*)&binaryOut);
				cout << "A >> B =   " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;
				
				AleftBbyte = (char)num1 << (char)num2;
				byteToDecimalStr(AleftBbyte, (char*)&decimalOut);
				byteToHexStr(AleftBbyte, (char*)&hexOut);
				byteToBinaryStr(AleftBbyte, (char*)&binaryOut);
				cout << "A << B =   " << decimalOut << "          ";
				cout << hexOut << "h       " << binaryOut << "b" << endl;
		  }
		  else // we didn't get a good response
			   cout << "??? I didn't understand that.  Please try again." << endl << endl;
	 }

	 return 0;
}

// This function takes an integer (forced to a byte length) and the address of a character
// string as its inputs.  It will convert the value of the integer to a decimal by dividing
// the number by the base 10 and adding extracted digits in the remainder to a string that is
// returned in the address passed in the inputs.  There is no error checking - any possible
// byte value is valid and it is up to the user to provide reasonable inputs.  The result
// string is padded with leading 0s up to a 3-digit field (255 is the max for one byte).
void byteToDecimalStr(unsigned char num, char* rstr)
{
	 // declare some temporary variables to work with
	 char resultStr[4];
	 char tempStr[4];
	 unsigned char tnum = num;
	 unsigned char remainder;
	 int cnt = 3;		// this is for padding leading 0s

	 strncpy(resultStr, "", 4);		// start with a blank string
	 while (cnt != 0)    // loop until all digits are added
   {
		  remainder = tnum % 10;		// use modulo to get the digit
		  tnum = tnum / 10;			    // reduce the number for the next iteration
		  switch (remainder)        // based on the digit, get a character
      {
			   case 0:
				    strncpy(tempStr, "0", 4);
				    break;
			   case 1:
			      strncpy(tempStr, "1", 4);
				    break;
			   case 2:
				    strncpy(tempStr, "2", 4);
				    break;
			   case 3:
				    strncpy(tempStr, "3", 4);
				    break;
			   case 4:
				    strncpy(tempStr, "4", 4);
				    break;
			   case 5:
			 	    strncpy(tempStr, "5", 4);
				    break;
			   case 6:
				    strncpy(tempStr, "6", 4);
				    break;
			   case 7:
				    strncpy(tempStr, "7", 4);
				    break;
			   case 8:
				    strncpy(tempStr, "8", 4);
				    break;
			   case 9:
				    strncpy(tempStr, "9", 4);
				    break;
		  }

		  strncat(tempStr, resultStr, 4);  // add the digit to the front
		  strncpy(resultStr, tempStr, 4);
		  cnt--;
	 }

	 strncpy(rstr, resultStr, 4);
}

// void byteToBinaryStr( char, char*)
// This function takes an integer (forced to a byte length) and the address of a character
// string as its inputs.  It will convert the value of the integer to a binary by dividing
// the number by the base 2 and adding extracted digits in the remainder to a string that is
// returned in the address passed in the inputs.  There is no error checking - any possible
// byte value is valid and it is up to the user to provide reasonable inputs.  The result
// string is padded with leading 0s up to an 8-digit field (11111111 is the max for one byte).
void byteToBinaryStr(unsigned char num, char* rstr)
{
	 // declare some temporary variables to work with
	char resultStr[8];
	char tempStr[8];
	unsigned char tnum = num;
	unsigned char remainder;
	int cnt = 8;
	
	strncpy(resultStr, "", 8);
	while(cnt != 0){
		remainder = tnum % 2;
		tnum = tnum / 2;
		switch (remainder){
			case 0:
				strncpy(tempStr, "0", 8);
				break;
			case 1:
				strncpy(tempStr, "1", 8);
				break;
		}
		strncat(tempStr, resultStr, 8);
		strncpy(resultStr, tempStr, 8);
		cnt--;
		
	}
	
	
	strncpy(rstr, resultStr, 8);
}

// void byteToHexStr( char, char*)
// This function takes an integer (forced to a byte length) and the address of a character
// string as its inputs.  It will convert the value of the integer to a hexadecimal by dividing
// the number by the base 16 and adding extracted digits in the remainder to a string that is
// returned in the address passed in the inputs.  There is no error checking - any possible
// byte value is valid and it is up to the user to provide reasonable inputs.  The result
// string is padded with leading 0s up to a 2-digit field (FF is the max for one byte).
void byteToHexStr(unsigned char num, char* rstr)
{
	 // declare some temporary variables to work with
	char resultStr[2];
	char tempStr[2];
	unsigned char tnum = num;
	unsigned char remainder;
	int cnt = 2;
	
	strncpy(resultStr, "", 2);
	while(cnt != 0){
		remainder = tnum % 16;
		tnum = tnum / 16;
		switch(remainder){
			case 0:
				strncpy(tempStr, "0", 2);
				break;
			case 1:
				strncpy(tempStr, "1", 2);
				break;
			case 2:
				strncpy(tempStr, "2", 2);
				break;
			case 3:
				strncpy(tempStr, "3", 2);
				break;
			case 4:
				strncpy(tempStr, "4", 2);
				break;
			case 5:
				strncpy(tempStr, "5", 2);
				break;
			case 6:
				strncpy(tempStr, "6", 2);
				break;
			case 7:
				strncpy(tempStr, "7", 2);
				break;
			case 8:
				strncpy(tempStr, "8", 2);
				break;
			case 9:
				strncpy(tempStr, "9", 2);
				break;
			case 10:
				strncpy(tempStr, "A", 2);
				break;
			case 11:
				strncpy(tempStr, "B", 2);
				break;
			case 12:
				strncpy(tempStr, "C", 2);
				break;
			case 13:
				strncpy(tempStr, "D", 2);
				break;
			case 14:
				strncpy(tempStr, "E", 2);
				break;
			case 15:
				strncpy(tempStr, "F", 2);
				break;
		}
		
		strncat(tempStr, resultStr, 3);
		strncpy(resultStr, tempStr, 3);
		cnt--;
		
	}
	
	strncpy(rstr, resultStr, 3);
}

