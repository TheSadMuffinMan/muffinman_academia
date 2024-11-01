/*
This main function is designed to read in input text  file 
storing vertex connection data for a graph in the format of:
first line = text designating next line is the number of vertices
second line = number of vertices
third lines = format of data for vertex connections
fourth and on = source vertex, destination vertex, edge weight
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "digraph.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc<2){
		std::cerr<<"Error: Missing filename as main function arg.\n";
		return 1;
	}

	string filename = argv[1];
	ifstream file(filename);
	if(!file.is_open()){
		cerr<<"Error: File named "<<filename<<" could not be opened.\n";
		return 1;
	}
	string word, line;
	int vTo, vFrom, edgeWeight, Gsize; // destination vertex, source vertex, edge weight, graph size

	getline(file, line); //throw away first line of input text
	getline(file, line);
	cout<<line<<endl;
	Gsize = stoi(line); // get the graph size integer 
	getline(file, line); // throw away 3rd line

	DiGraph dg(Gsize); // create graph op

	while(!file.eof()){
		//using getline: (Having a hard time getting this to work)
		// the first character of each line after the first is not being read
		//getline(file, word, ' ');
		//vFrom = stoi(word);
		//getline(file, word, ' ');
		//vTo = stoi(word);
		//getline(file, word, ' ');
		//edgeWeight = stoi(word);
		//getline(file,line);

		////using sstream:
		getline(file, line);
		istringstream iss(line);
		iss>>vFrom>>vTo>>edgeWeight;

		//cout<<"vFrom: "<<vFrom<<endl;
		//cout<<"vTo: "<<vTo<<endl;
		//cout<<"weight: "<<edgeWeight<<endl;
		//cout<<endl;
		dg.addEdge(vFrom, vTo, edgeWeight); // add connections in graph
	}
	file.close();

    std::ofstream logStream;
    logStream.open("log.txt", std::ios::app);
    if (!logStream.is_open())
    {
        std::cerr << "Log stream failed to open, aborting." << std::endl;
        return 0;
    }

    // Getting the current time from Chrono Library.
    auto now = std::chrono::system_clock::now();

    // Casting "now" to time_t type.
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Converting "now_time_t" to a tm struct.
    std::tm now_tm = *std::localtime(&now_time_t);

    logStream << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "]";
    logStream << " Graph with " << Gsize << " nodes created." << std::endl;
    logStream.close();

	int input, v1,v2,v3, destV;
	cout<<"Enter a negative integer to close the program.\n";
	while(true){ // terminal interface loop
		cout<<"Provide 3 source vertices: ";
		
		cin>>v1;
		if(v1<0) break;
		cin>>v2;
		if(v2<0) break;
		cin>>v3;
		if(v3<0) break;
		
		cout<<"\nDestination 1?: ";
		cin>>destV;
		if(destV<0) break;
		
		cout<<"Shortest path 1 from "<<v1<<": ";
		dg.dijkstraSPT(v1, destV);
		cout<<"Shortest path 2 from "<<v2<<": ";
		dg.dijkstraSPT(v2, destV);
		cout<<"Shortest path 3 from "<<v3<<": ";
		dg.dijkstraSPT(v3, destV);


		
		cout<<"\nDestination 2?: ";
		cin>>destV;
		if(destV<0) break;
		
		cout<<"Shortest path 1 from "<<v1<<": ";
		dg.dijkstraSPT(v1, destV);
		cout<<"Shortest path 2 from "<<v2<<": ";
		dg.dijkstraSPT(v2, destV);
		cout<<"Shortest path 3 from "<<v3<<": ";
		dg.dijkstraSPT(v3, destV);

		cout<<"\nDestination 3?: ";
		cin>>destV;
		if(destV<0) break;
		
		cout<<"Shortest path 1 from "<<v1<<": ";
		dg.dijkstraSPT(v1, destV);
		cout<<"Shortest path 2 from "<<v2<<": ";
		dg.dijkstraSPT(v2, destV);
		cout<<"Shortest path 3 from "<<v3<<": ";
		dg.dijkstraSPT(v3, destV);
	}

	return 0;
}