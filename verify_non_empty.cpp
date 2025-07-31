#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 暴力解法：列出所有非空子陣列並計算OR值
int bruteForce(vector<int>& arr) {
    unordered_set<int> result;
    int n = arr.size();
    
    cout << "所有非空子陣列及其OR值：" << endl;
    
    // 遍歷所有可能的起始位置
    for (int i = 0; i < n; i++) {
        // 遍歷所有可能的結束位置
        for (int j = i; j < n; j++) {
            int orValue = 0;
            cout << "[";
            
            // 計算子陣列[i, j]的OR值
            for (int k = i; k <= j; k++) {
                orValue |= arr[k];
                cout << arr[k];
                if (k < j) cout << ",";
            }
            
            cout << "] -> OR值: " << orValue << endl;
            result.insert(orValue);
        }
    }
    
    cout << "不同OR值數量: " << result.size() << endl;
    return result.size();
}

// 我們的原始解法
int optimizedSolution(vector<int>& arr) {
    unordered_set<int> result;
    unordered_set<int> current;
    
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        unordered_set<int> next;
        next.insert(num);
        
        for (unordered_set<int>::iterator it = current.begin(); it != current.end(); it++) {
            int prev = *it;
            next.insert(prev | num);
        }
        
        for (unordered_set<int>::iterator it = next.begin(); it != next.end(); it++) {
            int val = *it;
            result.insert(val);
        }
        
        current = next;
    }
    
    return result.size();
}

int main() {
    vector<int> test = {1, 1, 2};
    
    cout << "=== 暴力解法（手動列出所有非空子陣列）===" << endl;
    int bruteResult = bruteForce(test);
    
    cout << "\n=== 我們的優化解法 ===" << endl;
    int optimizedResult = optimizedSolution(test);
    cout << "結果: " << optimizedResult << endl;
    
    cout << "\n=== 比較結果 ===" << endl;
    cout << "暴力解法: " << bruteResult << endl;
    cout << "優化解法: " << optimizedResult << endl;
    cout << "結果相同: " << (bruteResult == optimizedResult ? "是" : "否") << endl;
    
    return 0;
}