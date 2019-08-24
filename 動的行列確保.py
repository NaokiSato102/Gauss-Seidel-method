import numpy as np



print('何行行列にする？(2≦ n)')
while True:
	mat_size = int(input("n=") )
	if(mat_size>=2):
		break
	else:
		print('もう一度お願いします')



mat_A = np.arange(mat_size**2).reshape( mat_size,mat_size ) #mat_sizeの正方行列を作ります。
mat_B = np.arange(mat_size) #mat_sizeの1次行列を作ります。
print(mat_A)
print(mat_B)

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