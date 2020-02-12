////#include <vector>
////#include <iostream>
////#include <random>
////using namespace std;
////
////
//////该函数接受三个参数分别指定随机数范围和种子，返回double
////int random_unint(unsigned int min, unsigned int max, unsigned int seed=0) {
////    static std::default_random_engine e(seed);
////    static std::uniform_real_distribution<double> u(min, max);
////    return u(e);
////}
////
////int main()
////{
////    // 1,2,3,4
////    // 1,2,1,2
////    vector<int> vec_sum{1,3,4,6};
////
////    int m=0,n=0,j=0;
////    for (int i = 0; i < 120; ++i)
////    {
////        int dice_roll = random_unint(0, 5, time(NULL));
////        int k=0;
////        for(;k<vec_sum.size();++k)
////        {
////            if(dice_roll<vec_sum[k])
////            {
////                if (k == 0)
////                {
////                    m++;
////                } else if (k==1)
////                {
////                    n++;
////                } else if (k==2)
////                    j++;
////                }
////                break;
////            }
////        }
////
////        cout << m <<"  "<< n << "  " << j<< endl;
////
////    return 0;
////
////}
//
//
//#include <random>
//#include <iostream>
//#include <ctime>
//#include <vector>
//
//int main(void)
//{
//    int m = 0, n = 0, j = 0;
//    for (int i = 0; i < 100; ++i)
//    {
//        std::vector<int> vec_sum{1,3,4};
//        static std::default_random_engine e(time(NULL));
//        static std::uniform_int_distribution<double> u(0, 3);
//        int dice_roll = u(e);
//        int k=0;
//        for(;k<vec_sum.size();++k)
//        {
//            if(dice_roll < vec_sum[k])
//            {
//                if (k == 0)
//                {
//                    m++;
//                } else if (k==1)
//                {
//                    n++;
//                } else if (k==2)
//                    j++;
//                break;
//            }
//        }
//    }
//
////    for (int i = 0; i < 999; ++i) {
////        int s = random_unint(0, 2, time(NULL));
////        if (s == 0) {
////            m++;
////        } else if (s == 1) {
////            n++;
////        } else if (s == 2)
////            j++;
////    }
//
//    std::cout << m <<"  "<< n << "  " << j<< std::endl;
//
//    return 0;
//}