//
// Created by naser-ir on 03/11/2021.
// 207811282 Naser Rabah

#include "ex2.h"

/*
 * function name: add
 * input : (magntiude,magnitude)
 * output:magnitude
 * this function take 2 magnitude numbers and return the sum of them
 */
magnitude add(magnitude a, magnitude b) {
    // get th numbers without the msb
    int ar = (a & 0b01111111111111111111111111111111);
    int br = (b & 0b01111111111111111111111111111111);
    // if a and b is negative numbers
    if(a>>31 && b>>31){
        // the number zero have two forms
        if (a +b == 0){
            return a+b;
        } else { // if the two numbers are negative the sum must be also negative so we
            // add them without the msb then we set the msb to be 1
            return ((a + b) | (0b10000000000000000000000000000000));
        }
    } else if(a>>31) {
        // if a is negative  it is like doing b-a if a is bigger than b the sum will be negative number
        if(ar > br) { //so we do the add without msb then we set msb to be 1
            return ((ar - br) | (0b10000000000000000000000000000000));
        } else { //if b bigger than a the result will be positive number so the msb will still 0
            return br - ar;
        }
    } else if(b>>31) { // the same we did before but this time we switch between a and b
        if(ar > br) {
            return ar - br;
        } else {
            return ((br - ar) | (0b10000000000000000000000000000000));
        }
    } else { // if the two numbers are positive we jus add them but after that we set the msb to be 0 cause
        // the sum may change it
        return ((a+b)& 0b01111111111111111111111111111111);
    }
} // a + b
/*
 * function name: sub
 * input : (magntiude,magnitude)
 * output:magnitude
 * this function take 2 magnitude numbers and return a-b
 */
magnitude sub(magnitude a, magnitude b) {
    // get th numbers without the msb
    int ar = (a & 0b01111111111111111111111111111111);
    int br = (b & 0b01111111111111111111111111111111);
    if(a>>31 && b>>31) { // if the two numbers are negative it like we doing -a+b
        if (br > ar) { // if b >a the result will be positive
            int sum = br - ar;
            return (sum & 0b01111111111111111111111111111111);
        } else { // if a > b the result will be negative
            int sum = ar - br;
            return sum  | (0b10000000000000000000000000000000);
        }
    } else if (a>>31) { // if b is negative its like we doing -a-b
       int sum = ar + br; // we save the msb 1 and just add the other bit then set the msb to 1
        return (sum | (0b10000000000000000000000000000000));

    } else if (b>>31) { // if the b is negative its like a+b
       int sum = ar + br;
        return (sum & 0b01111111111111111111111111111111);
    } else { // the two numbers are positive so it a-b the same thing like the first if statement it just the opposite
        if (ar >= br){
            return (ar - br) & (0b01111111111111111111111111111111);
        } else {
            int sum = br - ar;
            return  (sum | (0b10000000000000000000000000000000));
        }
    }
} // a - b
/*
 * function name: multi
 * input : (magntiude,magnitude)
 * output:magnitude
 * this function take 2 magnitude numbers and return a*b
 */
magnitude multi(magnitude a, magnitude b) {
    // get th numbers without the msb
    int ar = (a & 0b01111111111111111111111111111111);
    int br = (b & 0b01111111111111111111111111111111);
    if(a>>31 && b>>31) { // two negative number will give positive number
        int sum = ar * br;
        return (sum & 0b01111111111111111111111111111111); // make sur the number is positive
    } else if(a>>31) { // a is negative so the result must be negative numbers
        int sum = br * ar;
        if (sum ==0) { // zero have two forms so make sure when we got zero the result still zero
            return sum;
        } else {
            return (sum | 0b10000000000000000000000000000000);// make sur the number is negative
        }
    } else if(b>>31) { // the same like when a is negative
        int sum = br * ar;
        if (sum ==0) {  // zero have two forms so make sure when we got zero the result still zero
            return sum;
        } else {
            return (sum | 0b10000000000000000000000000000000); // make sur the number is positive
        }
    }
    else {
        return (a*b) & 0b01111111111111111111111111111111;
    }
} // a * b

// true = 1, false = 0
int equal(magnitude a, magnitude b) {
    int ar = (a & 0b01111111111111111111111111111111);
    int br = (b & 0b01111111111111111111111111111111);
    if (ar == 0 && br == 0){ // zero have two forms so make sure when we got zero return equal
        return 1;
    }else if(a>>31 && b>>31) { // if the 2 numbers are negative check if they equal without msb
        if (ar == br) {
            return 1;
        } else {
            return 0;
        }
    } else if (a>>31){ // if a negative and b positive there no equal
        return 0;
    } else if (b>>31) { // if b negative and a positive there not equal
     return 0;
    } else { // if the 2 numbers positive check witch is bigger
        if (a == b) {
            return 1;
        } else {
            return 0;
        }
    }
} // a = b
int greater(magnitude a, magnitude b) {
    int ar = (a & 0b01111111111111111111111111111111);
    int br = (b & 0b01111111111111111111111111111111);
    if (ar == 0 && br==0) { // because zero have two forms
        return 0;
    } else if(a>>31 && b>>31) { // if the 2 numbers are negative check them without the msb
        if(br > ar){
            return 1;
        } else {
            return 0;
        }
    } else if(a>>31) { // if a negative and b positive that mean b>a return 0
        return 0;
    } else if(b>>31) { // if b negative and a positive that mean a>b return 1
        return 1;
    }
    else { // if the two number positive we can check witch bigger the same as if they are integers
        if(ar > br){
            return 1;
        } else {
            return 0;
        }
    }
} // a > b