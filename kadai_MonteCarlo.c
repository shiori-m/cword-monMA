#include <stdio.h>
#include <stdlib.h>
#define		NUM		10
#define		ERR		0.00001

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
	int				cincout	= 0;	/*���[�v�P�p�@�~���ɓ�������*/
	int				lcount 	= 0;	/*���[�v�P�p�@�S�̂̃��[�v��*/
	int				cincout2= 0;	/*���[�v�Q�p�@�~���ɓ�������*/
	int				lcount2 = 0;	/*���[�v�Q�p�@�S�̂̃��[�v��*/
	int				i		= 1;	/*�S�̂̃��[�v��*/
	
	/*�����̎�q�����*/
	printf("Random Seed Distiny => ");
	scanf("%d",&seed);
	srand(seed);
	
	/*���̃��[�v���s�����̌덷�����ȉ��Ȃ�~�������v�Z*/
	while(i < 100000)
	{
		/*�����_���ȍ��W���~���ɓ��邩�m������~����������o���@1���*/
		while(lcount < (NUM * i))
		{
			/*�����_�����W���� ( 0 <= x,y < 1 )*/
			x = (double)rand() / ((double)RAND_MAX + 1);
			y = (double)rand() / ((double)RAND_MAX + 1);
			printf("1R %d: r:%d x:%f,y:%f\n",lcount,cincout,x,y);
			
			/*�~���ɓ�����������*/
			if((x*x) + (y*y) <= 1)
			{
				cincout++;
			}
			
			lcount++;
			
		}
		
		/*�����_���ȍ��W���~���ɓ��邩�m������~����������o���@2���*/
		while(lcount2 < (NUM * i))
		{
			/*�����_�����W���� 0 <= x,y < 1*/
			x = (double)rand() / ((double)RAND_MAX + 1);
			y = (double)rand() / ((double)RAND_MAX + 1);
			printf("2R %d: r:%d x:%f,y:%f\n",lcount2,cincout2,x,y);
			
			/*�~���ɓ�����������*/
			if((x*x) + (y*y) <= 1)
			{
				cincout2++;
			}
			
			lcount2++;
			
		}
		
		/*1��ڂ̃��[�v�̉~���ɓ���m�����o��*/
		prob = ((double)cincout / (double)lcount);
		
		/*2��ڂ̃��[�v�̉~���ɓ���m�����o��*/
		prob2 = ((double)cincout2 / (double)lcount2);
		
		
		
		/*2�̃��[�v�̊m���̌덷���o��*/
		if( prob < prob2 )
		{
			err = prob2 - prob;
		}
		else
		{
			err = prob - prob2;
		} 
		printf("err:%f\n\n",err);
		
		/*�덷���K��͈͂Ȃ�m�����o�����[�v�𔲂���*/
		if( (ERR >= err) && (err > 0) )
		{
			break;
		}
		
		i++;
	}
	
	/*�~�����̋ߎ��l���Z�o*/
	s = prob * 4;
	
	/*�~�����ƃ��[�v�񐔕\��*/
	printf("Pi:%f\n",s);
	printf("loop:%d\n",i);
}