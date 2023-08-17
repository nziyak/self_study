import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report

dataset = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/models/naive bayes/breast-cancer (1).csv")
print(dataset.head())
print()

labelencoder = LabelEncoder()
dataset["diagnosis"] = labelencoder.fit_transform(dataset["diagnosis"].values) 

X = dataset.drop("diagnosis", axis =1)
y = dataset["diagnosis"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

model = GaussianNB()
modelGNB = model.fit(X_train, y_train)
print("fitted in Gaussian NB: ", modelGNB)
print()

predictions = model.predict(X_test)
print("Predictions:\n", predictions)
print()

print("Confusion matrix:\n", confusion_matrix(y_test, predictions))
print()

print("Classification report:\n", classification_report(y_test,predictions))