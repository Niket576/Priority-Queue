#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
using namespace std;

class MaxHeap {
    vector<int> hp;
    void upheapify(int ci) {    //ci = child index
        while(ci > 0) {
            int pi = (ci - 1) / 2;  //by default floor value in c++
            if(hp[pi] < hp[ci]) {   //this can also be written as if(this->hp[pi]) < this->hp[ci] : this is good way
                swap(hp[pi],hp[ci]);
                ci = pi;
            } else {
                break;
            }
        }
    }
    void downheapify(int idx) {
        while(idx < hp.size()) {
            int lc = 2*idx + 1;
            int rc = 2*idx + 2;
            if(lc >= hp.size()) break;  //idx-> leaf
            int maxEl = idx;
            if(hp[lc] > hp[maxEl]) {
                maxEl = lc;
            }
            if(rc < hp.size() && hp[rc] > hp[maxEl]) {
                maxEl = rc;
            }
            if(maxEl != idx) {
                swap(hp[idx],hp[maxEl]);
                idx = maxEl;    //for next iteration
            } else {
                break;
            }
        }
    }
    public: 
        void push(int ele) {
            hp.push_back(ele);
            upheapify(hp.size()-1);
        }
        void pop() {
            //remove the highest priority element
            if(empty()) return;
            swap(hp[0],hp[hp.size()-1]);
            hp.pop_back();
            if(!empty()) {
                downheapify(0);
            }
        }
        int peek() {
            if(empty()) return INT_MIN; //if hp is empty then INT_MIN is the greatest element-logically that's true
            return hp[0];
        }
        bool empty() {
            return hp.size() == 0;
        }
        void display() {
            cout<<"[";
            for(int i=0; i<hp.size(); i++) {
                cout<<hp[i]<<" ";
            }
            cout<<"]\n";
        }
};
int main() {
    MaxHeap hp;
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    hp.display();

    hp.pop();
    hp.display();
    
    return 0;
}