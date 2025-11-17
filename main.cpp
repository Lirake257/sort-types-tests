#include <iostream>
#include <fstream>
#include "sort_func.h"
#include "help_func.h"
#include <vector>
using namespace std;

int main(){
    generate_arr_save(1000, "files/a1000.txt");
    generate_arr_save(50000, "files/a50000.txt");
    generate_arr_save(100000, "files/a100000.txt");

    generate_sorted_arr_save(1000, "files/b1000.txt");
    generate_sorted_arr_save(50000, "files/b50000.txt");
    generate_sorted_arr_save(100000, "files/b100000.txt");

    generate_rev_sorted_arr_save(1000, "files/c1000.txt");
    generate_rev_sorted_arr_save(50000, "files/c50000.txt");
    generate_rev_sorted_arr_save(100000, "files/c100000.txt");

    generate_e_arr_save(1000, "files/e1000.txt",50);
    generate_e_arr_save(50000, "files/e50000.txt",2000);
    generate_e_arr_save(100000, "files/e100000.txt",5000);

    int *a1 = new int[1000]{}; read_file_to_arr(a1, "files/a1000.txt", 1000);
    int *a2 = new int[50000]{}; read_file_to_arr(a2, "files/a50000.txt", 50000);
    int *a3 = new int[100000]{}; read_file_to_arr(a3, "files/a100000.txt", 100000);

    int *b1 = new int[1000]{}; read_file_to_arr(b1, "files/b1000.txt", 1000);
    int *b2 = new int[50000]{}; read_file_to_arr(b2, "files/b50000.txt", 50000);
    int *b3 = new int[100000]{}; read_file_to_arr(b3, "files/b100000.txt", 100000);

    int *c1 = new int[1000]{}; read_file_to_arr(c1, "files/c1000.txt", 1000);
    int *c2 = new int[50000]{}; read_file_to_arr(c2, "files/c50000.txt", 50000);
    int *c3 = new int[100000]{}; read_file_to_arr(c3, "files/c100000.txt", 100000);

    int *e1 = new int[1000]{}; read_file_to_arr(e1, "files/e1000.txt", 1000);
    int *e2 = new int[50000]{}; read_file_to_arr(e2, "files/e50000.txt", 50000);
    int *e3 = new int[100000]{}; read_file_to_arr(e3, "files/e100000.txt", 100000);
    
    cout<<"tek1"<<endl;

    //vector<int> a1_merge_res = test10merge_res(a1, 1000, merge_sort);
    //vector<int> a1_bubble_res = test10_res(a1, 1000, bubble_sort);

    vector<vector<vector<long long>>> n1000_res = {
        {test10_res(a1, 1000, bubble_sort),test10_res(b1, 1000, bubble_sort), test10_res(c1, 1000, bubble_sort), test10_res(e1, 1000, bubble_sort)},
        {test10_res(a1, 1000, insertion_sort), test10_res(b1, 1000, insertion_sort), test10_res(c1, 1000, insertion_sort), test10_res(e1, 1000, insertion_sort)},
        {test10_res(a1, 1000, selection_sort), test10_res(b1, 1000, selection_sort), test10_res(c1, 1000, selection_sort), test10_res(e1, 1000, selection_sort)},
        {test10_res(a1, 1000, Shell_sort),test10_res(b1, 1000, Shell_sort), test10_res(c1, 1000, Shell_sort), test10_res(e1, 1000, Shell_sort)},
        {test10merge_res(a1, 1000, merge_sort), test10merge_res(b1, 1000, merge_sort), test10merge_res(c1, 1000, merge_sort), test10merge_res(e1, 1000, merge_sort)}
    };
    res_print(1000, n1000_res, "result.txt", true);
    vector<vector<vector<long long>>> n50000_res = {
        {test10_res(a2, 50000, bubble_sort),test10_res(b2, 50000, bubble_sort), test10_res(c2, 50000, bubble_sort), test10_res(e2, 50000, bubble_sort)},
        {test10_res(a2, 50000, insertion_sort), test10_res(b2, 50000, insertion_sort), test10_res(c2, 50000, insertion_sort), test10_res(e2, 50000, insertion_sort)},
        {test10_res(a2, 50000, selection_sort), test10_res(b2, 50000, selection_sort), test10_res(c2, 50000, selection_sort), test10_res(e2, 50000, selection_sort)},
        {test10_res(a2, 50000, Shell_sort),test10_res(b2, 50000, Shell_sort), test10_res(c2, 50000, Shell_sort), test10_res(e2, 50000, Shell_sort)},
        {test10merge_res(a2, 50000, merge_sort), test10merge_res(b2, 50000, merge_sort), test10merge_res(c2, 50000, merge_sort), test10merge_res(e2, 50000, merge_sort)}
    };
    res_print(50000, n50000_res, "result.txt", false);
    vector<vector<vector<long long>>> n100000_res = {
        {test10_res(a3, 100000, Shell_sort),test10_res(b3, 100000, Shell_sort), test10_res(c3, 100000, Shell_sort), test10_res(e3, 100000, Shell_sort)},
        {test10merge_res(a3, 100000, merge_sort), test10merge_res(b3, 100000, merge_sort), test10merge_res(c3, 100000, merge_sort), test10merge_res(e3, 100000, merge_sort)}
    };
    res100000_print(100000, n100000_res, "result.txt");


    delete []a1; delete []a2; delete []a3; delete []b1; delete []b2; delete []b3;
    delete []c1; delete []c2; delete []c3; delete []e1; delete []e2; delete []e3;
}
//g++ main.cpp help_func.cpp sort_func.cpp -o a.exe
//./a.exe