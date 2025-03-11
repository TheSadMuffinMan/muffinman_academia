# Residual plots
par(mfrow=c(2,2))
plot(model)

# Normal probability plot
qqnorm(residuals(model))
qqline(residuals(model))

