#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void read_matrix(FILE *fp, int matrix[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i += 1)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
}

void calculate_matrix(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS], int coef) 
{
    for (int i = 0; i < ROWS; i += 1)
    {
        for (int j = 0; j < COLS; j += 1)
        {
            c[i][j] = a[i][j] + coef * b[i][j];
        }
    }
}

void write_matrix(FILE *fp, int matrix[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i += 1) 
    {
        for (int j = 0; j < COLS; j += 1)
        {
            fprintf(fp, "%d ", matrix[i][j]);
            fprintf(fp, "\n");
        }
    }
}

int main() 
{
    system("chcp 65001");

    FILE *fa = fopen("matrix_a.txt", "r");
    FILE *fb = fopen("matrix_b.txt", "r");
    FILE *fc = fopen("exit.txt", "w");

    if (!fa || !fb || !fc) 
    {
        puts("Помилка відкриття одного з файлів.");
        exit(1);
    }

    int a[ROWS][COLS], b[ROWS][COLS], c[ROWS][COLS];
    int coef;

    printf("Введіть коефіцієнт c: ");
    scanf("%d", &coef);

    read_matrix(fa, a);
    read_matrix(fb, b);
    calculate_matrix(a, b, c, coef);
    write_matrix(fc, c);

    fclose(fa);
    fclose(fb);
    fclose(fc);

    puts("Результат записано у файл exit.txt");

    return 0;
}
