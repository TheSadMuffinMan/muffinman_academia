/*
NOT MY CODE. This client is from Keegan Erickson, my Code Group member.
*/

#include <stdio.h>
#include <bits/stdc++.h>

#define N 1000

class UnionFind{
	public:
	int i, j;
	int id[N]; // creates an id array for each node 
	int sz[N]; // keeps track of the size of the tree each node is associated with
	
	UnionFind(){ //default constructor
		for (i = 0; i < N; i++){ // populates the id arrays with each node number at its same index num
			id[i] = i; sz[i] = 1; //defaults the size of each node to 1
		}
	}
	UnionFind(int id[], int size){
		// parameterized constructor used to pass in an array of any size
		// so that an outside array may be manipulated by the class
		int sz[size];
		for (i = 0; i < size; i++){ // populates the id arrays with each node number at its same index num
			id[i] = i; sz[i] = 1; //defaults the size of each node to 1
		}
	}

	void Union(int p, int q){ //weighted quick union algorithm
		for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) {}//continue;
        else if (sz[i] < sz[j])
             { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        //printf(" %d %d\n", p, q);
	}

	int Find(int p){// goes to the index of p and returns its current id
		return id[p];
	}

	bool Connected(int p, int q){
		if (id[p] == id[q]) return true;
		else return false; 
	}
};

int main(){

	return 0;
}