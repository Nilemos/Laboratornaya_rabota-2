#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 


int main()

{
	setlocale(LC_ALL, "RUS"); 
	
	int min = 0; 
	int max = 0; 
	int n = 0; 
	char* mas = 0; 
	char i = 0; 
	FILE * fo; 
	
	printf( "������� �����������, ������������, ����������\n"); //�������� �� -128 �� 127 
	
	scanf("%d", &min); 
	scanf("%d", &max);
	scanf("%d", &n);
	
	if ((min < -128) || (max > 127))

	{

		printf("������: �������������� ���������");
		return 0;
	
	}
	
	mas = (char*)malloc(n * sizeof(char)); 
	srand(time(NULL)); 
	fo = fopen("test.txt", "w+");
	fprintf(fo, "%d\n", n);
	                                        //fprintf(fo, fprintf(fo, "%d\n", mas[i]))
	for (i;i < n; i++)
	    {

		mas[i] = ((double)rand()/RAND_MAX)*(max - min)+ min;
		fprintf(fo, "%d\n", mas[i]); 
		
	    }
	fclose(fo);
	free(mas);
	return 0; 

}