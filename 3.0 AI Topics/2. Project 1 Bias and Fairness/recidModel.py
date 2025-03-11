# To activate the needed dev environment, input below into terminal.
# conda activate AIClass

# PREDICTIVE AI
import pandas as pd # Used for data manipulation and analysis.
import numpy as np # Used for numerical operations.
import matplotlib.pyplot as plt # Used for data visualization.
import seaborn as sns # Used for enhanced visualization.
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report

# Read the housing data into memory.
data = pd.read_csv("final_preprocessed_recid.csv")

# Displaying the first few rows of the dataset to verify their integrity.
print(data.describe())

# Load the dataset
data = pd.read_csv("final_preprocessed_recid.csv")

# Store the target variable using its original name
target_column = "Recidivism_Supervision_Level"
y = data[target_column]  # Ensure we're using the correct target

# Identify categorical columns (EXCLUDING the target variable)
categorical_columns = ['Sex', 'Ethnicity', 'Legal_Status', 'Custody_Status', 'Marital_Status']

# Apply One-Hot Encoding (excluding the target variable)
data_encoded = pd.get_dummies(data.drop(columns=[target_column]), columns=categorical_columns, drop_first=True)

# Save the processed dataset
data_encoded.to_csv("encoded_recid.csv", index=False)

# Load the preprocessed dataset
data = pd.read_csv("encoded_recid.csv")

# Define features (X) and maintain the target (y)
X = data

# Split data into training/testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train the model
rf_model = RandomForestClassifier(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)

# Make predictions
y_pred = rf_model.predict(X_test)

# Evaluate the model
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy:.4f}")
print(classification_report(y_test, y_pred))

# Getting feature importance.
feature_importances = rf_model.feature_importances_

# Sorting features by importance.
sorted_idx = np.argsort(feature_importances)[::-1]
top_features = X.columns[sorted_idx]

# Plotting feature importance.
plt.figure(figsize=(10,6))
plt.barh(top_features[:10], feature_importances[sorted_idx][:10])
plt.xlabel("Feature Importance Score")
plt.title("Top 10 Important Features in Random Forest Model")
plt.gca().invert_yaxis()
plt.show()




# # Separating 'Rec' before encoding.
# y = data['Rec']  # Store the target variable

# # Identifying categorical columns.
# categorical_columns = ['Sex', 'Ethnicity', 'Legal_Status', 'Custody_Status', 'Marital_Status', 'Recidivism_Supervision_Level']

# # Applying one-hot encoding.
# data_encoded = pd.get_dummies(data.drop(columns=['Rec']), columns=categorical_columns, drop_first=True)

# # Saving the processed dataset.
# data_encoded.to_csv("encoded_recid.csv", index=False)

# # Pausing the program.
# dumpVar = input("\nWaiting for input...")
# # Load the preprocessed dataset
# data = pd.read_csv("encoded_recid.csv")

# # Defining features (X).
# X = data

# # Splitting into training (80%) and testing (20%) sets.
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 42)

# print(f"Training set size: {len(X_train)}")
# print(f"Testing set size: {len(X_test)}")

# # Pausing the program.
# dumpVar = input("\nInput anything to begin training.")
# print("\nTraining...")
# # Initializing and training the model.
# rf_model = RandomForestClassifier(n_estimators = 100, random_state = 42)
# rf_model.fit(X_train, y_train)

# # Making predictions.
# y_pred = rf_model.predict(X_test)

# # Printing accuracy score.
# accuracy = accuracy_score(y_test, y_pred)
# print(f"Model Accuracy: {accuracy:.4f}")

# # Printing a detailed classification report.
# print(classification_report(y_test, y_pred))