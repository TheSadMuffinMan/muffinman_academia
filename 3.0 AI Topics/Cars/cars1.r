# Load necessary libraries
library(dplyr)
library(tidyr)

# Load the dataset from the text file
cars_data <- read.csv("cars2.txt", header = TRUE, sep = ",", stringsAsFactors = FALSE)

# Display the first few rows to check loading
head(cars_data)

# Rename columns for clarity
colnames(cars_data) <- c("mpg", "cylinders", "cubic_inches", "hp", "weight_lbs", "time_to_60", "year", "brand")

# Convert relevant columns to appropriate data types
cars_data$cylinders <- as.integer(cars_data$cylinders) # Convert to integer cars_data$cubic_inches <-as. integer (cars_data$cubic_inches)
cars_data$hp <- as.integer(cars_data$hp)
cars_data$weight_lbs <- as.integer(cars_data$weight_lbs) cars_data$time_to_60 <-
    as.numeric(cars_data$time_to_60) cars_data$year <- as. integer (cars_data$year) cars_data$brand <-
    as.factor(cars_data$brand)meric

# Convert to categorical factor
# Handle missing values by replacing them with column medians cars_data <- cars_data %>%
mutate(across (where (is.numeric),~ ifelse(is.na(.), median(., na.rm = TRUE),
.)))

# Save the cleaned dataset
write.csv(cars_data, "cleaned_cars2.csv", row.names = FALSE)
# Print summary to confirm cleaning summary(cars_data)