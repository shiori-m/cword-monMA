/**************************************************/
/* 作成者       ：松崎 史緒理                     */
/* 変更者       ：荒井 敬生                       */
/* 作成日       ：2017/06/05                      */
/* プログラム名 ：pkadai-monte2.c                 */
/*                                                */
/**************************************************/
#include <stdio.h>
#include <stdlib.h>
#define		ERR		0.00001		/*確率の許容誤差*/


/* ---------------------------------------------- */
/* 関数名       ：main                            */
/* 機能概要     ：乱数入                          */
/* 作成者       ：松崎 史緒理                     */
/* 作成日       ：2017/06/05                      */
/* ---------------------------------------------- */

int main(void)
{
	int		i,j;			/*for文用変数*/
	int		loop;			/*ループ回数*/
	double	x,y;			/*x座標、ｙ座標*/
	double	z;				/*円内の範囲かどうかの変数*/
	double	pi,pi2;			/*円内に入った確率保持の変数*/
	double	pi3;			/*確率の差分の変数*/
	double	pi4				/*円周率（仮）*/
	int		s;				/*乱数の種*/
	int		count = 0;		/*円内に入った数の記録*/
	double	keepc;			/*円内に入った回数の保持*/
	double	keepc2;			/*円内に入った回数の保持(2回目)*/
	
	/* 乱数の種を入力 */
	printf("Random Seed Distiny =>");
	scanf( "%d", &s );

	/* 乱数の種を設定*/
	srand(s);
	
	/* ループ回数 */
	printf("ループさせたい回数を入力：");
	scanf( "%d", &loop );

	
	/*円周率を求めるため、ランダムな座標が円内に入る回数を求める*/
	for(i = 0;i < 2;i++)
	{
		for( j = 0 ; j < loop ;j++ )
		{
			/*ランダム座標生成 ( 0 <= x,y < 1 )*/
			 x = (double)rand()/((double)RAND_MAX + 1);
			 y = (double)rand()/((double)RAND_MAX + 1);
			
			/*円内に入ったか判定*/
			 z = x*x + y*y;
			if(z < 1)
			{
				count++;
			}
		}
		
		/*円内に入った数の記録*/
		if( i < 1 )
		{
			keepc = count;
		}
		if( 1 <= i < 2 )
		{
			keepc2 = count;
		}
	} 
	
	/* 確率を計算・出力 */
	pi  = (double)keepz / max;
	printf("1回目： %f\n", pi);
	
	pi2 = (double)keepz2 / max / 2;
	printf("2回目： %f\n", pi2);
	
	/*前回と今回のループので出した確率の誤差を計算*/
	if( pi < pi2 )
	{
		pi3 = pi2 - pi;
	}
	else
	{
		pi3 = pi - pi2;
	}
	
	if(0 == (0 == pi || 1 == pi))
	{
		/*誤差が規定範囲なら確率を出すループを抜ける*/
		if( (ERR >= pi3) && (pi3 > 0) )
		{
//			break;
		}
	}
	
		/*円周率の近似値を算出*/
	pi4 = pi * 4;
	
	/*円周率(仮)とループ回数表示*/
	printf("pi3:%f\n\n",pi3);
	printf("Pi:%f\n",pi4);
	printf("loop:%d\n",loop);

	
	return 0;
}
