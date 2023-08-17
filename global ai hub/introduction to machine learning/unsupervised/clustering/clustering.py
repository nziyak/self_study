import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings("ignore", category=FutureWarning)

dataset = pd.read_csv("/home/ziya/python/global ai hub/introduction to machine learning/clustering/Live.csv")

print(dataset.head())

model = KMeans(n_clusters=3)

model.fit(dataset)

labels = model.predict(dataset)

np.unique(labels, return_counts=True)

silhouettes = []

ks = list(range(2, 12))

for n_cluster in ks:
    kmeans = KMeans(n_clusters=n_cluster).fit(dataset)
    label = kmeans.labels_
    sil_coeff = silhouette_score(dataset, label, metric='euclidean')
    print("For n_clusters={}, The Silhouette Coefficient is {}".format(n_cluster, sil_coeff))
    silhouettes.append(sil_coeff)

plt.figure(figsize=(12, 8))    
plt.subplot(211)
plt.scatter(ks, silhouettes, marker='x', c='r')
plt.plot(ks, silhouettes)
plt.xlabel('k')
plt.ylabel('Silhouette score');

model = KMeans(n_clusters=4)
model.fit(dataset)
labels = model.predict(dataset)

np.unique(labels, return_counts=True)

dataset["labels"] = labels
print(dataset)

group_zero = dataset[dataset["labels"]==0]["num_comments"].mean()
print("num comments group 0: ", group_zero)

group_one = dataset[dataset["labels"]==1]["num_comments"].mean()
print("num comments group 1: ", group_one)

group_two = dataset[dataset["labels"]==2]["num_comments"].mean()
print("num comments group 2: ", group_two)

group_three = dataset[dataset["labels"]==3]["num_comments"].mean()
print("num comments group 3: ", group_three)

#-----------------------------------------------------------------------

group_zero = dataset[dataset["labels"]==0]["num_shares"].mean()
print("num shares group 0: ", group_zero)

group_one = dataset[dataset["labels"]==1]["num_shares"].mean()
print("num shares group 1: ", group_one)

group_two = dataset[dataset["labels"]==2]["num_shares"].mean()
print("num shares group 2: ", group_two)

group_three = dataset[dataset["labels"]==3]["num_shares"].mean()
print("num shares group 3: ", group_three)

#-----------------------------------------------------------------------

status_type = dataset[["status_type_photo", "status_type_video", "status_type_status"]].idxmax(axis=1)
dataset = pd.concat([dataset["labels"],status_type.rename("status_type")], axis=1)

grouped_dataset = dataset.groupby(["labels","status_type"])["status_type"].count()

print()
print(grouped_dataset)