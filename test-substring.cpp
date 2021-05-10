#include <string>
#include <iostream>
#include <vector>
#include "substring.h"
using namespace std;




int main()
{
    string text = "Raising say express had chiefly detract demands she. Quiet led own cause three him. Front no party young abode state up. Saved he do fruit woody of to. Met defective are allowance two perceived listening consulted contained. It chicken oh colonel pressed excited suppose to shortly. He improve started no we manners however effects. Prospect humoured mistress to by proposal marianne attended. Simplicity the far admiration preference everything. Up help home head spot an he room in.";
    string substr = "sa";
    cout << "Rabin_Karp:\nstart substr = ";
    for (auto i : RKSearch(text, substr))
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "Knuth–Morris–Pratt:\nstart substr = ";
    for (auto i : KMPSearch(text, substr))
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "Boyer-Moore:\nstart substr = ";
    for (auto i : BMSearch(text, substr))
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}