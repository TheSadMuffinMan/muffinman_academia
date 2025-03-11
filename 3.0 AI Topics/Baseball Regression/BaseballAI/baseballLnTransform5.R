# Ensure no missing values
baseball <- baseball %>% filter(!is.na(homeruns))

# Replace zero home runs with a small positive value to avoid log(0) issues
baseball <- baseball %>% mutate(homeruns = ifelse(homeruns == 0, 0.1, homeruns))

# Apply log transformation
baseball <- baseball %>% mutate(ln_homeruns = log(homeruns))

# Fit new regression model
model_ln <- lm(ln_homeruns ~ bat_ave, data=baseball)

# Summary of the new model
summary(model_ln)
