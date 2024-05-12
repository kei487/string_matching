#include <stdio.h>
#define N 15

typedef struct{
    int n;
    char type;
}RESULT;

int main(void){
    //variables setting
    int mat[N][N]={0},an=9,bn=9;
    int i,j;
    char a[]="tsudanuma",b[N]; //a is target ,b is input
    RESULT rsl[20]; //result:differece between a and b
    
    //input
    do{
        scanf("%s",b);
        i=0;bn=0;
        while(b[i]!='\0'&&i<N){
            bn++;i++;
        }
    }while(i==N);

    //process1 make matrix
    for(i=0;i<an;i++){
        for(j=0;j<bn;j++){
            if(a[i]==b[j]){
                mat[i][j]=1;
            }else{
                mat[i][j]=3;
            }
        }
        mat[i][bn]=3;
    }
    for(i=0;i<bn+1;i++){
        mat[an][i]=3;
    }
    
    //process2 rearch
    int c=0;
    i=0;j=0;
    while(i+j<an+bn){
        if(mat[i][j]==3){
            if(mat[i+1][j]==1){
                rsl[c].n=j;
                rsl[c].type='D';
                c++;i++;
            }
            else if(mat[i][j+1]==1){
                rsl[c].n=j;
                rsl[c].type='I';
                c++;j++;
            }
            else if(mat[i+1][j+1]==1){
                rsl[c].n=j;
                rsl[c].type='S';
                c++;i++;j++;
            }
        }
        else if(mat[i][j]==1){
            i++;j++;
        }
    }

    
    /*
    for(i=0;i<an+1;i++){
        for(int j=0;j<bn+1;j++){
            printf("%d  ",mat[i][j]);
        }printf("\n");
    }
    printf("c:%d\n",c);
    for(i=0;i<c;i++){
        printf("%d %c\n",rsl[i].n,rsl[i].type);
    }
    */
    
    //output
    c=0;
    printf("result:\n    ");
    for(i=0;i<bn;i++){
        if(rsl[c].n==i && rsl[c].type=='D'){
            printf(" ");
            c++;i--;
        }
        else{
            printf("%c",b[i]);
        }
    }printf("\n    ");

    c=0;
    for(i=0;i<bn;i++){
        if(rsl[c].n==i){
            if(rsl[c].type=='D'){
                printf("D ");
            }
            if(rsl[c].type=='S'){
                printf("S");
            }
            if(rsl[c].type=='I'){
                printf("I");
            }
            c++;
        }
        else{
            printf(" ");
        }
    }printf("\n");
}