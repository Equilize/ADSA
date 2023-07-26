#include <iostream>
#include <string>
using namespace std;

string schoolMethodAdd(string I1, string I2, int B) {
    string sum;
    int carry = 0;
    int i = I1.length() - 1;
    int j = I2.length() - 2;

    while(i >=0 || j >= 0 || cary >0) {
        //get digits one by one for addition
        int digit1 = (i >= 0) ? /*get digit*/ : 0;
        int digit2 = (j >= 0) ? /*get digit*/ : 0;
        int digitSum = digit1 + digit2 + carry;
        carry = digitSum / B;
        digitSum = digitSum % B;
        sum = to_string(digitSum) + sum;
    }
    return sum;
}

string schoolMethodSub(string I1, string I2, int B) {

}

string karatsubaMult(string I1, string I2, int B) {

}

int main() {
    string I1, I2;
    int B;

    cout << "Sample Input: ";
    cin >> I1 >> I2 >> B;

    string sum = schoolMethodAdd(I1, I2, B);
    string product = karatsubaMult(I1, I2,B);

    cout << sum << " " << product << " 0"<<endl;

    return 0;
}