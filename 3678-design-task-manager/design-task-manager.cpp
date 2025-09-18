class TaskManager {
private:
 
    unordered_map<int, pair<int, int>> taskMap;
    

    set<pair<int, int>, greater<pair<int, int>>> priorityQueue;
    
public:
    TaskManager(vector<vector<int>>& tasks) {
       
        for(const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            
           
            taskMap[taskId] = {priority, userId};
            
            priorityQueue.insert({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
       
        taskMap[taskId] = {priority, userId};
     
        priorityQueue.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        
        int oldPriority = taskMap[taskId].first;
        priorityQueue.erase({oldPriority, taskId});
        
       
        taskMap[taskId].first = newPriority;

        priorityQueue.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
      
        int priority = taskMap[taskId].first;
        priorityQueue.erase({priority, taskId});
        
       
        taskMap.erase(taskId);
    }
    
    int execTop() {
      
        if(priorityQueue.empty()) {
            return -1;
        }
        
        auto topTask = *priorityQueue.begin();
        int taskId = topTask.second;
        
        int userId = taskMap[taskId].second;
        
    
        priorityQueue.erase(priorityQueue.begin());
        taskMap.erase(taskId);
        
        return userId;
    }
};  