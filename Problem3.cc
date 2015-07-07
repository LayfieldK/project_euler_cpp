//The prime factors of 13195 are 5, 7, 13 and 29.

//What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>

//function to determine if input number is prime or not
bool isPrime(long number){
    //we only need to check up to the square root of the input number, as half of the factors will be above this number, and half will be below
    //so we will have covered them all when we reach this index
    for (long j = 2; pow(j,2) < number; j++) {
            if (number % j == 0) {
                return false;
            }
        }
        
        return true;
}

int main() {
    long inputNumber = 600851475143;
    long largePrimeFactor = 0;
    

    //just like for the isPrime function, we only need to check up to the square root of the input number to check every factor
    for(int i = 2; pow(i,2) < inputNumber; i++){
        
        //if the number we are checking evenly divides into the input number, it is a factor
        if (inputNumber % i == 0){
            
            //one factor is our loop index, and the other is the amount of times that it fits evenly into the input number
            long factor1 = i;
            long factor2 = inputNumber / i;
            
            //if either of these factors are prime and they are larger than our current largest prime factor, then set the largest prime factor to this new value
            if (isPrime(factor1) && factor1 > largePrimeFactor){
                largePrimeFactor = factor1;
            }
            if (isPrime(factor2) && factor2 > largePrimeFactor){
                largePrimeFactor = factor2;
            }
        }
    }
    
    //output
    std::cout << largePrimeFactor << std::endl;
}

