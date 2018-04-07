#include <stdio.h>

int main(){

    int list[5] = {2,12,66,3,100};
    int i,j,k,temp;
   
    for(i=0;i<5;i++){
        j = i;
        for(k=i+1;k<6;k++){
	    if(list[k] < list[j]) j = k;
	    temp = list[i];
	    list[i] = list[j];
	    list[j] = temp;
	}
    }

    for(i = 0;i<5;i++){
     printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
