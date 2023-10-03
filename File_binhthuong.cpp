#include <stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#pragma warning(disable:6066)
void nhap(int& n, int* a)
{
	printf("nhap n: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap so %d: ", i);
		scanf_s("%d", (a + i));
	}
}
//void xuat(int& n, int *a)
//{
//	printf("Xuat day so:\t");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\t", *(a+i));
//	}
//}
void SNT(int& n, int* a, FILE* f, int& dem)
{
	//fopen_s(&f, "VD2.txt", "w");
	f = fopen("VD2.txt", "w");
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		if (*(a + i) > 2)
		{
			for (int j = 2; j <= sqrt(*(a + i)); j++)
			{
				if (*(a + i) % j == 0)
				{
					count++;
				}
			}
			if (count == 0)
			{
				fprintf(f, "%d\t", *(a + i));
				dem++;
			}
		}
	}
	fclose(f);
}
void docfile(int& n, int b[100], FILE* f, int dem)
{
	f = fopen("VD2.txt", "r");
	//f = fopen("VD2.txt", "r");
	for (int i = 0; i < dem; i++)
	{
		fscanf(f, "%d", &b[i]);
		printf("%d\t", b[i]);
	}
	fclose(f);
}
int main()
{
	int dem = 0;
	FILE* f;
	f = fopen("VD2.txt", "w");
	int* a = (int*)calloc(100, sizeof(int));
	//int b = (int)calloc(100, sizeof(int));
	int b[100];
	int n;
	nhap(n, a);
	SNT(n, a, f, dem);
	docfile(n, b, f, dem);

}
