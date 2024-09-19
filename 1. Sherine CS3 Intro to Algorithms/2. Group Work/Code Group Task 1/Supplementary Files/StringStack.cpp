// NOT MY CODE, from Keegan in Code Group.

#include <stdio.h>
#include <string>
#include <iostream>

class StringStack
{
	private:
		std::string* s;
		int N;
		int capacity;
	public:
		StringStack():capacity(1){
			s= new std::string[capacity];
			N = 0;
		}
		void push(std::string item){
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
		std::string pop(){
			if(isEmpty()){
				std::cout<<"Stack underflow, cannot pop.\n";
				return "";
			}
			return s[--N];		
		}
	private:
		void resize(int newCapacity){
			//creates an array of trice the size and copies items over
			std::string* copy = new std::string[newCapacity];
			std::cout<<"resizing array.\n";
			for(int i = 0; i<N; i++){
				copy[i] = s[i];
			}
			delete[] s;
			s = copy;
			capacity = newCapacity;
		}
};

int main(){
	StringStack s;
	std::string a;
	s.push("Hello World!");
	a = s.pop();
	std::cout<<a<<"\n";
	s.push("asdf");
	s.push("jkl;");
	for(int i=0; i<5; i++){
		s.pop();
	}

	return 0;
}