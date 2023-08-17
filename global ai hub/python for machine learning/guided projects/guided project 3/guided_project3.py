#Open the file in read mode
file = open("/home/ziya/python/global ai hub/python for machine learning/guided projects/guided project 3/employee_revenue.txt", "r")
data = file.read()

#Seperate the data into lines
lines = data.splitlines()
print(lines)
print()

#Create empty lists
names = []
call_numbers = []
avg_deal_sizes = []
revenues = []

#Define a function to clean and extract the data
def clean_extract(lines):
    
    for employee in lines:
        #Clean the string
        employee = employee.strip(" ")
        employee = employee.lower()
        employee = employee.capitalize()

        #Split the clean string
        split_employee = employee.split(" ")
        
        #Extract the name
        name = split_employee[0]
        call_number = split_employee[2]

        #Extract the average deal size
        for i in split_employee:
            if "$" in i:
                avg_deal_size = i

        avg_deal_size = avg_deal_size.split("$")[0]       

        #Extract the revenue
        dollars_index = split_employee.index("dollars")
        revenue_index = dollars_index - 1
        revenue = split_employee[revenue_index]

        #Convert to the correct data types
        avg_deal_size = int(avg_deal_size)
        call_number = int(call_number)
        revenue = int(revenue)

        #Append the information to the lists
        names.append(name)
        call_numbers.append(call_number)
        avg_deal_sizes.append(avg_deal_size)
        revenues.append(revenue)

    return names, call_numbers, avg_deal_sizes, revenues

#Assign returned values to variables
names, call_numbers, avg_deal_sizes, revenues = clean_extract(lines)

#Print out the information
print("Name: ", names)
print("Number of calls: ", call_numbers)
print("Average deal sizes: ", avg_deal_sizes)
print("Revenues: ", revenues)
print()

#Check the number of employees
print(len(names))
print()

#Generate IDs
IDs = list(range(0,11))
print(IDs)
print()

#Check the number of IDs
print(len(IDs))
print()

#Pair the names with the IDs in a dictionary
dictionary1 = dict(zip(IDs, names))
print(dictionary1)
print()

#Pair the names with the revenues
dictionary2 = dict(zip(revenues, names))
print(dictionary2)
print()

#Find the lowest performing employees (ascending order)
sorted_dictionary = sorted(dictionary2)[0:3]

for i in sorted_dictionary:
    print(dictionary2[i])

#Find the best performing employees (descending order)
sorted_dictionary = sorted(dictionary2, reverse = True)[0:3]

print("Top 3 best performing employees:")
for i in sorted_dictionary:
    print(dictionary2[i])