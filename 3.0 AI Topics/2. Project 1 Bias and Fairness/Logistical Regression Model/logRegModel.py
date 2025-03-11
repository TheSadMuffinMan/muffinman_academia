import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from sklearn.model_selection import GridSearchCV

# Load dataset
data = pd.read_csv("final_preprocessed_recid.csv")

# Ensure 'Raw_Score' exists in the dataset
if 'Raw_Score' not in data.columns:
    raise ValueError("'Raw_Score' column not found in the dataset.")

# Use 'Raw_Score' as the target variable
# Convert it into a binary classification problem (e.g., threshold at median value)
threshold = data['Raw_Score'].median()  # You can adjust this threshold as needed
data['Recidivism'] = (data['Raw_Score'] > threshold).astype(int)

# Drop 'Raw_Score' now that we've used it to define 'Recidivism'
data = data.drop(columns=['Raw_Score'])

# Convert categorical features into one-hot encoded variables
categorical_cols = data.select_dtypes(include=['object']).columns  # Selecting text-based columns

# Apply Label Encoding to all categorical columns
le = LabelEncoder()
for col in categorical_cols:
    data[col] = le.fit_transform(data[col])

# Define features and target variable
X = data.drop(columns=['Recidivism'])  # Features
y = data['Recidivism']  # Target variable

# Split dataset into 80% training and 20% testing
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize Logistic Regression model
log_model = LogisticRegression(max_iter=1000)

# Train the model
log_model.fit(X_train, y_train)

# Predict class labels
y_pred = log_model.predict(X_test)

# Predict probabilities for each class
y_prob = log_model.predict_proba(X_test)[:, 1]  # Probability of class 1

# Accuracy Score
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy:.2f}")

# Confusion Matrix
conf_matrix = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:\n", conf_matrix)

# Classification Report
print("Classification Report:\n", classification_report(y_test, y_pred))

# Define parameter grid
param_grid = {'C': [0.01, 0.1, 1, 10, 100]}

# Grid Search with cross-validation
grid_search = GridSearchCV(LogisticRegression(max_iter=1000), param_grid, cv=5, scoring='accuracy')
grid_search.fit(X_train, y_train)

# Best parameter and best score
print("Best Parameters:", grid_search.best_params_)
print("Best Accuracy:", grid_search.best_score_)

data = pd.read_csv("final_preprocessed_recid.csv")

threshold = data['Raw_Score'].median()
data['Recidivism'] = (data['Raw_Score'] > threshold).astype(int)

# Plot distribution
plt.figure(figsize=(6, 4))
sns.countplot(x=data['Recidivism'], palette="coolwarm")
plt.title("Distribution of Recidivism")
plt.xlabel("Recidivism (0 = No, 1 = Yes)")
plt.ylabel("Count")
plt.show()
