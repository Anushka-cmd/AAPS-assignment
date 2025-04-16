#include <vector>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1; 
    
    int total = 10; 
    int uniqueDigits = 9;
    int availableNumbers = 9; 
    
    for (int i = 2; i <= n; i++) {
        if (availableNumbers == 0) {
            break; 
    ;
        uniqueDigits *= availableNumbers;
        total += uniqueDigits;
        availableNumbers--;
    }
    
    return total;
}