from time import time_ns as t 

def timeTest(size):
    print("\nSize = ",size,"\n")
    t0 = t()
    tab = []
    for i in range(size):
        tab.append(2*i)
    t1 = t()
    sum = 0
    for i in tab:
        sum += i
    t2 = t()

    print(f"Creation duration : {round((t1-t0) )} ns\nSum duration : {round((t2-t1))} ns\nSum = {sum}")

if __name__ == "__main__":
    timeTest(1000)
    timeTest(10000)
    timeTest(100000)