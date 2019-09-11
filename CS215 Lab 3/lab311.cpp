//Course: CS215-005
//Project: Lab Assignment 3
//Date: 09/15/2016
//Purpose: It repeatedly askes the user for a zip code
//         and prints the bar code.
//         Use : for half bars, | for full bars.
//Author: Andrew Blaney

#include <iostream>
#include <string>

using namespace std;

string code(int digit)
{switch (digit)
    {
        case 0:	return "||:::";
            break;
        case 1:	return ":::||";
            break;
        case 2:	return "::|:|";
            break;
        case 3:	return "::||:";
            break;
        case 4:	return ":|::|";
            break;
        case 5:	return ":|:|:";
            break;
        case 6:	return ":||::";
            break;
        case 7:	return "|:::|";
            break;
        case 8:	return "|::|:";
            break;
        case 9: return "|:|::";
            break;
        default: return "Invalid digit!";
    }
}


//It determines the barcode sequence for a given code (including the check digit)
string barcode(int postal,int sum)
{
    int tenth_unit = 10;
    
    int check;
    check = 10 - (sum % 10);
    
    string bars = code((postal%tenth_unit));
    postal = postal/ tenth_unit;
    
    bars = code(postal%tenth_unit) + bars;
    postal = postal / tenth_unit;
    
    bars = code(postal%tenth_unit) + bars ;
    postal = postal / tenth_unit;
    
    bars = code(postal%tenth_unit) + bars;
    postal = postal / tenth_unit;
    
    bars = code(postal%tenth_unit) + bars;
    
    bars += code(check);
    
    return bars;
    
}


//It calculates the sum of all digits of p.
int digitsum(int p)
{
    int tenth_unit = 10;
    int sum = 0;
    
    while (p > 0) {
        sum += p % tenth_unit;
        p = p / tenth_unit;
    }
    return sum;
    
}


int main()
{
    int digit;
    cout << ("Enter a 5-digit zip code (enter -1 to quit): ");
    cin >> digit;
    
    while (digit != -1) {
        
        
        int sumofdigits;
        sumofdigits = digitsum(digit);
        
        
        string barc;
        barc = barcode(digit, sumofdigits);
        
        cout << "The barcode representation of " << digit << " is:" << endl <<"|"<< barc << "|"<< endl << endl;
        cout << ("Enter a 5-digit zip code (enter -1 to quit): ");
        cin >> digit;
    }
    system("pause");
    return 0;
}