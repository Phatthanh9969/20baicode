#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ghifile(char c[100])
{
	char a[20];
	printf("Nhap ki tu: ");
	fgets(c, 100, stdin);
	FILE* f;
	f = fopen("BAITAP.txt", "wb");
	for (int i = 0; i < strlen(c); i++)
	{
		fwrite(&c[i], sizeof(char), 1, f);
	}
	fclose(f);
	//printf("%d", strlen(c));
}
void docfile(char c[10])
{
	FILE* f;
	f = fopen("BAITAP.txt", "rb");
	for (int i = 0; i < strlen(c); i++)
	{
		fread(&c[i], sizeof(char), 1, f);
		printf("%c", c[i]);
	}
	fclose(f);
	//printf("%d", strlen(c));
}
void Delete(char c[100])
{
	char f;
	printf("\nNhap ki tu muon xoa: ");
	scanf_s("%c", &f);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == f)
		{
			for (int j = i; j < strlen(c); j++)
			{
				c[j] = c[j + 1];
			}
			sizeof(c) - 1;
		}
	}
	printf("%s", c);
}
int main()
{

	char c[100];
	ghifile(c);
	Delete(c);
	docfile(c);

}
