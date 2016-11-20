
*/*/1.reorder the array so that the even entry appear first
2 Partition

void 2Partition(const vector<int>& A)
{   int even = 0, odd = A.size()-1;
    while(even < odd)
    {
       if(A[even]%2==0)
        even ++;
      else
        swap(A[even], A[odd--]);
    }
}

*/*/6.1. DutchFlagPartition
Give a pivot, reorder the array  that all element less than pivot appear first, followed by all elements equal to the pivot, 
and element > pivot appear last

1) Brute force: using an S: O(N), time : O(N)


2) optimization1. iterate twice S: O(1), time : O(2N)
void DutchFlagPartition(int pivot_Index, vector<Color>& A_ref)
{
	//iterate 1: 2 pointer method,  move all smaller in front

	//iterate 2: 2 pointer method move all larger to the end

}

3) optimization2.: two pointers: S: O(1), time : O(N)

typedef enum{RED, WHITE, BLUE} Color;
void DutchFlagPartition(int pivot_Index, vector<Color>& A_ref)
{
     int l = 0, e = 0, r = A_ref.size()-1;
     int pivot = A_ref[pivot_Index];
     while(l < r)
     {
         if(A_ref[e]<pivot){
         	swap(A_ref[e], A_ref[l])
         	e++; l++;
         }else if(A_ref[e]=pivot){
         	e++;
         }else{
            swap(A_ref[e], A_ref[r]);
            e++, l--;
        }

     }
}

*/*/6.2. Increment an arbitrary-precision integer
given an array <1,2,9> --> <1,3,0>
1) brute force: convert array to the number, +1, convert back
                when the number exceed the limit that the language can accept, this will not work
2) do it directly in an array
   void plusOne(vector<int>& A)
   {
   	  int n = A.size();
   	  A[n]++;
   	  for(int i=n;i>0 && A[i]==10;i--){
   	      A[i] = 0;
   	      A[i-1]++;
   	  }
   	  //1 carry out at the most sig digit
   	  if(A[0]==10){
   	  	A[0]=0;
   	  	A.insert(A.begin,1);
   	  }
   }


*/*/6.16 Pint A matrix in Sprial Way
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;


//1) T:O(n^2) S:O(1)

void print_matrix_clockwise(const vector<vector<int>> &A, int offset);

// @include
void print_matrix_in_spiral_order(const vector<vector<int>> &A) {
  for (int offset = 0; offset < ceil(0.5 * A.size()); ++offset) {
    print_matrix_clockwise(A, offset);
  }
}

void print_matrix_clockwise(const vector<vector<int>> &A, int offset) {
  if (offset == A.size() - offset - 1) {  // for matrix with odd size.
    cout << A[offset][offset];
  }

  for (int j = offset; j < A.size() - offset - 1; ++j) {  // top row
    cout << A[offset][j] << ' ';
  }
  for (int i = offset; i < A.size() - offset - 1; ++i) { // last column
    cout << A[i][A.size() - offset - 1] << ' ';
  }
  for (int j = A.size() - offset - 1; j > offset; --j) {// bottom row
    cout << A[A.size() - offset - 1][j] << ' ';
  }
  for (int i = A.size() - offset - 1; i > offset; --i) { // first column
    cout << A[i][offset] << ' ';
  }
}

/*2) T:O(n^2) S:O(1)
Optimization: merge 4 foor lop toghther*/

// @include
void print_matrix_in_spiral_order(vector<vector<int>> A) {
  const array<array<int, 2>, 4> shift = {{
                                          {{0, 1}}, // R stable, incre C , first row ++
                                          {{1, 0}}, // R incre , stable Y, last column ++
                                          {{0, -1}},  // R stable , decre Y, last row --
                                          {{-1, 0}}
                                          }}; // R dec , stable Y, first column --
  int dir = 0, x = 0, y = 0;

  for (int i = 0; i < A.size() * A.size(); ++i) {
    cout << A[x][y] << ' ';
    A[x][y] = 0;
    int nx = x + shift[dir][0], ny = y + shift[dir][1];
    if (nx < 0 || nx >= A.size() || ny < 0 || ny >= A.size() ||
        A[nx][ny] == 0) {
      dir = (dir + 1) & 3; // dir = 0,1,2,3
      nx = x + shift[dir][0], ny = y + shift[dir][1];
    }
    x = nx, y = ny;
  }
}
// @exclude

*/*/6.16 Rotate A matrix in 90 degrees

T:O(n^2)  S: O(1)
void rotate_matrix(vector<vector<int>>& A) {
  int max_Index = A.size() - 1;
  for (int i = 0; i < (A.size() >> 1); ++i) {//第几圈： i=0 最外圈， i=1
    for (int j = i; j < max_Index-i; ++j) {// n-1,n-2
      int temp = A[i][j];
      A[i][j] = A[max_Index - j][i];
      A[max_Index - j][i] = A[max_Index - i][max_Index - j];
      A[max_Index - i][max_Index - j] = A[j][max_Index - i];
      A[j][max_Index - i] = temp;
    }
  }
}

*/*/6.16 check if a Sudoku is valid

S: O(N^2)
bool  SudokuChecker(const vector<vector<int>>& A)
{

    // special case:

    // 1. A.empty
     if(A.empty())
      return false;
    //2. Rowsize != 9 or Colsize !=9
    if(A.size() !=9 || A[0].size()!=9)
      return false;
    // first check every row is ok
    for(int i=0; i<A.size(); ++i)
    {
        if(HasDuplicate(i,i+1,0,A.size()))
          return false;
    }

    // first check every column is ok
    for(int i=0; i<A[0].size(); ++i)
    {
        if(HasDuplicate(0,A.size(), i,i+1))
          return false;
    }

    // first check every squre is ok
    int SqSize = sqrt(A.size());

    for(int m=0; m<SqSize; ++m )
    {
        for(int n=0 ; n<SqSize; ++n)
        {
          if(HasDuplicate(SqSize*m,SqSize*m+SqSize,SqSizen*n, SqSize*n+SqSize))
          //(m,m+SqSize,n,n+SqSize)-这样每次 m+1, n+1 相当于移动一个， 我们要移动 SqSize 个 
            return false;
        }
    }
}

bool HasDuplicate(const vector<vector<int>>& A, int startRow, int endRow, int startCol, int endCol)
{
    vector<bool> is_found(A.size(), false);// 因为每次只检测9个数。。
    for(int i=startRow; i<endRow; ++i)
    {
      for(int j=startCol; j<endCol; ++j)
      {
         index = A[i][j];  // 忘记在parameter里加上A了
         if(is_found[index] && index!=0)// forget check if the cell is empty 
          return true;
        else
          is_found[index] =  true;
      }
    }
    return false;
}




*/*/6.19 Print Pascal Triangle
1
11
121
1331
14641





*/*/6.8 Enumrate all primes to n

1 brute force: T:O(N* sqrt(N)) S:O(N)
  for each(i=1 to =n)
  check if(isPrime(i));
  
  isPrime(i)
  {
    for each (j=2 to <sqrt(n))//n-1) // here it should go to sqrt(N):N开根号
      i%j!=0
  }

2. optimize using extra space:
idea: has a array store true/false for each number, 
if a number is a prime, all its multiple to n is not prime
S:O(n) T: NloglogN

vector<int> enumPrimes(int n)
{
    vector<int> result;
    vector<bool> is_prime(n,true);
    is_prime[0] = is_prime[1] = false;
    result.emplace_back(1);
    for(int i=2;i<=n;++i)
    {
       bool isPrime = true;
       /* you do not need to check this anymore
       if(is_prime[i-1]){ // only check the ones that is not  false
         you do not need to check any more
         for(int j=2;j<n;++j){
          if(i%j==0)
            isPrime = false;
            is_prime[i-1] = false;
         }
        }
       */

       if(is_prime[i-1]){
          result.emplace_back(i);
          //int a=2; no need to use this, using '+=i';
          //if a number is a prime, all its multiple to n is not prime
          for(int m = i*2; m<=n; m+=i) // for(int m = i*a; m<=n; m*=a)
          {
             is_prime[m-1] = false;
             //++a;
          }
       }
    }

    return result;
}



*/*/6.5 Delete duplicates from a sorted array - 2 pointer method 

*/*/6.4 advancing through an array
/*Takes an array of n integers, where A[i] denotes the maximum you can advance from index i, 
and returns weather it is possible to advance to last index start from begining of the array
T O(N) , S: O(1)
*/
bool CanReachEnd(const vector<int>& A)
{
 int furthest_so_far = 0, last_index = A.size()-1;
 for(int i=0; i<=furthest_so_far && furthest_so_far<last_index; ++i) // i> furthest_so_far means:根本走不到i
 {
    furthest_so_far = max(furthest_so_far, A[i]+i);
 }
 return furthest_so_far >= last_index;
}
/*
 variant:
   compute the minimum no. of steps needed to advance to the end: see recursion & DP
   */
int CanReachEnd(const vector<int>& A)
{
 int furthest_so_far = 0, last_index = A.size()-1, count = 0;
 for(int i=0; i<=furthest_so_far && furthest_so_far<last_index; ++i) // i> furthest_so_far means:根本走不到i
 {
    if(furthest_so_far < A[i]+i){
      count++;
    furthest_so_far = A[i]+i;
    }
    if(furthest_so_far==last_index)
      break;

 }
 return count;
}


*/*/6.6 Buy and selling a stock once
/*iterate through the array:
1. update min seen so far 
2. diff = compute(price[i]-min), 
3. update max if diff>max
*/
#include <limits> // numeric_limits : min max
#include <algorithm>// min, max
double BuyAndSellStockOnce(const vector<double>& prices)//(vector<int>& prices) : 1. const 2. double is better than int for prices
{
   int double = numeric_limits<double>::min(), min_so_far = numeric_limits<double>::max();
   for(int i=0; i< prices.size(); i++)
   {
      min_so_far = min(min_so_far, prices[i]);
      maxTotal = max(maxTotal, prices[i]-min_so_far);
   }
   return maxTotal;
}



*/*/6.6 Buy and selling a stock twice
/*1. 正着 iterate 一遍
    update min;
   f[i] = (maxTotal, price[i]-min)
2. 反着 iterate 一遍
     update max;
     maxTotal = (maxTotal, max - price[i] + f[i-1])
return maxtotal
*/

#include <limits> // numeric_limits : min max
#include <algorithm>// min, max
double BuyAndSellStockTwice(const vector<double>& prices)
{
   vector<double> forward_max(prices.size(),0);
   double maxTotal = numeric_limits<double>::min(), min_so_far = numeric_limits<double>::max();
   for(int i=0; i< prices.size(); ++i)
   {
      min_so_far = min(min_so_far, prices[i]);
      maxTotal = max(maxTotal, prices[i]-min_so_far);
      forward_max[i] = maxTotal;
   }

   double max_so_far = numeric_limits<double>::min();
   for(int i=prices.size()-1; i>0; --i)
   {
      max_so_far = max(max_so_far, prices[i]);
      maxTotal = max(maxTotal, max_so_far - prices[i] +  forward_max[i-1]);
   }
   return maxTotal;
}


*/*/Apply Permutation
重点在于： cyclic 解读 permutatation
ex:P:  1,2,3,0
P[0] = 1 : [0] <- A[1] 
[1]空出来了， 谁去了[1]? check P[1] = 2 : [1]<-A[2] 
P[2] = 3 : [2] <- A[3]  
P[3] = 0 : [3] <- A[0] 


#ifndef SOLUTIONS_PERMUTATION_ARRAY1_H_
#define SOLUTIONS_PERMUTATION_ARRAY1_H_

#include <algorithm>
#include <vector>

using std::vector;

// @include
void apply_permutation1(vector<int>* perm, vector<int>* A) {
  for (int i = 0; i < P->size(); ++i) {
      int next = i;
      while(p[next] >=0)
      {
        int elementComeEmpty = p[next]; // who comes to next?
        swap(A[next], A[elementComeEmpty]); // put 'elementComeEmpty' to 'next', put  'next' to elementComeEmpty;
         
        p[next] -=p.size(); // mark as done
        next = elementComeEmpty;  // who comes to  'elementComeEmpty' ?
      }
  }

  // Restore perm back.
  for_each(perm->begin(), perm->end(), [&](int &x) { x += perm->size(); });
}
// @exclude
#endif  // SOLUTIONS_PERMUTATION_ARRAY1_H_


