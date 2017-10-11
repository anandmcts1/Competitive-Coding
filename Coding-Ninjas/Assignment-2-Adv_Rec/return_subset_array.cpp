#include<iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n==0)
	{
		output[0][0]=0;
		return 1;
	}
	else
	{
		int smallOutput=subset(input+1,n-1,output);
		int i,j;

		for(i=0;i<smallOutput;i++)
		{
			output[smallOutput+i][0]=output[i][0]+1;
			output[smallOutput+i][1]=input[0];
			for(j=2;j<=output[i][0]+1;j++)
				output[smallOutput+i][j]=output[i][j-1];
		}
		return 2*smallOutput;
	}
}

int main()
{
    int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int output[20][20];

	int length=subset(arr,n,output);
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<output[i][0]+1;j++)
		{
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
}