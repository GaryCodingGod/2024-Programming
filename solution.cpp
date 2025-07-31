#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current;
        
        for (int num : arr) {
            unordered_set<int> next;
            // 加入當前元素本身
            next.insert(num);
            
            // 將當前元素與之前所有可能的OR值進行OR運算
            for (int prev : current) {
                next.insert(prev | num);
            }
            
            // 將所有新的OR值加入結果集
            for (int val : next) {
                result.insert(val);
            }
            
            current = next;
        }
        
        return result.size();
    }
};

// 測試函數
void test() {
    Solution sol;
    
    // 測試範例1
    vector<int> arr1 = {0};
    cout << "Test 1: [0] -> " << sol.subarrayBitwiseORs(arr1) << " (expected: 1)" << endl;
    
    // 測試範例2
    vector<int> arr2 = {1, 1, 2};
    cout << "Test 2: [1,1,2] -> " << sol.subarrayBitwiseORs(arr2) << " (expected: 3)" << endl;
    
    // 測試範例3
    vector<int> arr3 = {1, 2, 4};
    cout << "Test 3: [1,2,4] -> " << sol.subarrayBitwiseORs(arr3) << " (expected: 6)" << endl;
}

int main() {
    test();
    return 0;
}