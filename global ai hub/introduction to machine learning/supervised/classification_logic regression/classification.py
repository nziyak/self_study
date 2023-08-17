import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
from sklearn.svm import LinearSVC # support vector classification (support vector machine)

dataset = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/classification_logic regression/breast-cancer.csv")

print(dataset.shape)
print()

print("Head:\n ", dataset.head())
print()

print("Tail:\n ", dataset.tail())
print()

labelencoder = LabelEncoder()
dataset["diagnosis"] = labelencoder.fit_transform(dataset["diagnosis"].values) 

print("After encoding head:\n ", dataset.head())
print()

print("After encoding tail:\n ", dataset.tail())
print()

train, test = train_test_split(dataset, test_size=0.3) # we are splitting the dataset into train and test categories

# the aim feature is diagnosis so we are deleting it from the features list and assigning it as label
X_train = train.drop("diagnosis",axis=1)
y_train = train.loc[:,"diagnosis"]

X_test = test.drop("diagnosis",axis=1)
y_test = test.loc[:,"diagnosis"]
# you can do the same thing by first delete and assign diagnosis, then split it into two datasets

model_1 = LogisticRegression()

model_1.fit(X_train,y_train)

predictions = model_1.predict(X_test)
print("predictions (logistic regression):\n ", predictions)
print()

print("The confusion matrix (logistic regression):\n ", confusion_matrix(y_test, predictions))
print()

print("Classification report (logistic regression):\n ", classification_report(y_test, predictions))
print()

model_2 = LinearSVC()

model_2.fit(X_train,y_train)

predictions = model_2.predict(X_test)
print("predictions (linear SVC):\n ", predictions)
print()

print("The confusion matrix (linear SVC):\n ", confusion_matrix(y_test, predictions))
print()

print("Classification report (linear SVC):\n ", classification_report(y_test, predictions))