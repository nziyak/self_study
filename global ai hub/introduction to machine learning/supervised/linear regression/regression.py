import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from numpy import sqrt

train = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/linear regression/train.csv") # reading the file
test = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/linear regression/train.csv")

model = LinearRegression()
                                 #axis = 1 indicates the column will be deleted
X_train = train.drop('SalePrice', axis=1) # we want to predict Sale Price. with this line, we are taking this feature of house out of the list
y_train = train.loc[:,'SalePrice'] # then we are assigning it as label. label is the feature that we want to predict. other features remain as features or attributes

model.fit(X_train,y_train) #fit our model, which means teaching the hidden patterns in the training dataset into it. After the fitting process, our model is almost ready to make predictions. 

#But before that, we also need to divide our test dataset into “target” and “features”.
X_test = test.drop('SalePrice', axis=1)
y_test = test.loc[:,'SalePrice']

predictions = model.predict(X_test)

rmse = sqrt(mean_squared_error(y_test, predictions))
print("Root Mean Squared Error:", rmse)
print()

comparison = pd.DataFrame({"Actual Values": y_test,"Predictions": predictions})
print(comparison.head())
print()
print(comparison.tail())
print()

train.corr()["SalePrice"].sort_values(ascending=False).head(10)

correlations = train.corr()
print("Correlations: ", correlations)
print()

saleprice_correlations = correlations["SalePrice"]
print("Saleprice correlations: ", saleprice_correlations)
print()

sorted_saleprice_correlations = saleprice_correlations.sort_values(ascending=False).head(10) # to see the top 10
print("Sorted saleprice correlations: ", sorted_saleprice_correlations)