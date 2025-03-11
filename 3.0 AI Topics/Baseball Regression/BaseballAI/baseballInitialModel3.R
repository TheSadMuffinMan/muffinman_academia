# Fit regression model
model <- lm(homeruns ~ bat_ave, data=baseball)

# Summary of the model
summary(model)
