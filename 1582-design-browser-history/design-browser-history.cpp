class BrowserHistory {
private:
    stack<string> backstack;
    stack<string> forwardstack;
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        backstack.push(url);
        forwardstack=stack<string>();
    }
    
    string back(int steps) {
        while (steps > 0 && backstack.size() > 1) {
            forwardstack.push(backstack.top());
            backstack.pop();
            steps--;
        }
        return backstack.top();
    }
    
    string forward(int steps) {
        while (steps > 0 && !forwardstack.empty()) {
            backstack.push(forwardstack.top());
            forwardstack.pop();
            steps--;
        }
        return backstack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */