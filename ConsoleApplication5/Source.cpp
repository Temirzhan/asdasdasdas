#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h>


FILE *fp;
int main(int argc, char *argv[])
{
	char ch;
	if (argc != 2)
	{
		printf("Vi zabiblib\n");
		exit(1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("EROR\n");
		exit(1);
	}
	ch = getc(fp);
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);
	return 0;
}


void main2()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	const int Layer1 = 5;
	const int Layer2 = 2;
	const int outfiles = 10;
	char buffer[100];
	int i = 0;
	for (;i < Layer1;i++)
	{
		int j = 0;
		for (;j < Layer2;j++)
		{
			sprintf(buffer, "md folder%d\\val%d", i, j);
			system(buffer);
			int k = 0;
			for (;k < outfiles;k++)
			{
				sprintf(buffer, "folder%d/val%d/ficher%d.xml", i, j, k);
				if ((fp = fopen(buffer, "w")) != NULL)
				{
					fprintf(fp, "<xml>\n<i>%d</i></xml>", k);
					fclose(fp);
				}
			}
		}
	}
}