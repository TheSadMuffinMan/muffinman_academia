# Normalizing numeric columns using min-max scaling.

library(dplyr)

# Loading the dataset after handling outliers.
recid_data <- read.csv("outlier_handled_recid.csv")

# Normalizing using min-max scaling.
normalize <- function(column) {
  return((column - min(column, na.rm = TRUE)) / (max(column, na.rm = TRUE) - min(column, na.rm = TRUE)))
}

# Normalizing numeric columns.
numeric_columns <- c("Raw_Score", "Decile_Score")
recid_data[numeric_columns] <- lapply(recid_data[numeric_columns], normalize)

# Removing unnecessary "Assessment_Type" Column.
recid_data <- recid_data %>% select(-Assessment_Type)

# Saving the normalized dataset.
write.csv(recid_data, "normalized_recid.csv", row.names = FALSE)

# Printing summary to check normalization.
summary(recid_data)
