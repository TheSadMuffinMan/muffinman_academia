# Loading necessary library.
library(dplyr)

# Loading the dataset after handling outliers.
cars_data <- read.csv("outlier_handled_cars2.csv")

# Normalizing using min-max scaling.
normalize <- function(column) {
    return((column - min(column, na.rm = TRUE)) / (max(column, na.rm = TRUE) - min(column, na.rm = TRUE)))
}

# Normalizing numeric columns.
numeric_columns <- c("mpg", "cylinders", "cubic_inches", "hp", "weight_lbs", "time_to_60", "year")
cars_data[numeric_columns] <- lapply(cars_data[numeric_columns], normalize)

# Saving the normalized dataset.
write.csv(cars_data, "normalized_cars2.csv", row.names = FALSE)

# Printing summary to check normalization.
summary(cars_data)