from cProfile import label
import matplotlib.pyplot as plt
import numpy as np
import scipy.stats as stats

mu = 50
sigma = 16.5
x = np.linspace(mu - 3*sigma, mu + 3*sigma, 100)
y = stats.norm.pdf(x, mu, sigma)
plt.plot(33*x/100   , 100*y, label='fácil')
plt.plot(33*x/100+33, 100*y, label='médio')
plt.plot(33*x/100+66, 100*y, label='difícil')
plt.title ('Distribuição da dificuldade')
plt.ylabel('Probabilidade de encontrar[%]')
plt.xlabel('Resposta da função[%]')
plt.ylim([0,3])
plt.xlim([-10,100])
plt.legend()
plt.grid()
plt.savefig('images/dificuldade.png')
plt.show()