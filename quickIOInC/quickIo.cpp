#include<stdio.h>
#include<ctype.h>
inline int read(){
    int num=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        num=(num<<3)+(num<<1)+ch-'0';
        ch=getchar();
    }
    return num;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar('0'+x%10);
}
int main(){
    int a;
    a=read();
    write(a);
    return 0;
}
