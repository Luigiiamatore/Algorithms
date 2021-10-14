#include <stdio.h>
#define MAX 100

int main() {
    int nums[MAX];
    int n, inseriti = 0;

    for(int i = 0; i < 100; i++) {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int j = 0; j <= inseriti; j++) {
            if(j == inseriti) {
                nums[i] = n;
                break;
            }
            if(nums[j] > n) {
                for(int k = inseriti - 1; k >= j; k--)
                      nums[k+1] = nums[k];
                nums[j] = n;
                break;
            }
        }
        inseriti++;
    }

    for(int i = 0; i < inseriti; i++) {
        printf("%d ", nums[i]);
    }
}