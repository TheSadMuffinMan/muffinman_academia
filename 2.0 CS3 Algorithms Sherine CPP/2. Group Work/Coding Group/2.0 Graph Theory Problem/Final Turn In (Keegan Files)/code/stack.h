#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

template <typename T> class Stack{
private:
	T* s;
	int N;
	int capacity;
public:
	Stack():capacity(4){
		s= new T[capacity];
		N = 0;
	}
	void push(T item){
		if(N==capacity){
			resize(2*capacity);
		}
		s[N++]=item;
	}
	bool isEmpty(){
		if(N == 0){
			return true;
		}
		else{return false;}
	}
	T pop(){
		if(isEmpty()){
			std::cout<<"Stack underflow, cannot pop.\n";
			//return std::nullopt; // this would be preferred with the <optional> lib, however, not allowed in assignment.
			// nullopt would allow a check at pop implementation to verify stack is empty by comparing output
			return T(); // requires isEmpty() check  at pop 
		}
		return s[--N];		
	}
	void showStack(){
		cout<<"Stack contents, top to bottom:\n";
		for(int i = 0; i<N; i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	int size(){
		return N;
	}
	~Stack(){
		delete[] s;
	}
private:
	void resize(int newCapacity){
		//creates an array of twice the size and copies items over
		T* copy = new T[newCapacity];
		//std::cout<<"resizing array.\n";
		for(int i = 0; i<N; i++){
			copy[i] = s[i];
		}
		delete[] s;
		s = copy;
		capacity = newCapacity;
	}
};
