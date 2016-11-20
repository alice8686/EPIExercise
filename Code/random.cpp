*/*/***********************************************************************/
6.11 array Sample offline data
Given an input array A, and a size k.return a subset of size K, all subsets should be equal likely.

1) Brute force: get all subsets, and choose 1

2) Math theory: if all subsets of size k are equal likely,
then the construction process ensure that the subsets of size k+1 are also equal likely.
 K=1, K=2, K=3...K=k.
 //一个一个数generate 一直到k个
T: O(k), S: O(1)
 void RandomSampling(int k, vector<int>& A)
 {
 	default_random_engine generator((random_device())()); //(random_device())()-> generate a real random nubmer use as 'seed'
 	for(int i=0;i<k;i++)
 	{  
 	   int n = static_cast<int>(A.size())-1;
 	   int random_index = uniform_int_distribution<int>{i,n}(generator);
 	   swap(A[i], A[random_index]);
 	}
 }


 3) question: the rand() : return a uniformly ramdom number in [0,RAND_MAX-1]
    Does rand() mod n  generate a  uniformly ditributed in [0,n-1]? no