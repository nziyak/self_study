# #Please assign your personal information to variables
# my_name = "Nuri Ziya"
# my_surname = "Kırtepe"
# my_age = 20
# ID_num = 12382138123082
# where_i_live = "Tokat"
# health_insurance = True

# #Write a sentence using the print function to describe yourself using the variables above in the correct data type
# print(f"My name is {my_name} {my_surname}. I am {str(my_age)} years old.")

# ######################### SHOPPING PROGRAM #########################

#Create the item_list
item_list = ["laptop", "headset", "second monitor", "mousepad", "usb drive", "external drive"]

#Print the list
print(item_list)

#Use list slicing to divide the mandatory items
mandatory_item_list = item_list[0:2]

#Use list slicing to divide the optional items
optional_item_list = item_list[2:]

#Print both to the screen
print(mandatory_item_list)
print(optional_item_list)

#Assign the spending limit value to a variable called limit
limit = 5000

#Create a dictionary that contains each item and its price
price_sheet = {
    "laptop": 1500,
    "headset": 100,
    "second monitor": 200,
    "mousepad": 50,
    "usb drive": 70,
    "external drive": 250
}

#Initialize the cart list
cart = []

#Define the "add_to_cart" function
def add_to_cart(item, quantity):
    cart.append((item, quantity))
    item_list.remove(item)
    
#Define the "create_invoice" function
def create_invoice():
    
    total_amount_inc_tax = 0
    
    for item, quantity in cart:
        
        price = price_sheet[item]
        tax = 0.25 * price
        total = (tax + price) * quantity
        total_amount_inc_tax += total
        print("Item:", item, "\t", "Price:", price, "\t", "Quantity:", "\t", "Tax:", tax, "\t", "Total:", total, "\n")
    
    print("After the taxes are applied the total amount is:", "\t", total_amount_inc_tax)
    return total_amount_inc_tax

#Define the "checkout" function
def checkout():
    global limit
    total_amount = create_invoice()
    
    if limit == 0:
        print("You dont have any budget")
    
    elif total_amount > limit:
        print("The amount you have to pay is above the spending limit. You have to drop some items.")    
    
    else:
        limit -= total_amount
        print(f"The total amount you've paid is {total_amount}. You have {limit} dollars left.")    
        
#Call the "add_to_cart" function for each item
 
#Add first item to cart
add_to_cart("laptop", 1)
 
#Add second item to cart
add_to_cart("headset", 3)
 
#Add third item to cart
add_to_cart("second monitor", 2)
 
#Add fourth item to cart
#add_to_cart("turtle", 4)

add_to_cart("mousepad", 2)
add_to_cart("usb drive", 1)
add_to_cart("external drive", 1)

#Call the create "checkout" function to pay for all your items
checkout()         

# ######################### ROCK SCISSORS AND PAPER #########################

# import random

# actions = ["rock", "scissors", "paper"]

# computer_score = 0
# human_score = 0

# total_rounds = input("How many rounds do you want to play? Please enter a number here: ")

# round_counter = 0

# while True:
    
#     round_counter += 1
    
#     print("Round number:", round_counter)
    
#     computer_choice = random.choice(actions)
    
#     player_choice = input("Please choose your action: ")
    
#     print("Computer: ", computer_choice)
#     print("Human: ", player_choice)
    
#     if computer_choice == player_choice:
#         print("Tie!")
    
#     elif computer_choice == "paper":
        
#         if player_choice == "rock":
#             print("computer wins!")
#             computer_score += 1
            
#         else: 
#             print("human wins!")
#             human_score += 1
            
#     elif computer_choice == "rock":
        
#         if player_choice == "scissors":
#             print("computer wins!")
#             computer_score += 1
            
#         else: 
#             print("human wins!") 
#             human_score += 1
            
#     elif computer_choice == "scissors":
        
#         if player_choice == "paper":
#             print("computer wins!")
#             computer_score += 1
            
#         else: 
#             print("human wins!")                        
#             human_score += 1
            
#     if round_counter == int(total_rounds):
#         break 
    
# if computer_score == human_score:
#     print("Tie!")           
    
# elif computer_score > human_score:
#     print("Computer won!")
    
# elif human_score > computer_score:
#     print("Human won!") 
    
######################### SALESPERSON REVENUE TRACKER #########################           

# salesperson_revenue = {
#     "Ben":0,
#     "Omer":0,
#     "Karen":0,
#     "Ziya":0,
#     "Mert":0,
#     "Atilla":0,
#     "Betül":0,
#     "Kemal":0
# }

# def enter_revenue(name, revenue):
#     global salesperson_revenue
#     salesperson_revenue[name] += revenue
    
# while True:
#     name = input("Employee name: ")
    
#     if name == "quit":
#         break
    
#     revenue = int(input("Enter a revenue: ")) 
    
#     enter_revenue(name, revenue)
    
#     print(f"{name}'s revenue is {salesperson_revenue[name]}") 
    
# print(salesperson_revenue)  