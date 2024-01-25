#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    
    printf("Bir sayı girin: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d sayısı asaldır.\n", num);
    } else {
        printf("%d sayısı asal değildir.\n", num);
    }

    return 0;
}
