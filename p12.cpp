/**
 * This problem was asked by Amazon.

   There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

   For example, if N is 4, then there are 5 unique ways:

   1, 1, 1, 1
   2, 1, 1
   1, 2, 1
   1, 1, 2
   2, 2
   
   What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
 */


#include <iostream>
#include <vector>
using namespace std;

int getSteps(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	
	return getSteps(n-1) + getSteps(n-2);
}

int getStepsDPUtil(int n) {
	vector<int> f(n+1);
	
	f[0] = 1;
	f[1] = 2;
	
	for (int i = 2; i <= n; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	
	return f[n];
}

int getStepsDP(int n) {
	return getStepsDPUtil(n-1);
}

int main() {
	// your code goes here
	
	cout << "ANS = " << getSteps(4) << " " << getStepsDP(4) << endl;
	cout << "ANS = " << getSteps(1) << " " << getStepsDP(1) << endl;
	cout << "ANS = " << getSteps(6) << " " << getStepsDP(6) << endl;
	return 0;
}
