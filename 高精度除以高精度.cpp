#include<cstdio>
#include<string.h>
#define   N  500
int  bj(int a[], int b[], int k1, int k2) { /*�Ƚϴ�С����*/
	int i, t, flag;       /*flag����־λ*/
	if(k1 < k2)
		flag = 0;           /*������С�ڳ�������0*/
	else if(k1 > k2)
		flag = 1;      /*���������ڳ�������1*/ 
	else {
		/*�������ͳ���λ���������λ���бȽ�*/
		i = k1;
		t = 0;
		while(t == 0 && i > 0) {
			if(a[i] > b[i]) {
				t = 1;
				flag = 1;
			} else if(a[i] == b[i])  i--;
			else  {
				t = 1;
				flag = 0;
			}
		}
		if(i == 0 && t == 0)  flag = 2;     /*���������ڳ�������2*/
	}
	return flag;
}
int  jf(int a[], int b[], int k1, int k2) {     /*��������*/
	int  i, k, d[N];
	for(i = 0; i < k2; i++)  d[i] = b[i];        /*�ѳ�����������d*/
	for(i = k2; i < N; i++)  d[i] = 0;          /*d���������ݵĸ�λ��0*/
	k = k1 - k2 - 1;                            /*���������ʼλ��*/
	if(k < 0)  k = 0;
	if(k > 0) {
		for(i = k2 - 1; i >= 0; i--)  d[i + k] = d[i];  /*�ƶ�����λ���뱻��������*/
		for(i = 0; i < k; i++)  d[i] = 0;            /*�ƶ��������λ��0*/
	}
	for(i = 0; i < k1; i++) {
		if(a[i] >= d[i])  a[i] -= d[i];
		else {
			a[i + 1] = a[i + 1] - 1;
			a[i] = 10 + a[i] - d[i];
		}
	}
	return k;
}
int main() {
	int  a[N] = {0}, b[N] = {0}, c[N] = {0}, d[N] = {0};
	int  i, ka, kb, m, t, t1, t2, k, x, kd, kk;
	
	
	char  a1[N], b1[N];
	printf("Input ������:");
	scanf("%s", a1);
	ka = strlen(a1);
	for(i = 0; i < ka; i++)  a[i] = a1[ka - i -1] - '0';
	printf("Input ����:");
	scanf("%s", b1);
	kb = strlen(b1);
	for(i = 0; i < kb; i++)  b[i] = b1[kb - i -1] - '0';
	
	
	kd = ka;    /*���汻����λ��  */
	t2 = bj(a, b, ka, kb);
	m = 0;
	do {
		while(a[ka - 1] == 0)  ka--;
		t = bj(a, b, ka, kb);
		if(t >= 1) {
			k = jf(a, b, ka, kb);
			c[k]++;
			if(k > m)  m = k;
			t1 = 0;
			for(i = k; i <= m; i++) {
				x = c[i] + t1;
				c[i] = x % 10;
				t1 = x / 10;
			}
			if(t1 > 0)  {
				m++;
				c[m] = t1;
			}
		}
	} while(t == 1);
	if(t2 == 0) {
		printf("��=0");
		printf("\n����=");
		for(i = kd - 1; i >= 0; i--)  printf("%d", a[i]);
		return 1;
	}
	if(t2 == 2) {
		printf("�� = 1");
		printf("\n���� = 0");
		return 1;
	}
	kk = kd;
	while(!c[kd - 1])  kd--;
	printf("�� = ");
	for(i = kd - 1; i >= 0; i--)  printf("%d", c[i]);
	while(!a[kk])  kk--;
	printf("\n���� = ");
	if(kk < 0) {
		printf("0");
		return 1;
	}
	for(i = kk; i >= 0; i--)  printf("%d", a[i]);
}
