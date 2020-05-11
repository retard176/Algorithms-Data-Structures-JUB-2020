#include <bits/stdc++.h>

using namespace std; 
  
#define d 256   // input alphabet -> ascii encoding

void rk_search(char pat[], char txt[], int q)  {  
    // store string lengths
    int M = strlen(pat);  
    int N = strlen(txt);  

    int i, j;  

    int p = 0; // initial pattern hash  
    int t = 0; // initial text hash
    int h = 1;  
  
    for (i = 0; i < M - 1; i++)  {
        h = (h * d) % q;  
    }
  
 
    for (i = 0; i < M; i++)  {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
  
    // bruteforce check 
    for (i = 0; i <= N - M; i++)  {  
        if ( p == t )  {                    // check one by one
            for (j = 0; j < M; j++)  {  
                if (txt[i+j] != pat[j]) {  
                    break;  
                }
            }    
            if (j == M)  {
                cout<<"Match at index "<< i<< "!" << endl;  
            }
        }
        
        if ( i < N-M )  {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;    
            if (t < 0)  {
                t = (t + q);            // in case negative value
            }
        }  
    }  
}  
  
// Tester function
int main()  {  
    char txt[] = "abedabc";  
    char pat[] = "abc";  

    int q = 101; // Use 101 because chars encoded in ascii! (Large int range)

    rk_search(pat, txt, q);  

    return 0;  
}  