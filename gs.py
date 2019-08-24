import numpy as np
MAX_MATRIX_SIZE = 10 #最大行列サイズ　たぶん動的確保できるようになるから不要になる
MAX_TRIAL = 1000 #試行数
CONVERGENCE = 0.00001 #収束判定の閾値
DIVERGENCE = 10000000000 #発散判定の閾値

mat_A = np.array( [ [5,-1,3], [-1,4,2], [1,2,-4] ] )
mat_B = np.array( [2,1,2] )
mat_tmp_ans = np.zeros(3)
mat_ans = np.ones(3)

#現在の行列の表示　もっといい方法ないかな？ありそうだけど。
for row in range (mat_A.shape[0]):
	for col in range (mat_A.shape[0]):
		print('+({: })x{}'.format(mat_A[row,col], col+1 ), end="" )
	print(' = {: }'.format(mat_B[row] ) )

fg0 = False
check = 0.0
for row in range (mat_A.shape[0]):
	for col in range (mat_A.shape[0]):
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
	
	for row in range (mat_A.shape[0]):
		mat_tmp_ans[row] = mat_ans[row] #前回のmat_ans[row]を保持する。一気にコピーは計算の処理の関係上ダメ。 

		mat_ans[row] = mat_B[row] #第row列の定数項を代入

		for col in range (mat_A.shape[0]):
			if(row!=col):
				mat_ans[row] -= mat_A[row,col] * mat_ans[col]
		mat_ans[row] /= mat_A[row,row]

	print('第{}回試行'.format(trial+1))
	for row in range (mat_A.shape[0]):
		print('x{}={} '.format(row+1,mat_ans[row] ), end="" )
	print('')

	#収束発散判定
	error = np.sum(np.abs(mat_ans - mat_tmp_ans) )

	if(error <= CONVERGENCE):
		print('収束！')
		break
	if(error > DIVERGENCE):
		print('発散！')
		break
else:
	print('試行回数上限到達！')

print('終了！')