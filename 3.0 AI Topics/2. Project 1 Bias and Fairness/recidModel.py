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
data = pd.read_csv("normalized_recid.csv")

# Displaying the first few rows of the dataset to verify their integrity.
print(data.head())

# Displaying basic info about the dataset.
print(data.info())

# Summary statistics.
print(data.describe())
