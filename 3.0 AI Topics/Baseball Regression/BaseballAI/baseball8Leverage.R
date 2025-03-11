# Cook's distance to identify influential points
cooksd <- cooks.distance(model_ln)

plot(cooksd, type="h", main="Cook's Distance for Influential Points")

abline(h = 4/length(cooksd), col="red")
