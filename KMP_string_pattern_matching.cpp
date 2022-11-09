// C++ program for implementation of KMP pattern searching
// algorithm
#include<bits/stdc++.h>
using namespace std; 
void computeLPSArray(char* pat, int M, int* lps);
 
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        
        if (j == M) {
            printf("match found at index %d ", i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    cout<<" "<<endl;
}
 
// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// Driver program to test above function
int main(int argc,char **argv)
{   cout << "//String matching : "<<endl;
    char txt[] = "0101000101110011000001001001101110010010001000101101001001111100101100100000110010110010111001011100";
    char txt_str[]="1100101011010101001000100101001111110111011001010110000000001110001010010100001010111101001110110100";
    char pat[] = "01001";
    char pat1[]="1011";
    char pat2[]="11011";
    KMPSearch(pat, txt);
    cout<<"//Pattern matching : "<<endl;
    KMPSearch(pat1,txt_str);
    KMPSearch(pat2,txt_str);
    cout<<"Pattern matches at index pairs (6,34) (6,38) (6,91) (35,91) (39,91) (47,91) (80,91)"<<endl;
    return 0;
}