#include <iostream>       //standard input-output library
#include <vector>         //vector container for arrays
#include <ctime>          //time library for seeding
#include <cstdlib>        //random number generation

#include "input.h"        //header for input functions
#include "QuickSorter.h"  //header for quicksort logic
#include "NumberList.h"   //header for linked list

using namespace std;       //standard namespace for c++ 

//function prototypes
int menuOption();
void Challenge1();
void Challenge3();
void Challenge4();
void Challenge6();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge10(); 
void Challenge11();
void Challenge12();

//handles main program execution
//controls menu and challenges
//runs selected challenge cases
int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: Challenge1(); break;
        case 3: Challenge3(); break;
        case 4: Challenge4(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 9: Challenge9(); break;
        case 10: Challenge10(); break;
        case 11: Challenge11(); break;
        case 12: Challenge12(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;

}

//displays menu for selection
//prompts user for valid option
//returns user selected integer
int menuOption()
{
    system("cls");
    cout << "\n\tCMPR121 Chapter 20: Recursion (page 1255-1256) by Francisco Bumanglag";
    cout << "\n\t" << string(90, char(205));
    cout << "\n\t\t 1. Iterative Factorial";
    cout << "\n\t\t 3. QuickSort Template";
    cout << "\n\t\t 4. Recursive Array Sum";
    cout << "\n\t\t 6. Recursive Power Function";
    cout << "\n\t\t 7. Sum of Numbers";
    cout << "\n\t\t 8. isMember Function";
    cout << "\n\t\t 9. String Reverser";
    cout << "\n\t\t10. maxNode Function";
    cout << "\n\t\t11. Palindrome Detector";
    cout << "\n\t\t12. Ackermann's Function";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\t\t0. Exit";
    cout << "\n\t" << string(90, char(205));

    return inputInteger("\n\t\tOption: ", 0, 12);
}


//challenge 1 --iteratively calculates factorial of n
//loops from n down to 1
//returns final factorial result
long long factorialIterative(long long n) {
    long long result = 1;
    for (long long i = n; i > 0; i--) {
        result *= i; //multiply result by current i
    }
    return result; //return final factorial
}

//challenge 1 -- recursively calculates factorial of n
//checks if base case met
//multiplies n with recursive call
long long factorialRecursive(long long n) {
    if (n == 0) {
        return 1; //base case for recursion
    }
    else {
        return n * factorialRecursive(n - 1); //recursive case for factorial
    }
}

//Challenge 1 function
void Challenge1()
{
    system("cls");

    cout << "\t1. Iterative Factorial";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tWrite an iterative version(using a loop instead of recursion) of the factorial function";
    cout << "\n\tshown in this chapter.Test it with a driver program."; 

    long number = inputInteger("\n\n\tEnter the number (1...20): ", 1,20);

    cout << "\n\tFactorial (iterative) of " << number << " : " << factorialIterative(number);
    cout << "\n\tFactorial (recursive) of " << number << " : " << factorialRecursive(number) << "\n";
}

//challenge 3 //formats array into string output
//loops through each array element
//adds commas between array values
string formatArray(const int* array, int size) {
    stringstream output; //initialize string stream
    for (int i = 0; i < size; ++i) {
        output << array[i]; //add current element to output
        if (i < size - 1) {
            output << ", "; //add comma between elements
        }
    }
    return output.str(); //return formatted string
}

//challenge 3 fucntion
void Challenge3() {
    system("cls");
    srand(static_cast<unsigned int>(time(0)));

    cout << "\n\t3. QuickSort Template";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tCreate a template version of the QuickSort algorithm that will work with any data";
    cout << "\n\ttype. Demonstrate the template with a driver function.";

    //get array size
    int size = inputInteger("\n\n\tEnter a size (1..100) of the dynamic integer array: ", 1, 100);

    //dynamically allocate an array and populate it with random values
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100; //random values between 0 and 99
    }

    //create a QuickSorter object
    QuickSorter<int> sorter;

    //display original array
    cout << "\n\nRandomly unsorted array: ";
    cout << formatArray(array, size) << endl;

    //sort the array
    sorter.quickSort(array, size);

    //display sorted array
    cout << "\nQuickSorted array: ";
    cout << formatArray(array, size) << endl;

    //free allocated memory
    delete[] array;
}

//challenge 4 - calculates sum using recursion
//base case returns first element
//recursive step adds current value
int ArraySumRecursive(int* array, int size, int index) {
    if (index == 0) //check for base case
        return array[0]; //return first element
    else
        return array[index] + ArraySumRecursive(array, size, index - 1); //recursive call
}

//challenge 4 - calculates sum using iteration
//initializes sum to zero
//loops through all array elements
int ArraySumIterative(int* array, int size) {
    int sum = 0; //initialize sum variable
    for (int i = 0; i < size; i++) //iterate over array
        sum += array[i]; //add current element to sum

    return sum; //return final sum
}

//challenge 4 fucntion
void Challenge4()
{
    system("cls");

    srand(static_cast<unsigned int>(time(0)));

    cout << "\n\t4. Recursive Array Sum";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tWrite a function that accepts an array of integers and a number indicating the number";
    cout << "\n\tof elements as arguments. The function should recursively calculate the sum of all the"; 
    cout << "\n\tnumbers in the array. Demonstrate the function in a driver program. ";

    int size = inputInteger("\n\n\tEnter a size (1..100) of the dynamic integer array: ", true);

    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 100; //generate random numbers between 0 and 99
        cout << (i == 0 ? "\n\nRandom array: " : "") << *(array + i) << (i < size - 1 ? ", " : "");
    }

    cout << "\n\n\tSum of the array (iterative) : " << ArraySumIterative(array, size);
    cout << "\n\tSum of the array (recursive) : " << ArraySumRecursive(array, size, size-1) << '\n';

    delete[] array;
}


//challenge6 - recursive function to calculate power
long long powerRecursive(int base, int exponent) {
    if (exponent == 0) {
        return 1; //base case: any number to the power of 0 is 1
    }
    return base * powerRecursive(base, exponent - 1); //recursive step
}

//challenge 6 function
void Challenge6() {
    system("cls");

    cout << "\t6. Recursive Power Function";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tWrite a function that uses recursion to raise a number to a power. The function should";
    cout << "\n\taccept two arguments: the number to be raised and the exponent. Assume that the";
    cout << "\n\texponent is a nonnegative integer. Demonstrate the function in a program.";

    //get base number
    int base = inputInteger("\n\n\tEnter a number for x (1..100): ", 1, 100);

    //get exponent number
    int exponent = inputInteger("\n\tEnter a number for y (0..100): ", 0, 100);

    //calculate power using the recursive function
    long long result = powerRecursive(base, exponent);

    // Display the result
    cout << "\n\n\tPower(" << base << ", " << exponent << ") = " << result << "\n";
}

//challenge 7 -- sums integers using iteration
//initializes sum to zero
//adds all numbers sequentially

int SumIterative(int n) {
    int sum = 0; //initialize sum variable
    for (int i = 0; i <= n; i++) //iterate through range
        sum += i; //add current number to sum

    return sum; //return final sum
}

//challenge 7 -- sums integers using recursion
//base case checks for zero
//adds current number to recursion
int SumRecursive(int n) {
    if (n == 0) //check base case for zero
        return 0; //return zero for base case

    if (n == 1) //check base case for one
        return 1; //return one for base case

    return n + SumRecursive(n - 1); //recursive call with n-1
}

//challenge 7 function
void Challenge7()
{
    system("cls");

    cout << "\t7. Sum of Numbers"; 
    cout << "\n\t" << string(60, char(196));
    cout << "\n\tWrite a function that accepts an integer argument and returns the sum of all the integers";
    cout << "\n\tfrom 1 up to the number passed as an argument. For example, if 50 is passed as"; 
    cout << "\n\tan argument, the function will return the sum of 1, 2, 3, 4, ... 50. Use recursion"; 
    cout << "\n\tto calculate the sum. Demonstrate the function in a program."; 

    long number = inputInteger("\n\n\tEnter the number: ", true);

    cout << "\n\tSum (iterative) of " << number << " : " << SumIterative(number);
    cout << "\n\tSum (recursive) of " << number << " : " << SumRecursive(number) << "\n";
}

//challenge 8 -- recursive function to check if a value exists in the array
bool isMember(const int* array, int size, int value) {
    if (size == 0) {
        return false; //base case: array is empty, value not found
    }
    if (array[size - 1] == value) {
        return true; //base case: value found
    }
    return isMember(array, size - 1, value); //recursive step
}

//challenge 8 function
void Challenge8() {
    system("cls");

    cout << "\t8. isMember Function";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tWrite a recursive Boolean function named isMember. The function should accept two";
    cout << "\n\targuments: an array and a value. The function should return true if the value is found";
    cout << "\n\tin the array, or false if the value is not found in the array. Demonstrate the function";
    cout << "\n\tin a driver program.";

    //get the size of the array
    int size = inputInteger("\n\n\tEnter a size (1..100) of the array of integers: ", 1, 100);

    //dynamically allocate and populate the array with random values (1 to 100)
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1; //random numbers between 1 and 100
    }

    //display the array
    cout << "\n\nArray: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << (i < size - 1 ? ", " : "\n");
    }

    //get the value to search for
    int value = inputInteger("\n\tEnter an integer value: ", 0, 100);

    //use the isMember function to check if the value exists in the array
    bool found = isMember(array, size, value);

    //display the result
    if (found) {
        cout << "\n\tThe integer value is found in the array.\n";
    }
    else {
        cout << "\n\tThe integer value is not found in the array.\n";
    }

    //clean up allocated memory
    delete[] array;
}


//challenge9 -- recursive function to reverse a string
void reverseString(const string& input, int index) {
    if (index < 0) {
        return; //base case: End recursion
    }
    cout << input[index]; //print current character
    reverseString(input, index - 1); //recursive call with the previous index
}

//challenge 9  function
void Challenge9() {
    system("cls");

    cout << "\t9. String Reverser";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tWrite a recursive function that accepts a string object as its argument and prints the";
    cout << "\n\tstring in reverse order. Demonstrate the function in a driver program.";

    //prompt user to enter a string
    cout << "\n\n\tEnter a string: ";
    string input;
    getline(cin, input); //read the input string

    //print the reversed string
    cout << "\n\tReversed string: ";
    reverseString(input, input.length() - 1);
    cout << endl;
}

//challenge 10 fucntion
void Challenge10()
{
    system("cls");

    cout << "\t10. maxNode Function";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tAdd a member function named maxNode to the Numberlist class discussed in this chapter.";
    cout << "\n\tThe function should return the largest value stored in the list. Use recursion in";
    cout << "\n\tthe function to traverse the list. Demonstrate the function in a driver program.\n";

    //create a NumberList object
    NumberList list;

    //populate the list with random values
    srand(static_cast<unsigned int>(time(0)));
    int size = rand() % 15 + 1; // Random size between 15 and 20
    for (int i = 0; i < size; ++i)
    {
        list.appendNode(static_cast<double>(rand() % 1000) / 100.0); //random doubles between 0.0 and 10.0
    }

    //display the list
    cout << "\n\tNumberList:\n";
    list.displayList();

    //find and display the largest value
    double maxVal = list.maxNode();
    cout << "\n\tThe largest value stored in the list is " << maxVal << ".\n";
}



//challenge 11 -- recursive function to check if a string is a palindrome
bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end)
        return true; //base case: all characters matched
    if (str[start] != str[end])
        return false; //characters at start and end do not match
    return isPalindrome(str, start + 1, end - 1); //recursive case
}

//challenge 11 function
void Challenge11() {
    system("cls");

    cout << "\tn11. Palindrome Detector";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tA palindrome is any word, phrase, or sentence that reads the same forward and backward.";
    cout << "\n\tHere are some well-known palindromes:";
    cout << "\n\n\tAble was I ere I saw Elba";
    cout << "\n\tAmanap lanacanal Panama";
    cout << "\n\tDesserts I stressed";
    cout << "\n\tKayak";
    cout << "\n\n\tWrite a bool function that uses recursion to determine if a string argument is a palindrome.";
    cout << "\n\tThe function should return true if the argument reads the same forward and backward.";
    cout << "\n\tDemonstrate the function in a program.\n";

    //input
    string input;
    cout << "\n\n\tEnter a string: ";
    getline(cin, input);

    //normalize the string: remove non-alphanumeric characters and convert to lowercase
    string filtered;
    for (char ch : input) {
        if (isalnum(ch))
            filtered += tolower(ch);
    }

    //check if the filtered string is a palindrome
    if (isPalindrome(filtered, 0, filtered.length() - 1)) {
        cout << "\n\tThe string is a palindrome.\n";
    }
    else {
        cout << "\n\tThe string is not a palindrome.\n";
    }
}

//challenge12 -- recursive function for Ackermann's Function
unsigned long long ackermann(unsigned long long m, unsigned long long n) {
    if (m == 0)
        return n + 1; //base case: if m = 0
    else if (n == 0)
        return ackermann(m - 1, 1); //recursive case: if n = 0
    else
        return ackermann(m - 1, ackermann(m, n - 1)); //recursive case: m > 0 and n > 0
}

//challenge 12 fucntion
void Challenge12() {
    system("cls");

    cout << "\t12. Ackermann's Function";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\tAckermann's Function is a recursive mathematical algorithm that can be used to";
    cout << "\n\ttest how well a computer performs recursion. Write a function A(m, n) that solves";
    cout << "\n\tAckermann's Function. Use the following logic in your function:";
    cout << "\n\t\tIf m = 0 then return n + 1";
    cout << "\n\t\tIf n = 0 then return A(m - 1, 1)";
    cout << "\n\t\tOtherwise, return A(m - 1, A(m, n - 1))";

    //test cases to demonstrate Ackermann's function
    cout << "\n\n\tTest your function in a driver program that displays the following values:";
    cout << "\n\tA(0, 0), A(0, 1), A(1, 1), A(1, 2), A(1, 3), A(2, 2), A(3, 2)\n";

    //display predefined test cases
    cout << "\n\tA(0, 0) = " << ackermann(0, 0);
    cout << "\n\tA(0, 1) = " << ackermann(0, 1);
    cout << "\n\tA(1, 1) = " << ackermann(1, 1);
    cout << "\n\tA(1, 2) = " << ackermann(1, 2);
    cout << "\n\tA(1, 3) = " << ackermann(1, 3);
    cout << "\n\tA(2, 2) = " << ackermann(2, 2);
    cout << "\n\tA(3, 2) = " << ackermann(3, 2);

    //input for user-defined m and n
    unsigned long long m, n;

    cout << "\n\n\tEnter a number for m (0..3): ";
    m = inputInteger("\t", 0, 3);

    cout << "\n\tEnter a number for n (0..3): ";
    n = inputInteger("\t", 0, 3);

    //display result for user-defined m and n
    cout << "\n\tA(" << m << ", " << n << ") = " << ackermann(m, n) << "\n";
}
