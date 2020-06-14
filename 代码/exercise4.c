#include"stdio.h"
#include<unistd.h>
//实验环境Ubuntu 20.04
int main(){

       
       if(fork()==0)
            printf("b\n");
       else
       {
           if(fork()==0)
                printf("c\n");
            else
            {
                printf("a\n");
            }
            
       }
       return 0;
    
}