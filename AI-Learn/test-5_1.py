# Let's do that again.
# We will repeat what we did in step 3, but change the decision boundary.
import warnings
warnings.filterwarnings("ignore")
import matplotlib.pyplot as graph
# %matplotlib inline
graph.rcParams['figure.figsize'] = (15,5)
graph.rcParams["font.family"] = 'DejaVu Sans'
graph.rcParams["font.size"] = '12'
graph.rcParams['image.cmap'] = 'rainbow'
import pandas as pd
import numpy as np
from sklearn import linear_model



dataset = pd.read_csv('Data/football_data.txt', index_col = False, sep = '\t', header = 0)


print(dataset.head())
###
# REPLACE THE <numberOfGoals> WITH THE NUMBER OF GOALS YOU WANT TO EVALUATE
###
p = 2
###

# Here we build the new logistic regression model.
# The C=200 is where we change the decision boundary.

clf = linear_model.LogisticRegression(C=200)
###


# REPLACE <addWonCompetition> BELOW WITH 'won_competition' (INCLUDING THE QUOTES)
train_Y = dataset['won_competition']

# REPLACE <addAverageGoals> BELOW WITH 'average_goals_per_match' (INCLUDING THE QUOTES)
train_X = dataset['average_goals_per_match']




# This step fits (calculates) the model
# We are using our feature (x - number of goals scored) and our outcome/label (y - won/lost)
clf.fit(train_X[:, np.newaxis], train_Y)
# This works out the loss
def sigmoid(train_X):
    return 1 / (1 + np.exp(-train_X))
X_test = np.linspace(0, 3, 300)
loss = sigmoid(X_test * clf.coef_ + clf.intercept_).ravel()




# This makes the prediction for your chosen number of goals.
probOfWinning = clf.predict_proba([[p]])[0][1]

# This prints out the result.
print("Probability of winning this year")
print(str(probOfWinning * 100) + "%")

# This plots the result.
graph.scatter(train_X, train_Y, c = train_Y, marker = 'D')
graph.yticks([0, probOfWinning, 1], ['No = 0.0', round(probOfWinning,3), 'Yes = 1.0'])
graph.plot(X_test, loss, color = 'gold', linewidth = 3)

graph.plot(p, probOfWinning, 'ko') # result point
graph.plot(np.linspace(0, p, 2), np.full([2],probOfWinning), dashes = [6, 3], color = 'black') # dashed lines (to y-axis)
graph.plot(np.full([2],p), np.linspace(0, probOfWinning, 2), dashes = [6, 3], color = 'black') # dashed lines (to x-axis)

graph.ylabel("Competition Win Likelihood")
graph.xlabel("Average number of goals per match")
graph.show()
