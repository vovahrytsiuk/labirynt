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


#endif