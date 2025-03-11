# Loading necessary libraries.
library(dplyr)
library(tidyr)

# Loading the dataset from the text file.
recid_data <- read.csv("compas-scores-raw.txt", header = TRUE, sep = ",", stringsAsFactors = TRUE)

# Displaying the first few rows to check loading.
head(recid_data)

# Renaming columns for clarity.
colnames(recid_data) <- c("Person_ID_AXE", "Assessment_ID_AXE", "Case_ID_AXE", "Agency_Text", "Last_Name", "First_Name", "Middle_Name", "Sex", "Ethnicity", "Date_Of_Birth_AXE", "Scaleset_ID_AXE", "Scale_Set_AXE", "Assessment_Reason_AXE", "Language_AXE", "Legal_Status", "Custody_Status", "Marital_Status", "Screening_Date_AXE", "Rec_Supervision_Level_AXE", "Recidivism_Supervision_Level", "Scale_ID_AXE", "Display_Text", "Raw_Score", "Decile_Score", "Score_Text_AXE", "Assessment_Type", "Is_Complete_AXE", "Is_Deleted_AXE")

# Removing unnecessary data columns. See report Task 2 for full reasoning why each column was deleted.
recid_data <- recid_data %>%
  select(-c(Person_ID_AXE, Assessment_ID_AXE, Case_ID_AXE, Date_Of_Birth_AXE, Scaleset_ID_AXE, Scale_Set_AXE, Assessment_Reason_AXE, Language_AXE, Screening_Date_AXE, Rec_Supervision_Level_AXE, Scale_ID_AXE, Score_Text_AXE, Is_Complete_AXE, Is_Deleted_AXE))

# Deleting rows where Display_Text is NOT "Risk of Failure to Appear".
recid_data <- recid_data[recid_data$Display_Text != "Risk of Failure to Appear", ]

# Getting rid of all rows that are a copy.
recid_data <- recid_data %>% filter(recid_data$Assessment_Type != "Copy", )

# Converting columns to appropriate data types.
recid_data$Agency_Text <- as.character(recid_data$Agency_Text)
recid_data$Last_Name <- as.character(recid_data$Last_Name)
recid_data$First_Name <- as.character(recid_data$First_Name)
recid_data$Middle_Name <- as.character(recid_data$Middle_Name)
recid_data$Sex <- as.factor(recid_data$Sex)
recid_data$Ethnicity <- as.factor(recid_data$Ethnicity)
recid_data$Legal_Status <- as.factor(recid_data$Legal_Status)
recid_data$Custody_Status <- as.factor(recid_data$Custody_Status)
recid_data$Marital_Status <- as.factor(recid_data$Marital_Status)
recid_data$Recidivism_Supervision_Level <- as.factor(recid_data$Recidivism_Supervision_Level)
recid_data$Display_Text <- as.character(recid_data$Display_Text)
recid_data$Raw_Score <- as.numeric(recid_data$Raw_Score)
recid_data$Decile_Score <- as.integer(recid_data$Decile_Score)
recid_data$Assessment_Type <- as.character(recid_data$Assessment_Type)

# Filtering out all actual recidivism data. Risk of violence data is separated into its own csv.
recid_data <- recid_data %>% filter(Display_Text == unique(recid_data$Display_Text)[2])

# Filtering out all "Risk of Violence" data.
violence_data <- recid_data %>% filter(Display_Text == unique(recid_data$Display_Text)[1])

# Handling missing data values by replacing them with column medians.
recid_data <- recid_data %>%
  mutate(across(where(is.numeric), ~ ifelse(is.na(.), median(., na.rm = TRUE),.)))

# Printing summary to confirm cleaning.
summary(recid_data)

# Saving the cleaned dataset.
write.csv(recid_data, "cleaned_recid_data.csv", row.names = FALSE)

