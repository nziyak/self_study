#this project is about comparing the companies situation between the last year and this year
import pandas as pd
import numpy as np

#reading the data file
last_year = pd.read_csv("/home/ziya/python/global ai hub/python for machine learning/guided projects/guided project 5/employee_revenue_lastyear.csv")


"""print()
print(last_year.head()) # head() will give the 5 rows by default
print()

print()
print(last_year.tail()) # tail() will give the 5 rows by default
print()

#quick way to learn number of rows and columns is shape method:
print(last_year.shape)
print()

#use the .info() function to get more details:
print(last_year.info())
"""
#lets add a column "Year" which holds 2021
last_year["Year"] = 2021
"""
print()
print(last_year)"""

#add this years data:
names = np.array(['Ben', 'Omer', 'Karen', 'Celine', 'Sue', 'Bora', 'Rose', 'Ellen', 'Bob', 'Taylor,', 'Jude'])
call_numbers =  np.array([300, 10, 500, 70, 100, 100, 600, 800, 200, 450, 80])
average_deal_size =  np.array([8, 6, 24, 32, 5, 25, 25, 40, 15, 10, 12])
revenues =  np.array([2400, 60, 12000, 2275, 500, 770, 4000, 6000, 800, 1200, 500])

dictionary = {"name": names,
              "calls": call_numbers,
              "avg_deal_size": average_deal_size,
              "revenue": revenues}

#convert the dictionary to a Pandas DataFrame
current_year = pd.DataFrame(dictionary)

"""#use .head() function to check it:
print()
print(current_year.head())"""

current_year["Year"] = 2022 #adding 2022
"""
print()
print(current_year.head())
print(last_year.head())"""

#when we print that two years data, we see their column numbers are not same.
#so we assign one of them to another

current_year.columns = last_year.columns

print(current_year.head())
print(last_year.head())

#now concatenate two datas:
all_data = pd.concat([last_year, current_year], axis=0)

print()
print(all_data)
#indexes are incorrect. so we delete and recreate the indexes:

all_data.reset_index(drop = True, inplace=True) #drop deletes the existing indexes

print()
print(all_data)

all_data.isna().any() #we check that if there is any missing values

text_columns = ["Name"] #to prevent the error which occurs when you try to fill the missing string values with numerical values
all_data[text_columns] = all_data[text_columns].fillna(value="Missing", inplace = False) #fills the missing values with the mean value of the datas.

numeric_columns = ["Number of Calls",  "Average Deal Size",  "Revenue",  "Year"]
mean_values = all_data[numeric_columns].mean()  # Calculate the mean value of numeric columns
all_data[numeric_columns] = all_data[numeric_columns].fillna(value=mean_values, inplace=False)

print("\n****************missing values are filled****************")
print(all_data)

all_data.drop_duplicates(inplace=True)

print("\n*****************duplicating lines are dropped****************")
print(all_data)

#because of lines are deleted, we need to reset the indexes again:

all_data.reset_index(drop=True)
print("\n****************indexes are resetted****************")
print(all_data)

print("\n****************overall performance analysis****************")
print(all_data.describe()) #analyzing the overall performance of the employees using describe method.

#also we can analyze just one years performance:
print("\n****************2021 performance analysis****************")
print(all_data[all_data["Year"] == 2021].describe())

print("\n****************2022 performance analysis****************")
print(all_data[all_data["Year"] == 2022].describe())

#we can sort the values by one column:
print("\n****************sorted by revenues****************")
print(all_data.sort_values(by="Revenue"))

#we can sort the values of one year by revenues
print("\n****************2022 values sorted by revenues****************")
print(all_data[all_data["Year"] == 2022].sort_values(by="Revenue"))

#we can count and list how many year the employees in the company by counting their names
print("\n****************work years of employees****************")
print(all_data["Name"].value_counts())