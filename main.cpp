#include "source.h"


int main(){
    vector<string> input = inputData();
    
    int weight;
    int height;
    int startTop, endTop;
    
    map<int, vector<int> > adjacencyList = parsData(input, weight, height);
    incialize_start_and_top(startTop, endTop, weight);
    
    int*parent = create_array(weight*height);
    fill_array(parent, weight*height, -1);
    
    
    deikstra(adjacencyList, parent, weight*height, startTop, endTop);
    
   
    vector<int> path = find_path(parent, startTop, endTop);
    insert_path(input, path, weight, endTop);
    print_answer(input);

    return 0;
}