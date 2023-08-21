#include <iostream>
#include <string>
using namespace std;

string schoolMethodAdd(string int1, string int2, int B) {
    string sum;
    int carry = 0;
    int i = int1.length() - 1;
    int j = int2.length() - 1;

    while(i >=0 || j >= 0 || carry > 0) {
        //get digits one by one for addition
        int digit1 = (i >= 0) ? int1[i--] - '0': 0;
        int digit2 = (j >= 0) ? int2[j--] - '0' : 0;
        int digitSum = digit1 + digit2 + carry;
        carry = digitSum / B;
        digitSum = digitSum % B;
        sum = to_string(digitSum) + sum;
    }
    return sum;
}

//string schoolMethodSub(string I1, string I2, int B) {
    string diff;
    int borrow = 0;
    
    /*
    7963    digit 1
    - 24    digit 2

    while loop (through all digits)
    digit1 -= borrow
    if digit1 < digit2 
        borrow = 1
        digitDiff = digit1 - digit2 + borrow*B
    else 
    digitDiff = digit1 - digit2 

    diff = to_string(digitDiff) + diff

    return diff
    
    */
//}

//string karatsubaMult(string I1, string I2, int B) {


/*



*/

//}

int main() {
    string I1, I2;
    int B;

    cout << "Sample Input: ";
    cin >> I1 >> I2 >> B;

    string sum = schoolMethodAdd(I1, I2, B);
    //string product = karatsubaMult(I1, I2,B);

    cout << sum << " " /*<< product << " 0" */<<endl;

    return 0;
}