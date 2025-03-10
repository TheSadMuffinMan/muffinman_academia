# Handling outliers script.

library(dplyr)

# Loading cleaned data.
recid_data <- read.csv("cleaned_recid_data.csv")

# Function detects and replaces outliers.
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
numeric_columns <- c("Raw_Score", "Decile_Score")
recid_data[numeric_columns] <- lapply(recid_data[numeric_columns], handle_outliers)

# Saving the modified dataset.
write.csv(recid_data, "outlier_handled_recid.csv", row.names = FALSE)

# Printing summary after handling outliers.
summary(recid_data)
