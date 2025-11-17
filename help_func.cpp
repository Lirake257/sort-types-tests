#include "help_func.h"
#include <vector>
#include <fstream> //файлы
#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <iomanip> //вывод
void Output(std::vector<int> arr){
    for(int &i : arr){std::cout << i << " ";}
}

void write_arr_to_file(const std::vector<int> &arr, const std::string &filename){
    std::ofstream file(filename);
    for(int i=0; i<size(arr)-1; i++){
        file << arr[i] << "\n";
    } file << arr[size(arr)-1];
    file.close();
}

void read_file_to_arr(int *arr, const std::string filename, int n){
    std::ifstream file(filename);
    for(int i=0; i<n; i++){
        file >> arr[i];
    }
    file.close();
}

std::vector<int> generate_arr(size_t n) {
    std::vector<int> arr(n);
    
    // Инициализация генератора случайных чисел
    std::random_device rd;  // Источник энтропии
    std::mt19937 gen(rd()); // Генератор Mersenne Twister
    std::uniform_int_distribution<int> dist(0, n - 1); // Равномерное распределение
    
    // Заполнение массива случайными числами от 0 до n-1
    for (int &i : arr) {
        i = dist(gen);
    }
    return arr;
}

bool sort_check(const int* arr, const int& arrlen){
    for(int i=0; i<arrlen-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

void generate_arr_save(size_t n, std::string filename) {
    std::vector<int> arr = generate_arr(n);
    write_arr_to_file(arr,filename);
}

void generate_sorted_arr_save(size_t n, std::string filename) {
    std::vector<int> arr = generate_arr(n);
    std::sort(arr.begin(), arr.end());
    write_arr_to_file(arr,filename);
}

void generate_rev_sorted_arr_save(size_t n, std::string filename) {
    std::vector<int> arr = generate_arr(n);
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    write_arr_to_file(arr,filename);
}

void generate_e_arr_save(size_t n, std::string filename, size_t m){
    std::vector<int> arr (n);
    for(int i=0; i<(n/m); i++){
        std::vector<int> temparr = generate_arr(m);
        std::sort(temparr.begin(), temparr.end());
        for(int j=0; j<m; j++){
            arr[j+m*i] = temparr[j];
        }
    }
    write_arr_to_file(arr, filename);
}

std::vector<long long> test10_res(const int* arr, const int &arrlen, void (*sort)(int*, size_t, long long&, long long&, long long&)){
    std::vector<long long> res{0,0,0};
    for(int k=0; k<10; k++){
        long long sort_time=0, if_count=0, swap_count=0;
        int *arr_copy = new int[arrlen];
        for (int i=0; i<arrlen; i++){
            arr_copy[i] = arr[i];
        }
        
        sort(arr_copy, arrlen, sort_time, if_count, swap_count);
        if(sort_check(arr_copy,arrlen)){
            res[0] += sort_time;
            res[1] += if_count;
            res[2] += swap_count;
        }
        else{
            std::cout << "sort error" << std::endl;
        }
        
    }
    res[0]/=10.0;
    res[1]/=10.0;
    res[2]/=10.0;
    return res;
}

std::vector<long long> test10merge_res(const int* arr, const int &arrlen, void (*sort)(int*, size_t, long long&, long long&, long long&, bool, size_t)){
    std::vector<long long> res{0,0,0};
    for(int k=0; k<10; k++){
        long long sort_time=0, if_count=0, swap_count=0;
        int *arr_copy = new int[arrlen];
        for (int i=0; i<arrlen; i++){
            arr_copy[i] = arr[i];
        }
        
        sort(arr_copy, arrlen, sort_time, if_count, swap_count, true, 0);
        if(sort_check(arr_copy,arrlen)){
            res[0] += sort_time;
            res[1] += if_count;
            res[2] += swap_count;
        }
        else{
            std::cout << "sort error" << std::endl;
        }
        
    }
    res[0]/=10.0;
    res[1]/=10.0;
    res[2]/=10.0;
    return res;
}

void res_print(int n, std::vector<std::vector<std::vector<long long>>> arr, std::string filename, bool first_call){
    std::ofstream file;
    if(first_call){
        file.open(filename);}
    else{file.open(filename, std::ios::app);}

    std::cout<<"N = "<<n<<std::endl;
    file <<"N = "<<n<<std::endl;
    for(int dataset = 0; dataset < 4; dataset++){
        int col_wid=13;
        switch (dataset)
        {
        case 0:
            std::cout<<"Dataset: uniform distribution"<<std::endl;
            file<<"Dataset: uniform distribution"<<std::endl;
            break;
        case 1:
            std::cout<<"Dataset: sorted"<<std::endl;
            file<<"Dataset: sorted"<<std::endl;
            break;
        case 2:
            std::cout<<"Dataset: sorted, reverse"<<std::endl;
            file<<"Dataset: sorted, reverse"<<std::endl;
            break;
        case 3:
            std::cout << "Dataset: the pieces are sorted"<<std::endl;
            file << "Dataset: the pieces are sorted"<<std::endl;
        }
        std::cout << std::setw(col_wid) << std::right << "";
        std::cout << std::setw(col_wid) << std::right << "Bubble";
        std::cout << std::setw(col_wid) << std::right << "Insertion";
        std::cout << std::setw(col_wid) << std::right << "Selection";
        std::cout << std::setw(col_wid) << std::right << "Shell";
        std::cout << std::setw(col_wid) << std::right << "Merge\n";
        std::cout << std::string(col_wid*6, '-') << std::endl;
        std::cout << std::setw(col_wid) << std::right << "Time";

        file << std::setw(col_wid) << std::right << "";
        file << std::setw(col_wid) << std::right << "Bubble";
        file << std::setw(col_wid) << std::right << "Insertion";
        file << std::setw(col_wid) << std::right << "Selection";
        file << std::setw(col_wid) << std::right << "Shell";
        file << std::setw(col_wid) << std::right << "Merge\n";
        file << std::string(col_wid*6, '-') << std::endl;
        file << std::setw(col_wid) << std::right << "Time";

        for(int j=0; j<5; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][0];
            file << std::setw(col_wid) << std::right << arr[j][dataset][0];
        }
        std::cout << std::endl << std::setw(col_wid) << std::right << "Comparisons";
        file << std::endl << std::setw(col_wid) << std::right << "Comparisons";
        for(int j=0; j<5; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][1];
            file << std::setw(col_wid) << std::right << arr[j][dataset][1];
        }
        std::cout << std::endl << std::setw(col_wid) << std::right << "Swaps";
        file << std::endl << std::setw(col_wid) << std::right << "Swaps";
        for(int j=0; j<5; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][2];
            file << std::setw(col_wid) << std::right << arr[j][dataset][2];
        }std::cout << std::endl << std::string(col_wid*6, '-')<<std::endl;
        file << std::endl << std::string(col_wid*6, '-')<<std::endl;
    }
}

void res100000_print(int n, std::vector<std::vector<std::vector<long long>>> arr, std::string filename){
    std::ofstream file;
    file.open(filename, std::ios::app);

    std::cout<<"N = "<<n<<std::endl;
    file<<"N = "<<n<<std::endl;
    for(int dataset = 0; dataset < 4; dataset++){
        int col_wid=13;
        switch (dataset)
        {
        case 0:
            std::cout<<"Dataset: uniform distribution"<<std::endl;
            file<<"Dataset: uniform distribution"<<std::endl;
            break;
        case 1:
            std::cout<<"Dataset: sorted"<<std::endl;
            file<<"Dataset: sorted"<<std::endl;
            break;
        case 2:
            std::cout<<"Dataset: sorted, reverse"<<std::endl;
            file<<"Dataset: sorted, reverse"<<std::endl;
            break;
        case 3:
            std::cout << "Dataset: the pieces are sorted"<<std::endl;
            file << "Dataset: the pieces are sorted"<<std::endl;
        }
        std::cout << std::setw(col_wid) << std::right << "";
        std::cout << std::setw(col_wid) << std::right << "Shell";
        std::cout << std::setw(col_wid) << std::right << "Merge\n";
        std::cout << std::string(col_wid*6, '-') << std::endl;
        std::cout << std::setw(col_wid) << std::right << "Time";

        file << std::setw(col_wid) << std::right << "";
        file << std::setw(col_wid) << std::right << "Shell";
        file << std::setw(col_wid) << std::right << "Merge\n";
        file << std::string(col_wid*6, '-') << std::endl;
        file << std::setw(col_wid) << std::right << "Time";

        for(int j=0; j<2; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][0];
            file << std::setw(col_wid) << std::right << arr[j][dataset][0];
        }
        std::cout << std::endl << std::setw(col_wid) << std::right << "Comparisons";
        file << std::endl << std::setw(col_wid) << std::right << "Comparisons";
        for(int j=0; j<2; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][1];
            file << std::setw(col_wid) << std::right << arr[j][dataset][1];
        }
        std::cout << std::endl << std::setw(col_wid) << std::right << "Swaps";
        file << std::endl << std::setw(col_wid) << std::right << "Swaps";
        for(int j=0; j<2; j++){
            std::cout << std::setw(col_wid) << std::right << arr[j][dataset][2];
            file << std::setw(col_wid) << std::right << arr[j][dataset][2];
        }std::cout << std::endl << std::string(col_wid*6, '-')<<std::endl;
        file << std::endl << std::string(col_wid*6, '-')<<std::endl;
    }
}
