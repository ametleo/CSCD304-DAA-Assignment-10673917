#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
using namespace std;
 
void print_array(int arr[], int size);
void generate_random_entries(int arr[], int size);
void merge_sort_and_plot();
void Merge(int *a, int low, int high, int mid)
{
	
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}
 
 void merge_sort_and_plot() {
    ofstream file_writer;
    file_writer.open("data.csv");
    for (int arr_size = 50; arr_size < 20000; arr_size+=50) {
        int arr[arr_size];
        generate_random_entries(arr, arr_size);

        chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();
        merge_sort(arr, 0, arr_size - 1);
        chrono::steady_clock::time_point stop = chrono::high_resolution_clock::now();

        chrono::steady_clock::duration duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        file_writer << arr_size << "\t" << duration.count() << endl;
    }
    file_writer.close();
    cout << "Data is ready to be plotted" << endl;
}

 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"\n->"<<arr[i];
 			
	return 0;
}
void print_array(int arr[], int size) {
    for (size_t i = 0; i < size; ++i) {
        if (i > 0) cout << ", ";
        cout << arr[i];
    }
    cout << endl;
}

void generate_random_entries(int arr[], int size) {
    srand((unsigned) time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
