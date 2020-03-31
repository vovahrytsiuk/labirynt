#include "source.h"

void PriorityQueue::insert(Pair element){
    queue.push_back(element);
    
}

int PriorityQueue::get_minimal_key(){
    int minI = 0;
    for(auto i = 0; i < queue.size(); i++){
        if(queue[i].priority < queue[minI].priority){
            minI = i;
        }
    }
    int minimalKey = queue[minI].value;
    queue.erase(queue.begin() + minI);
    for(int i = 0; i < queue.size(); i++){
        if(queue[i].value == minimalKey){
            queue.erase(queue.begin() +i);
        }
    }
    return minimalKey;
}

bool PriorityQueue::is_empty(){
    if(queue.size() > 0){
        return false;
    }
    return true;
}

void deikstra(map<int, vector<int> > adjacencyLinst, int* parent, int numberOfTops, int startTop, int endTop){
    PriorityQueue queue;
    Pair p = {startTop, 0};
    queue.insert(p);
    int* l = create_array(numberOfTops);
    fill_array(l, numberOfTops, INF);
    l[startTop] = 0;
    while(!queue.is_empty()){
        int x = queue.get_minimal_key();
        
        for(int i = 0; i < adjacencyLinst[x].size(); i++){
            if(l[adjacencyLinst[x][i]] > l[x] + 1){
                l[adjacencyLinst[x][i]] = l[x] + 1;
                p.value = adjacencyLinst[x][i];
                p.priority = 1;
                parent[adjacencyLinst[x][i]] = x;
                queue.insert(p);
            }
        }
        if(x == endTop){
            break;
        }
    }
}

int* create_array(int size){
    int* arr = new int[size];
    return arr;
}

void fill_array(int* arr, int size, int value){
    for(int i = 0; i < size; i++){
        arr[i] = value;
    }
}
