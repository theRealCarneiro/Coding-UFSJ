from numpy import *
from scipy.stats import mode

class KNN():

    def __init__(self, k):
        self.k = k


    def fit(self, x_train, y_train):
        self.x_train = x_train
        self.y_train = y_train
        self.m, self.n = x_train.shape


    def predict(self, x_test):
        self.x_test = x_test
        self.m_test, self.n = x_test.shape
        y_predict = zeros(self.m_test)
        for i in range(self.m_test):
            x = self.x_test[i]
            neighbors = zeros(self.k)
            distances_e = zeros(self.m)
            for j in range(self.m):
                distances = sqrt(sum(square(x - self.x_train[j])))
                distances_e[j] = distances
            j = distances_e.argsort()
            y_train_sorted = self.y_train[j]
            neighbors = y_train_sorted[:self.k]
            y_predict[i] = mode(neighbors)[0][0]
        return y_predict
