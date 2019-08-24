import numpy as np
MAX_TRIAL = 1000 #試行数
CONVERGENCE = 0.00001 #収束判定の閾値
DIVERGENCE = 10000000000 #発散判定の閾値

print('何行行列にする？(2≦ n)')
while True:
	mat_size = int(input("n=") )
	if(mat_size>=2):
		break
	else:
		print('もう一度お願いします')

mat_A = np.zeros( (mat_size, mat_size) ) #mat_sizeの正方行列を作ります。
mat_B = np.zeros(mat_size) #mat_sizeの1次行列を作ります。
mat_tmp_ans = np.zeros(mat_size)
mat_ans = np.ones(mat_size)

for row in range (mat_size):
	print('第{}列'.format(row+1) )
	for col in range (mat_size):
		print('第{}行の係数は何にする？'.format(col+1) )
		mat_A[row,col] = float(input("=") )
	mat_B[row] = float(input("定数はどうする？\n=") )

for row in range (mat_size):
	for col in range (mat_size):
		print('+({: })x{}'.format(mat_A[row,col], col+1 ), end="" )
	print(' = {: }'.format(mat_B[row] ) )

fg0 = False
check = 0.0
for row in range (mat_size):
	for col in range (mat_size):
		if(row!=col):
			check += abs(mat_A[row,col] )
	if(abs(mat_A[row,row] ) < check ):
		fg0 = True
if(fg0): #True
	print('収束条件を満たしていません。')
else: #False
	print('収束条件を満たしています。')

#反復試行ループ
for trial in range(MAX_TRIAL):
	error = 0.0 #エラー値を初期化
	
	for row in range (mat_size):
		mat_tmp_ans[row] = mat_ans[row] #前回のmat_ans[row]を保持する。一気にコピーは計算の処理の関係上ダメ。 

		mat_ans[row] = mat_B[row] #第row列の定数項を代入

		for col in range (mat_size):
			if(row!=col):
				mat_ans[row] -= mat_A[row,col] * mat_ans[col]
		mat_ans[row] /= mat_A[row,row]

	print('第{}回試行'.format(trial+1))
	for row in range (mat_size):
		print('x{}={} '.format(row+1,mat_ans[row] ), end="" )
	print('')

	#収束発散判定
	error = np.sum(np.abs(mat_ans - mat_tmp_ans) )#収束判定がめっちゃ簡単に実装できた。pythonの威力ですねぇ。

	if(error <= CONVERGENCE):
		print('収束！')
		break
	if(error > DIVERGENCE):
		print('発散！')
		break
else:
	print('試行回数上限到達！')

print('終了！')