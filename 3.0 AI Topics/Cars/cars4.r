# Loading necessary libraries.
library(dplyr)
library(caret)

# Loading the dataset.
cars_data <- read.csv("normalized_cars_2.csv")

# Converting brand to dummy variables (one-hot encoding).
cars_data <- dummyVarys(~ brand, data = cars_data)
cars_data <- as.data.fram(predict(cars_data, newdata = read.csv("normalized_cars2.csv")))

# Saving the final preprocessed dataset.
write.csv(cars_data, "final_preprocessed_cars2.csv", row.names = FALSE)

# Displaying first few rows to confirm encoding.
head(cars_data)