#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>



void insertionsort(char* mas, int n)
{
    int i;
    int j;
    int temp;

    for (i = 1; i < n; i++)
    {
        for (j = i; j > 0 && mas[j - 1] > mas[j]; j--)
        {
                temp = mas[j - 1];
                mas[j - 1] = mas[j];
                mas[j] = temp;
        }
    }
}

void bubblesort(char* mas, int n)
{
    int i; 
    int j; 
    int temp; 

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                temp = mas[j]; 
                mas[j] = mas[j + 1]; 
                mas[j + 1] = temp;
            }
        }
    }
}
void qsortRecursive(char* mas, int size) {
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;

    //����������� ������� �������
    int mid = mas[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (mas[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (mas[j] > mid) {
            j--;
        }

        //������ �������� �������
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"����� �����"
        qsortRecursive(&mas[i], size - i);
    }
}








int main()
{
    int swap; 

    int i; 
    char* mas; 
    char* backup;
    int n; 
    int c; 
    int a = 0; 
    FILE* fi;
    clock_t time;

    setlocale(LC_ALL, "rus"); 
    fi = fopen("C:\\Users\\morfi\\source\\repos\\Project1\\Project1\\test.txt", "r");
    fscanf(fi, "%d\n", &n);
    mas = (char*)malloc(n * sizeof(int)); 
    backup = (char*)malloc(n * sizeof(int)); 
    for (i = 0; i < n; i++)
    {
        fscanf(fi, "%d\n", &mas[i]);
        backup[i] = mas[i];
    }
    fclose(fi);
    do {

   
        printf("�������� ���-��\n1 - ������\n2 - ����������\n3 - �����\n4 - �����\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            for (i = 0; i < n; i++)
                printf("mas[%d] = %d\n", i, mas[i]);
            break;
        case 2:
            system("cls");
            printf("�������� ������� ����������:1 - �������. 2 - �����������. 3 - ���������� ��������\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:

                printf("Vi vabrali qsort\n");
                time = clock();
                qsortRecursive(mas, n);
                time = clock() - time; 
                printf("����� ������ - %lf ���.\n", (double)time/CLOCKS_PER_SEC);
                break;
            case 2:
                printf("vi vibrali puziric");
                time = clock();
                bubblesort(mas, n);
                time = clock() - time;
                printf("����� ������ - %lf ���.\n", (double)time / CLOCKS_PER_SEC);
                
                break;
            case 3:
                printf("vi vibrali vstavku\n"); 
                time = clock();
                insertionsort(mas, n);
                time = clock() - time;
                printf("����� ������ - %lf ���.\n", (double)time / CLOCKS_PER_SEC);
                
                break;
            default:
                printf("Vvod neverniy. Noovogo goda ne budit.");


            }
            break;
        case 3:
            for (i = 0; i < n; i++)
                mas[i] = backup[i];
            break;
        case 4:
            free(mas);
            free(backup);
            return 0;
        default:
            printf(" vi elban. Napisano Russkim blyat yazikom ot 1 do 4. perezapuskai");
        }
    } while (a >= 0);
    free(mas);
    free(backup);
    return 0; 

}