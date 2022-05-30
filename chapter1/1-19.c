#include <stdio.h>

#define MAXLINE 100

int lineget(char line[]);
void reverse(char s[],int len);
void copy(char to[], char from[]);

int main() {
	char input[MAXLINE];
	int len;
	
	while ( (len = lineget(input) ) != 0 ) {
		reverse(input,len);
		printf("%s",input);
	}

	return 0;
}

int lineget(char line[]) {
	int i;
	char c;

	for ( i = 0; i < MAXLINE-1 && (c = getchar()) && c != '\n'; i++) {
		line[i] = c;
	}

	if (line[i] == '\n') {
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';
	return i;
}

void reverse(char s[],int len) {
	int i, j;
	j = 0;
	char arr[len];
	copy(arr,s);

	for (i = (len-1); s[i] > 0; i--) {
		s[j] = arr[i];
		j++;
	}
}

void copy(char to[], char from[]) {
	int i = 0;
	while ( (to[i] = from[i]) != '\0') {
		i++;
	}
}
		


