# Loading necessary libraries.
library(tidyverse)

# Loading the dataset.
baseball <- read.table("baseball.txt", header=TRUE)

# Filtering players with at_bats >= 100.
baseball <- baseball %>% filter(at_bats >= 100)

# View struct.
str(baseball)
