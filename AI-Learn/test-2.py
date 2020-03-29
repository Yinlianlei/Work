# This sets up the graphing configuration
import warnings
warnings.filterwarnings("ignore")
import matplotlib.pyplot as graph
# %matplotlib inline 是在使用jupyter notebook 或者 jupyter qtconsole的时候，才会经常用到%matplotlib
graph.rcParams['figure.figsize'] = (15,5)
graph.rcParams["font.family"] = 'Consolas'
graph.rcParams["font.size"] = '12'
import pandas as pd
import statsmodels.formula.api as smf

# Imports our new data set!
dataset = pd.read_csv('Data/chocolate_data_multiple_linear_regression.txt', index_col=False, sep="\t",header=0)
 
###    
# REPLACE <printDataHere> with print(dataset.head())
###
print(dataset.head())
###
###
# REPLACE <addFeatureHere> BELOW WITH weight
### first-version
# formula = 'customer_happiness ~ cocoa_percent'
###

# second-version
formula = 'customer_happiness ~ weight + cocoa_percent + cost'

# This performs linear regression
# first-version
#lm = smf.ols(formula = formula, data = dataset).fit()

# second-version
lm = smf.ols(formula = formula, data = dataset).fit()


featureName = formula.split(" ")[-1]

# Get the data for the x parameter (the feature)
x = dataset[featureName]

# This makes and shows a graph
intercept = lm.params[0]
slope = lm.params[1]
line = slope * x + intercept
graph.plot(x, line, '-', c = 'red')
graph.scatter(x, dataset.customer_happiness,c='#7B68EE')
graph.ylabel('Customer Happiness')
graph.xlabel(featureName)
graph.show()
# lm 为拟合度,越大越好
# print(lm.rsquared)

print(lm.params)

print("R²: " + str(lm.rsquared))
