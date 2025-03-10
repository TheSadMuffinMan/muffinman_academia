# Loading necessary libraries.
library(dplyr)
library(tidyr)

# Loading the dataset from the text file.
recid_data <- read.csv("compas-scores-raw.txt", header = TRUE, sep = ",", stringsAsFactors = TRUE)

# Displaying the first few rows to check loading.
head(recid_data)

# Renaming columns for clarity.
colnames(recid_data) <- c("Person_ID_AXE", "Assessment_ID_AXE", "Case_ID_AXE", "Agency_Text", "Last_Name", "First_Name", "Middle_Name", "Sex", "Ethnicity", "Date_Of_Birth", "Scaleset_ID_AXE", "Scale_Set_AXE", "Assessment_Reason_AXE", "Language_AXE", "Legal_Status", "Custody_Status", "Marital_Status", "Screening_Date", "Rec_Supervision_Level_AXE", "Recidivism_Supervision_Level", "Scale_ID", "Display_Text", "Raw_Score", "Decile_Score", "Score_Text_AXE", "Assessment_Type", "Is_Complete_AXE", "Is_Deleted_AXE")

# Removing unnecessary data columns. See report Task 2 for full reasoning why each column was deleted.
recid_data <- recid_data %>%
  select(-c(Person_ID_AXE, Assessment_ID_AXE, Case_ID_AXE, Scaleset_ID_AXE, Scale_Set_AXE, Assessment_Reason_AXE, Language_AXE, Rec_Supervision_Level_AXE, Score_Text_AXE, Is_Complete_AXE, Is_Deleted_AXE))

# Keep only rows where Display_Text is NOT "Risk of Failure to Appear"
recid_data <- recid_data[recid_data$Display_Text != "Risk of Failure to Appear", ]

# Converting relevant columns to appropriate data types.
recid_data$Agency_Text <- as.factor(recid_data$Agency_Text)
recid_data$Last_Name <- as.factor(recid_data$Last_Name)
recid_data$First_Name <- as.factor(recid_data$First_Name)
recid_data$Middle_Name <- as.factor(recid_data$Middle_Name)
recid_data$Sex <- as.integer(recid_data$Sex) # Integer chosen here because it can be treated as if its a boolean value.
recid_data$Ethnicity <- as.factor(recid_data$Ethnicity)
recid_data$Date_Of_Birth <- as.Date(recid_data$Date_Of_Birth, format = '%m%d%y') # Thank you Berkeley for your help with this line: https://www.stat.berkeley.edu/~s133/dates.html
recid_data$Legal_Status <- as.factor(recid_data$Legal_Status)
recid_data$Custody_Status <- as.factor(recid_data$Custody_Status)
recid_data$Marital_Status <- as.factor(recid_data$Marital_Status)
recid_data$Screening_Date <- as.Date(recid_data$Screening_Date, format = '%m%d%y')
# recid_data$Rec_Supervision_Level <- as.factor(recid_data$Rec_Supervision_Level) # Not needed because next line quantifies the same thing but is easier to understand.
recid_data$Recidivism_Supervision_Level <- as.factor(recid_data$Recidivism_Supervision_Level)
recid_data$Scale_ID <- as.integer(recid_data$Scale_ID) # Unsure of what this data variable is.
recid_data$Display_Text <- as.factor(recid_data$Display_Text) # ****** Need to remove every third data frame (Based on this entry) ******
recid_data$Raw_Score <- as.numeric(recid_data$Raw_Score)
recid_data$Decile_Score <- as.numeric(recid_data$Decile_Score)
recid_data$Assessment_Type <- as.factor(recid_data$Assessment_Type)

# Removing every data frame correlated with "Risk of Failure to Appear".
# recid_data <- recid_data %>%
#   filter(Display_Text != "Risk of Failure to Appear")

# Handling missing data values by replacing them with column medians.
recid_data <- recid_data %>%
  mutate(across(where(is.numeric), ~ ifelse(is.na(.), median(., na.rm = TRUE),.)))

# Saving the cleaned dataset.
write.csv(recid_data, "cleaned_recid_data.csv", row.names = FALSE)

# Printing summary to confirm cleaning.
summary(recid_data)

