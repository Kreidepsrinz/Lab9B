/*
* Programmers block
Name: Jennifer Wilson
Student Number: A01411257
Description: This program rotates the bits in an int data type, by one bit to the left each time it is called.
*/

//no deprecate codes
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1

//include files
#include <stdio.h> //printf(), scanf()
#include <conio.h> //getch(), kbhit()
#include <windows.h> //sleep
#define ESC 27
#define BS 8 //backspace  
#define MASK0 0x00000001 //for bit rotation
#define MASK31 0x80000000 //for bit rotation

//function prototypes
int Rotate(int val);
void DisplayBits(int iValue);

int main(void)
   {
   printf("Lab 9_B by Jennifer Wilson.\n");
   printf("This program rotates the bits in an int data type, by one bit to the left each time it is called.\n");

   int num;
   printf("\nEnter a number: ");
   scanf("%d", &num);

   printf("\nPress ESC to exit\n\n");

   while (1) //infinite loop
      {
      DisplayBits(num); //prints the bits to the screen
      Sleep(500); //pause for 500 milliseconds
      printf("\r");
      num = Rotate(num); //rotates the bits, does not print to the screen

      if (kbhit() && getch() == 27)
         exit(0); //exits the program if ESC is pressed
      }
   return 0;
   } //end program

//----------------------------------------------------------------------
//function definition:
int Rotate(int val)
   {
   int newVal; //new value after rotation
   newVal = val << 1; //shift value 1 bit to left

   if (val & MASK31) //if the 31st bit is set
      newVal |= MASK0; //set the 0th bit to 1
   else
      newVal &= ~MASK0; //else set the 0th bit to 0

   return newVal;
   }

void DisplayBits(int iValue)
   {
   int iBitCount; //bit counter
   int iMask = 1 << 31; //bit mask

   for (iBitCount = 1; iBitCount <= 32; iBitCount++)
      {
      if (iValue & iMask)
         putchar('1');
      else
         putchar('0'); //endifelse

      iValue <<= 1; //shift value 1 bit to left
      } //endfor
   } //endDisplayBits

