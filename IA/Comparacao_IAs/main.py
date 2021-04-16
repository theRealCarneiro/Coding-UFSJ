from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from scipy.stats import mode
from knn import KNN
import matplotlib.pyplot as plt
import numpy as np
import warnings
warnings.filterwarnings("ignore")


def teste_knn(modelo):
    x_train, x_test, y_train, y_test=train_test_split(modelo.data,modelo.target,test_size=0.33)
    
    clf = KNN(k = 3)
    clf.fit(x_train, y_train)

    print("Acuracia knn: ")
    print(accuracy_score(y_test, clf.predict(x_test)))

    accuracy_values = []
    for x in range(1, 50):
        clf = KNN(k = x)
        clf.fit(x_train, y_train)
        accuracy=accuracy_score(y_test, clf.predict(x_test))
        accuracy_values.append([x, accuracy])

    accuracy_values=np.array(accuracy_values)

    
    return accuracy_values


def teste_nn(modelo):
    x_train, x_test, y_train, y_test=train_test_split(modelo.data,modelo.target,test_size=0.33)
    clf = MLPClassifier(solver='lbfgs', alpha=1e-5, hidden_layer_sizes=(49, 7), random_state=1).fit(x_train,y_train)

    print("Acuracia rede neural: ")
    print(accuracy_score(y_test,clf.predict(x_test)))

    accuracy_values=[]

    for x in range(1,50):
      clf = MLPClassifier(solver='lbfgs', alpha=1e-5, hidden_layer_sizes=(x, int(max(np.sqrt(x), 1))), random_state=1).fit(x_train,y_train)
      accuracy=accuracy_score(y_test,clf.predict(x_test))
      accuracy_values.append([x,accuracy])
      pass

    accuracy_values=np.array(accuracy_values)

    return accuracy_values

def teste_nb(modelo):
    x_train, x_test, y_train, y_test=train_test_split(modelo.data,modelo.target,test_size=0.33)
    clf = GaussianNB(var_smoothing=10^10).fit(x_train,y_train)

    print("Acuracia Naive Bayes: ")
    print(accuracy_score(y_test,clf.predict(x_test)))

    accuracy_values=[]

    for x in range(1,50):
      clf = GaussianNB(var_smoothing=10^(x)).fit(x_train,y_train)
      accuracy=accuracy_score(y_test,clf.predict(x_test))
      accuracy_values.append([x,accuracy])
      pass

    accuracy_values=np.array(accuracy_values)

    return accuracy_values

def teste_svc(modelo):
    x_train, x_test, y_train, y_test=train_test_split(modelo.data,modelo.target,test_size=0.33)
    clf = SVC(C=10).fit(x_train,y_train)

    print("Acuracia SVM: ")
    print(accuracy_score(y_test,clf.predict(x_test)))

    accuracy_values=[]

    for x in range(1,50):
      clf = SVC(C=x).fit(x_train,y_train)
      accuracy=accuracy_score(y_test,clf.predict(x_test))
      accuracy_values.append([x,accuracy])
      pass

    accuracy_values=np.array(accuracy_values)

    return accuracy_values

def teste_ad(modelo):
    x_train, x_test, y_train, y_test=train_test_split(modelo.data,modelo.target,test_size=0.33)
    clf = DecisionTreeClassifier(min_samples_leaf=10).fit(x_train,y_train)

    print("Acuracia arovre de decisão")
    print(accuracy_score(y_test,clf.predict(x_test)))

    accuracy_values=[]

    for x in range(1,50):
      clf = DecisionTreeClassifier(min_samples_leaf=x).fit(x_train,y_train)
      accuracy=accuracy_score(y_test,clf.predict(x_test))
      accuracy_values.append([x,accuracy])
      pass

    accuracy_values=np.array(accuracy_values)

    return accuracy_values


def main():
    modelo = [datasets.load_iris(),datasets.load_digits(),datasets.load_wine(),datasets.load_breast_cancer()]
    modelos = ['Iris','Dígitos','Vinho','Câncer de mama']
    for i in range(0,4):
        a=teste_knn(modelo[i])  
        b=teste_nn(modelo[i])
        c=teste_nb(modelo[i])
        d=teste_svc(modelo[i])
        e=teste_ad(modelo[i])
        plt.plot(a[:,0],a[:,1],label='knn')
        plt.plot(b[:,0],b[:,1],label='Rede Neural')
        plt.plot(c[:,0],c[:,1],label='Naive-Bayes')
        plt.plot(d[:,0],d[:,1],label='SCM')
        plt.plot(e[:,0],e[:,1],label='Árvore de decisão')
        plt.xlabel("N")
        plt.ylabel("Acurácia")
        plt.legend()
        plt.suptitle(modelos[i])
        plt.show()
    

if __name__ == "__main__" :
    main()
