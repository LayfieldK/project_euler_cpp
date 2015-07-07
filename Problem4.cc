//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

//Find the largest palindrome made from the product of two 3-digit numbers.



#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

//the compiler I'm using has problems with std::to_string, so here is a workaround function that does the same thing
template <typename T>
std::string to_string(T value)
{
	std::ostringstream oString ;
	oString << value ;
	return oString.str() ;
}


//function to determine if input number is a palindrome
bool isPalindrome(string number){
    
    //create duplicate variable to hold reverse of input string number
    string reverseNumber = number;
    std::reverse(reverseNumber.begin(), reverseNumber.end());
    
    //if the input and the reverse are the same, it is a palindrome
    if (number == reverseNumber){
        return true;
    } else {
        return false;
    }
}

int main() {
    
    //smallest and largest 3 digit numbers
    int minNum = 100;
    int maxNum = 999;
    int largestPalindrome = 0;
    
    //every combination of two 3 digit numbers
    for (int i = minNum; i <= maxNum; i++){
        
        //inner loop always starts at one more than the outer loop's index so as to not try the same numbers multiple times
        for (int j = i + 1; j <= maxNum; j++){
            
            //convert product of two numbers to string
            int product = i * j;
            string strProduct = to_string(product);
            
            //if the number is a palindrome and it is a larger number than the previously largest palindrome, reset the variable
            if (isPalindrome(strProduct) && product > largestPalindrome){
                largestPalindrome = product;
            }
        }
    }
        
    //output
    std::cout << largestPalindrome << std::endl;
}

