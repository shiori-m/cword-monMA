#include <stdio.h>
#include <stdlib.h>
#define		CNUM	10			/*�~����̃��[�v��*/
#define		LNUM	100000		/*�S�̃��[�v��*/
#define		ERR		0.00001		/*�m���̋��e�덷*/

/*���C���֐�*/
void main(void)
{
	/*�ϐ��錾*/
	unsigned int	seed;			/*�����̎�*/
	double			prob;			/*�~���ɓ������m��*/
	double			prob2	= 0;	/*�O�̃��[�v�ŏo�����m��*/
	double			err;			/*�O�̊m���Ƃ̌덷*/
	double			x, y;			/*x���W�A�����W*/
	double			s;				/*����o�����~�����̋ߎ��l*/
	int				cincout	= 0;	/*�~���ɓ�������*/
	int				lcount 	= 0;	/*�S�̂̃��[�v��*/
	
	/*�����̎�q�����*/
	printf("Random Seed Distiny => ");
	scanf("%d",&seed);
	srand(seed);
	
	/*�~���������߂邽�߁A�����_���ȍ��W���~���ɓ���m�������߂�*/
	while(lcount < LNUM)
	{
	
		/*�����_�����W���� ( 0 <= x,y < 1 )*/
		x = (double)rand() / ((double)RAND_MAX + 1);
		y = (double)rand() / ((double)RAND_MAX + 1);
		printf("loop:%d r:%d x:%f,y:%f\n",lcount,cincout,x,y);
		
		/*�~���ɓ�����������*/
		if((x*x) + (y*y) <= 1)
		{
			cincout++;
		}
		
		lcount++;
		
		
		
		/*�~���ɓ���m�����o��*/
		prob = ((double)cincout / (double)lcount);
		
		
		/*�O��ƍ���̃��[�v�̂ŏo�����m���̌덷���v�Z*/
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
			/*�덷���K��͈͂Ȃ�m�����o�����[�v�𔲂���*/
			if( (ERR >= err) && (err > 0) )
			{
				printf("err:%f\n\n",err);
				break;
			}
		}
		
		/*�~���ɓ���m����ۑ�*/
		prob2 = prob;
	}
	
	/*�~�����̋ߎ��l���Z�o*/
	s = prob * 4;
	
	/*�~����(��)�ƃ��[�v�񐔕\��*/
	printf("Pi:%f\n",s);
	printf("loop:%d\n",lcount);
}