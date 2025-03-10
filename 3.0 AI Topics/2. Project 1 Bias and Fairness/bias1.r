# Loading necessary libraries.
library(dplyr)
library(tidyr)

# Loading the dataset from the text file.
recid_data <- read.csv("compas-scores-raw.txt", header = TRUE, sep = ",", stringsAsFactors = FALSE)

# Displaying the first few rows to check loading.
head(cars_data)

# Renaming columns for clarity.
colnames(cars_data) <- c("mpg", "cylinders", "cubic_inches", "hp", "weight_lbs", "time_to_60", "year", "brand")

# Converting relevant columns to appropriate data types.
cars_data$cylinders <- as.integer(cars_data$cylinders) # Converting to an integer.
cars_data$cubic_inches <- as.integer(cars_data$cubic_inches)
cars_data$hp <- as.integer(cars_data$hp)
cars_data$weight_lbs <- as.integer(cars_data$weight_lbs)
cars_data$time_to_60 <- as.numeric(cars_data$time_to_60)
cars_data$year <- as.integer(cars_data$year)
cars_data$brand <- as.factor(cars_data$brand) # Converting to categorical factor.

# Handling missing values by replacing them with column medians.
cars_data <- cars_data %>%
  mutate(across(where(is.numeric), ~ ifelse(is.na(.), median(., na.rm = TRUE),.)))

# Saving the cleaned dataset.
write.csv(cars_data, "cleaned_cars2.csv", row.names = FALSE)

# Printing summary to confirm cleaning.
summary(cars_data)

