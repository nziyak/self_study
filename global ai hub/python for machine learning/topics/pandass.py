# pandas library have "series" which is similar to arrays in numpy. but instead of 
# holding only one dimension, series can hold any type.
import pandas as pd
import numpy as np

my_series = pd.Series([10, 27, 32, 41, 5])

print("\nsize of the series: ", my_series.size)
print()

print("number of dimensions: ", my_series.ndim)
print()

print("first two elements:")
print(my_series.head(2))
print()

print("last two elements:")
print(my_series.tail(2))
print()

# slicing:

print(my_series[1:4])
print()

#dataframe is Pandas Series with 2 dimensions which is a table-like structure with rows and columns.

#lets first create a python list:

numbers = [[1, 2, 39, 67, 90], [1, 2, 39, 67, 90]]

df = pd.DataFrame(numbers)

print(df)
 
#using numpy arrays gives more efficient results by saving both time and memory

arr = np.array([[1,2,39,67,90], [8,12,45,12,8], [2,8,34,90,102]])

df = pd.DataFrame(arr)

print()
print(df.describe())

print()
print(df.describe().T) #adding .T at the end of a DataFrame it will transpose the data, which means it will reverse the columns with the rows.

#we have functions to read datas from files such as csv, txt, xlsx. here how to use them:

dataframe_csv = pd.read_csv("file.csv")
dataframe_txt = pd.read_csv("file.txt")
dataframe_xlsx = pd.read_excel("file.xlsx")