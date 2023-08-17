#Define the "Logistics" class
class Logistic:
    #Initialize the object's attributes 
    def __init__(self, company_name, foundation_year, founder_name, company_slogan, inventory_space):
        self.company_name = company_name
        self.foundation_year = foundation_year
        self.founder_name = founder_name
        self.company_slogan = company_slogan
        self.inventory_space = inventory_space

    #Define the print_report method
    def print_report(self):
        print(f"""
        The company {self.company_name} is founded in {self.foundation_year}.
        This companies founder is {self.founder_name}
        Company_slogan = {self.company_slogan}
        Inventory space of the company = {self.inventory_space}""")

    #Define the update_inventory_space method
    def update_inventory_space(self, new_storage_space):
        self.inventory_space = new_storage_space
        print(f"Inventory space has been changed to {self.inventory_space}.")

#Create the object "logistic_company1" with it's attributes
logistic_company1 = Logistic("LogCom", 1990, "Laura McCartey", "There is noplace we cannot reach", 2500)        

#Update the inventory space
logistic_company1.update_inventory_space(3000)
#Call the print_report method for logistic_company1
logistic_company1.print_report()