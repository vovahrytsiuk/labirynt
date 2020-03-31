#ifndef SOURCE_H
#define SOURCE_H




#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>



using namespace std;


const int INF = 1000000;



struct Pair{
    int value;
    int priority;
};

class PriorityQueue{
private:
    vector<Pair> queue;

    
public:
    void insert(Pair element);
    int get_minimal_key();
    bool is_empty();

};

void deikstra(map<int, vector<int> > adjacencyLinst,int*parent,  int  numberOfTops, int startTop, int endTop); 
int* create_array(int size);
void fill_array(int* arr, int size, int value);
#endif