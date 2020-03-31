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


vector<string> inputData(){
    string fileName = "input.txt";
    //cout << "Enter file with labirynt" << endl;
    //cin >> fileName;
    fstream fin(fileName);
    vector<string> data;
    string str;
    while(!fin.eof()){
        getline(fin, str);
        data.push_back(str);
    }
    return data;
}

map<int, vector<int> > parsData(vector<string> inputData, int& weight, int& height){
    map<int, vector<int> > adjacencyList;
    height = (inputData.size() -2 );
    weight = (inputData[1].length()-2);
    for(int i = 1; i < inputData.size() -1;i+=1){
        for(int j = 1; j < inputData[i].size()-1; j+=1){
            if(inputData[i][j] == ' '){
                int top = weight*(i-1) + j -1;
                if(inputData[i-1][j] == ' '){
                    adjacencyList[top].push_back(weight*(i-2) + j - 1);
                }
                if(inputData[i][j-1] == ' '){
                    adjacencyList[top].push_back(weight*(i-1) + j - 2);
                }
                if(inputData[i][j+1] == ' '){
                    adjacencyList[top].push_back(weight*(i-1) + j);
                }
                if(inputData[i+1][j] == ' '){
                    adjacencyList[top].push_back(weight*i + j - 1);
                }
            }
        }
    }
    return adjacencyList;

}

vector<int> find_path(int* parent, int startTop, int endTop){
    vector<int> path;
    int curentTop = endTop;
    while(curentTop != startTop){
        curentTop = parent[curentTop];
        path.push_back(curentTop);
        
    }
    for(int i = 0; i < path.size()/2; i++){
        int term = path[i];
        path[i] = path[path.size() - i - 1];
        path[path.size() - i - 1] = term;
    }
    return path;
}

void insert_path(vector<string> & inputData, vector<int> path, int weight, int endTop){
    int k;
    int i, j;
    for(k = 0; k < path.size(); k++){
        
        
        i = path[k]/weight;
        j = path[k] - i*weight;
        int symbol = (int)'1' + k;
        if(symbol > 57){
            symbol += 39;
        }
        inputData[i+1][j+1] = symbol;
    }
    i = endTop/weight;
    j = endTop - i*weight;
    int symbol = (int)'1' + k;
        if(symbol > 57){
            symbol += 39;
        }
        inputData[i+1][j+1] = symbol;
    

}

void print_answer(vector<string> results){
    for(int i = 0; i < results.size();i++){
        for(int j = 0; j < results[i].length();j++){
        cout << results[i][j] <<  " ";
        }
        cout << endl;
    }
}

void incialize_start_and_top(int& startTop, int& endTop, int weight){
    int si, sj, ei, ej;// координати початку та кінця(з 0)
    si = 6;
    sj = 1;
    ei = 1;
    ej = 6;
    startTop = weight*(si-1) + sj -1;
    endTop = weight*(ei-1) + ej -1;
}