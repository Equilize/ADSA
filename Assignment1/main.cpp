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

string schoolMethodSub(string int1, string int2, int B) {
    string diff;
    int borrow = 0;
    int i = int1.length() - 1;
    int j = int2.length() - 1;

    while(i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? int1[i--] - '0': 0;
        int digit2 = (j >= 0) ? int2[j--] - '0' : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += B;
            borrow = 1;
        } else {
            borrow = 0;
        }

        int digitDiff = digit1 - digit2;
        diff = to_string(digitDiff) + diff;
    }

    while (diff.length() > 1 && diff[0] == '0') {
        diff = diff.substr(1);
    }

    return diff;


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
}

string karatsubaMult(string int1, string int2, int B) {

    //First case when both numbers are 1 digit long
    if (int1.length() == 1 && int2.length() == 1) {
        int x = stoi(int1);
        int y = stoi(int2);
        int z = x * y;
        return to_string(z);
    }

    //Other cases
    //Resolve if digit length is odd number for divide and conquer
    int maxLength = max(int1.length(), int2.length());
    if (maxLength % 2 != 0) {
        maxLength ++;
    }

    while (int1.length() < maxLength) {
        int1 = "0" + int1;
    }

    while (int2.length() < maxLength) {
        int2 = "0" + int2;
    }

    //Divide x and y into two parts
    int halfIndex = maxLength / 2;
    string firstHalf1 = int1.substr(0 , halfIndex);
    string secondHalf1 = int1.substr(halfIndex);
    string firstHalf2 = int2.substr(0 , halfIndex);
    string secondHalf2 = int2.substr(halfIndex);

    //Recursive call based on formula 
    string z0 = karatsubaMult(secondHalf1, secondHalf2, B);
    string z1 = karatsubaMult(schoolMethodAdd(firstHalf1, secondHalf1, B), schoolMethodAdd(firstHalf2, secondHalf2, B), B);
    string z2 = karatsubaMult(firstHalf1, firstHalf2, B);

    //Combining results
    string part1 = z2;
    for (int i = 0; i < 2*(maxLength - halfIndex); i++) {
        part1 += "0";
    }

    string part2 = schoolMethodSub(schoolMethodSub(z1, z2, B), z0, B);
    for (int i = 0; i < maxLength - halfIndex; i++) {
        part2 += "0";
    }

    string product = schoolMethodAdd(schoolMethodAdd(part1, part2, B), z0, B);
    while (product.length() > 1 && product[0] == '0') {
        product = product.substr(1);
    }

    return product;
}

int main() {
    string int1, int2;
    int B;

    
    cin >> int1 >> int2 >> B;

    string sum = schoolMethodAdd(int1, int2, B);
    string product = karatsubaMult(int1, int2,B);

    cout << sum << " " << product  <<endl;

    return 0;
}