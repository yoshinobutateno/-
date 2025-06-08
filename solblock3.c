#include <stdio.h>
#include <stdlib.h>

void tboumas(int g,int m,int block,int maxblock,int blocksizes[maxblock][2],int ***blockdata,int maxnum){
    int i,j,ii,jj,k;
        //縦に長い棒の時
        if(blocksizes[block-1][0]== 4 && blocksizes[block-1][1]== 1){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;
                if(blockdata[block-1][3][0]==-1) blockdata[block-1][3][0] = 0;

            for(i=0;i<g-3;i++){
                for(j=0;j<m;j++){
                if(i==0){

                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+2,j,block,i+3,j,block);                   
                    }
                else if(i!=0){

                printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+2,j,block,i+3,j,block);
                    }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+1,j+1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+2,j,blockdata[block-1][2][0],i+2,j-1,blockdata[block-1][2][0],i+2,j+1,blockdata[block-1][2][0]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                    } 
                }
                if(blockdata[block-1][3][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+3,j,blockdata[block-1][3][0],i+3,j-1,blockdata[block-1][3][0],i+3,j+1,blockdata[block-1][3][0],i+4,j,blockdata[block-1][3][0]);
                }
                if(blockdata[block-1][3][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+3,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+3,j,k);
                    }                
                }
                if(maxnum==0) printf("))\n");
            }
        }
            
           printf("(|| ");
           for(i=0;i<g-3;i++){
                for(j=0;j<m;j++){
                    if(i==g-4&&j==m-1) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
                printf("\n");
        }
        //横棒
         else if(blocksizes[block-1][0] == 1 && blocksizes[block-1][1] == 4){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;
                if(blockdata[block-1][0][3]==-1) blockdata[block-1][0][3] = 0;
                
            for(i=0;i<g;i++){
                for(j=0;j<m-3;j++){
                    if(j==0){
                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i,j+3,block);                     
                    }
                else if(j!=0){                        
                printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i,j+3,block);                
            }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i+1,j,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i+1,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+2,blockdata[block-1][0][2],i-1,j+2,blockdata[block-1][0][2],i+1,j+2,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    } 
                }
                if(blockdata[block-1][0][3] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i,j+3,blockdata[block-1][0][3],i-1,j+3,blockdata[block-1][0][3],i+1,j+3,blockdata[block-1][0][3],i,j+4,blockdata[block-1][0][3]);
                }
                if(blockdata[block-1][0][3] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i,j+3,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+3,k);
                    }                
                }
                if(maxnum==0) printf("))\n");
              }
                }
    
            printf("(|| ");
           for(i=0;i<g;i++){
                for(j=0;j<m-3;j++){
                    if(i==g-1&&j==m-4) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
        printf("\n");
        }
    }
void yonmas(int g,int m,int block,int maxblock,int blocksizes[maxblock][2],int ***blockdata,int maxnum){
    int i,j,k,ii,jj;
        if (blocksizes[block-1][0]==2 && blocksizes[block-1][1]==2){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;

        for(i=0;i<g-1;i++){
        for(j=0;j<m-1;j++){
            if(i==0&&j==0){                     
                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i+1,j,block,i+1,j+1,block);
                    }        
            else if(i==0 && j!=0){ 

                printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i+1,j,block,i+1,j+1,block);
                        
                        }
            else if(i!=0 && j==0){

                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i+1,j,block,i+1,j+1,block);
                    }
            else {

                        printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i+1,j,block,i+1,j+1,block);
                    }

                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i,j+2,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+2,j,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    } 
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1)))))\n",i+1,j+1,blockdata[block-1][1][1],i+2,j+1,blockdata[block-1][1][1],i+1,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }}

            printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-2&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
                printf("\n");
        }    
        }



void sanni(int g,int m,int block,int maxblock,int blocksizes[maxblock][2],int ***blockdata,int maxnum){
    int i,j,k,ii,jj;
    if (blocksizes[block-1][0]==3 && blocksizes[block-1][1]==2){
        
        //ト
    if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1]== 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1]!= 0 && blockdata[block-1][2][0]!=0 && blockdata[block-1][2][1]==0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;      
        for(i=0;i<g-2;i++){
            for(j=0;j<m-1;j++){
                if(i==0 && j==0){
                    if(blockdata[block-1][0][0] > 0 ) {
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    }

                else printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j+1,block,i+2,j,block);
                    }
                else if(i==0 && j!=0){
                    
                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j+1,block,i+2,j,block);
                }
                else if(i!=0 && j==0){
                    if(blockdata[block-1][1][0] > 0 ) {
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;}

                else printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+1,j+1,block,i+2,j,block);
                }
                else if(i!=0 && j!=0){

                printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i+1,j,block,i+1,j+1,block,i+2,j,block);
                }
            
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (= b_%d_%d_%d 1) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i+1,j+1,blockdata[block-1][1][1],i,j+1,blockdata[block-1][1][1],i+1,j+2,blockdata[block-1][1][1],i+2,j+1,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j,blockdata[block-1][2][0],i+2,j-1,blockdata[block-1][2][0],i+2,j+1,blockdata[block-1][2][0],i+3,j,blockdata[block-1][2][0]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                    }                
                }
                  if(maxnum==0) printf("))\n");
    }}
  
                if(blockdata[block-1][1][0] > 0){    
                printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=1;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}
                if(blockdata[block-1][1][0] == 0){
                printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}
    }
    else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1]!= 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1]!= 0 && blockdata[block-1][2][0]==0 && blockdata[block-1][2][1]!=0){
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][2][1]==-1) blockdata[block-1][2][1] = 0;
        for(i=0;i<g-2;i++){
            for(j=1;j<m;j++){
                if(i==0 && j==m-1){
                    if(blockdata[block-1][1][1] > 0){
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    }

                else printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j-1,block,i+2,j,block);
                    }
                else if(i==0 && j!=m-1){

                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j-1,block,i+2,j,block);
                }
                else if(i!=0 && j==m-1){
                    if(blockdata[block-1][1][1] > 0){
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    }
                   else printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+1,j-1,block,i+2,j,block);
                }
                else if(i!=0 && j!=m-1){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i+1,j,block,i+1,j-1,block,i+2,j,block);
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][1],i,j+1,blockdata[block-1][0][1],i,j-1,blockdata[block-1][0][1],i-1,j,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i+1,j-1,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0],i+1,j-2,blockdata[block-1][1][0],i+2,j-1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j-1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j-1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (= b_%d_%d_%d 1)) ",i+1,j,blockdata[block-1][1][1],i+1,j+1,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][2][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j,blockdata[block-1][2][1],i+2,j-1,blockdata[block-1][2][1],i+2,j+1,blockdata[block-1][2][1],i+3,j,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
    }}

        if(blockdata[block-1][1][1] > 0){
            printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=1;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }
           }
        }
    if(blockdata[block-1][1][1]==0){
            printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=1;j<m;j++){
                    if(i==g-3&&j==m-1) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }
                }}
for(i=1;i<g-1;i++){
    for(j=0;j<m-1;j++){
        printf("(=> (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (= x_%d_%d_%d 1))\n",i,j,block,i,j+1,block,i-1,j+1,block);
    }
}
    }

        else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1]!= 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1] == 0 && blockdata[block-1][2][0] !=0 && blockdata[block-1][2][1] ==0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;
        for(i=0;i<g-2;i++){
            for(j=0;j<m-1;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i+1,j,block,i+2,j,block);
                    }
                else if(i==0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i+1,j,block,i+2,j,block);
                }
                else if(i!=0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i+1,j,block,i+2,j,block);
                }
                else if(i!=0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i+1,j,block,i+2,j,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i+1,j+1,blockdata[block-1][0][1],i,j+2,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+1,j+1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j,blockdata[block-1][2][0],i+2,j-1,blockdata[block-1][2][0],i+2,j+1,blockdata[block-1][2][0],i+3,j,blockdata[block-1][2][0]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }
    }
        printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }

        else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1]== 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1] == 0 && blockdata[block-1][2][0] !=0 && blockdata[block-1][2][1] !=0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;
                if(blockdata[block-1][2][1]==-1) blockdata[block-1][2][1] = 0;
        for(i=0;i<g-2;i++){
            for(j=0;j<m-1;j++){
                if(i==0 && j==0){
                printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+2,j,block,i+2,j+1,block);}
                else if(i==0 && j!=0){ printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i+1,j,block,i+2,j,block,i+2,j+1,block);}
                else if(i!=0 && j==0){printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+2,j,block,i+2,j+1,block);}
                else if(i!=0 && j!=0){ printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i+1,j,block,i+2,j,block,i+2,j+1,block);}
                                
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+1,j+1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+2,j,blockdata[block-1][2][0],i+2,j-1,blockdata[block-1][2][0],i+3,j,blockdata[block-1][2][0]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j,k);
                    }
                }
                if(blockdata[block-1][2][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j+1,blockdata[block-1][2][1],i+1,j+1,blockdata[block-1][2][1],i+2,j+2,blockdata[block-1][2][1],i+3,j+1,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j+1,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }}
            printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }

    else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] != 0 &&blockdata[block-1][1][0] == 0 &&blockdata[block-1][1][1] != 0 && blockdata[block-1][2][0] ==0 && blockdata[block-1][2][1] !=0){
        if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
        if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
        if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
        if(blockdata[block-1][2][1]==-1) blockdata[block-1][2][1] = 0;
        for(i=0;i<g-2;i++){
            for(j=0;j<m-1;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i+1,j+1,block,i+2,j+1,block);
                    }
                else if(i==0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i+1,j+1,block,i+2,j+1,block);
                }
                else if(i!=0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i+1,j+1,block,i+2,j+1,block);
                }
                else if(i!=0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i+1,j+1,block,i+2,j+1,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i+1,j,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i+1,j+1,blockdata[block-1][0][1],i,j+2,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j+1,blockdata[block-1][1][1],i+1,j,blockdata[block-1][1][1],i+1,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][2][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j+1,blockdata[block-1][2][1],i+2,j,blockdata[block-1][2][1],i+2,j+2,blockdata[block-1][2][1],i+3,j+1,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j+1,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }
        }

            printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    
    }
        else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1] != 0 &&blockdata[block-1][1][0] == 0 &&blockdata[block-1][1][1] != 0 && blockdata[block-1][2][0] != 0 && blockdata[block-1][2][1] !=0){
            if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
            if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
            if(blockdata[block-1][2][1]==-1) blockdata[block-1][2][1] = 0;
            if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;
        for(i=2;i<g;i++){
            for(j=0;j<m-1;j++){
                if(i==g-1 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i-1,j+1,block,i-2,j+1,block);
                    }
                else if(i==g-1 && j!=0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i-1,j+1,block,i-2,j+1,block);
                }
                else if(i!=g-1 && j==0){
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i-1,j+1,block,i-2,j+1,block);
                }
                else if(i!=g-1 && j!=0 &&i!=g-1){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i+1,j,block,i,j-1,block,i,j,block,i,j+1,block,i-1,j+1,block,i-2,j+1,block);
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][2][0],i-1,j,blockdata[block-1][2][0],i,j-1,blockdata[block-1][2][0],i+1,j,blockdata[block-1][2][0]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][2][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][2][1],i+1,j+1,blockdata[block-1][2][1],i,j+2,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i-1,j+1,blockdata[block-1][1][1],i-1,j,blockdata[block-1][1][1],i-1,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i-2,j+1,blockdata[block-1][0][1],i-2,j,blockdata[block-1][0][1],i-2,j+2,blockdata[block-1][0][1],i-3,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0))s)\n",i-2,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i-2,j+1,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }
    }

            printf("(|| ");
           for(i=2;i<g;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-1&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }
                }
    }
        else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] == 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1] != 0 && blockdata[block-1][2][0] ==0 && blockdata[block-1][2][1] !=0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][2][1]==-1) blockdata[block-1][2][1] = 0;            
        for(i=0;i<g-2;i++){
            for(j=0;j<m-1;j++){
                if(i==0 && j==0){ 
                   printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j+1,block,i+2,j+1,block);
                    }
                else if(i==0 && j!=0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i+1,j,block,i+1,j+1,block,i+2,j+1,block);
                }
                else if(i!=0 && j==0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+1,j+1,block,i+2,j+1,block);
                }
                else if(i!=0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i+1,j,block,i+1,j+1,block,i+2,j+1,block);
                }
                 if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+2,j,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j+1,blockdata[block-1][1][1],i,j+1,blockdata[block-1][1][1],i+1,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][2][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j+1,blockdata[block-1][2][1],i+2,j,blockdata[block-1][2][1],i+2,j+2,blockdata[block-1][2][1],i+3,j+1,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j+1,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }
        }

                printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=0;j<m-1;j++){
                    if(i==g-3&&j==m-2) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
    else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1] != 0 &&blockdata[block-1][1][0] != 0 &&blockdata[block-1][1][1] != 0 && blockdata[block-1][2][0] !=0 && blockdata[block-1][2][1] ==0){
            if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
            if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
            if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
            if(blockdata[block-1][2][0]==-1) blockdata[block-1][2][0] = 0;
        for(i=0;i<g-2;i++){
            for(j=1;j<m;j++){
                if(i==0 && j==m-1){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j-1,block,i+2,j-1,block);
                    }
                else if(i==0 && j!=m-1){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i+1,j,block,i+1,j-1,block,i+2,j-1,block);
                }
                else if(i!=0 && j==m-1){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+1,j-1,block,i+2,j-1,block);
                }
                else if(i!=0 && j!=m-1){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j+1,block,i,j,block,i+1,j,block,i+1,j-1,block,i+2,j-1,block);
                }
                  if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][1],i-1,j,blockdata[block-1][0][1],i,j-1,blockdata[block-1][0][1],i,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j-1,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0],i+1,j-2,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j-1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j-1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][1],i+1,j+1,blockdata[block-1][1][1],i+2,j,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][2][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+2,j-1,blockdata[block-1][2][0],i+2,j,blockdata[block-1][2][0],i+2,j-2,blockdata[block-1][2][1],i+3,j-1,blockdata[block-1][2][1]);
                }
                if(blockdata[block-1][2][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+2,j-1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+2,j-1,k);
                    }                
                }
                    if(maxnum==0) printf("))\n");
            }
    }

        printf("(|| ");
           for(i=0;i<g-2;i++){
                for(j=1;j<m;j++){
                    if(i==g-3&&j==m-1) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
    printf("\n");
}
}

void yoko(int g,int m,int block,int maxblock,int blocksizes[maxblock][2],int ***blockdata,int maxnum){
    int i,j,k,ii,jj;
    if (blocksizes[block-1][0]==2 && blocksizes[block-1][1]==3){
    if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1]!= 0 &&blockdata[block-1][0][2] != 0 &&blockdata[block-1][1][0] == 0 && blockdata[block-1][1][1]!=0 && blockdata[block-1][1][2]== 0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;        
        for(i=0;i<g-1;i++){
            for(j=0;j<m-2;j++){
                if(i==0 && j==0){
                    if(blockdata[block-1][0][1] > 0) {
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    }
                    else printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i+1,j+1,block);
                    }
                else if(i==0 && j!=0){
                    if(blockdata[block-1][0][1] > 0) {
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    }
                    else printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+1,block);           
                }
                else if(i!=0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+1,block);
                }
                else if(i!=0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+1,block);
                }
                  if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i+1,j,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (= b_%d_%d_%d 1) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i+1,j+1,blockdata[block-1][1][1],i+1,j,blockdata[block-1][1][1],i+2,j+1,blockdata[block-1][1][1],i+1,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i,j+2,blockdata[block-1][0][2],i-1,j+2,blockdata[block-1][0][2],i+1,j+2,blockdata[block-1][0][2],i,j+3,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0))s)\n",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    }                
                }
    if(maxnum==0) printf("))\n");
            }
    }

    if(blockdata[block-1][0][1] > 0){
        printf("(|| ");
           for(i=1;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}

    if(blockdata[block-1][0][1] == 0){
        printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}

    }
    else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1] !=0 && blockdata[block-1][0][2] == 0 &&blockdata[block-1][1][0]!= 0 && blockdata[block-1][1][1]!=0 && blockdata[block-1][1][2]!=0){
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][1][2]==-1) blockdata[block-1][1][2] = 0;
        for(i=1;i<g;i++){
            for(j=0;j<m-2;j++){
                if(i==g-1 && j==0){
                    if(blockdata[block-1][1][1] > 0){
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    } 
                    else printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i-1,j+1,block);
                    }
                else if(i==g-1 && j!=0){
                    if(blockdata[block-1][1][1] > 0){
                        printf("(!= x_%d_%d_%d 1)\n",i,j,block);
                        continue;
                    } 
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i-1,j+1,block); 

                }
                else if(i!= g-1 && j==0){
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i-1,j+1,block);
                }
                else if(i!= g-1 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i+1,j,block,i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i-1,j+1,block);
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][1][0],i-1,j,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0],i+1,j,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (= b_%d_%d_%d 1) ",i,j+1,blockdata[block-1][1][1],i+1,j+1,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i-1,j+1,blockdata[block-1][0][1],i-1,j,blockdata[block-1][0][1],i-2,j+1,blockdata[block-1][0][1],i-1,j+2,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                    }
                }
                if(blockdata[block-1][1][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i,j+2,blockdata[block-1][1][2],i-1,j+2,blockdata[block-1][1][2],i+1,j+2,blockdata[block-1][1][2],i,j+3,blockdata[block-1][1][2]);
                }
                if(blockdata[block-1][1][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    }                
                }
                if(maxnum==0) printf("))\n");
            }
    }

        if(blockdata[block-1][1][1]>0){
            printf("(|| ");
           for(i=1;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}
    if(blockdata[block-1][1][1]==0){
            printf("(|| ");
           for(i=1;i<g;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-1&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}}
    }
        else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] !=0 && blockdata[block-1][0][2] != 0 &&blockdata[block-1][1][0]!= 0 && blockdata[block-1][1][1]==0 && blockdata[block-1][1][2]==0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0; 
        for(i=0;i<g-1;i++){
            for(j=0;j<m-2;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i+1,j,block);
                    }
                else if(i==0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j,block); 
                }
                else if(i!= 0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j,block);
                }
                else if(i!= 0 && j!=0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i+1,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j+2,blockdata[block-1][0][2],i-1,j+2,blockdata[block-1][0][2],i,j+3,blockdata[block-1][0][2],i+1,j+2,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+2,j,blockdata[block-1][1][0],i+1,j+1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }                
                }
    if(maxnum==0) printf("))\n");            
            }
    }

            printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
        else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] !=0 && blockdata[block-1][0][2] != 0 &&blockdata[block-1][1][0] == 0 && blockdata[block-1][1][1] == 0 && blockdata[block-1][1][2] != 0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;
                if(blockdata[block-1][1][2]==-1) blockdata[block-1][1][2] = 0;
        for(i=0;i<g-1;i++){
            for(j=0;j<m-2;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i+1,j+2,block);
                    }
                else if(i == 0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+2,block); 
                }
                else if(i!= 0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+2,block);
                }
                else if(i!= 0 && j!=0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i+1,j+2,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i+1,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+2,blockdata[block-1][0][2],i-1,j+2,blockdata[block-1][0][2],i,j+3,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    }
                }
                if(blockdata[block-1][1][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+1,j+2,blockdata[block-1][1][2],i+1,j+1,blockdata[block-1][1][2],i+2,j+2,blockdata[block-1][1][2],i+1,j+3,blockdata[block-1][1][2]);
                }
                if(blockdata[block-1][1][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+1,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+2,k);
                    }                
                } 
    if(maxnum==0) printf("))\n");           
            }

    }

            printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
    else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] ==0 && blockdata[block-1][0][2] == 0 &&blockdata[block-1][1][0] != 0 && blockdata[block-1][1][1] != 0 && blockdata[block-1][1][2] != 0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][1][2]==-1) blockdata[block-1][1][2] = 0;
        for(i=0;i<g-1;i++){
            for(j=0;j<m-2;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i+1,j,block,i+1,j+1,block,i+1,j+2,block);
                    }
                else if(i == 0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i+1,j,block,i+1,j+1,block,i+1,j+2,block);
                }
                else if(i!= 0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i+1,j,block,i+1,j+1,block,i+1,j+2,block);
                }
                else if(i!= 0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i+1,j,block,i+1,j+1,block,i+1,j+2,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i,j+1,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j,blockdata[block-1][1][0],i+1,j-1,blockdata[block-1][1][0],i+2,j,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j+1,blockdata[block-1][1][1],i,j+1,blockdata[block-1][1][1],i+2,j+1,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][1][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+1,j+2,blockdata[block-1][1][2],i,j+2,blockdata[block-1][1][2],i+2,j+2,blockdata[block-1][1][2],i+1,j+3,blockdata[block-1][1][2]);
                }
                if(blockdata[block-1][1][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+1,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+2,k);
                    }                
                } 
    if(maxnum==0) printf("))\n");           
                }
            }

             printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
    else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1] ==0 && blockdata[block-1][0][2] != 0 &&blockdata[block-1][1][0] != 0 && blockdata[block-1][1][1] != 0 && blockdata[block-1][1][2] != 0){
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][1][2]==-1) blockdata[block-1][1][2] = 0;
        for(i=1;i<g;i++){
            for(j=0;j<m-2;j++){
                if(i==g-1 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i,j+2,block,i-1,j+2,block);
                    }
                else if(i == g-1 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i-1,j+2,block);
                }
                else if(i!= g-1 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i,j+2,block,i-1,j+2,block);
                }
                else if(i!= g-1 && j!=0){
                   printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i,j+2,block,i-1,j+2,block);
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i-1,j+2,blockdata[block-1][0][2],i-1,j+1,blockdata[block-1][0][2],i-1,j+3,blockdata[block-1][0][2],i-2,j+2,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i-1,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i-1,j+2,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][1][0],i-1,j,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][1][1],i-1,j+1,blockdata[block-1][1][1],i+1,j+1,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1)))))\n",i,j+2,blockdata[block-1][1][2],i+1,j+2,blockdata[block-1][1][2],i,j+3,blockdata[block-1][1][2]);
                }
                if(blockdata[block-1][1][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+2,k);
                    }                
                }
   if(maxnum==0) printf("))\n");               
            }
    }
 
            printf("(|| ");
           for(i=1;i<g;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-1&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
    else if (blockdata[block-1][0][0] != 0 && blockdata[block-1][0][1] !=0 && blockdata[block-1][0][2] == 0 &&blockdata[block-1][1][0] == 0 && blockdata[block-1][1][1] != 0 && blockdata[block-1][1][2] != 0){
                if(blockdata[block-1][0][0]==-1) blockdata[block-1][0][0] = 0;
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
                if(blockdata[block-1][1][2]==-1) blockdata[block-1][1][2] = 0;
        for(i=0;i<g-1;i++){
            for(j=0;j<m-2;j++){
                if(i==0 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i+1,j+1,block,i+1,j+2,block);
                    }
                else if(i == 0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i+1,j+1,block,i+1,j+2,block);
                }
                else if(i!= 0 && j==0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j,block,i,j+1,block,i+1,j+1,block,i+1,j+2,block);
                }
                else if(i!= 0 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i-1,j,block,i,j-1,block,i,j,block,i,j+1,block,i+1,j+1,block,i+1,j+2,block);
                }
                if(blockdata[block-1][0][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][0][0],i-1,j,blockdata[block-1][0][0],i,j-1,blockdata[block-1][0][0],i+1,j,blockdata[block-1][0][0]);
                }
                if(blockdata[block-1][0][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i,j+1,blockdata[block-1][0][1],i-1,j+1,blockdata[block-1][0][1],i,j+2,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i+1,j+1,blockdata[block-1][1][1],i+1,j,blockdata[block-1][1][1],i+2,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+1,k);
                    }
                }
                if(blockdata[block-1][1][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2)))))\n",i+1,j+2,blockdata[block-1][1][2],i,j+2,blockdata[block-1][1][2],i+1,j+3,blockdata[block-1][1][2],i+2,j+2,blockdata[block-1][1][2]);
                }
                if(blockdata[block-1][1][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i+1,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i+1,j+2,k);
                    }                
                }    
    if(maxnum==0) printf("))\n");
            }
    }

            printf("(|| ");
           for(i=0;i<g-1;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-2&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }

    else if (blockdata[block-1][0][0] == 0 && blockdata[block-1][0][1] !=0 && blockdata[block-1][0][2] != 0 &&blockdata[block-1][1][0] != 0 && blockdata[block-1][1][1] != 0 && blockdata[block-1][1][2] == 0){
                if(blockdata[block-1][0][1]==-1) blockdata[block-1][0][1] = 0;
                if(blockdata[block-1][0][2]==-1) blockdata[block-1][0][2] = 0;
                if(blockdata[block-1][1][0]==-1) blockdata[block-1][1][0] = 0;
                if(blockdata[block-1][1][1]==-1) blockdata[block-1][1][1] = 0;
        for(i=1;i<g;i++){
            for(j=0;j<m-2;j++){
                if(i==g-1 && j==0){ 
                    printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i-1,j+1,block,i-1,j+2,block);
                    }
                else if(i == g-1 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j-1,block,i,j,block,i,j+1,block,i-1,j+1,block,i-1,j+2,block);
                }
                else if(i!= g-1 && j==0){
                   printf("(=> (= x_%d_%d_%d 1) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i,j,block,i,j+1,block,i-1,j+1,block,i-1,j+2,block);
                }
                else if(i!= g-1 && j!=0){
                    printf("(=> (&& (!= x_%d_%d_%d 1) (!= x_%d_%d_%d 1) (= x_%d_%d_%d 1)) (&& (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) (= x_%d_%d_%d 1) ",i+1,j,block,i,j-1,block,i,j,block,i,j+1,block,i-1,j+1,block,i-1,j+2,block);
                }
                if(blockdata[block-1][0][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1))) ",i-1,j+1,blockdata[block-1][0][1],i-1,j,blockdata[block-1][0][1],i-2,j+1,blockdata[block-1][0][1]);
                }
                if(blockdata[block-1][0][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i-1,j+1,k);
                    }
                }
                if(blockdata[block-1][0][2] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i-1,j+2,blockdata[block-1][0][2],i-2,j+2,blockdata[block-1][0][2],i-1,j+3,blockdata[block-1][0][2],i,j+2,blockdata[block-1][0][2]);
                }
                if(blockdata[block-1][0][2] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i-1,j+2,k);
                        else printf("(= b_%d_%d_%d 0) ",i-1,j+2,k);
                    }
                }
                if(blockdata[block-1][1][0] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 2))) ",i,j,blockdata[block-1][1][0],i-1,j,blockdata[block-1][1][0],i,j-1,blockdata[block-1][1][0],i+1,j,blockdata[block-1][1][0]);
                }
                if(blockdata[block-1][1][0] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0) ",i,j,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j,k);
                    }
                }
                if(blockdata[block-1][1][1] > 0){
                    printf("(= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d) ((1 1) (0 1)))))\n",i,j+1,blockdata[block-1][1][1],i+1,j+1,blockdata[block-1][1][1],i,j+2,blockdata[block-1][1][1]);
                }
                if(blockdata[block-1][1][1] == 0){
                    for(k=1;k<=maxnum;k++){
                        if(k==maxnum) printf("(= b_%d_%d_%d 0)))\n",i,j+1,k);
                        else printf("(= b_%d_%d_%d 0) ",i,j+1,k);
                    }                
                } 
    if(maxnum==0) printf("))\n"); 
            }
    }

            printf("(|| ");
           for(i=1;i<g;i++){
                for(j=0;j<m-2;j++){
                    if(i==g-1&&j==m-3) printf("(= x_%d_%d_%d 1))\n",i,j,block);
                    else printf("(= x_%d_%d_%d 1) ",i,j,block);
                }}
    }
printf("\n");
}
}

int main(int argc, char *argv[]) {
	FILE *fp; 
      fp=fopen(argv[1],"r");
if(fp==NULL){
printf("resultはありません\n");
exit(1);}
    int i,j,k,rows,cols,numblocks = 0,g,m,zero,ii,jj,kk;
    int MAX_BLOCKS,maxnum;
    char bltmp[4];
    int a,b,c,d;
    char line[100];
g=atoi(argv[2]);
m=atoi(argv[3]);
while(fgets(line,sizeof(line),fp) != NULL){
    if(line[0]=='B'&&line[5]=='_'){
        bltmp[0]=line[10];
        if('1'<=line[11]<='9'){
            bltmp[1]=line[11];
            if('1'<=line[12]<='9'){
                bltmp[2]=line[12];}
            }
        }
}
rewind(fp);
MAX_BLOCKS = atoi(bltmp);
    int blockSizes[MAX_BLOCKS][2];  // [numblock][0]: 行数, [numblock][1]: 列数
    int*** blockdata;
    blockdata=(int***)malloc(sizeof(int**)*MAX_BLOCKS);
while(fgets(line,sizeof(line),fp) != NULL){
        if (line[5] == '#') {
             sscanf(line, "BLOCK#%d %dX%d", &numblocks,&cols,&rows);
             blockSizes[numblocks-1][0]=rows;
             blockSizes[numblocks-1][1]=cols;
                blockdata[numblocks-1]=(int**)malloc(sizeof(int*)*rows);
                for(i=0;i<rows;i++){
                    blockdata[numblocks-1][i]=(int*)malloc(sizeof(int)*cols);
                }        
    }
}
rewind(fp);
while(fgets(line,sizeof(line),fp) != NULL){
    if (line[5] == '#') {
        sscanf(line, "BLOCK#%d %dX%d", &numblocks,&cols,&rows);
    if(cols==3){
        fscanf(fp,"%d %d %d",&a,&b,&c);
    for(i=0;i<rows;i++){
        blockdata[numblocks-1][i][0]=a;
        blockdata[numblocks-1][i][1]=b;
        blockdata[numblocks-1][i][2]=c;
        fscanf(fp,"%d %d %d",&a,&b,&c);
    }
    }
    else if(cols==2){
        fscanf(fp,"%d %d",&a,&b);
    for(i=0;i<rows;i++){
        blockdata[numblocks-1][i][0]=a;
        blockdata[numblocks-1][i][1]=b;
        fscanf(fp,"%d %d",&a,&b);
    }
    }
    else if(cols==1){
        fscanf(fp,"%d",&a);
    for(i=0;i<rows;i++){
        blockdata[numblocks-1][i][0]=a;
        fscanf(fp,"%d",&a);
    }
}
    else if(cols==4){
        fscanf(fp,"%d %d %d %d",&a,&b,&c,&d);
    for(i=0;i<rows;i++){
        blockdata[numblocks-1][i][0]=a;
        blockdata[numblocks-1][i][1]=b;
        blockdata[numblocks-1][i][2]=c;
        blockdata[numblocks-1][i][3]=d;
        fscanf(fp,"%d %d %d %d",&a,&b,&c,&d);
    }
}
    }
}
    fclose(fp);
//ブロック表示
/*for (int k = 0; k < MAX_BLOCKS; k++) {
    printf("block=%d\n",k+1);
        for (int i = 0; i < blockSizes[k][0]; i++) {
            for (int j = 0; j < blockSizes[k][1]; j++) {

                printf("%d ", blockdata[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }*/
   
/*for(i=-1;i<=g;i++){
    for(j=-1;j<=m;j++){
        if(i==-1||i==g||j==-1||j==m){
            if((i==-1&&j==-1)||(i==-1&&j==m)||(i==g&&j==-1)||(i==g&&j==m)) continue;
            printf("(int x_%d_%d_%d 0 0)\n",i,j);
        }
        else printf("(int x_%d_%d_%d 0 1)\n",i,j,MAX_BLOCKS);
    }
}*/

for(i=0;i<g;i++){
    for(j=0;j<m;j++){
        for(k=1;k<=MAX_BLOCKS;k++){
 printf("(int x_%d_%d_%d 0 1)\n",i,j,k);
    }
}}

maxnum =0;
for (int k = 0; k < MAX_BLOCKS; k++) {
        for (int i = 0; i < blockSizes[k][0]; i++) {
            for (int j = 0; j < blockSizes[k][1]; j++) {
                if(maxnum < blockdata[k][i][j]){
                    maxnum=blockdata[k][i][j];
                }
            }
        }
    }
if(maxnum != 0) {
for(i=-1;i<=g;i++){
    for(j=-1;j<=m;j++){
        for(k=1;k<=maxnum;k++){
        if(i==-1||i==g||j==-1||j==m){
            if((i==-1&&j==-1)||(i==-1&&j==m)||(i==g&&j==-1)||(i==g&&j==m)) continue;
            printf("(int b_%d_%d_%d 0 0)\n",i,j,k);}

        else printf("(int b_%d_%d_%d 0 1)\n",i,j,k);
        }
    }
}}
//ブロックが配置されてないとき白マスの周囲
if(maxnum != 0) {
for(i=0;i<g;i++){
    for(j=0;j<m;j++){
        
        for(k=1;k<=maxnum;k++){
            printf("(=> (= 0 (+ ");
                    for(kk=1;kk<=MAX_BLOCKS;kk++){
                        if(kk==MAX_BLOCKS) printf("x_%d_%d_%d)) ",i,j,kk);
                        else printf("x_%d_%d_%d ",i,j,kk);
                    }
            
                printf("(=> (= b_%d_%d_%d 1) (global_cardinality (b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d) ((1 2) (0 2)))))\n",i,j,k,i-1,j,k,i,j+1,k,i+1,j,k,i,j-1,k);
            }
        }
    }}


for(i=0;i<g-1;i++){
    for(j=0;j<m-1;j++){
        for(k=1;k<maxnum;k++){
        printf("(>= 3 (+ b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d b_%d_%d_%d))\n",i,j,k,i,j+1,k,i+1,j,k,i+1,j+1,k);
    }
}
}

for(k=1;k<=MAX_BLOCKS;k++){
tboumas(g,m,k,MAX_BLOCKS,blockSizes,blockdata,maxnum);
yonmas(g,m,k,MAX_BLOCKS,blockSizes,blockdata,maxnum);
sanni(g,m,k,MAX_BLOCKS,blockSizes,blockdata,maxnum);
yoko(g,m,k,MAX_BLOCKS,blockSizes,blockdata,maxnum);
}

zero=(g*m)-(MAX_BLOCKS*4);

if(maxnum!=0){
for(i=0;i<g;i++){
    for(j=0;j<m;j++){
        printf("(|| (global_cardinality (");
        for(k=1;k<=maxnum;k++){
            if(k==maxnum) {
                printf("b_%d_%d_%d) ((1 1) (0 %d))) (global_cardinality (",i,j,k,k-1);
            for(kk=1;kk<=maxnum;kk++){
            if(kk==maxnum) printf("b_%d_%d_%d) ((1 0) (0 %d))))\n",i,j,kk,kk);
            else printf("b_%d_%d_%d ",i,j,kk);                
            }
                }
            else printf("b_%d_%d_%d ",i,j,k);

        }
    }
}
}

for(i=0;i<g;i++){
    for(j=0;j<m;j++){
        printf("(|| (global_cardinality (");
        for(k=1;k<=MAX_BLOCKS;k++){
            if(k==MAX_BLOCKS) {
                printf("x_%d_%d_%d) ((1 1) (0 %d))) (global_cardinality (",i,j,k,MAX_BLOCKS-1);
            for(kk=1;kk<=MAX_BLOCKS;kk++){
            if(kk==MAX_BLOCKS) printf("x_%d_%d_%d) ((1 0) (0 %d))))\n",i,j,kk,MAX_BLOCKS);
            else printf("x_%d_%d_%d ",i,j,kk);                
            }
                }
            else printf("x_%d_%d_%d ",i,j,k);

        }
    }
}


for(k=1;k<=MAX_BLOCKS;k++){
    printf("(global_cardinality (");
    for(i=0;i<g;i++){
        for(j=0;j<m;j++){
            if(i==g-1&&j==m-1) printf("x_%d_%d_%d) ((1 4) (0 %d)))\n",i,j,k,g*m-4);
            else printf("x_%d_%d_%d ",i,j,k);

        }
    }
}

/*for (int k = 0; k < MAX_BLOCKS; k++) {
    printf("block=%d\n",k+1);
        for (int i = 0; i < blockSizes[k][0]; i++) {
            for (int j = 0; j < blockSizes[k][1]; j++) {

                printf("%d ", blockdata[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }*/
    // メモリの解放
    for (int k = 0; k < MAX_BLOCKS; k++) {
        for (int i = 0; i < blockSizes[k][0]; i++) {
            free(blockdata[k][i]);
        }
        free(blockdata[k]);
    }
    free(blockdata);
    return 0;
}