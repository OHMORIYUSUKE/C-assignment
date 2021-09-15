#include <stdio.h>
#include<stdlib.h>

int m=6;
int array[7]={4,2,6,1,3,7,5};

void swap(int *r,int *l){
    int tmp;
    tmp=*r;
    *r=*l;
    *l=tmp;
}

void view(){
    for(int i=0;i<=6;i++){
        printf("%d",array[i]);
    }
    printf("\n");
}

void heap(){
    int i,j;
    for(i=(m-1)/2;i>=0;i--){
        j=i;
        while(1){
            if(2*j+2<=m && array[j]<array[2*j+2] && array[2*j+1]<array[2*j+2]){
                swap(&array[j],&array[2*j+2]);
                j=2*j+2;
            }else if(2*j+1<=m && array[j]<array[2*j+1]){
                swap(&array[j],&array[2*j+1]);
                j=2*j+1;
            }else{
                break;
            }
        }
    }
}

void heapSort(){
    while(m>=0){
        heap();
        view();
        swap(&array[0],&array[m]);
        //view();
        m--;
    }
}

void main(){
    view();
    heapSort();
}