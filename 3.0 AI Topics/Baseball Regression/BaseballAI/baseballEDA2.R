# Script generates a scatter plot of home runs vs. batting average
library(ggplot2)

ggplot(baseball, aes(x=bat_ave, y=homeruns)) + geom_point() + labs(title="Home Runs vs. Batting Average", x="Batting Average", y="Home Runs")
