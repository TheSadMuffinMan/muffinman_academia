# To activate the needed dev environment, input below into terminal.
# conda activate AIClass

# PREDICTIVE AI
import pandas as pd # Used for data manipulation and analysis.
import numpy as np # Used for numerical operations.
import matplotlib.pyplot as plt # Used for data visualization.
import seaborn as sns # Used for enhanced visualization.
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Read the housing data into memory.
data = pd.read_csv("USA_Housing.csv")

# Displaying the first few rows of the dataset to verify their integrity.
print(data.head())

# Displaying basic info about the dataset.
print(data.info())

# Summary statistics.
print(data.describe())

# Visualizing correlations between features.
# numeric_data = data.select_dtypes(include=[np.number]) # Selecting only numeric columns.
# *****THREE LINES BELOW ARE BREAKING, HENCE THE COMMENT OUT*****
# sns.heatmap(data.corr(), annot=True, cmap = "coolwarm")
# plt.title("Feature Correlation Matrix")
# plt.show()

# Check for missing values.
print("Missing values in each column: ")
print(data.isnull().sum())

# Normalize numeric columns.
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler()
numeric_columns = ['Avg. Area Income', 'Avg. Area House Age', 'Avg. Area Number of Rooms',
    'Avg. Area Number of Bedrooms', 'Area Population']

data[numeric_columns] = scaler.fit_transform(data[numeric_columns])

print("Normalized Data Sample: ")
print(data.head())

# Define features (X) and target variable (Y).
X = data[['Avg. Area Income', 'Avg. Area House Age', 'Avg. Area Number of Rooms',
    'Avg. Area Number of Bedrooms', 'Area Population']]
y = data['Price']

# Split the data into training and testing sets.
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.1, random_state = 42)

print(f"Testing set size: {len(X_train)}")
print(f"Testing set size: {len(X_test)}")

# Initialize and train the linear regression model.
model = LinearRegression()
model.fit(X_train, y_train)

# Display coefficients.
print("Model Coefficients: ", model.coef_)
print("Model Intercept: ", model.intercept_)

# Make predictions on the test set.
y_pred = model.predict(X_test)

# Calculate evaluation metrics.
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print(f"Mean Squared Error: {mse}")
print(f"R^2 Score: {r2}")

# Example prediction.
example_data = pd.DataFrame({
    'Avg. Area Income': [65000],
    'Avg. Area House Age': [5],
    'Avg. Area Number of Rooms': [7],
    'Avg. Area Number of Bedrooms': [4],
    'Area Population': [30000]
    })

# Normalize the example data.
example_data[numeric_columns] = scaler.transform(example_data[numeric_columns])

# Predict price.
predicted_price = model.predict(example_data)
print(f"Predicted Price: ${predicted_price[0]:,.2f}")

# Plot actual vs. predicted price.
plt.figure(figsize=(8,6))
plt.scatter(y_test, y_pred, alpha = 0.7)
plt.title("Actual vs. Predicted Prices")
plt.xlabel("Actual Prices")
plt.ylabel("Predicted Prices")
plt.grid(True)
plt.show()