def fun(x):
	
	def addone():
		x += 1

	addone()
	print(x)

	addone()
	print(x)

fun(6)