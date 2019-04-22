
#!/usr/bin/env python
process_queue = []
total_wtime = 0


def gtable():
	print('0',end=" ")
	process_time=0
	for i in range(n):
		for j in range(process_queue[i][2]):
			print('-',end=" ")
		process_time+=process_queue[i][2]	
		print(process_time,end=" ")

def gname():
	for i in range(n):
		for j in range(process_queue[i][2]-2):
			print(' ',end=" ")	
		print(''+process_queue[i][0],end=" ")
					

n = int(input('Enter the total no of processes: '))

for i in range(n):
    process_queue.append([])#append a list object to the list
    process_queue[i].append(input('Enter p_name: '))
    process_queue[i].append(int(input('Enter p_arrival: ')))
    total_wtime += process_queue[i][1]
    process_queue[i].append(int(input('Enter p_bust: ')))
    print ("")

process_queue.sort(key = lambda process_queue:process_queue[1])

print ('ProcessName\t\tArrivalTime\t\tBurstTime')

for i in range(n):
    print (process_queue[i][0],'\t\t\t\t',process_queue[i][1],'\t\t\t\t',process_queue[i][2])
    
print ('Total waiting time: ',total_wtime)
print ('Average waiting time: ',(total_wtime/n))

gtable()
print('')
gname()
print('')
gtable()



