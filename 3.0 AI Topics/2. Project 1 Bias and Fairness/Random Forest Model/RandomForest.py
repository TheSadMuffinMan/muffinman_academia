import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

# Load the dataset
data = pd.read_csv("FINAL_Preprocessed.csv")

# Storing the target variable using its original name.
target_column = "Decile_Score"
y = data[target_column]

# Identifying categorical columns.
categorical_columns = ['Sex', 'Ethnicity', 'Legal_Status', 'Custody_Status', 'Marital_Status']

# Applying One-Hot Encoding (excluding the target variable).
data_encoded = pd.get_dummies(data.drop(columns=[target_column]), columns=categorical_columns, drop_first=True)

# Splitting data into training/testing sets.
X_train, X_test, y_train, y_test = train_test_split(data_encoded, y, test_size=0.2, random_state=50)

# Training the model.
rf_model = RandomForestClassifier(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)

# Making predictions.
y_pred = rf_model.predict(X_test)

# Evaluating the model.
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy:.4f}")
print(classification_report(y_test, y_pred))

# Feature importance
feature_importances = rf_model.feature_importances_

# Sorting features by importance.
sorted_idx = np.argsort(feature_importances)[::-1]
top_features = data_encoded.columns[sorted_idx]

# Plotting feature importance.
plt.figure(figsize=(10,6))
plt.barh(top_features[:10], feature_importances[sorted_idx][:10])
plt.xlabel("Feature Importance Score")
plt.title("Top 10 Important Features in Random Forest Model")
plt.gca().invert_yaxis()
plt.show()
