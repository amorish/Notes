// A) VECTOR

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    
    // ***Lec-1: Declaration***
    
    // declare  a vector
    vector<int> v1;
    
    // declare a vector with size and initial value 
    vector<int> v2(3,5);    
    // vectorName(initial size of vector, value of each element)
    
    // print a vector
    for(int x : v2){
        cout<<x<<" ";
    }
    
    cout<<endl;
    
    // declare a vector and initialize with list
    vector<int> v3 = {2, 7, 1};
    
    for(int x : v3){
        cout<<x<<" ";
    }
    
    cout<<endl<<endl;
    
    //-------------------------------------------------------
    
    // ***Lec-2: Insertion***
    vector<char> vec1 = {'a', 'c', 'd', 'f'};
    
    // insert at the end
    vec1.push_back('g');
    
    // insert at a position
    vec1.insert(vec1.begin()+1,'b');
    vec1.insert(vec1.begin()+4,'e');
    
    for(char x : vec1){
        cout<<x<<" ";
    }
    
    cout<<endl<<endl;
    
    //--------------------------------------------------------
    
    // ***Lec-3: Accessing , Updation, Size of Vector***
    
    vector<int> vc = {2, 1, 5, 10};
    
    //using vector[index]
    cout<<"Element at position 3: "<<vc[2]<<endl;
    //using vector.at(index)
    cout<<"Element at position 2: "<<vc.at(1)<<endl<<endl;
    
    //updation
    vc[1]=8;
    cout<<"After updation,"<<endl<<"Element at position 2: "<<vc[1]<<endl<<endl;
    
    // Size of a Vector
    cout<<"Size of vc: "<<vc.size()<<endl<<endl;
    
    //--------------------------------------------------------
    
    // ***Lec-4:  Traversal & Deletion***
    
    vector<char> vect = {'a', 'e', 'i', 'o', 'u'};
    
    // traversal
    for(int i = 0; i<vect.size(); i++){
        cout<<vect[i]<<" ";
    }
    
    cout<<endl<<endl;
    
    // Deletion of last element
    vect.pop_back();
    
    vect.erase(find(vect.begin(),vect.end(),'e'));
    
    cout<<"After deletion: "<<endl;
    
    for(int i = 0; i<vect.size(); i++){
        cout<<vect[i]<<" ";
    }
    
    cout<<endl<<endl;
    
    //--------------------------------------------------------
    
    
    // ***Lect-5: check Empty or not***
    
    vector<int> v;
    if(v.empty()){
        cout<<"vector is empty"<<endl;
    }
    
    v.push_back(1);
    
    if(!v.empty()){
        cout<<"vector is not empty, 1st element is: "<<v[0]<<endl<<endl;
    }
    
    // -------------------------------------------------------
    
    // ***Multi-dimensional Vector***
    
    vector<vector<int>> matrix;
    
    matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    cout<<"Traversing 2D vector using index-based loop:\n";
    
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // 3 rows , 4 columns all initialized to 0
    vector<vector<int>> mtrx(3, vector<int> (4,0));
    
    cout<<"\nelement at 2nd row, 4th colm: "<<mtrx[1][3];
    
    return 0;
}

//================================================================================================

// OUPUT:

/*
5 5 5 
2 7 1 

a b c d e f g 

Element at position 3: 5
Element at position 2: 1

After updation,
Element at position 2: 8

Size of vc: 4

a e i o u 

After deletion: 
a i o 

vector is empty
vector is not empty, 1st element is: 1

Traversing 2D vector using index-based loop:
1 2 3 
4 5 6 
7 8 9 

element at 2nd row, 4th colm: 0

=== Code Execution Successful ===

*/
