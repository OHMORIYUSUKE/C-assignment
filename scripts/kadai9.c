#include <stdio.h>

int A[8]={5,4,3,8,6,7,2,1};

//値を交換する関数
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*クイックソート*/
void QuickSort(int A[], int left, int right)
{
	// 変数定義
	int Left, Right;
	int pivot;

	// 初期値は引数から
	Left = left; 
	Right = right;

	// 基準は真ん中に設定
	pivot = A[(left + right) / 2];

	// ソーティング
	while (1) {

		// 基準より小さい値を左から見つけていく
		while (A[Left] < pivot) {
			Left++;
			}

		// 基準より大きい値を右から見つけていく
		while (pivot < A[Right]) {
			Right--;
			} 

		// 見つかった値の順序が逆になったら終了 
		if (Left >= Right) {
			break;
			}

		// 値を交換
		swap(&A[Left], &A[Right]);

	}

	//左のデータ群を対象としてクイックソートを再帰
	if (left < Left - 1) {
		QuickSort(A, left, Left - 1);
		}

	//右のデータ群を対象としてクイックソートを再帰
	if (Right + 1 < right) {
		QuickSort(A, Right + 1, right);
		}

}

void main(){
    printf("--Befor-QuickSort--\n");
    for(int i=0;i<8;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    QuickSort(A, 0, 7);
    printf("--After-QuickSort--\n");
    for(int i=0;i<8;i++){
        printf("%d ",A[i]);
    }
}