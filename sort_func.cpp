#include "sort_func.h"
#include <vector>
#include <chrono>

void selection_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count){
    auto start_time = std::chrono::high_resolution_clock::now();
    for(size_t i=0; i<arrlen-1; i++){
        size_t min_j = i;
        for(size_t j=i+1; j<arrlen; j++){
            if(arr[min_j] > arr[j]){
                min_j = j;
            }
            if_count++;
        }
        std::swap(arr[min_j], arr[i]); swap_count++;
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void insertion_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count){
    auto start_time = std::chrono::high_resolution_clock::now();
    for(size_t i=1; i<arrlen; i++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j]; swap_count++;
            j--;
            if_count++;
        }
        if_count++;
        arr[j+1] = temp; swap_count++;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void bubble_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count){
    auto start_time = std::chrono::high_resolution_clock::now();
    bool cc = false;
    for(size_t i=0; i<arrlen; i++){
        for(size_t j=0; j<arrlen-i-1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]); swap_count++;
                cc=true;
            }
            if_count++;
        }
        if(!cc){break;}
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void merge(int* arr, size_t left, size_t mid, size_t right, long long &if_count, long long &swap_count){
    size_t n1{mid+1-left}, n2{right-mid};
    std::vector<int> arr1(n1), arr2(n2);

    for(size_t i=0; i<n1; i++){arr1[i]=arr[i+left];}
    for(size_t i=0; i<n2; i++){arr2[i]=arr[i+mid+1];}

    size_t i{0}, j{0}, k{left};
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else{
            arr[k] = arr2[j];
            j++;
        }
        k++; if_count++; swap_count++;
    }
    while (i < n1) {
        arr[k] = arr1[i]; swap_count++;
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j]; swap_count++;
        j++;
        k++;
    }
}
void merge_sort(int* arr, size_t right, long long &if_count, long long &swap_count, size_t left){
    if(left>=right){return;}
    size_t mid = left + (right - left)/2; // вместо (left+right)/2
    merge_sort(arr, mid, if_count, swap_count, left);
    merge_sort(arr, right, if_count, swap_count, mid+1);
    merge(arr,left,mid,right, if_count, swap_count);
}
void merge_sort_ob(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count){
    auto start_time = std::chrono::high_resolution_clock::now();

    if_count = 0;
    swap_count = 0;

    merge_sort(arr, arrlen-1, if_count, swap_count, 0);

    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void Shell_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count){
    std::vector<int> gaps {89394,39844,18298,8359,3785,1695,749,326,138,57,23,10,4,1};
    int gap_start;
    for(size_t i=0;i<14; i++){
        if(arrlen > gaps[i]){
            gap_start = i;
            break;
        }
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int gap_i = gap_start; gap_i < 14; gap_i++){
        size_t gap = gaps[gap_i];
        for(size_t i = gap; i<arrlen; i++){
            int temp = arr[i];
            int j = i-gap;
            while(j>=0 && arr[j]>temp){
                arr[j + gap] = arr[j]; swap_count++;
                j -= gap;
                if_count++;
            }
            if_count++;
            arr[j + gap] = temp; swap_count++;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void quick_sort(int* arr, int left, int right, long long &if_count, long long &swap_count) {
    if (left >= right) return;
    
    int pivot = arr[left];
    int l = left;
    int r = right;
    
    while (l <= r) {
        while (arr[l] < pivot) {
            l++;
            if_count++;
        } if_count++;
        
        while (arr[r] > pivot) {
            r--;
            if_count++;
        } if_count++;
        
        if (l <= r) {
            std::swap(arr[l], arr[r]); swap_count++;
            l++;
            r--;
        }
    }
    
    if (left < r) quick_sort(arr, left, r, if_count, swap_count);
    if (l < right) quick_sort(arr, l, right, if_count, swap_count);
}
void quick_sort_ob(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count) {
    auto start_time = std::chrono::high_resolution_clock::now();

    if_count = 0;
    swap_count = 0;

    quick_sort(arr, 0, arrlen - 1, if_count, swap_count);
    
    auto end_time = std::chrono::high_resolution_clock::now();
    sort_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}
