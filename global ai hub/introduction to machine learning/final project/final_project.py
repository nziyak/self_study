# Import Pandas and Matplotlib
import pandas as pd
import matplotlib.pyplot as plt

# Import Label Encoder and train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split

# Import Logistic Regression, Ridge Classifier, Decision Tree
# Gaussian Naive Bayes, MLP Classifier and Random Forest models
from sklearn.linear_model import LogisticRegression, RidgeClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import RandomForestClassifier

# Import Classification Report function
from sklearn.metrics import classification_report

# Read the "mushroom.csv" file
data = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/final project/mushrooms.csv")

print(data.head())
print()

# Use value_counts method on "class" column of data object
classes = data["class"].value_counts()

# Print the result
print(classes)
print()

# Add the bar for edible class
plt.bar("Edible", classes['e'])

# Add the bar for poisonous class
plt.bar("Poisonous", classes['p'])

# Print the plot
plt.show()

# Create the X variable for features
X = data.loc[:, ["cap-shape", "cap-color", "ring-number", "ring-type"]]
# Create the y variable for output labels
y = data.loc[:, "class"]

# Create an LabelEncoder object
encoder = LabelEncoder()

# Encode the features to integers inside a for loop
for i in X.columns:
    X[i] = encoder.fit_transform(X[i])

# Encode the ouput labels to integers
y = encoder.fit_transform(y)

print(X)
print()
print(y)
print()


# Split the dataset into train and test sets with 70-30 ratio
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)


# Create an object using the LogisticRegression() class
logistic_classifier_model = LogisticRegression()

# Create an object using the RidgeClassifier() class
ridge_classifier_model = RidgeClassifier()

# Create an object using the DecisionTreeClassifier() class
decision_tree_model = DecisionTreeClassifier()

# Create an object using the GaussianNB() class
naive_bayes_model = GaussianNB()

# Create an object using the MLPClassifier() class
neural_network_model = MLPClassifier()


# Train the Logistic Classifier model
logistic_classifier_model.fit(X_train, y_train)

# Train the Ridge Classifier model
ridge_classifier_model.fit(X_train, y_train)

# Train the Decision Tree model
decision_tree_model.fit(X_train, y_train)

# Train the Naive Bayes model
naive_bayes_model.fit(X_train, y_train)

# Train the Neural Network model
neural_network_model.fit(X_train, y_train)


# Make prediction using the test dataset on Logistic Classifier model
logistic_pred = logistic_classifier_model.predict(X_test)

# Make prediction using the test dataset on Ridge Classifier model
ridge_pred = ridge_classifier_model.predict(X_test)

# Make prediction using the test dataset on Decision Tree model
tree_pred = decision_tree_model.predict(X_test)

# Make prediction using the test dataset on Naive Bayes model
naive_bayes_pred = naive_bayes_model.predict(X_test)

# Make prediction using the test dataset on Neural Network model
neural_network_pred = neural_network_model.predict(X_test)


# Create a Classification Report for Logistic Classifier model
logistic_report = classification_report(y_test, logistic_pred)

# Create a Classification Report for Ridge Classifier model
ridge_report = classification_report(y_test, ridge_pred)

# Create a Classification Report for Decision Tree model
tree_report = classification_report(y_test, tree_pred)

# Create a Classification Report for Naive Bayes model
naive_bayes_report = classification_report(y_test, naive_bayes_pred)

# Create a Classification Report for Neural Network model
neural_network_report = classification_report(y_test, neural_network_pred)


# Print the report of the Logistic Regression model
print("********** Logistic Regression **********")
print(logistic_report)
# Print the report of the Ridge Regression model
print("********** Ridge Regression **********")
print(ridge_report)
# Print the report of the Decision Tree model
print("********** Decision Tree **********")
print(tree_report)
# Print the report of the Naive Bayes model
print("********** Naive Bayes **********")
print(naive_bayes_report)
# Print the report of the Neural Network model
print("********** Neural Network **********")
print(neural_network_report)


# Create Random Forest Classifier object, train it and make predicitons
random_forest_model = RandomForestClassifier()
random_forest_model.fit(X_train, y_train)
random_forest_pred = random_forest_model.predict(X_test)


# Create a classification Report for Random Forest model
random_forest_report = classification_report(y_test, random_forest_pred)

# Print the classification report
print("********** Random Forest **********")
print(random_forest_report)