#include <bits/stdc++.h>
int main()
{
	char c;
	int cnt = 0;
	while (scanf("%c", &c) == 1) {
		//assert(c != ' ');
		c >= 'S' ? c -= 1 : c;
		c == 'Y' ? c -= 1 : c;
		cnt += ((c - 65) / 3) + 3;
	}
	printf("%d", cnt);
}
