#include "iostream"

void K_Rotation(int a[], int n, int k){
    int temp[n];
    for(int i = 0; i < n; i++){
        temp[(i + k) % n] = a[i];
    }
    for(int i = 0; i < n; i++){
        a[i] = temp[i];
    }
}
int main(){
    int a[] = {35, 24, 65, 3, 19, 22};
    int n = sizeof(a) / sizeof(a[0]);
    int k;
    std::cout << "Enter rotation value: ";
    std::cin >> k;
    K_Rotation(a, n, k);
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    return 0;
}