#include <stdio.h>
#define STR 15

int main(){
    //variable
int i,j,n,tn,matrix[STR][STR];
    char str[STR],trg[]="tsudanuma";
    i=0;tn=0;
    while(trg[i]!='\0'&&i<STR){
        tn++;i++;
    }
    for(i=0;i<STR;i++){
        for(j=0;j<STR;j++){
            matrix[i][j]=1;
        }
    }

    //input
    do{
        scanf("%s",str);
        i=0;n=0;
        while(str[i]!='\0'&&i<STR){
        n++;i++;
        }
    }while(i==STR);
    
    //process1 make matrix
    for(i=0;i<tn;i++){
        for(j=0;j<n;j++){
            if(trg[i]==str[j]){
                matrix[i][j]=3;
            }else{
                matrix[i][j]=0;
            }
        }
    }

    //process2 rearch
    


    //output
    for(i=0;i<tn;i++){
        for(j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

}