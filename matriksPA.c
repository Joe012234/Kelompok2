//Kalkulator Matriks Kelompok 2 Aljali
/*  
    Nama Kelompok : 1. Samuel Napitupulu
                    2. Joe Manurung
                    3. Trisna Paulina
                    4. Ruth Simamora
    Program Studi : D3TK02
*/

#include <stdio.h>

void display(int matrix[10][10], int row, int column) {
    for (int i = 0; i < row; i++){
        printf("| ");
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
            if (j == column - 1) {
                printf("|\n");
            }
        }
    }
}

void assortment(int matrix[10][10], int row, int column) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("[%d][%d] : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

}

void multiply(int A[10][10], int B[10][10],int C[10][10],int rowA,int columnA,int rowB,int columnB) {
    int i, j, k;
    if(columnA == rowB) {
        for(i = 0; i < rowA; i++) {
            for(j = 0; j < columnB; j++) {
                C[i][j] = 0;
            }
        }
    }
    else{
        printf("Matriks tidak bisa dikalikan\n");
    }

    for (i=0; i<rowA; i++) {
        for(j=0; j<columnB; j++) {
            for(k=0; k<columnA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    printf("\nPerkalian Matriks (A*B) : \n");

}

void addition(int A[10][10], int B[10][10],int C[10][10],int rowA,int columnA,int rowB,int columnB) {
    if (columnA == columnB && rowA == rowB) {
        int i,j;
        printf("\nPenjumlahan Matriks (A+B) : \n");
        for (i=0; i < rowA; i++) {
            for (j=0; j< columnA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    else {
        printf("Matriks tidak dapat di jumlahkan");
    }
}

void subtraction(int A[10][10], int B[10][10], int C[10][10], int rowA, int columnA, int rowB, int columnB) {
    if (columnA == columnB && rowA == rowB) {
        int i,j;
        printf("\nPengurangan Matriks (A-B) : \n");
        for (i=0; i < rowA; i++) {
            for (j=0; j < columnA; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }
    else {
        printf("\n Matriks Tidak dapat di kurangkan");
    }
}

void transpose(int C[10][10], int rowC, int columnC) {
    int i,j;
    int fakeC[rowC][columnC];
    printf("\nTranspose Matriks:) : \n");
    for (i=0; i<rowC; i++) {
        for (j=0; j<columnC; j++) {
             fakeC[i][j] = C[i][j];
        }
    }
    for (i=0; i<rowC; i++) {
        for (j=0; j<columnC; j++) {
            C[i][j] = fakeC[j][i];
        }
    }
}


void determinant(int C[10][10], int rowC, int columnC) {
    int deter = C[0][0]*(C[1][1]*C[2][2] - C[1][2]*C[2][1]) - C[0][1]*(C[1][0]*C[2][2] - C[1][2]*C[2][0]) + C[0][2]*(C[1][0]*C[2][1] - C[1][1]*C[2][0]);
    printf("%d",deter);
}
void main() {
    while (1) {
        int option, rowA, rowB, columnA, columnB, rowC, columnC, A[10][10],B[10][10],C[10][10];

        printf("\nMatriks Kalkulator.. Pilih menu yang anda inginkan:-\n");
        printf(" 1. Perkalian (A*B) \n 2. Penjumlahan (A+B) \n 3. Pengurangan (A-B) \n 4. Transpose\n 5. Determinant \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Masukan [BARIS] Matriks A < 10 : ");
                scanf("%d",&rowA);
                printf("Masukan [KOLOM] Matriks A < 10 : ");
                scanf("%d",&columnA);
                printf("Masukan [BARIS] Matriks B < 10 : ");
                scanf("%d",&rowB);
                printf("Masukan [KOLOM] Matriks B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatriks A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatriks B:\n");
                assortment(B, rowB, columnB);
                multiply(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;

            case 2:

                printf("Masukan [BARIS] Matriks A < 10 : ");
                scanf("%d",&rowA);
                printf("Masukan [KOLOM] Matriks A < 10 : ");
                scanf("%d",&columnA);
                printf("Masukan [BARIS] Matriks B < 10 : ");
                scanf("%d",&rowB);
                printf("Masukan [KOLOM] Matriks B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatrix A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatrix B:\n");
                assortment(B, rowB, columnB);
                addition(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;

            case 3:

                printf("Masukan [BARIS] Matriks A < 10 : ");
                scanf("%d",&rowA);
                printf("Masukan [KOLOM] Matriks A < 10 : ");
                scanf("%d",&columnA);
                printf("Masukan [BARIS] Matriks B < 10 : ");
                scanf("%d",&rowB);
                printf("Masukan [KOLOM] Matriks B < 10 : ");
                scanf("%d",&columnB);

                printf("\nMatrix A:\n");
                assortment(A, rowA, columnA);
                printf("\nMatrix B:\n");
                assortment(B, rowB, columnB);
                subtraction(A, B, C, rowA, columnA, rowB, columnB);
                display(C,rowA, columnB);
                break;


            case 4:
                printf("Masukan [BARIS] Matriks A < 10 : ");
                scanf("%d",&rowC);
                printf("Masukan [KOLOM] Matriks A < 10 : ");
                scanf("%d",&columnC);
                assortment(C, rowC, columnC);
                display(C, rowC, columnC);
                transpose(C, rowC, columnC);
                printf("\n");
                display(C, rowC, columnC);
                break;

            case 5:
                printf("Masukan [BARIS] Matriks A < 10 : ");
                scanf("%d",&rowC);
                printf("Masukan [KOLOM] Matriks A A < 10 : ");
                scanf("%d",&columnC);
                assortment(C, rowC, columnC);
                determinant(C, rowC, columnC);
                printf("\n");
                break;
                
        }
    }  


} 

//refrensi 
//https://kampusliterasi.blogspot.com/2021/04/program-kalkulator-matriks-bahasa.html
//https://www.kopicoding.com/kalkulator-sederhana-bahasa-c/
//https://www.youtube.com/watch?v=4A0gQo_J6hs
//https://ngubekilmu.blogspot.com/2016/03/cara-membuat-program-kalkulator.html
//https://sederhana.webs.com/apps/blog/show/6734869-program-penjumlahan-pengurangan-perkalian-dan-determinan-matriks-bahasa-c
//https://www.kopicoding.com/transpose-matriks-bahasa-c/
//https://github.com/mtaubler/Matrix/blob/master/matrix.c