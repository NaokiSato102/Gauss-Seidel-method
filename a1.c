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
	double	answer[]={1,1,1};//解の初期値は0としておく。
	double	tmpans[MAXGYOUSU]={};
	double	check, error;
	int i, gyousu=3,fg,hoge,huga;

	//行列表示開始
	for(hoge=0;hoge<gyousu;hoge++){
		for(huga=0;huga<gyousu;huga++){
				printf("+(%lf)x%d",gyouretu[hoge][huga],huga+1);
		}
		printf("=%lf\n",gyouretu[hoge][gyousu]);
	}
	//行列表示終了


	//収束条件を確認開始
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
		puts("満たしています。");
	}
	else if(fg>0){
		puts("満たしていません。");
	}
	//収束条件を確認終了
	
	
	//反復試行ループ
	for(i = 0;i < SIKOUSU;i++){
		
		error=0.0;//前週のエラー値をリセット
		
		for(hoge=0; hoge< gyousu ;hoge++ ){//第hoge列の計算
						
			tmpans[hoge]=answer[hoge];//前回のhoge
		
			answer[hoge] = gyouretu[hoge][gyousu];//第hoge列の定数項を代入。
			//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);//現在の解を表示
			for(huga=0;huga < gyousu ;huga++){//
				if(hoge!=huga){//行と列の数が同じでない時↓
					answer[hoge]-=gyouretu[hoge][huga]*answer[huga];//第hoge列の各項の係数と暫定解を掛けあわせ除算。
					//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);//現在の解を表示
				}
			}
			answer[hoge]/=gyouretu[hoge][hoge];//最後に除算
			
			//printf("[debug]:answer[%d]=%lf\n",hoge,answer[hoge]);	//現在の解を表示
			
		}//第hoge列の計算閉
	
		printf("第%03d回試行 ",i+1);
		for(hoge=0;hoge<gyousu;hoge++){
			printf("x%02d=%lf ",hoge+1,answer[hoge]);
		}
		puts("");//改行

		for(hoge=0;hoge<gyousu;hoge++){
			error+=fabs( answer[hoge]-tmpans[hoge] );
		}

		if(error<=SYUSOKU){
			i=SIKOUSU;
			printf("収束！！\n");
		}
		
		if(error>HASSAN){
			i=SIKOUSU;
			printf("発散\n");
		}
		
 }//反復試行ループ閉
}