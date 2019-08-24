#include <stdio.h>
#include <math.h>
#define MAXGYOUSU 10
#define SIKOUSU 1000
#define SYUSOKU 0.00001
#define HASSAN 10000000000

int main(){
	double	gyouretu[3][4]={
		{ 5,-1, 3, 2},
		{-1, 4, 2, 1},
		{ 1, 2,-4, 2}
		};
	double	answer[]={1,1,1};//���̏����l��0�Ƃ��Ă����B
	double	tmpans[MAXGYOUSU]={};
	double	check, error;
	int i, gyousu=3,fg,hoge,huga;

	//�s��\���J�n
	for(hoge=0;hoge<gyousu;hoge++){
		for(huga=0;huga<gyousu;huga++){
				printf("+(%lf)x%d",gyouretu[hoge][huga],huga+1);
		}
		printf("=%lf\n",gyouretu[hoge][gyousu]);
	}
	//�s��\���I��


	//�����������m�F�J�n
	fg=0;
	for(hoge=0;hoge<gyousu;hoge++){
		for(huga=0;huga<gyousu;huga++){
			if(huga!=hoge){
				check+=fabs(gyouretu[hoge][huga]);
			}		
		}
		if( fabs(gyouretu[hoge][hoge]) < check){
			fg+=1;
		}	
	}
	if(fg==0){
		puts("�������Ă��܂��B");
	}
	else if(fg>0){
		puts("�������Ă��܂���B");
	}
	//�����������m�F�I��
	
	
	//�������s���[�v
	for(i = 0;i < SIKOUSU;i++){
		
		error=0.0;//�O�T�̃G���[�l�����Z�b�g
		
		for(hoge=0; hoge< gyousu ;hoge++ ){//��hoge��̌v�Z
						
			tmpans[hoge]=answer[hoge];//�O���hoge
		
			answer[hoge] = gyouretu[hoge][gyousu];//��hoge��̒萔�������B
			//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);//���݂̉���\��
			for(huga=0;huga < gyousu ;huga++){//
				if(hoge!=huga){//�s�Ɨ�̐��������łȂ�����
					answer[hoge]-=gyouretu[hoge][huga]*answer[huga];//��hoge��̊e���̌W���Ǝb������|�����킹���Z�B
					//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);//���݂̉���\��
				}
			}
			answer[hoge]/=gyouretu[hoge][hoge];//�Ō�ɏ��Z
			
			//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);	//���݂̉���\��
			
		}//��hoge��̌v�Z��
	
		printf("��%03d�񎎍s ",i+1);
		for(hoge=0;hoge<gyousu;hoge++){
			printf("x%02d=%lf ",hoge+1,answer[hoge]);
		}
		puts("");//���s

		for(hoge=0;hoge<gyousu;hoge++){
			error+=fabs( answer[hoge]-tmpans[hoge] );
		}

		if(error<=SYUSOKU){
			i=SIKOUSU;
			printf("�����I�I\n");
		}
		
		if(error>HASSAN){
			i=SIKOUSU;
			printf("���U\n");
		}
		
 }//�������s���[�v��
}