7.0. Check if a string is palindromic
观察 怎么同时handle odd and even length of string
bool isPalindromic(string& s)
{
	for(int i=0, j = s.size()-1; i<j; i++, j--){ //i<j
		if(s[i] != s[j])
			return false;
	}
	return true;
}

*/
7.1 Inter coverter string and integers
	1. integer to string
	  1 首先怎么extract each digit from integer？
	     integer % 10. 
	  2. 这样只能从最小一位 extract
	  3. 每得到一位数都要放在 result 最前面 // string is an array, insert ar front is O(N)
	  4. 优化：先 放在后面， 最后reverse whole result // time O(N)??

#include <cmath>
	string intergerToString(int num)
	{
		string result = "";
		bool isNegative = false; // do not forget to check negative
		if(num<0)
			isNegative = true;

		while(num){
	    int digit = abs(num)%10;
	    num/=10;
	    result +=digit;
	    }

	    if(isNegative){
	    	result+='-'
	    }
	    return {result.rbegin(), result.rend()}; // contruct a string
	}

	2.string to integer
	int stringToInteger(string& s)
	{
		int result = 0;
		bool isNegative =(s[0]=='-');// do not forget to check negative
		for(int i=isNegative?1:0; i<s.size(); i++)
		{
          result = result * 10 + (s[i]-'0');
		}
		return isNegative? -result: result;
	}

*/
7.2 Base conversion
Input: an string, a int b1, int b2, the string represent a number on base b1, output the string that representing the integer on base b2. 

string BaseConversion(string& s, int b1, int b2){

	// first: convert s to a integer in b1
	int num = 0;
	bool isNegative =(s[0]=='-');// do not forget to check negative
	for(int i=isNegative?1:0; i<s.size(); i++){
        int digit = isdigit(s[i])? s[i]-'0' : s[i]-'A' +10;
		num = num*b1 + digit;
	}
    
    // second: convert num to a string in base 2
    return (isNegative? "-":"") + contructFromBase(num,b2);
}

string contructFromBase(int num, int base)
{
	return num==0?"":contructFromBase(num/base, base) + (char) (num%base>10? 
																('A'+(num%base-10)) 
																: '0' + num%base);
}

*/
7.3 Compute the spreadsheet column encoding..............................................................................................
Columns are identified by : 'A'...'Z','AB'...'ZZ', write a program that convert a Column Id to a integer
'A' -> 1
"D" -> 4
"AA" -> 27
"ZZ" -> 702
Brute force solution: enum the Column Ids until it is ==Input
takes O(26^n)  n is the length of the string

Optimization: 
A-> 1
B-> 2
and a base = 26 integer

int ColumnIDToInteger(string& s)
{
	int result = 0;
	for(int i=0; i<s.size(); ++i){
		result += result*26 + (s[i]-'A' +1)// as A is mapped column 1
	}
	return result;
}


string IntegerToColumnID(int num)
{
	string result;
	do{
		result += (num%26) - 1 +'A';
		num/=26;
	}while(num)
	return {result.rbegin(), result.rend()};
}
*/
7.4 Replace and Remove
For an input string
1. replace each 'a' with 2 'd's
2. delete each 'b'

input : string and a Size, Size is the no. of characters that need to be processed
the string have enough space to hold the final result

basic solution:
iterate forward through string, insert 'dd' when meet 'a', then remove 'b'
insertion/deletion of string is time consuming O(n)
and the total time is O(N^n)

optimization:
iterate twice
iterate forward
first time remove all 'b'
iterate backward
fill the array with 'dd' replace 'a'

void ReplaceAndRemove(string& s, int size)
{
   // iterate forward: remove all b;
   int index = 0;
   int a_count = 0;
   for(int i=0; i<size; ++i)
   {
     if(s[i]!='b'){
     	s[index] = s[i];
     	index++;
 	 }
 	 if(s[i] == 'a')
 	 	a_count++;
   }
   //iterate backward: replace all 'a' with 'dd'
   index = s.size()-1;
   int i = size-1;
   while(i>0){
   	if(s[i]!=a){
   		s[index] = s[i];
   		index --;
   	}else{
        s[index--] = 'd';
        s[index--] = 'd';
   	}
   	i--;
   }
}
*/
7.7 phone mnemonic
// see recursion

*/
7.8 The look and say problem
1,11,21,1211,111221,312211,13112221,1113213211

// Brute force silution:No
// Optimzation:
Time complexity analysis:
Hard to get a precision complexity
每一个数 at most 是之前一个数的 2 倍 length(当前一个数的所有数字都不一样)
-> N iteration, max length（at N iteration） <= 2^(N): O(N-1)*[2^(N-2)] = O(N*2^N)

*/
7.9 Convert from Roman to decimal
I  1
V  5
X  10
L  50
C  100
D  500
M  1000
A Valid roman no. string:
1. symbles appear in non increasing order
2. except:
   I can precede V and X
   X can precede L and C
   C can precede D and M
3. Integer is the sum of symbles other than exceptions
// Brute force silution: 
from left to right:
add the value fo each symbol
Exceptions: add the 'pair' value by caculating : I(S[i+1]) - (S[i])
// Optimzation:
a slight eaiser to code solution: from right to left O(N)

#include <string>
using std::string;
int RomanToInteger(const string& s){// input should be const reference

}

7.9.1  check if a Roman string is valid or not
7.9.2  takes a positive integer, convert to shortest Roman string























