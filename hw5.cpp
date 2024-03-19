#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
{
    this->text = text;
    this->date = date;
    this->workloads = workloads;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad)
{
    this->name = name;
    this->login = login;
    this->maxLoad = maxLoad;

}


// task 2
int Task::getTotalLoad() const
{
    int totalLoad = 0;
    for (const auto& pair : workloads)
    {
        totalLoad += pair.second;
    }
    return totalLoad;
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        if (t1.getTotalLoad() != t2.getTotalLoad()) {
            return t1.getTotalLoad() < t2.getTotalLoad();
        } else if (t1.date != t2.date) {
            return t1.date < t2.date;
        } else {
            return t1.text < t2.text;
        }
    });


}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int totalLoad = 0;
    for (const Task& task : allTasks) {
        auto it = task.workloads.find(worker.login);
        if (it != task.workloads.end()) {
            totalLoad += it->second;
        }
    }
    return totalLoad;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    for (const auto& worker : workers) {
        int totalLoad = getWorkerLoad(tasks, worker) + newTask.getTotalLoad();
        if (totalLoad > worker.maxLoad) {
            throw std::runtime_error("Overworked");
        }
    }
    tasks.push_back(newTask);
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);
    std::vector<Worker> overworkedWorkers;
    for (const auto& worker : workers) {
        int totalLoad = getWorkerLoad(tasks, worker);
        if (totalLoad > worker.maxLoad) {
            overworkedWorkers.push_back(worker);
        }
    }

    if (!overworkedWorkers.empty()) {
        std::sort(overworkedWorkers.begin(), overworkedWorkers.end(), [](const Worker& w1, const Worker& w2) {
            return w1.login < w2.login;
        });

        std::string errorMessage = "Overworked: ";
        for (size_t i = 0; i < overworkedWorkers.size(); ++i) {
            const Worker& worker = overworkedWorkers[i];
            int currentLoad = getWorkerLoad(tasks, worker);
            int difference =  currentLoad-worker.maxLoad;
            errorMessage += worker.login + " by " + std::to_string(difference);
            if (i < overworkedWorkers.size() - 1) {
                errorMessage += ", ";
            }
        }

        throw std::runtime_error(errorMessage);
    }
}
