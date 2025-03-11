# Standard error of estimate
s <- summary(model_ln)$sigma
exp(s)

# R-squared value
summary(model_ln)$r.squared

# HYPOTHESIS TESTING
# t-test for regression coefficient
summary(model_ln)$coefficients

# Confidence interval for beta1
confint(model_ln, level=0.95)