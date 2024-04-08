#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> maxheap; //max heap, by default it will be the max heap
    //for min heap some extra parameters need to be passed
    priority_queue<int, vector<int>, greater<int> > hp;     //now this has become min heap

    //for creating heap from vector
    vector<int> v = {9,6,1,19,3,2,8,12,5};
    priority_queue<int, vector<int>, greater<int> > minhpvector(v.begin(),v.end());

    //creating heap using arr
    int arr[] = {9,6,1,19,3,2,8,12,5};
    priority_queue<int> maxhparray(arr, arr+9);     //creating the max heap
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    
    cout<<hp.top()<<"\n";
    cout<<minhpvector.top()<<"\n";
    cout<<maxhparray.top()<<"\n";

    return 0;
}