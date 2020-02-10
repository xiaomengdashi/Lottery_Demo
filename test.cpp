//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    Solution(vector<int>& w) {
//        for(int i=0;i<w.size();++i){
//            sum+=w[i];
//            vec_sum.push_back(sum);
//        }
//    }
//
//    int pickIndex() {
//        srand((unsigned)time(NULL));//每次都重新设置随机种子
//        int target = rand()%sum;
//        int i=0;
//        for(;i<vec_sum.size();++i){
//            if(target<vec_sum[i]){
//                break;
//            }
//        }
//        return i;
//    }
//private:
//    vector<int> vec_sum;
//    int sum=0;
//};
//
//int main()
//{
//    vector<int> w{1,2,3};
//    Solution* obj = new Solution(w);
//    int param_1 = obj->pickIndex();
//    cout << param_1 << endl;
//    return 0;
//
//}
//
