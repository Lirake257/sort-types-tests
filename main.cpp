#include <iostream>
#include <fstream>
#include "sort_func.h"
#include "help_func.h"
#include <vector>
using namespace std;

int main(){
    generate_arr_save(1000, "files/a1000.txt");
    generate_arr_save(10000, "files/a10000.txt");
    generate_arr_save(100000, "files/a100000.txt");

    generate_sorted_arr_save(1000, "files/b1000.txt");
    generate_sorted_arr_save(10000, "files/b10000.txt");
    generate_sorted_arr_save(100000, "files/b100000.txt");

    generate_rev_sorted_arr_save(1000, "files/c1000.txt");
    generate_rev_sorted_arr_save(10000, "files/c10000.txt");
    generate_rev_sorted_arr_save(100000, "files/c100000.txt");

    generate_e_arr_save(1000, "files/e1000.txt",50);
    generate_e_arr_save(10000, "files/e10000.txt",2000);
    generate_e_arr_save(100000, "files/e100000.txt",5000);

    int *a1 = new int[1000]{}; read_file_to_arr(a1, "files/a1000.txt", 1000);
    int *a2 = new int[10000]{}; read_file_to_arr(a2, "files/a10000.txt", 10000);
    int *a3 = new int[100000]{}; read_file_to_arr(a3, "files/a100000.txt", 100000);

    int *b1 = new int[1000]{}; read_file_to_arr(b1, "files/b1000.txt", 1000);
    int *b2 = new int[10000]{}; read_file_to_arr(b2, "files/b10000.txt", 10000);
    int *b3 = new int[100000]{}; read_file_to_arr(b3, "files/b100000.txt", 100000);

    int *c1 = new int[1000]{}; read_file_to_arr(c1, "files/c1000.txt", 1000);
    int *c2 = new int[10000]{}; read_file_to_arr(c2, "files/c10000.txt", 10000);
    int *c3 = new int[100000]{}; read_file_to_arr(c3, "files/c100000.txt", 100000);

    int *e1 = new int[1000]{}; read_file_to_arr(e1, "files/e1000.txt", 1000);
    int *e2 = new int[10000]{}; read_file_to_arr(e2, "files/e10000.txt", 10000);
    int *e3 = new int[100000]{}; read_file_to_arr(e3, "files/e100000.txt", 100000);
    
    //vector<int> a1_merge_res = test10merge_res(a1, 1000, merge_sort);
    //vector<int> a1_bubble_res = test10_res(a1, 1000, bubble_sort);

    vector<void(*)(int*, size_t, long long&, long long&, long long&)> sorts_arr{bubble_sort, insertion_sort, selection_sort, Shell_sort, merge_sort_ob, quick_sort_ob};
    vector<int*> arrs1 {a1,b1,c1,e1};
    vector<int*> arrs2 {a2,b2,c2,e2};
    vector<int*> arrs3 {a3,b3,c3,e3};

    vector<vector<vector<long long>>> n1000_res;
    for(int i=0; i<6; i++){
        vector<vector<long long>> temp;
        for(int j=0; j<4; j++){
            temp.push_back(test10_res(arrs1[j], 1000, sorts_arr[i]));
        }
        n1000_res.push_back(temp);
    }
    res_print(1000, n1000_res, "result.txt", true);

    vector<vector<vector<long long>>> n10000_res;
    for(int i=0; i<6; i++){
        vector<vector<long long>> temp;
        for(int j=0; j<4; j++){
            temp.push_back(test10_res(arrs2[j], 10000, sorts_arr[i]));
        }
        n10000_res.push_back(temp);
    }
    res_print(10000, n10000_res, "result.txt", false);

    vector<vector<vector<long long>>> n100000_res;
    for(int i=3; i<6; i++){
        vector<vector<long long>> temp;
        for(int j=0; j<4; j++){
            temp.push_back(test10_res(arrs3[j], 100000, sorts_arr[i]));
        }
        n100000_res.push_back(temp);
    }
    res100000_print(100000, n100000_res, "result.txt");

    delete []a1; delete []a2; delete []a3; delete []b1; delete []b2; delete []b3;
    delete []c1; delete []c2; delete []c3; delete []e1; delete []e2; delete []e3;
}
//g++ main.cpp help_func.cpp sort_func.cpp -o a.exe
//g++ "-Wl,--stack,32000000" main.cpp help_func.cpp sort_func.cpp -o a.exe
//./a.exe
