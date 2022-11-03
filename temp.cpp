#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    //Insert values 1 to 10
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);

    vector<int>::iterator new_end;
    new_end = remove(v.begin(), v.end(), 20);

    for(int i=0;i<v.size(); i++){
        cout << v[i] << " ";
    }
    //Prints [10 30 40 10]
    return 0;
}