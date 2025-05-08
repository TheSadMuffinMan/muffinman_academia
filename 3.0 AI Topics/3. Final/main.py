import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report
from sklearn.metrics import roc_curve, roc_auc_score

# Loading German Credit Data Set.
data = pd.read_csv("german.data", delim_whitespace=True, header=None)

# Assigning column names for clarification.
data.columns = [
    'StatusCheckingAcc', 'Duration', 'CreditHistory', 'ExpensiveItems', 'CreditAmount', 'Savings', 'EmploymentSince',
    'InstallmentRate', 'PersonalStatusSex', 'Debtors', 'ResidenceSince', 'Property', 'Age',
    'OtherInstallmentPlans', 'Housing', 'ExistingCredits', 'Job', 'LiablePeople', 'Telephone',
    'ForeignWorker', 'CreditRisk'
]

# Converting target to binary: 1 = Good → 0, 2 = Bad → 1.
data['CreditRisk'] = data['CreditRisk'].map({1: 0, 2: 1})

# Split into input features and target.
X = data.drop('CreditRisk', axis=1)
y = data['CreditRisk']

# Identifying columns with categorical data (object dtype).
categorical_cols = X.select_dtypes(include='object').columns.tolist()

# Numeric columns don't require encoding.
numeric_cols = X.select_dtypes(exclude='object').columns.tolist()

# Define a preprocessing pipeline.
# - One-hot encode categorical columns.
# - Leave numeric columns untouched (passthrough).
preprocessor = ColumnTransformer(
    transformers=[
        ('cat', OneHotEncoder(handle_unknown='ignore'), categorical_cols)
    ],
    remainder='passthrough'
)

# Create a complete pipeline: preprocessing followed by logistic regression.
model = Pipeline(steps=[
    ('preprocessing', preprocessor),
    ('classifier', LogisticRegression(max_iter=1000, solver='liblinear'))  # 'liblinear' is reliable for small datasets
])

# Train-test split (80/20).
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=60)

# Train the model.
model.fit(X_train, y_train)

# Predict on the test set.
y_pred = model.predict(X_test)

# Display performance metrics.
print(classification_report(y_test, y_pred))

# Get feature names after one-hot encoding.
ohe = model.named_steps['preprocessing'].named_transformers_['cat']
feature_names_ohe = ohe.get_feature_names_out(categorical_cols)

# Combine with numeric columns that were passed through.
full_feature_names = np.concatenate([feature_names_ohe, numeric_cols])

# Get the logistic regression coefficients.
coefficients = model.named_steps['classifier'].coef_[0]

# Create a dataframe to view them clearly.
coef_df = pd.DataFrame({
    'Feature': full_feature_names,
    'Coefficient': coefficients
})

# Sort by impact (positive → increased chance of loan denial).
coef_df_sorted = coef_df.sort_values(by='Coefficient', ascending=False)

# Display.
print(coef_df_sorted.to_string(index=False))

# Select top 10 positive and top 10 negative coefficients.
top_positive = coef_df_sorted.head(10)
top_negative = coef_df_sorted.tail(10)
top_features = pd.concat([top_positive, top_negative])

# Plotting the bar chart.
plt.figure(figsize=(12, 6))
bars = plt.barh(top_features['Feature'], top_features['Coefficient'], color='skyblue')
plt.axvline(0, color='black', linewidth=0.8)  # Zero line for reference.
plt.title('Top Influential Features in Logistic Regression (Loan Denial Risk)')
plt.xlabel('Coefficient (More positive = more likely to deny loan)')
plt.ylabel('Feature')
plt.tight_layout()
plt.gca().invert_yaxis()  # Show highest values at top.
plt.show()

# Get predicted probabilities for the positive class (class 1).
y_proba = model.predict_proba(X_test)[:, 1]

# Calculating ROC curve.
fpr, tpr, thresholds = roc_curve(y_test, y_proba)
roc_auc = roc_auc_score(y_test, y_proba)

# Plotting ROC curve.
plt.figure(figsize=(8, 6))
plt.plot(fpr, tpr, color='darkorange', lw=2, label=f'ROC curve (area = {roc_auc:.2f})')
plt.plot([0, 1], [0, 1], color='navy', lw=2, linestyle='--')  # Diagonal line
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('Receiver Operating Characteristic (ROC) Curve')
plt.legend(loc='lower right')
plt.grid()
plt.tight_layout()
plt.show()