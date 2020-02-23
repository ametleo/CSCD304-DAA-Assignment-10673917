#include <iostream>
using namespace std;

int main(){

	int min,max,num=0;
	
	cout<<"Enter the number of values : ";
	
	cin>>num;
	cout<<"Enter the numbers "<<endl;
	int arr[num];
	for(int i = 0; i < num; i++){
		
		cout<<"Number "<< i+1 <<" : ";
		cin>>arr[i];
		cout<<endl;
	}
    	min = arr[0];
		max = arr[0];
	
	for(int j=0;j<num;j++){
		
		if(arr[j]>max){
			max= arr[j];
		}
		
		if(arr[j]<min){
			min=arr[j];
		}
	}
	
	cout<< "The minimum number is : "<<min<<endl;
	cout<<"The maximum number is : "<<max<<endl;
	

return 0;	
}
