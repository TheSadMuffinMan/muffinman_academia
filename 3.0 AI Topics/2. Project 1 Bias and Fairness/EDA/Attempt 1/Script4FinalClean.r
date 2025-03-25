# Predicting and final processing.

# Loading necessary libraries.
library(dplyr)
library(caret)

# Loading the dataset.
recid_data <- read.csv("normalized_recid.csv")

# Removing all character columns because they aren't needed.
recid_data <- recid_data %>%
  select(-c(Agency_Text, Last_Name, First_Name, Middle_Name, Display_Text))

# Displaying first few rows to confirm encoding.
head(recid_data)
summary(recid_data)

# Saving the final preprocessed dataset.
write.csv(recid_data, "final_preprocessed_recid.csv", row.names = FALSE)
