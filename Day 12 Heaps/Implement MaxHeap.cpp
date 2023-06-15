#include <iostream>
using namespace std;

int flag = 1;

void Maxheap(int arr[], int n, int i)
{
	// Find parent
	int parent = (i - 1) / 2;

	if (arr[parent] > 0) {
		// For Max-Heap
		// If current node is greater than its parent
		// Swap both of them and call heapify again
		// for the parent
		if (arr[i] > arr[parent]) {
			swap(arr[i], arr[parent]);

			// Recursively heapify the parent node
			Maxheap(arr, n, parent);
		}
	}
}

void MaxheapDel(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        MaxheapDel(arr, n, largest);
    }
}

void Insert(int arr[], int &n, int Key)
{
	// Increase the size of Heap by 1
	n = n + 1;

	// Insert the element at end of Heap
	arr[n - 1] = Key;

	// Heapify the new node following a
	// Bottom-up approach
	Maxheap(arr, n, n - 1);
}

void Delete(int arr[], int &n)
{
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    n = n - 1;
 
    // heapify the root node
    MaxheapDel(arr, n, 0);
}

void Display (int a[], int n)
{
    cout<<"\nMax heap array : ";
    for (int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int choice, key, len=0;
    int arr[50];
    
    do
    {
        cout<<"\nPress 1 to display the max heap in level order"<<endl;
        cout<<"\nPress 2 to insert an element in the max heap"<<endl;
        cout<<"\nPress 3 to delete the first element of the max heap"<<endl;
        cout<<"\nPress 0 to exit the program"<<endl;
        
        cin>>choice;
        
        switch (choice)
        {
            case 1 :
                if (flag)
                {
                    cout<<"\nThe heap is empty"<<endl;
                    break;
                }
                Display(arr, len);
                break;
                
            case 2 :
                flag = 0;
                cout<<"\nEnter the value of element that you want to insert : ";
                cin>>key;
                Insert (arr, len, key);
                cout<<"\nInsertion has been done successfully in the max heap"<<endl;
                break;
                
            case 3 :
                if (flag)
                {
                    cout<<"\nThe heap is empty"<<endl;
                    cout<<"Nothing can be deleted"<<endl;
                    break;
                }
                
                Delete (arr, len);
                cout<<"\nDeletion has been done successfully from the max heap"<<endl;
            
            case 0 :
                break;
            
            default :
                cout<<"\nInvalid choice"<<endl;
                cout<<"Please enter valid choice"<<endl;
        }
    } while (choice);
    
    return 0;
}
