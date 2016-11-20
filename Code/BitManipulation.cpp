


1.convert signed to unsigned?
2.negative twos complement representation
   -15 = ~15+1

3.Right Propagate the rightmost bits: 01010000 to 01011111
x = x | (x-1)

4.Compute x modulo a power of two: return 13 for 77 mod : number mod 2^n
#include<stdio.h>
/* This function will return n % d.
   d : is a power of 2, must be one of: 1, 2, 4, 8, 16, 32, … 
   useful links: http://www.geeksforgeeks.org/compute-modulus-division-by-a-power-of-2-number/
 */
unsigned int getModulo(unsigned int n, unsigned int d)
{
  return ( n & (d-1) );number & 00000011, power 位数之后的都是余数： 00010000-1 = 00001111（只保留后面这几位）
} 


5.Test if x a power of 2
bool isPowerof2(int x)
{
	return ( (x > 0) && ((x & (x - 1)) == 0) ); // 一定要给 （x&（x-1）） 括号括起来==0， 不然检测 x-1==0

}

*/*/***********************************************************************/

6.Count the number of bits set to one in a number
Brute Force: O(N) : N is the no. of bits in x.
 int countBitsSetTo1(int x)
{
	int count = 0;
	while(x)
	{
       if(x&1==1) 'perform on the twos complement representatiin of x'
       	count++;
       x>>=1;
	}
	return count;
}

2. better solution : O(K), but K = no. of 1s bits in X
int countBitsSetTo1(int x)
{
	// To do: check x is negative - using unsigned int
	int count = 0;
	while(x)
	{
        count++;
        x = x&(x-1); // eliminate the last 1
	}
	return count;
}
*/*/***********************************************************************/

7.compute parity
Way1: Brute force and optimization
short computeParity(unsigned long x)
{
	short result = 0;
	while(x)
	{
	  if(x&1)
      result ^=1;
      x>>=1;'O(N) solution--> could be optimized: x=x&(x-1), O(K) solution, k is the no. of 1s'  
	}
}

for 64 bits inputs, the above code still not very effcient, so we could consider
Way2:  cache some result we have before: like a look up table
O(N/L): L is the mask length(not including built up the table)
1)Build a look up table:
	index: 000000--->22222222: 2^16
	value: paritis:0,1,0,1
2)split 64 bit x into four 16 bits, extract each 16 bits
3)look up parity of each 16 bits, XOR  the four parity
short computeParityUsingCache(unsigned long x)
{
	int length = 16;
	int mask = 0xffff;
	//extract first 16 bits:
	short parity1 = loopUpTable[x>>length*3 & mask];
	short parity2 = loopUpTable[x>>length*2 & mask];
    short parity3 = loopUpTable[x>>length & mask];
    short parity4 = loopUpTable[x & mask];

   //
    return parity1^parity2^parity3^parity4;
}

way3: using XOR communicative: the order of performing XOR does not changed


*/*/***********************************************************************/

8.swap bits

9. compute X*Y
10. compute X/Y
11. compute  X^Y
12. reverse integer
13. Check if a integer is palidorm
14. find the closest no. with same no. of 1s
*/*/***********************************************************************/

136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 Palantir Airbnb
Hide Tags Hash Table Bit Manipulation
Hide Similar Problems (M) Single Number II (M) Single Number III (M) Missing Number (H) Find the Duplicate Number (E) Find the Difference

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto x:nums)
        {
        	result ^=x;
        }
        return result;
    }
};

*/*/***********************************************************************/
371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Hide Company Tags Hulu
Hide Tags Bit Manipulation
Hide Similar Problems (M) Add Two Numbers
https://www.hrwhisper.me/leetcode-sum-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
    int sum = 0, carryin = 0, k=1,temp_a = a, temp_b = b;
    for(int i=0;i<32;i++){//while(temp_a || temp_b){ 
    	//if a<0 OR b<0, >>shift补位为1， 所以a and b never=0.so do not use while
        unsigned ax = a & k, bx = b & k;
        unsigned carryout = (ax & bx) | (ax & carryin) | (bx & carryin);
        sum |= (ax ^ bx ^ carryin);
        carryin = carryout<<1;
       // temp_a>>=1;temp_b>>=1;
        k <<= 1;
    }
    sum = sum | carryin;
    return sum;

    }
};



*/*/***********************************************************************/
338. Counting Bits   
Total Accepted: 52420
Total Submissions: 88990
Difficulty: Medium
Contributors: Admin
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1 s in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:
You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?

Hide Tags Dynamic Programming Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits

/*https://www.hrwhisper.me/leetcode-counting-bits/ */
a)Brute force:

b)Optimization:
1.You should make use of what you have produced already.
2.Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?
'0' 1 2 3 '4' 5 6 7 '8' 9 10 11 12 13 14 15 '16'
'0' 1 1 2 '1' 2 2 3 '1' 2 2  3  2  3  3  4  '1'
[5,7] = [1,3] +1
[9,15] = [1,7] +1
T:O(N) S:O(N)
vector<int> countBits(int num) {
    vector<int> result(num+1,0);
    int before = 0;
    for(int i=1;i<=num;i++)
    {
        if(!(i & (i-1))){
            result[i] = 1;
            before = 1;
          }
        else{
            result[i] = result[before]+1;
            before++;
        }
    }
    return result;
}



*/*/***********************************************************************/
137. Single Number II   QuestionEditorial Solution  My Submissions
Total Accepted: 100834
Total Submissions: 254305
Difficulty: Medium
Contributors: Admin
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Hide Tags Bit Manipulation
Hide Similar Problems (E) Single Number (M) Single Number III
http:/yucoding.blogspot.co.uk/2014/10/single-number-ii.html
Brute force:


Optimization:
T: O(N) S: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned t1 =0, t2 = 0, t3 = 0;
        for(unsigned i=0;i<nums.size();i++)
        {
            int x = nums[i];
            t1 = t1^x;
            t2 = t2 | ((t1^x)&x);/*这次出现了1（x） & (上回出现一次=t1 ^ x(消除掉上一步的影响)）*/
            t3 = t1&t2; /* 1 appear 3 times*/
            /*消除掉 bits that 1 appear 3 times*/
            t3 = ~(t1&t2); 
            t1 = t1&t3;  
            t2 = t2&t3;
        }
        return t1; /* single number only once*/
    }
};
*/***********************************************************************/
190. Reverse Bits   QuestionEditorial Solution  My Submissions
Total Accepted: 82439
Total Submissions: 279150
Difficulty: Easy
Contributors: Admin
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Apple Airbnb
Hide Tags Bit Manipulation
Hide Similar Problems (E) Number of 1 Bits
Have you met this question in a real interview? Yes  

1. brute force solution : iterate through all 32 bits, swap pairwise O(n)
2. Optimization: only swap the bits that is different: < O(n)
    uint32_t reverseBits(uint32_t n) {
        int i=0,j=31;
        while(i<j)
        {
            swapBits(n,i,j);
            i++;j--;
        }
        return n;
    }

    void swapBits(uint32_t n, int i,int j)
    {
        /* first extract ith and j th bits*/
        if((n>>i & 1) !=(n>>j & 1)){
        uint32_t mask = 1<<i | 1<<j;
        n = n^mask;
       }

    }
3. another method
   uint32_t reverseBits(unit32_t n)
   {
       uint32_t result = 0;
       for(int i=0;i<32;i++)
       {
          result+=n&1;
          if(i<31)
          {
            result<<=1;
            n>>=1;
          }
       }
       return  result;
   }


*/*/***********************************************************************/
78. Subsets   
QuestionEditorial Solution  My Submissions
Total Accepted: 124785
Total Submissions: 352644
Difficulty: Medium
Contributors: Admin
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Hide Company Tags Amazon Uber Facebook
Hide Tags Array Backtracking Bit Manipulation
Hide Similar Problems (M) Generalized Abbreviation

T:O(2^n*n) S: O(2^n)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.empty()){
        vector<int> temp;
        result.push_back(temp);
        /* can not write as : result.push_back(new vector<int>()); 因为 ew vector<int>() is a pointer type*/
        return result;
    }
    int n = nums.size();
    for(int i=0;i<pow(2,n);i++)
    {
        vector<int> temp;
        int mask = i;
        for(int j=0;j<nums.size();j++)
        {
            if(mask&1)
            {
                temp.push_back(nums[j]);
            }
            mask>>=1;/*i>>=1; */
            /* you should not use i here, as it is changes, how to use it in next iteration?*/
        }
        result.push_back(temp);

    }
    return result;
}

*/*/***********************************************************************/
318. Maximum Product of Word Lengths 
Total Accepted: 36963
Total Submissions: 88959
Difficulty: Medium
Contributors: Admin
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Bit Manipulation

/*1)Brute force*/  O(n^2 * m) : m is the average words length
/*2) optimization*/ O(n^2 * 26 + m) 
using a binary encode for each words:length 26
mn+n^2

//这里要记住两点
/*1. 要用数组储存转化好的二进制， 而不是在 maxProduct 每次用时convert*/
/*2. helper method 要写在最前面，不然方法里没法识别*/
void stringToBinary(vector<int>& binary, vector<string>& words)
{
    for(int j=0;j<words.size();j++){
    string word = words[j];
    int result = 0;
    for(int i=0;i<word.size();i++)
    {
        int index = word[i] - 'a';/*here not   + '0' 并不是转化， 而是 a:0,b:1， a 作为一个参照*/
        result |= 1<<index;
    }
        binary[j] = result;
    }
}

int maxProduct(vector<string>& words) {
    int max = 0;
    
    if(words.empty())
        return max;
    vector<int> binary(words.size(),0);
    stringToBinary(binary,words);
    for(int i=0;i<words.size();i++){
        for(int j=0; j<words.size();j++)
        {
            if((binary[i] & binary[j]) == 0){
                int length = words[i].size() * words[j].size();
                if(length>max)
                    max = length;
            }
        }
    }
    return max;
}
*/*/***********************************************************************/
389. Find the Difference  
 QuestionEditorial Solution  My Submissions
Total Accepted: 33305
Total Submissions: 66827
Difficulty: Easy
Contributors: Admin
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
Hide Company Tags Google
Hide Tags Hash Table Bit Manipulation
Hide Similar Problems (E) Single Number

/*
int stringToBinary(string& s)
{
   int result = 0;
   for(int i=0;i<s.size();i++)
   {
      int index = s[i] - 'a';
      result |=1<<index;
   }
   return result;
}
char findDifference(string& s, string& t){
    int index = stringToBinary(s) ^ stringToBinary(t);
    char result =  index+'a';
    return result;
}
*/
char 也可以用XOR!!! how? Char->ASCII code--> int-->binary
char findTheDifference(string s, string t) {
        int i = 0, res = 0;
        
        for (i = 0; i < s.size(); i++) {
            res ^= s[i] ^ t[i];
        }
        
        return (res ^ t[i]); // t[i] is the last element in t
}

*/*/***********************************************************************/
169. Majority Element   QuestionEditorial Solution  My Submissions
Total Accepted: 153944
Total Submissions: 349061
Difficulty: Easy
Contributors: Admin
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Company Tags Adobe Zenefits
Hide Tags Array Divide and Conquer Bit Manipulation
Hide Similar Problems (M) Majority Element II

1) brute force: 
a. have two for look, keep track of count of each element, if there is one >n/2, break the loop 
T:O(n^2) S: O(1)
b.using a hash map count each element, then loop through the map check which one is > n/2
T: O(n) s:O(n)

2) bit manipulation algorithm 
   每个bit count 一下
   count>n/2 就用|= 连到 result里
   T: O(32*n) = O(n) S:O(1)
int majorityElement(vector<int>& nums)
{
    int result = 0;
    int size = nums.size();
    for(int i=0;i<32;i++)
    {
      int count = 0;
      for(int j=0;j<size;j++)
      {  
         if(((nums[j]>>i) & 1)==1)
          count ++;
      }
      if(count > (size/2))
        result |= 1<<i;
    }
    return result;
}


3)Using Moore’s Voting Algorithm
int majorityElement(vector<int>& nums)
{
   
}

*/*/***********************************************************************/
397. Integer Replacement   QuestionEditorial Solution  My Submissions
Total Accepted: 9315
Total Submissions: 32661
Difficulty: Medium
Contributors: Admin
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
Hide Company Tags Google Baidu
Hide Tags Math Bit Manipulation
http://www.cnblogs.com/grandyang/p/5873525.html
/*
int integerReplacement(int n)
{
  int count = 0;
  while(n>1){
  if((n&1)==0)// n is a even
  {
    n /=2;
  }else
  {
    n=n-1;
  }
   count ++;
  }
  return count;
}*/

1. recursion
depth between O(logN)  and O(N)
branches: 2
int integerReplacement(int n)
{
  if(n==1)
    return 0;
  if(n%2==0)
    return 1+integerReplacement(n/2);
  else
    //return 1+min(integerReplacement(n+1), integerReplacement(n-1));
    // 这里 如果n = INT_MAX, n+1 will exceed
    // 用2+ ： 就可以直接/2
  {
    long long t = n;
    return 2+min(integerReplacement((t+1)/2), integerReplacement((t-1)/2));
  }
}



2. optimize: iteration
int integerReplacement(int n)
{
   int count = 0;
   // use long long t to avoid integer overflow
   long long t = n;
   while(t>1)
   {
     ++count;
     if((t&1)==0)
     {
       t>>=1;
     }else{
        if(t!=3&&((t&2)==2))  //if((n&2)==1) 检测第二位是不是1 // n+1 就变成4 的倍数， 然后就能一路 /2 到1.
       {
          ++t;
       }else
       --t;
     }
   }
   return count;
}



































