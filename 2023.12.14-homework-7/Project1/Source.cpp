#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

#include<cstring>
#include<string>
#include<fstream>

/*pureC
count words and display the longest sentence.
realise functions:
strcat()
strstr()
substr()
strcmp()
strmult()*/
int Countsize(char* filename);
int StrLen(char* str);

char* Strcat(char* str1, char* str2);
char* Substr(char* str, int from, int to);
int Strcmp(char* str1, char* str2);
int Strstr(char* str1, char* str2);
char* Strmult(char* str1, int n);

int Countwords(char* filename);
char* Maxsentence(char* filename);


int main(int argc, char* argv[])
{
	char* a = new char[6] {'f', '.', 't', 'x', 't', '\0'};
	printf_s("%d \n", Countwords(a));
	printf_s("%s \n", Maxsentence(a));

	free(a);
	return 0;
}

int Countsize(char* filename)
{
	FILE* file = fopen(filename, "r");

	int length = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		length++;
	}
	length++;
	fclose(file);
	return length;
}
int StrLen(char* str)
{
	int res = 0;
	while (str[++res] != '\0');
	return res;
}

char* Strcat(char* str1, char* str2)
{
	int len1 = StrLen(str1);
	int len2 = StrLen(str2);
	int newlen = len1 + len2 + 1;
	char* str = (char*)malloc(sizeof(char) * newlen);
	char* a = new char[3] {'a', 'b', 'g'};

	for (int i = 0; i < len1; ++i)
	{
		str[i] = str1[i];
	}
	for (int i = len1; i < newlen - 1; ++i)
	{
		str[i] = str2[i - len1];
	}
	str[newlen - 1] = '\0';
	return str;
}
char* Substr(char* str, int from, int to)
{
	int len = StrLen(str);
	char* substr = (char*)malloc(sizeof(char) * (to - from + 2));
	for (int i = 0; i < to - from + 1;++i)
	{
		substr[i] = str[from + i];
	}
	substr[to - from + 1] = '\0';
	return substr;
}
int Strcmp(char* str1, char* str2)
{
	int len1 = StrLen(str1);
	int len2 = StrLen(str2);
	for (int i = 0; (i < len1) && (i < len2);++i)
	{
		if (str1[i] != str2[i])
		{
			return ((int)str1[i] - (int)str2[i]);
		}
	}
	return 0;
}
int Strstr(char* str1, char* str2)
{
	int len1 = StrLen(str1);
	int len2 = StrLen(str2);
	int ind = 0;
	bool T = false;
	for (int i = 0; i < len1;++i)
	{
		if (str1[i] == str2[0])
		{
			T = true;
			ind = i;
			int n = 1;
			for (int j = i + 1; j < i + len2;++j)
			{
				T = T && (str1[j] == str2[n]);
				n++;
			}
			if (T)
			{
				return ind;
			}
		}
	}

	return NULL;
}
char* Strmult(char* str1, int n)
{
	int len = StrLen(str1);
	char* str = (char*)malloc(sizeof(char) * len * n + 1);
	for (int j = 0; j < n;++j)
	{
		for (int i = 0 + len * j; i < len * (j + 1);++i)
		{
			str[i] = str1[i - len * j];
		}
	}
	str[len * n] = '\0';
	return str;

}

int Countwords(char* filename)
{
	FILE* file = fopen(filename, "r");
	int count = 0;
	while (!feof(file))
	{
		char c = 0;
		fscanf_s(file, "%c", &c);
		if (c == ' ' || c == '\n' || c == '\t')
		{
			count++;
		}
	}
	count++;

	fclose(file);
	return count;
}
char* Maxsentence(char* filename)
{
	FILE* file = fopen(filename, "r");
	int len = Countsize(filename);

	char* sentences = (char*)malloc(sizeof(char) * len);
	int i = 0;
	while (!feof(file))
	{
		fscanf_s(file, "%c", &sentences[i]);
		++i;
	}
	sentences[i + 1] = '\0';
	int ind1 = -1;
	int ind2 = 0;
	int len2 = 0;
	int maxlen = 0;
	for (int i = 0; i < len; ++i)
	{
		len2++;
		if ((sentences[i] == '.') || (sentences[i] == '?') || (sentences[i] == '!'))
		{
			if (len2 > maxlen)
			{
				maxlen = len2;
				ind1 = ind2;
				ind2 = i;
			}
			len2 = 0;
		}
	}

	fclose(file);
	return Substr(sentences, ind1 + 1, ind2);
}

