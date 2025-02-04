# Churn? Data program.

import pandas as pd
import matplotlib.pyplot as plt

file_path = "churn.txt"
df = pd.read_csv(file_path)

if 'Phone' in df.columns:
    df = df.drop(columns=['Phone'])

if 'Churn?' in df.columns:
    df['Churn?'] = df['Churn?'].str.strip('.').map({'True': 1, 'False': 0})

summary_stats = df.describe(include='all')
print("Summary Statistics")
print(summary_stats)

summary_stats.to_csv("summary_statistics,csv", index=True)
print("\nSummary Statistics save as 'summary_statistics.csv'.")

categorical_vars = df.select_dtypes(include=['object', 'bool']).columns
numerical_vars = df.select_dtypes(include=['number']).columns

for col in numerical_vars:
    plt.figure(figsize=(8, 5))
    plt.hist(df[col], bins=10, edgecolor='black', alpha=0.7)
    plt.title(f'Histogram of {col}')
    plt.xlabel(col)
    plt.ylabel('Frequency')
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.show()

for col in categorical_vars:
    plt.figure(figsize=(8, 5))
    df[col].value_counts().plot(kind='bar', color='c', edgecolor='black', alpha=0.7)
    plt.title(f'Bar Chart of {col}')
    plt.xlabel(col)
    plt.ylabel('Count')
    plt.xticks(rotation=45)
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.show()
