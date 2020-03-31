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