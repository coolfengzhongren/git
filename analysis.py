import pandas as pd
import json 


def analysis(file, user_id):
	minutes = 0
	times = 0

	with open(file,'r') as fp1:
		datas = json.load(fp1)
		print(datas)

		for data in datas:
			if data['user_id'] == user_id:
				minutes += data['minutes']
				times +=1    #python中没有times++这种自增的语法 
				pass
	return times,minutes
	pass