#include <iostream>
#include <string>
using namespace std;

string strip_leading_zeros (string s) {
        int i = 0;
        string ret = "";
        while (s[i] == '0') {
                if (s[i+1] == '\0') {
                        break;
                }
                i++;
        }
        while (s[i] != '\0') {
                ret += s[i];
                i++;
        }
        return ret;
}

string add(string x, string y) {
        string X = strip_leading_zeros(x);
        string Y = strip_leading_zeros(y);
        int lengthX = 0;
        int lengthY = 0;
        int carry = 0;

        while (X[lengthX] != '\0') {
                lengthX++;
        }
        while (Y[lengthY] != '\0') {
                lengthY++;
        }

        int i = lengthX-1;
        int j = lengthY-1;
        string ans = "";

        while (i >= 0 or j >= 0 or carry > 0) {
                int digitX = 0;
                int digitY = 0;

                if (i >= 0) {
                        digitX = X[i] - '0';
                }
                if (j >= 0) {
                        digitY = Y[j] - '0';
                }

                int sum = digitX + digitY + carry;
                int numb = sum % 10;
                carry = sum / 10;
                ans = char('0' + numb) + ans;
                i--;
                j--;
        }
        return strip_leading_zeros(ans);
}

string mul_one_numb(string x, int numb) {
    x = strip_leading_zeros(x);

    if (numb == 0) {
            return "0";
    }

    int length_x = 0;
    while (x[length_x] != '\0') {
            length_x++;
    }

    int i = length_x - 1;
    int carry = 0;
    string ans = "";

    while (i >= 0 || carry > 0) {
        int digitX = 0;
        if (i >= 0) {
                digitX = x[i] - '0';
        }

        int prod = digitX * numb + carry;

        int newDigit = prod % 10;
        carry = prod / 10;

        ans = char('0' + newDigit) + ans;

        i--;
    }

    return strip_leading_zeros(ans);
}

string multi(string x, string y) {
        x = strip_leading_zeros(x);
        y = strip_leading_zeros(y);

        if (x == "0" and y == "0") {
                return "0";
        }

        int length_y = 0;
        while (y[length_y] != '\0') {
                length_y++;
        }
        string ans = "0";
        int zeros = 0;

        for (int j = length_y - 1; j >= 0; j--) {
                int numb = y[j] - '0';
                string row = mul_one_numb(x, numb);
                for (int z = 0; z < zeros; z++) {
                        row += '0';
                }
                ans = add(ans, row);
                zeros++;
        }
        return strip_leading_zeros(ans);
}



int main() {
        string a, b;
        char operation;

        cin >> a;
        cin >> operation;
        cin>> b;

        if (operation == '+') {
                cout << add(a,b) << endl;
        }
        else if (operation == '*') {
                cout << multi(a,b) << endl;
        }
        return 0;
}
