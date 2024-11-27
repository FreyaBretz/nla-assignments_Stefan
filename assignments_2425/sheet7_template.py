#import scipy
import numpy as np
import matplotlib.pyplot as plt

def vmult(v):

def richardson_iteration(b, omega, x):

def plot_vector(v):

def main():
    n = 20;
    size = n ** 2;
    
    b = np.ones(size);
    x = np.zeros(size);
    for i in range(50):
        x, resi = richardson_iteration(b, omega, x);
        if (resi < 1e-7):
            break
            

if __name__ == "__main__":
    main()
