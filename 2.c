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
    //Óêàçàòåëè â íà÷àëî è â êîíåö ìàññèâà
    int i = 0;
    int j = size - 1;

    //Öåíòðàëüíûé ýëåìåíò ìàññèâà
    int mid = mas[size / 2];

    //Äåëèì ìàññèâ
    do {
        //Ïðîáåãàåì ýëåìåíòû, èùåì òå, êîòîðûå íóæíî ïåðåêèíóòü â äðóãóþ ÷àñòü
        //Â ëåâîé ÷àñòè ìàññèâà ïðîïóñêàåì(îñòàâëÿåì íà ìåñòå) ýëåìåíòû, êîòîðûå ìåíüøå öåíòðàëüíîãî
        while (mas[i] < mid) {
            i++;
        }
        //Â ïðàâîé ÷àñòè ïðîïóñêàåì ýëåìåíòû, êîòîðûå áîëüøå öåíòðàëüíîãî
        while (mas[j] > mid) {
            j--;
        }

        //Ìåíÿåì ýëåìåíòû ìåñòàìè
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Ðåêóðñèâíûå âûçîâû, åñëè îñòàëîñü, ÷òî ñîðòèðîâàòü
    if (j > 0) {
        //"Ëåâûé êóñîê"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Ïðâûé êóñîê"
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

   
        printf("Âûáåðèòå ÷òî-òî\n1 - ïå÷àòü\n2 - ñîðòèðîâêà\n3 - ñáðîñ\n4 - âûõîä\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            for (i = 0; i < n; i++)
                printf("mas[%d] = %d\n", i, mas[i]);
            break;
        case 2:
            system("cls");
            printf("Âûáåðèòå âàðèàíò ñîðòèðîâêè:1 - Áûñòðàÿ. 2 - Ïóçûðüêîâàÿ. 3 - Ñîðòèðîâêà Âñòàâêîé\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:

                printf("Vi vabrali qsort\n");
                time = clock();
                qsortRecursive(mas, n);
                time = clock() - time; 
                printf("Âðåìÿ ðàáîòû - %lf ñåê.\n", (double)time/CLOCKS_PER_SEC);
                break;
            case 2:
                printf("vi vibrali puziric");
                time = clock();
                bubblesort(mas, n);
                time = clock() - time;
                printf("Âðåìÿ ðàáîòû - %lf ñåê.\n", (double)time / CLOCKS_PER_SEC);
                
                break;
            case 3:
                printf("vi vibrali vstavku\n"); 
                time = clock();
                insertionsort(mas, n);
                time = clock() - time;
                printf("Âðåìÿ ðàáîòû - %lf ñåê.\n", (double)time / CLOCKS_PER_SEC);
                
                break;
            default:
                printf("Error");


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
            printf("Error");
        }
    } while (a >= 0);
    free(mas);
    free(backup);
    return 0; 

}
