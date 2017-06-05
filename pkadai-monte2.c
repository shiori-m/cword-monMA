/**************************************************/
/* 作成者       ：松崎 史緒理                     */
/* 作成日       ：2017/06/05                      */
/* プログラム名 ：pkadai-monte2.c                 */
/**************************************************/
#include <stdio.h>
#include <stdlib.h>


/* ---------------------------------------------- */
/* 関数名       ：main                            */
/* 機能概要     ：乱数入                          */
/* 作成者       ：松崎 史緒理                     */
/* 作成日       ：2017/06/05                      */
/* ---------------------------------------------- */

int main(void)
{
	int i;
	int count = 0;
	int max = 100000000;
	double x,y;				//座標の変数
	double z;				//円内の範囲かどうかの変数
	double pi,pi2;			//確率の変数
	double pi3;				//確率の差分の変数
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
	
	/* 確率を計算・出力 */
	pi  = (double)keepz / max;
	printf("1回目： %f\n", pi);
	pi2 = (double)keepz2 / max / 2;
	printf("2回目： %f\n", pi2);
	
	/* piとpi2の確率の差分 */
	pi3 = (pi2 - pi);
	printf("差分 ：%f\n", pi3);
	
	if( 0.00001 < pi3 )
	{
		
	}
	
	return 0;
}
