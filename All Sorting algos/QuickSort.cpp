# include<bits/stdc++.h>
using namespace std; 

int partition(vector<int>&arr,int s,int e){
    
    int pivot = arr[s];
    int cnt =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot) cnt++;
    }

    // place pivot elememt
    int pivotIndex = s + cnt;

    swap(arr[s],arr[pivotIndex]);

    // manage left and right part
    int i=s,j=e,mid;

    while(i<pivotIndex && j>pivotIndex){

        while(arr[i]<pivot) i++;
        

        while(arr[j]>pivot) j--;

        // agar break
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
            i++,j--;
        }

    }

    return pivotIndex;



}

void quickSort(vector<int>&a,int s,int e){
    if(s>=e) return;

    int p = partition(a,s,e);

    // left part ko handle
    quickSort(a,s,p-1);
    // right part ko handle
    quickSort(a,p+1,e);

}

int main(){
    vector<int>a = {1,4,2,5,6,8,7,7};
    int n = a.size();
    int s = 0,e = n-1;
    quickSort(a,s,e);
    
    for(int i: a) cout<<i<<" ";
        


 return 0;
}