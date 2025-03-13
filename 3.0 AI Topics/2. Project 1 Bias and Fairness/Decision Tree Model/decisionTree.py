import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.preprocessing import MinMaxScaler, LabelEncoder
from sklearn.metrics import accuracy_score

# Loading the dataset.
data = pd.read_csv("final_preprocessed_recid.csv")

# Converting categorical columns using Label Encoding.
categorical_cols = ['Sex', 'Ethnicity', 'Legal_Status', 'Custody_Status', 'Marital_Status']

# Fixing catagorical data that is entered weirdly.
data['Ethnicity'] = data['Ethnicity'].replace(
    {
    'African-Am': 'African-American',
    'Oriental': 'Asian'
})

# Encoding categorical columns.
label_encoders = {}
for col in categorical_cols:
    le = LabelEncoder()
    data[col] = le.fit_transform(data[col])
    label_encoders[col] = le  # Store encoders for later use

# Converting 'Decile_Score' into binary target (1 = Recidivist, 0 = Non-Recidivist).
threshold = 0.5 # This value signifies what value determines one to be a recidivist.
data['Recidivist'] = (data['Decile_Score'] >= threshold).astype(int)

# Dropping original 'Decile_Score' since we now have a binary target.
data = data.drop(columns=['Decile_Score'])

# Defining features and target variable.
X = data.drop(columns=['Recidivist'])
y = data['Recidivist']  # Target value/variable that we are trying to predict.

# Splitting dataset into training and test sets.
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.1, random_state=42)

# Initializing and training Decision Tree Classifier.
model = DecisionTreeClassifier(max_depth=5, random_state=42)
model.fit(X_train, y_train)

# Making predictions and evaluating the model.
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"Model Accuracy: {accuracy:.2f}")

# Function makes predictions based on user input (below).
def predict_recidivism(user_input):
    user_df = pd.DataFrame([user_input])

    # Converting categorical features again.
    for col in categorical_cols:
        if user_df[col][0] in label_encoders[col].classes_:
            user_df[col] = label_encoders[col].transform(user_df[col])
        else:
            print(f"Warning: {user_df[col][0]} not found in training data for column {col}. Defaulting to most common value.")
            user_df[col] = label_encoders[col].transform([label_encoders[col].classes_[0]])[0]  # Default to most common

    # Predict recidivism!
    prediction = model.predict(user_df)[0]
    return "Recidivist" if prediction == 1 else "Non-Recidivist"

print(data['Recidivist'].value_counts())

# Example usage.
user_input = {
    'Sex': 'Male',
    'Ethnicity': 'Asian',
    'Legal_Status': 'Conditional Release',
    'Custody_Status': 'Probation',  # Fixed typo from 'Probabtion' to 'Probation'
    'Marital_Status': 'Single'
}

prediction_result = predict_recidivism(user_input)
print(f"Prediction: {prediction_result}")
