#include "source.h"


int main(){
    vector<string> input = inputData();
    
    int weight;
    int height;
    map<int, vector<int> > adjacencyList = parsData(input, weight, height);
    
    int*parent = create_array(weight*height);
    fill_array(parent, weight*height, -1);
    
    
    deikstra(adjacencyList, parent, weight*height, 30, 5);
    
   
    vector<int> path = find_path(parent, 30, 5);
    insert_path(input, path, weight, 5);
    print_answer(input);

    return 0;
}