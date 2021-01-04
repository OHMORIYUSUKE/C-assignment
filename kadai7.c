#include <stdio.h>
#include<stdlib.h>

#define seisekiMax 256
int seisekicount = 0;

struct Seiseki{
        char name[256];
	int kokugo;
        int sansu;
        int rika;
	};

void putSeisekiArray(struct Seiseki *seiseki){
        char buf[256];
        char name[256];
        int kokugo,sansu,rika;
        int i=0;
        FILE *fp;
        fp = fopen("data.txt","r");
                if(fp==NULL){
                        /*ファイルオープン失敗*/
                        printf("errer");
                        exit(1);
                }

        while(fgets(buf, sizeof(buf), fp)!=NULL){
                sscanf(buf,"%s %d %d %d",seiseki[i].name,&seiseki[i].kokugo,&seiseki[i].sansu,&seiseki[i].rika);
                i++;
        }
        seisekicount=i;
        fclose(fp);
}

void view(struct Seiseki *seiseki){
        for(int i=0;i<seisekicount;i++){
                printf("%s %d %d %d",seiseki[i].name,seiseki[i].kokugo,seiseki[i].sansu,seiseki[i].rika);
                printf("\n");
        }
}

/*選択ソート*/
void sort_sentaku(struct Seiseki *seiseki)
{
    int i, j;
    struct Seiseki tmp;    
    for (i = 0; i < seisekicount; i++) {
        for (j = i + 1; j < seisekicount; j++) {
            if (seiseki[i].kokugo < seiseki[j].kokugo) {
                tmp=seiseki[i];
                seiseki[i]=seiseki[j];
                seiseki[j]=tmp;
            }
        }
    }
}
/*バブルソート*/
void sort(struct Seiseki *seiseki){
        int i,j;
        struct Seiseki tmp;
        for(i=0;i<seisekicount;i++){
                for(j=0;j<seisekicount-i-1;j++){
                        if(seiseki[j].kokugo<seiseki[j+1].kokugo){
                                tmp=seiseki[j];
                                seiseki[j]=seiseki[j+1];
                                seiseki[j+1]=tmp;
                        }
                }
        }
}


int main(){
 /* 構造体配列の宣言*/
 /* seisekiMAXはメイン関数の外で#define で256に設定 */
 /* Seiseki 型もメイン関数の外で定義しているものとする　*/
 struct Seiseki seiseki[seisekiMax];
 /* putSisekiArray の中でファイルからデータを読み込む　*/
 putSeisekiArray( seiseki );
 /* ソート前のデータを表示 */
 printf("**** origin ****\n");
 view( seiseki );
 /* バブルソートを行う　*/
 sort( seiseki );
 /* ソート後のデータを表示　*/
 printf("**** sorted ****\n");
 view( seiseki );
 return 0;
}