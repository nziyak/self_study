import numpy as np
import time

initial_time = time.time()

array = np.array([1,2,3,4,5]) #array is faster than lists while processing by numpy

#print(type(array))

#lets see that speed different with an example:

#lets say we have a list named revenues:

revenues = [2000, 5000, 3000, 65000, 7200, 31000, 26550, 1900, 3820, 5100, 41000]

sum = 0

for i in revenues:
    sum += i

print("sum is: ", sum)
print()

termination_time = time.time()

time_list = termination_time - initial_time

#print("Execution time with list: ", termination_time - initial_time)

#######################################

array = np.array(revenues)

initial_time = time.time()

sum = array.sum()
print(sum)
print()

termination_time = time.time()

time_array = termination_time - initial_time

#print("Execution time with array: ", termination_time - initial_time)
print("Execution time with array: ", time_array)
print("Execution time with list: ", time_list)
print(time_list/time_array)
print("\n\n")
#array requires less memory
#array can not hold different type of values

x = ["Ben", 500, "Jake", "Liz", 6000]
print(x)

for i in x:
    print(type(i))

print()

arrayx = np.array(x)
print(arrayx)    

for i in arrayx:
    print(type(i))

#when we assign the list to numpy array, the type of the each element is changed to numpy string type

#we can work with multidimensional datas with the help of numpy arrays, for example:
print()
array2 = np.array([[1,2,3],[4,5,6]])
print(array2)
print()

#to get the number of dimensions a array have, we can use .ndim method of numpy:
print("number of dimensions: ", array2.ndim)
print()

#to get the number of rows and the elements each row have, we can use .shape method of numpy:
print("(row number, element number in each row): ", array2.shape)
print()

#to calculate the number of elements array has, we can use the .size method of numpy:
print("num. of elements: ", array2.size)