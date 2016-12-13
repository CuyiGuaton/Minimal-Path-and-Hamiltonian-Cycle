library(ggplot2)   
tabla=read.table("informe/plots/plot4n10000.txt")
p=tabla$V1
Tiempo=tabla$V2
ggplot(data = tabla, aes(x=p, y=Tiempo)) +  geom_point() + scale_x_continuous(breaks=seq(0, 1, 0.05))  + ggtitle("Tiempo vs p para n = 10000") + theme(plot.title = element_text(hjust = 0.5))
#+ scale_y_continuous(breaks = seq(min(Tiempo), max(Tiempo),0.0001))


