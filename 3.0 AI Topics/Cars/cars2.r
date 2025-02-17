# Loading necessary library.
library(dplyr)

# Loading cleaned data.
cars_data <- read.csv("cleaned_cars2.csv")

# Function dectects and replaces outliers.
handle_outliers <- function(column) {
    Q1 <- quantile(column, 0.25, na.rm = TRUE)
    Q3 <- quantile(column, 0.75, na.rm = TRUE)
    IQR <- Q3 - Q1
    lower_bound <- Q1 - 1.5 * IQR
    upper_bound <- Q3 + 1.5 * IQR
    column <- ifelse(column < lower_bound | column > upper_bound, median(column, na.rm = TRUE), column)
    return(column)
}

# Applying outlier handling to numeric columns.
numeric_columns <- c("mpg", "cylinders", "cubic_inches", "hp", "weight_lbs", "time_to_60", "year")
cars_data[numeric_columns] <- lapply(cars_data[numeric_columns], handle_outliers)

# Saving the modified dataset.
write.csv(cars_data, "outlier_handled_cars2.csv", row.names = FALSE)

# Printing summary after handling outliers.
summary(cars_data)