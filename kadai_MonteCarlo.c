#include <stdio.h>
#include <stdlib.h>
#define		NUM		10
#define		ERR		0.00001

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
	int				cincout	= 0;	/*ループ１用　円内に入った回数*/
	int				lcount 	= 0;	/*ループ１用　全体のループ回数*/
	int				cincout2= 0;	/*ループ２用　円内に入った回数*/
	int				lcount2 = 0;	/*ループ２用　全体のループ回数*/
	int				i		= 1;	/*全体のループ回数*/
	
	/*乱数の種子を入力*/
	printf("Random Seed Distiny => ");
	scanf("%d",&seed);
	srand(seed);
	
	/*二回のループを行いその誤差が一定以下なら円周率を計算*/
	while(i < 100000)
	{
		/*ランダムな座標が円内に入るか確率から円周率を割り出す　1回目*/
		while(lcount < (NUM * i))
		{
			/*ランダム座標生成 ( 0 <= x,y < 1 )*/
			x = (double)rand() / ((double)RAND_MAX + 1);
			y = (double)rand() / ((double)RAND_MAX + 1);
			printf("1R %d: r:%d x:%f,y:%f\n",lcount,cincout,x,y);
			
			/*円内に入ったか判定*/
			if((x*x) + (y*y) <= 1)
			{
				cincout++;
			}
			
			lcount++;
			
		}
		
		/*ランダムな座標が円内に入るか確率から円周率を割り出す　2回目*/
		while(lcount2 < (NUM * i))
		{
			/*ランダム座標生成 0 <= x,y < 1*/
			x = (double)rand() / ((double)RAND_MAX + 1);
			y = (double)rand() / ((double)RAND_MAX + 1);
			printf("2R %d: r:%d x:%f,y:%f\n",lcount2,cincout2,x,y);
			
			/*円内に入ったか判定*/
			if((x*x) + (y*y) <= 1)
			{
				cincout2++;
			}
			
			lcount2++;
			
		}
		
		/*1回目のループの円内に入る確率を出す*/
		prob = ((double)cincout / (double)lcount);
		
		/*2回目のループの円内に入る確率を出す*/
		prob2 = ((double)cincout2 / (double)lcount2);
		
		
		
		/*2つのループの確率の誤差を出す*/
		if( prob < prob2 )
		{
			err = prob2 - prob;
		}
		else
		{
			err = prob - prob2;
		} 
		printf("err:%f\n\n",err);
		
		/*誤差が規定範囲なら確率を出すループを抜ける*/
		if( (ERR >= err) && (err > 0) )
		{
			break;
		}
		
		i++;
	}
	
	/*円周率の近似値を算出*/
	s = prob * 4;
	
	/*円周率とループ回数表示*/
	printf("Pi:%f\n",s);
	printf("loop:%d\n",i);
}