/*
 * C言語のサンプルプログラム - Webkaru
 * - 乱数を使って円周率を求めてみよう（モンテカルロ法） -
 */
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
	int i;
	int count = 0;
	int max = 10000000;
	double x,y,z,pi;
	int s;					//乱数の種
	int c = 0;
	double keepz;
	double keepz2;
	
	/* 乱数の種を入力 */
	printf("入力：");
	scanf( "%d", &s );

	/* 乱数の種を */
	srand(s);	
	
	/* 0 〜 1 の乱数を生成・出力 */
	while( c++ < 2 )
	{
		for( i = 0 ; i < max ; i++ )
		{
			 x = (double)rand()/((double)RAND_MAX+1);
			 y = (double)rand()/((double)RAND_MAX+1);
			 z = x*x + y*y;
			if(z<1)
			count++;
		}
		if(  c <= 1 )
		{
			keepz = count;
		}
		if( 1 < c <= 2 )
		{
			keepz2 = count;
		}
	}
	
	/* 円周率を計算・出力 */
	pi = (double)count / max  4 / 2;
	printf("%f\n", pi);
	/* 確率を計算・出力 */
	pi = (double)count / max / 2;
	printf("%f\n", pi);
	
	
	return 0;
}
