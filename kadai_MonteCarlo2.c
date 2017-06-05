#include <stdio.h>
#include <stdlib.h>
#define		CNUM	10			/*円判定のループ回数*/
#define		LNUM	100000		/*全体ループ回数*/
#define		ERR		0.00001		/*確率の許容誤差*/

/*メイン関数*/
void main(void)
{
	/*変数宣言*/
	unsigned int	seed;			/*乱数の種*/
	double			prob;			/*円内に入った確率*/
	double			prob2	= 0;	/*前のループで出した確率*/
	double			err;			/*前の確率との誤差*/
	double			x, y;			/*x座標、ｙ座標*/
	double			s;				/*割り出した円周率の近似値*/
	int				cincout	= 0;	/*円内に入った回数*/
	int				lcount 	= 0;	/*全体のループ回数*/
	
	/*乱数の種子を入力*/
	printf("Random Seed Distiny => ");
	scanf("%d",&seed);
	srand(seed);
	
	/*円周率を求めるため、ランダムな座標が円内に入る確率を求める*/
	while(lcount < LNUM)
	{
	
		/*ランダム座標生成 ( 0 <= x,y < 1 )*/
		x = (double)rand() / ((double)RAND_MAX + 1);
		y = (double)rand() / ((double)RAND_MAX + 1);
		printf("loop:%d r:%d x:%f,y:%f\n",lcount,cincout,x,y);
		
		/*円内に入ったか判定*/
		if((x*x) + (y*y) <= 1)
		{
			cincout++;
		}
		
		lcount++;
		
		
		
		/*円内に入る確率を出す*/
		prob = ((double)cincout / (double)lcount);
		
		
		/*前回と今回のループので出した確率の誤差を計算*/
		if( prob < prob2 )
		{
			err = prob2 - prob;
		}
		else
		{
			err = prob - prob2;
		} 
		
		
		if(0 == (0 == prob || 1 == prob))
		{
			/*誤差が規定範囲なら確率を出すループを抜ける*/
			if( (ERR >= err) && (err > 0) )
			{
				printf("err:%f\n\n",err);
				break;
			}
		}
		
		/*円内に入る確率を保存*/
		prob2 = prob;
	}
	
	/*円周率の近似値を算出*/
	s = prob * 4;
	
	/*円周率(仮)とループ回数表示*/
	printf("Pi:%f\n",s);
	printf("loop:%d\n",lcount);
}