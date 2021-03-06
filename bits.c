/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Weston Dransfield
* Summary:
*    This application shows a variety of 'bit tricks' that can be used
*    in place of standart operations.
***********************************************************************/

/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */
#include "btest.h"
#include <limits.h>


/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
    "westonkd+jkevinj",
   /* Student name 1: Replace with the name of first team member */
   "Weston Dransfield",
   /* Login ID 1: Replace with the login ID of first team member */
   "westonkd",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "Kevin Johnson",
   /* Login ID 2: Login ID of the second team member */
   "jkevinj"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 * Returns ~x & ~y
 */
int bitNor(int x, int y) {
   //simply DeMorganize ~(x|y) to get ~x & ~y
  return ~x & ~y;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 *
 * XOR = (x or y) and ~(x and y)
 *     = ~(~x and ~y) and ~(x and y)
 */
int bitXor(int x, int y) {
   //Use the above bitNor (notted) anded with 'not x and y'.
  return ~(~x & ~y) & ~(x & y);
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *
 *  Any number XOR itself is always 0. We just need to use two ! in order
 *  to turn the return value into a 1 or 0.
 */
int isNotEqual(int x, int y) {
   //x XOR y equals zero if x and y are equal
  return !!(x ^ y);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 * Use 0xFF as a mask and then just push the desired byte over to it and and.
 */
int getByte(int x, int n) {
   //shift x to the proper position to apply the mask
   x = x >> (n << 3);

   //AND x and the mask to get the proper bit
  return x & 0xFF;
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 * AND x by 1 to get the LSB. Shift 31 left then 31 right to fill with this bit
 */
int copyLSB(int x) {
   //Get least significant bit then shift left 31. Use the arithmetic right shift
   //to fill the bitstring with that bit
  return (x & 1) << 31 >> 31;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 * To achieve the logical right shift the following happens:
 * 1. Create the number 0111 1111 1111 1111 1111 1111 1111 1111
 * 2. Shift the above number right n-1 bits (>> n << 1).
 * http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/
 */
int logicalShift(int x, int n) {
  //do arithmetic right shift and mask with the proper number
   return (x >> n) & (((~0 ^ (128 << 24)) >> n << 1) + 1);
//return (x >> n) & (1 << 31 >> 31) & ~(1 << 31) >> n << 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
   /* So the idea is to 'divide abd conquer.' It counts the 1's in
      each pair of bits, then in each nibble, then each byte, then
      each pair of bytes, then the whole thing all together.

      "Hacker's Delight" by Henry S. Warren has more on how it is done. */
   int fives   = (((((0x55 << 8 ) | 0x55) << 8 ) | 0x55) << 8 ) | 0x55;
   int threes  = (((((0x33 << 8 ) | 0x33) << 8 ) | 0x33) << 8 ) | 0x33;
   int zerof   = (((((0x0F << 8 ) | 0x0F) << 8 ) | 0x0F) << 8 ) | 0x0F;
   int i = x + ~((x >> 1) & fives) + 1;
   i = (i & threes) + ((i >> 2) & threes);
   i = (i + (i >> 4)) & zerof;
   i = i + (i >> 8);
   i = i + (i >> 16);
   return i & 0x3F;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 * This method first puts all non 0 values into the form 1111. If the value is
 * 0 it puts it stays in the form 00000
 *
 * The final step is to add 1. This overflows 1111 to 0000 and changes 0000 to
 * 0001.
 * http://stackoverflow.com/questions/4764971/implementing-logical-negation-with-only-bitwise-operators-except
 */
int bang(int x) {
   //take advantage of overflow to convert 0000 to 1111 and wxyz to 1111
   //where wxyz are not all zeros
   int converted = ((x >> 31) | ((~x + 1) >> 31));

   //overflow 1111 to 0000 or change 0000 to 0001
   return converted + 1;
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 */
int leastBitPos(int x) {
   int mask = ((~x + 1)) & x;
   return x & mask;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {;
   // take the inverse of 0 to get all 1's, then clear the sign bit
      return ((~0) ^ (128 << 24));
}
/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
   // the first bit is the sign, so check it
   return !(x >> 31);
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
   /* find the xor of the two numbers, determine the most significant different bit,
      then compare the numbers to find where x has a 1 instead of a 0 in y (except sign bit) */

   // take the XOR to find what is different
   int i = x ^ y;
   int msb1 = (0x80 << 24);

   // smear the bits
   i = (i >> 1 ) | i;
   i = (i >> 2 ) | i;
   i = (i >> 4 ) | i;
   i = (i >> 8 ) | i;
   i = (i >> 16) | i;

   // find the most significant different bit
   i = i & (~(i >> 1) | ( msb1 ));

   // make the actual comparison against the numbers and the significant bit
   // (makes use of tmin and tmax)
   i = i & ((x ^ ( msb1 )) & (y ^ ((~0) ^ ( msb1 ))));

   // do !! to force it into a 1 or 0
   return !!i;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 * This method adds a masked sign to the value shifted by n.
 * Adding the masked sign is necessary for negative values.
 * http://stackoverflow.com/questions/5061093/dividing-by-power-of-2-using-bit-shifting
 */
int divpwr2(int x, int n) {
   //create mask
   int mask = ((1 << n) + ~0);

   //add the sign with applied mask and shift by n
   return (x + ((x >> 31) & mask)) >> n;
}
/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
   // find the sign bit
   int sign = (x >> 31) & 1;
   // find the mask
   int mask = (x >> 31);
   // apply the mask and add the sign bit
   return (x ^ mask) + sign;
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 * This method relies on the signs of both a and b and the sign of the sum
 * http://stackoverflow.com/questions/10078778/bitwise-overflow-checking-in-c
 * if a and b have different signs, you cannot get overflow.
 * if they are the same, check that a is different from sum and b is different from sum,
 * if they are the same, then there was no overflow.
 */
int addOK(int x, int y) {
   //the computed sum
   int sum = x + y;

   //sign of the first operand
   int a = x >> 31;

   //sign of the seond operand
   int b = y >> 31;

   //sign of the sum
   int sumSign = sum >> 31;

   //check for overflow and convert to 0000 or 00001
   return (!!(a^b)) | (!(a^sumSign)&!(b^sumSign));
}
