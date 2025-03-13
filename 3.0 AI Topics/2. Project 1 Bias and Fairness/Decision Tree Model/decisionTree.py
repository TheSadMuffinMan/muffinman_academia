import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.preprocessing import MinMaxScaler, LabelEncoder
from sklearn.metrics import accuracy_score

# Load the dataset
data = pd.read_csv("final_preprocessed_recid.csv")

# Convert categorical columns using Label Encoding
categorical_cols = ['Sex', 'Ethnicity', 'Legal_Status', 'Custody_Status', 'Marital_Status']

# Fixing "weird" data.
data['Ethnicity'] = data['Ethnicity'].replace(
    {
    'African-Am': 'African-American',
    'Oriental': 'Asian'
})

label_encoders = {}
for col in categorical_cols:
    le = LabelEncoder()
    data[col] = le.fit_transform(data[col])
    label_encoders[col] = le  # Store encoders for later use

# Convert 'Decile_Score' into binary target (1 = Recidivist, 0 = Non-Recidivist)
threshold = 0.5 # This value signifies what value determines one to be a recidivist.
data['Recidivist'] = (data['Decile_Score'] >= threshold).astype(int)

# Drop original 'Decile_Score' since we now have a binary target
data = data.drop(columns=['Decile_Score'])

# Defining features and target variable.
X = data.drop(columns=['Recidivist'])
y = data['Recidivist']  # Target value/variable that we are trying to predict.

# Splitting dataset into train and test sets.
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.1, random_state=42)

# Initialize and train Decision Tree Classifier
model = DecisionTreeClassifier(max_depth=5, random_state=42)
model.fit(X_train, y_train)

# Make predictions and evaluate the model
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy:.2f}")

# Function to make predictions on user input
def predict_recidivism(user_input):
    """Takes a dictionary of user input and predicts recidivism."""
    user_df = pd.DataFrame([user_input])

    # Convert categorical features
    for col in categorical_cols:
        if user_df[col][0] in label_encoders[col].classes_:
            user_df[col] = label_encoders[col].transform(user_df[col])
        else:
            user_df[col] = label_encoders[col].transform([label_encoders[col].classes_[0]])[0]  # Default to most common

    # Predict recidivism
    prediction = model.predict(user_df)[0]
    return "Recidivist" if prediction == 1 else "Non-Recidivist"

# print(data['Decile_Score'].describe())
print(data['Recidivist'].value_counts())

dumbVar = input("Input anything to continue.")

# Example usage
user_input = {
    'Sex': 'Male',
    'Ethnicity': 'African-American',
    'Legal_Status': 'Pretrial',
    'Custody_Status': 'Jail Inmate',
    'Marital_Status': 'Single'
}

prediction_result = predict_recidivism(user_input)
print(f"Prediction: {prediction_result}")
