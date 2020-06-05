import warnings
warnings.filterwarnings("ignore")
import matplotlib.pyplot as graph
# %matplotlib inline
graph.rcParams['figure.figsize'] = (15,5)
graph.rcParams["font.family"] = "DejaVu Sans"
graph.rcParams["font.size"] = "12"
graph.rcParams['image.cmap'] = 'rainbow'
graph.rcParams['axes.facecolor'] = 'white'
graph.rcParams['figure.facecolor'] = 'white'
import numpy as np
import pandas as pd

dataset = pd.read_csv('Data/COV.csv')

Show_T=np.transpose(dataset)
print(dataset.head(4))

days=dataset.columns.values

Show_X=[dataset[day].mean() for day in days]
Show_Y=np.transpose([float(day) for day in days])

poly_1 = np.polyfit(Show_X,Show_Y,1)
poly_2 = np.polyfit(Show_X,Show_Y,2)
poly_3 = np.polyfit(Show_X,Show_Y,3)
poly_4 = np.polyfit(Show_X,Show_Y,4)
poly_5 = np.polyfit(Show_X,Show_Y,5)
poly_6 = np.polyfit(Show_X,Show_Y,6)
poly_7 = np.polyfit(Show_X,Show_Y,7)

graph.scatter(Show_X,Show_Y)
xp = np.linspace(0,40,40)

for row in range(0,Show_T.shape[1]):
    graph.plot(dataset.columns.values,Show_T[row])

graph.plot(xp,np.polyval(poly_7,xp),'y-')

graph.xticks(Show_X,dataset.columns.values)
graph.ylim(0,40)
graph.title("Test")
graph.xlabel("Date")
graph.ylabel("Data")

graph.show()


