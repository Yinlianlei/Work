import warnings
warnings.filterwarnings("ignore")
import pandas as pd
import matplotlib.pyplot as graph
import statsmodels.formula.api as smf
from scipy import stats

dataset = pd.read_csv('Data/chocolate_data.txt', index_col=False, sep="\t",header=0)
# read_csv读取CSV 文件到DataFrame也支持文件的部分导入和选择迭代
# index_col 用作行索引的列编号或者列名
# sep 指定分隔符
# header 指定行数用来作为列名，数据开始行数
    
###
# REPLACE <PrintDataHere> WITH print(dataset.head())
###
print(dataset.head())
###

def PerformLinearRegression(formula):

    # This performs linear regression 
    # .ols 普通最小二乘模型
    # .ols 回归用于计算回归系数 使误差平方 最小化
    # .fit()获取拟合结果 用于查看拟合度
    lm = smf.ols(formula = formula, data = dataset).fit()

    featureName=formula.split(" ")[-1]

    # get the data for the x parameter (our feature)
    train_X=dataset[featureName]

    # This makes and shows a graph
    intercept=lm.params[0]
    slope=lm.params[1]
    line = slope * train_X + intercept
    
    # 绘画折线
    graph.plot(train_X, line, '-', c = 'red')
    # 设置点的位置 还可以设置点的大小和颜色 这里设置成了紫罗兰色
    graph.scatter(train_X, dataset.customer_happiness,c='#EE80EE')
    # 设置横纵坐标的名称
    graph.ylabel('customer_happiness')
    graph.xlabel(featureName)
    graph.show()

# This performs the linear regression steps listed above
# The text in red is the formula for our regression
# 'X~Y' 输入格式
PerformLinearRegression('customer_happiness ~ cocoa_percent')

