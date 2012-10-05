/*
ID: jsealey1
LANG: C++
TASK: calfflac
*/
 #include <cstdio> 
 #include <string> 
 #include <iostream> 
 #include <algorithm> 
 using namespace std; 
 int main(){ 
    freopen("calfflac.in","r",stdin); 
    freopen("calfflac.out","w",stdout); 
    char a[20005],b[20005],c; 
    int ba[20005],d[20005],r=0,rpos=0; 
    int ai=0,bi=0; 
    while(scanf("%c",&c)!=EOF){ 
         a[ai]=c; 
         if(c>='a'&&c<='z'||c>='A'&&c<='Z'){ 
             b[bi]=c; 
             if(c>='A'&&c<='Z')b[bi]+='a'-'A';  
             ba[bi]=ai;  
             bi++;  
         } 
         ai++;  
    } 
    d[0]=1; 
    for(int i=1;i<bi;i++){     
        if(b[i]==b[i-d[i-1]-1])d[i]=d[i-1]+2; 
        else if(b[i]==b[i-1])d[i]=2; 
        else d[i]=1; 
        if(d[i]>r){ 
             r=d[i]; 
             rpos=i; 
         }  
    } 
    printf("%d\n",r); 
     for(int i=ba[rpos-r+1];i<=ba[rpos];i++){ 
         printf("%c",a[i]); 
    } 
    printf("\n"); 
    return 0; 
 }
