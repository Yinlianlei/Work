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

dataset = pd.read_csv('Data/traffic_by_hour.csv')
print(dataset.head())

dataset_T = np.transpose(dataset)
print(dataset_T)
'''
# The first version
for sample in range(0, dataset_T.shape[1]):
    graph.plot(dataset.columns.values, dataset_T[sample])
graph.xlabel('Time of day')
graph.ylabel('Internet traffic (Gbps)')
graph.show()
'''

hours = dataset.columns.values

train_Y = [dataset[hour].mean() for hour in hours]  # This will be our outcome we measure (label) - amount of internet traffic

train_X = np.transpose([int(hour) for hour in hours]) # This is our feature - time of day

###
# REPLACE THE <replaceWithDegree> BELOW WITH 1
###
poly_1 = np.polyfit(train_X, train_Y,1)
###
# REPLACE THE <replaceWithDegree>'s BELOW WITH 2, 3, AND THEN 4
###
poly_2 = np.polyfit(train_X, train_Y, 2)
poly_3 = np.polyfit(train_X, train_Y, 3)
poly_4 = np.polyfit(train_X, train_Y, 4)
###
# REPLACE THE <replaceWithDegree>'s 5, 6, AND 7
###
poly_5 = np.polyfit(train_X, train_Y, 5)
poly_6 = np.polyfit(train_X, train_Y, 6)
poly_7 = np.polyfit(train_X, train_Y, 7)


'''
# The second version
graph.scatter(train_X, train_Y)
for sample in range(0,dataset_T.shape[1]):
    graph.plot(hours, dataset_T[sample], alpha=0.25)
graph.xlabel('Time of day')
graph.ylabel('Internet traffic (Gbps)')
graph.show()
'''
# Let's plot it!
graph.scatter(train_X, train_Y)
xp = np.linspace(0, 24, 100)

'''
# black dashed linear degree 1
graph.plot(xp, np.polyval(poly_1, xp), 'k--')
# red degree 2
graph.plot(xp, np.polyval(poly_2, xp), 'r-')
# blue degree 3
graph.plot(xp, np.polyval(poly_3, xp), 'b-') 
# yellow degree 4
graph.plot(xp, np.polyval(poly_4, xp), 'y-') 
# red degree 5
graph.plot(xp, np.polyval(poly_5, xp), 'r-') 
# blue degree 6
graph.plot(xp, np.polyval(poly_6, xp), 'b-') 
# yellow degree 7
graph.plot(xp, np.polyval(poly_7, xp), 'y-') 
'''
# The Forth version
for row in range(0,dataset_T.shape[1]):
    graph.plot(dataset.columns.values, dataset_T[row], alpha = 0.5)
###
# REPLACE <replaceWithPoly6> BELOW WITH poly_6 - THE POLYNOMIAL WE WISH TO VISUALIZE
###
'''
# The Forth version
graph.plot(xp, np.polyval(poly_6, xp), 'k-')
###

graph.xticks(train_X, dataset.columns.values)
graph.xlabel('Time of day')
graph.ylabel('Internet traffic (Gbps)')
graph.show()
'''
###
# REPLACE <replaceWithTime> BELOW WITH 12.5 (this represents the time 12:30)
###
time = 12.5
###
###
# REPLACE <replaceWithPoly6> BELOW WITH poly_6 SO WE CAN VISUALIZE THE 6TH DEGREE POLYNOMIAL MODEL
###
pred = np.polyval(poly_6, time)
###

print("at t=%s, predicted internet traffic is %s Gbps"%(time,pred))

# Now let's visualise it
graph.plot(xp, np.polyval(poly_6, xp), 'y-')

graph.plot(time, pred, 'ko') # result point
graph.plot(np.linspace(0, time, 2), np.full([2], pred), dashes=[6, 3], color='black') # dashed lines (to y-axis)
graph.plot(np.full([2], time), np.linspace(0, pred, 2), dashes=[6, 3], color='black') # dashed lines (to x-axis)

graph.xticks(train_X, dataset.columns.values)
graph.ylim(0, 60)
graph.title('expected traffic throughout the day')
graph.xlabel('time of day')
graph.ylabel('internet traffic (Gbps)')

graph.show()

